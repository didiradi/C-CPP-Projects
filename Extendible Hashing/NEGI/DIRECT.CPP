// direct.cpp

#include "C:\NEGI\direct.h"
#include "C:\NEGI\hash.cpp"
#include "C:\NEGI\clear.cpp"
#include "C:\NEGI\mani\functions.h"
#include <strstream.h>


const int MaxKeySize = 12;



Directory::Directory (int maxBucketKeys)
{
	Depth = 0; // depth of directory
	NumCells = 1; // number of entries, = 2**Depth
	BucketAddr = new int [NumCells]; // array of bucket addresses

	MaxBucketKeys = maxBucketKeys;
	DirectoryBuffer = new LengthFieldBuffer; // default size
	DirectoryFile = new BufferFile(*DirectoryBuffer);
	CurrentBucket = new Bucket (*this, MaxBucketKeys);
	theBucketBuffer = new BucketBuffer (MaxKeySize, MaxBucketKeys);
	BucketFile = new BufferFile (*theBucketBuffer);
	PrintBucket = new Bucket (*this, MaxBucketKeys);
}

Directory::~Directory ()
{
	Close();
}

int Directory::getMaxBucketSize()
{
return MaxBucketKeys;
}

void makeNames(char * name, char *& dirName, char *& bktName)
{
	ostrstream directoryName;
	directoryName<<name<<".dir"<<ends;
	dirName = strdup(directoryName.str());
	ostrstream bucketName;
	bucketName <<name<<".bkt"<<ends;
	bktName = strdup(bucketName.str());
}

int Directory::Open (char * name)
{
	int result;
	char * directoryName, * bucketName;
	makeNames(name, directoryName, bucketName);
	result = DirectoryFile->Open(directoryName, ios::in|ios::out);
	if (!result) return 0;
	result = DirectoryFile->Read();
	if (result==-1) return 0;
	result = Unpack();
	if (!result==-1) return 0;
	result = BucketFile->Open(bucketName,ios::in|ios::out);
	return result;
}

int Directory::Create (char * name)
{
	// create two files, clear the directory, create a single bucket
	// and add it to the directory and the bucket file
	int result;
	char * directoryName, * bucketName;
	makeNames(name, directoryName, bucketName);
	result = DirectoryFile->Create(directoryName, ios::in|ios::out);
	if (!result) return 0;
	result = BucketFile->Create(bucketName,ios::in|ios::out);
	if (!result) return 0;
	// store the empty CurrentBucket in the BucketFile and add to Directory
	BucketAddr[0] = StoreBucket (CurrentBucket);
	return result;
}

int Directory::Close ()
{// write the directory and close. error occurs on buffer overflow
	int result;
	result = Pack();
	if (result==-1) return 0;
	DirectoryFile -> Rewind();
	result = DirectoryFile->Write();
	if (result==-1) return 0;
	return DirectoryFile->Close() && BucketFile->Close();
}

int Directory::Insert (char * key, int recAddr)
{
	int found = Search (key);
	if (found == -1) return CurrentBucket->Insert(key, recAddr);
	return 0;// key already in directory
}

int Directory::Remove (char * key)
{// remove the key and return its RecAddr
	int bucketAddr = Find(key);
	LoadBucket (CurrentBucket, bucketAddr);
	return CurrentBucket -> Remove (key);
}

int Directory::Search (char * key)
{// return RecAddr for key, also put current bucket into variable
	int bucketAddr = Find(key);
	LoadBucket (CurrentBucket, bucketAddr);
	return CurrentBucket->Search(key);
}

int Directory::ReSize ()
// double the size of the directory
{
	int newSize = 2 * NumCells;
	int * newBucketAddr = new int[newSize];
	for (int i = 0; i < NumCells; i++)
	{
		newBucketAddr[2*i] = BucketAddr[i];
		newBucketAddr[2*i+1] = BucketAddr[i];
	}
	delete BucketAddr;
	BucketAddr = newBucketAddr;
	Depth ++;
	NumCells = newSize;
	return 1;
}


int Directory :: Collapse()
{
   // if collapse is possible reduce size by half
   if (Depth == 0) return 0;// only one bucket
   // look for buddies that are different, if found return
   for (int i=0;i<NumCells;i+=2)
	  if(BucketAddr[i] != BucketAddr[i+1])
		return 0;
   int newSize = NumCells / 2;
   int * newAddrs = new int [newSize];
   for(int j =0; j<newSize;j++)
	 newAddrs[j] = BucketAddr[j*2];
   delete BucketAddr;
   BucketAddr = newAddrs;
   Depth --;
   NumCells = newSize;
   return 1;
}


int Directory:: DoubleSize ()
{
  // double the size of the directory
  int newSize = 2 * NumCells;
  int *newBucketAddr = new int[newSize];
  for(int i=0;i<NumCells;i++){
	newBucketAddr[2*i] = BucketAddr[i];
	newBucketAddr[2*i+1] = BucketAddr[i];
  }

  delete BucketAddr;
  BucketAddr = newBucketAddr;
  Depth++;
  NumCells = newSize;
  return 1;
}




int Directory::Reduction ()
{// if collapse is possible, reduce size by half
	if (Depth == 0) return 0; // only 1 bucket
	// look for buddies that are different, if found return
	for (int i = 0; i < NumCells; i += 2)
		if (BucketAddr[i] != BucketAddr[i+1]) return 0;
	int newSize = NumCells / 2;
	int * newAddrs = new int [newSize];
	for (int j = 0; j < newSize; j++)
		newAddrs[j] = BucketAddr[j*2];
	delete BucketAddr;
	BucketAddr = newAddrs;
	Depth --;
	NumCells = newSize;
	return 1;
}

int Directory::InsertBucket (int bucketAddr, int first, int last)
{// change cells to refer to this bucket
	for (int i = first; i <= last; i++)
		BucketAddr[i] = bucketAddr;
	return 1;
}

int Directory::RemoveBucket (int bucketIndex, int bucketDepth)
{// implementation left as exercise
	// set all cells for this bucket to its buddy bucket
	int fillBits = Depth-bucketDepth; // number of bits to fill
	int buddyIndex = bucketIndex ^ (1<<(fillBits-1)); // flip low bit
	int newBucketAddr = BucketAddr[buddyIndex];
	int lowIndex = bucketIndex >> fillBits << fillBits; // zero low bits
	int highIndex = lowIndex + (1<<fillBits) - 1; // set low bits to 1
	for (int i = lowIndex; i <= highIndex; i++)
		BucketAddr[i] = newBucketAddr;
	return 0;
}

int Directory::Find (char * key)
// return BucketAddr for key
{
	return BucketAddr[MakeAddress (key, Depth)];
}

int Directory::Pack ()  const
{// pack the buffer and return the number of bytes packed
	int result, packsize;
	DirectoryBuffer -> Clear();
	packsize = DirectoryBuffer -> Pack (&Depth, sizeof(int));
	if (packsize == -1) return -1;
	for (int i = 0; i<NumCells; i++)
	{
		result = DirectoryBuffer -> Pack (&BucketAddr[i], sizeof(int));
		if (result == -1) return -1;
		packsize += result;
	}
	return packsize;
}

int Directory::Unpack ()
{
	int result;
	result = DirectoryBuffer -> Unpack (&Depth, sizeof(int));
	if (result == -1) return -1;
	NumCells = 1 << Depth;
	if (BucketAddr != 0) delete BucketAddr;
	BucketAddr = new int[NumCells];
	for (int i = 0; i<NumCells; i++)
	{
		result = DirectoryBuffer -> Unpack (&BucketAddr[i], sizeof(int));
		if (result == -1) return -1;
	}
	return 0;
}

int Directory::StoreBucket (Bucket * bucket)
{// update or append the bucket to the bucket file
	int result;
	result = theBucketBuffer -> Pack (* bucket);
	if (result == -1) return -1;
	int addr = bucket->BucketAddr;
	if (addr != 0) return BucketFile->Write (addr);
	addr = BucketFile -> Append ();
	bucket -> BucketAddr = addr;
	return addr;
}

int Directory::LoadBucket(Bucket * bucket, int bucketAddr)
{// read bucket from file, and set BucketAddr field
	int result;
	result = BucketFile -> Read (bucketAddr);
	if (result == -1) return 0;
	result = theBucketBuffer -> Unpack (*bucket);
	if (result == -1) return 0;
	bucket->BucketAddr = bucketAddr;
	return 1;
}
int Directory::getdepth()
{
return Depth;
}

void Directory::Print (void)
{
clearScr();
int tcells=0;
int count=1;
int drow=50;
int col=110;
int x1,y1;
int x=10;int y=60;

	setcolor(12);
	settextstyle(0,0,1);

	outtextxy(10,y,"DIRECTORY DEPTH                : ");
	x=x+textwidth("DIRECTORY DEPTH                : ");
	y=60;
	gprintf(&x,&y,"%d",Depth);
	x=10;y=70;
	gprintf(&x,&y,"DIRECTORY SIZE (2^depth)       : ");
	x=x+textwidth("DIRECTORY SIZE                 : ");
	y=70;
	gprintf(&x,&y,"%d",NumCells);


for (int i = 0; i<NumCells; i++)
{

disp:   if(tcells<32)
	{

	//write direc addr
	setcolor(YELLOW);
	x=10;
	y=95;
	outtextxy(x,y,"DIR");
	//write directory contents
	x=70;
	outtextxy(x,y,"DIRECTORY");
	x=160;
	outtextxy(x,y,"BUCKET ADDR");

	if(MaxBucketKeys==1)
	{
	x=260;
	outtextxy(x,y,"KEY");
	x=330;
	outtextxy(x,y,"ADDR");
	}
	else if(MaxBucketKeys==2)
	{
	x=260;
	outtextxy(x,y,"KEY");
	x=330;
	outtextxy(x,y,"ADDR");

	x=380;
	outtextxy(x,y,"KEY");
	x=450;
	outtextxy(x,y,"ADDR");
	}
	else if(MaxBucketKeys==3)
	{
	x=260;
	outtextxy(x,y,"KEY");
	x=330;
	outtextxy(x,y,"ADDR");

	x=380;
	outtextxy(x,y,"KEY");
	x=450;
	outtextxy(x,y,"ADDR");

	x=500;
	outtextxy(x,y,"KEY");
	x=570;
	outtextxy(x,y,"ADDR");
	}

	settextstyle(0,0,1);


		//draw directory

		setcolor(15);
		rectangle(drow,col,drow+100,col+10);
		setcolor(BROWN);
		//draw directory address
		x1=10;
		y1=col+1;
		gprintf(&x1,&y1,"%p",i);

		//print directory contents
		x1=drow+40;
		y1=col+1;
		setcolor(WHITE);
		gprintf(&x1,&y1,"%d",BucketAddr[i]);

		if(BucketAddr[i]!=BucketAddr[i+1])
		{
		//draw buckets
		setcolor(15);
		if(MaxBucketKeys==1)
		{
		rectangle(250,col,370,col+10);
		rectangle(330,col,370,col+10);
		}
		else if (MaxBucketKeys==2)
		{
		rectangle(250,col,370,col+10);
		rectangle(330,col,370,col+10);
		rectangle(370,col,490,col+10);
		rectangle(450,col,490,col+10);
		}
		else if(MaxBucketKeys==3)
		{
		rectangle(250,col,370,col+10);
		rectangle(330,col,370,col+10);
		rectangle(370,col,490,col+10);
		rectangle(450,col,490,col+10);
		rectangle(490,col,610,col+10);
		rectangle(570,col,610,col+10);
		}
		else
		{
		clearScr();
		rectangle(100,100,getmaxx()-100,getmaxy()-100);
		rectangle(100+1,100+1,getmaxx()-101,getmaxy()-101);
		setcolor(15);
		outtextxy(150,getmaxy()/2-10,"CAN'T DISPLAY THE FULL BUCKET ON SCREEN");
		outtextxy(150,getmaxy()/2,"THE MAXIMUM NUMBER OF KEYS PER BUCKET ARE ");
		outtextxy(150,getmaxy()/2+10,"MORE THAN THREE, WHICH CAN'T BE DISPLAYED");
		DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
		getche();
		clearScr();
		return;
		}
		setcolor(12);
		x1=210;
		y1=col+1;
		gprintf(&x1,&y1,"%d",BucketAddr[i]);
		count++;
		//DRAW ARROWS
		setcolor(CYAN);
		line(155,col+5,205,col+5);
		line(205,col+5,201,col+1);
		line(205,col+5,201,col+9);
		//LOAD THE BUCKET
		LoadBucket (PrintBucket, BucketAddr[i]);
		int mkeys=PrintBucket->retMaxKeys();
		int nkeys=PrintBucket->retNumKeys();
		setcolor(GREEN);
		x1=240;
		y1=col+1;
		gprintf(&x1,&y1,"%d",nkeys);
		settextstyle(2,0,0);

		int x2=252;
		int y2=col;
		for(int j=0;j<nkeys;j++)
		{
			if(j==0)
			{
			x2=252;
			}
			if(j==1)
			{
			x2=372;
			}
			if(j==2)
			{
			x2=492;
			}
			setcolor(CYAN);
			settextstyle(2,0,4);
			char* key=PrintBucket->retKey(j);
			int raddr=PrintBucket->retRecAddr(j);
			gprintf(&x2,&y2,"%s",key);
			x2=x2+82;
			y2=col;
			gprintf(&x2,&y2,"%d",raddr);
			y2=col;

		}
		settextstyle(0,0,0);

		}

		x1=15;
		y1=440;
		setcolor(15);
		outtextxy(x1,y1,"CURRENTLY DISPLAYING DIRECTORY CELLS ( ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS ( ");
		y1=440;
		gprintf(&x1,&y1,"%d",tcells+1);
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ");
		y1=440;
		outtextxy(x1,y1," TO ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (   ")+textwidth(" TO   ");
		y1=440;
		gprintf(&x1,&y1,"%d",NumCells);

		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ")+textwidth(" TO    ");
		y1=440;
		outtextxy(x1,y1,"  ) FROM A TOTAL NUMBER OF ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ")+textwidth(" TO     ")+textwidth("  ) FROM A TOTAL NUMBER OF ");
		y1=440;
		gprintf(&x1,&y1,"%d ",NumCells);


	    }
	    else
	    {
		i=0;
		DrawStatusBar("HELP","DATA FILE D:\\NEGI\\HASH.DIR STILL HAS DATA ! PRESS ANY KEY");


		int x1=15;
		int y1=440;
		setcolor(RED);
		outtextxy(x1,y1,"CURRENTLY DISPLAYING DIRECTORY CELLS ( ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS ( ");
		y1=440;
		gprintf(&x1,&y1,"%d",tcells);
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ");
		y1=440;
		outtextxy(x1,y1," TO  ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ")+textwidth(" TO   ");
		y1=440;
		gprintf(&x1,&y1,"%d",NumCells-1);

		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ")+textwidth(" TO   ");
		y1=440;
		outtextxy(x1,y1,"   ) FROM A TOTAL NUMBER OF ");
		x1=15+textwidth("CURRENTLY DISPLAYING DIRECTORY CELLS (  ")+textwidth(" TO   ")+textwidth(" ) FROM A TOTAL NUMBER OF ");
		y1=440;
		gprintf(&x1,&y1,"%d ",NumCells);


		tcells+=20;
		getche();
		clearScr();
		goto disp;
}
	col=col+10;
}

      setcolor(12);
      settextstyle(0,0,0);
	x=10;y=80;
	gprintf(&x,&y,"TOTAL NUMBER OF BUCKETS        : ");
	x=x+textwidth("DIRECTORY SIZE                 : ");
	y=80;
	gprintf(&x,&y,"%d",count-1);
	DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");

	getche();
	clearScr();
}

float Directory::Space_util(char* myfile)
{
fstream file;
file.open(myfile,ios::in);

float count=1;


for(int i=0;i<NumCells-1;i++)
{
if(BucketAddr[i]==BucketAddr[i+1])
continue;
else
count++;
}

return count;
}

int  Directory::getnumcells()
{
return NumCells;
}
Bucket::Bucket (Directory & dir, int maxKeys) // constructor
:TextIndex (maxKeys), Dir (dir)
{
	BucketAddr = 0;
	Depth = 0;
}

int Bucket::Insert (char * key, int recAddr)
{
	if (NumKeys < MaxKeys)
	{
		int result = TextIndex::Insert (key, recAddr);
		Dir.StoreBucket (this);
		return result;
	}
	else
	{
		Split ();
		return Dir.Insert (key, recAddr);
	}
}

int Bucket::Remove (char * key)
{// remove the key, return its RecAddr
	int result = TextIndex::Remove (key);
	if (!result) return 0; // key not in bucket
	TryCombine (); // attempt to combine with buddy
	// make the changes permanent
	Dir.StoreBucket(this);
	return 1;
}

Bucket * Bucket::Split ()
{
	int newStart, newEnd;
	if (Depth == Dir.Depth)// no room to split this bucket
		Dir.DoubleSize();
	Bucket * newBucket = new Bucket (Dir, MaxKeys);
	Dir.StoreBucket (newBucket);
	NewRange (newStart, newEnd);
	Dir.InsertBucket(newBucket->BucketAddr, newStart, newEnd);
	Depth ++;
	newBucket->Depth = Depth;
	Redistribute (*newBucket);
	Dir.StoreBucket (this);
	Dir.StoreBucket (newBucket);
	return newBucket;
}

int Bucket::FindBuddy ()
{// find the directory address of the bucket that is paired with this
	if (Dir.Depth == 0) return -1; // no buddy, empty directory
	// unless bucket depth == directory depth, there is no single
	// bucket to pair with
	if (Depth < Dir.Depth) return -1;
	int sharedAddress = MakeAddress(Keys[0], Depth); // address of any key
	return sharedAddress ^ 1; // exclusive or with low bit
}

int Bucket::TryCombine ()
{// called after insert to combine buddies, if possible
	int result;
	int buddyIndex = FindBuddy ();
	if (buddyIndex == -1) return 0;// no combination possible
	// load buddy bucket into memory
	int buddyAddr = Dir.BucketAddr[buddyIndex];
	Bucket * buddyBucket = new Bucket (Dir, MaxKeys);
	Dir . LoadBucket (buddyBucket, buddyAddr);
	// if the sum of the sizes of the buckets is too big, return
	if (NumKeys + buddyBucket->NumKeys > MaxKeys) return 0;
	Combine (buddyBucket, buddyIndex);// collapse the 2 buckets
	result = Dir.Collapse ();
	if (result) TryCombine(); //if collapse, may be able to combine
	return 1;
}

int Bucket::Combine (Bucket * buddy, int buddyIndex)
{// collapse this and buddy into a single bucket
	int result;
	// move keys from buddy to this
	for (int i = 0; i < buddy->NumKeys; i++)
	{// insert the key of the buddy into this
		result = Insert (buddy->Keys[i],buddy->RecAddrs[i]);
		if (!result) return 0;
	}
	Depth --;// reduce the depth of the bucket
	Dir . RemoveBucket (buddyIndex, Depth);
	return 1;
}

int Bucket::NewRange (int & newStart, int & newEnd)
{// make a range for the new split bucket
	int sharedAddr = MakeAddress(Keys[0], Depth);
	int bitsToFill = Dir.Depth - (Depth + 1);
	newStart = (sharedAddr << 1) | 1;
	newEnd = newStart;
	for (int j = 0; j < bitsToFill; j++)
	{
		newStart = newStart << 1;
		newEnd = (newEnd << 1) | 1;
	}
	return 1;
}

int Bucket::Redistribute (Bucket & newBucket)
{
	// check each key in this bucket
	for (int i = NumKeys - 1; i >= 0; i--)
	{
		int bucketAddr = Dir.Find (Keys[i]); // look up the bucket
		if (bucketAddr != BucketAddr)// key belongs in the new bucket
		{
			newBucket.TextIndex::Insert (Keys[i], RecAddrs[i]);
			TextIndex::Remove (Keys[i]); // delete key from this bucket
		}
	}
	return 1;
}

void Bucket::Print()
{/*
	outtextxy(100,350,"Bucket Depth : ");
	int x=100;
	int y=350+textwidth("Buckeyt Depth : ");
	gprintf(&x,&y,"%d",Depth);
// 	TextIndex::Print (cout);*/

}
int Bucket::retMaxKeys()
{
return(TextIndex::getMaxKeys());
}

int Bucket::retNumKeys()
{
return(TextIndex::getNumKeys());
}

char* Bucket::retKey(int i)
{
return(TextIndex::getKeys(i));
}

int Bucket::retRecAddr(int i)
{
return(TextIndex::getRecAddr(i));
}

BucketBuffer::BucketBuffer (int keySize, int maxKeys)
: TextIndexBuffer(keySize,maxKeys,1,sizeof(int))
{
	AddField (sizeof(int));
}

int BucketBuffer::Pack (const Bucket & bucket)
{
	int result;
	TextIndexBuffer::Pack(bucket);
	if (result == -1) return -1;
	return FixedFieldBuffer::Pack (&bucket.Depth);
}

int BucketBuffer::Unpack (Bucket & bucket)
{
	int result;
	result = TextIndexBuffer::Unpack(bucket);
	if (result == -1) return -1;
	return FixedFieldBuffer::Unpack (&bucket.Depth);
}