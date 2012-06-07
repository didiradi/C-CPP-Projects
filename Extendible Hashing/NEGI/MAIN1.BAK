
// MAIN PROGRAM


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

#include "C:\NEGI\student.cpp"
#include "C:\NEGI\validate.cpp"
#include "C:\NEGI\screens.cpp"
#include "C:\NEGI\copy.cpp"
#include "C:\NEGI\mani\screen.h"
#include "C:\NEGI\mani\mouse.h"

void DisplayInfo(Student &st);

int count=0;
int allcount=0;
int size=0;
int usable=0;
int tcount=0;

int cur=1,c;
char *gregno;
Directory Dir (3);

void deleterecord (char *myfile,char *m);

void  append(char *myfile)
{

clearScr();
	Student s;

       inp:

	setcolor(CYAN);
	outtextxy(50,55,"INPUT THE DETAILS");
	setcolor(8);
	rectangle(100,70,550,300);
	rectangle(101,71,549,299);
	printfields();

	yourInput();
	DisplayInfo(s);

	DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");
	input(32,6,s.URN,"alphanumeric","","10",1);

	yourInput();
	DisplayInfo(s);
	int res = Dir.Search(s.URN);
	if(res!=-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("DUPLICATE","This USN already exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		printfields();
		goto inp;
		}
		else
		{
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		return;
		}

	}
	else
	{
		DrawStatusBar("FNAME","Enter the valid NAME; Format: XXXX; Invalid : Digits,Punc,Space");
		input(32,8,s.Fname,"alphabetic");

		yourInput();
		DisplayInfo(s);
		DrawStatusBar("LNAME","Enter the valid NAME; Format: XXXX; Invalid : Digits,Punc,Space");
		input(32,10,s.Lname,"alphabetic");

		yourInput();
		DisplayInfo(s);
		DrawStatusBar("ADDRESS","Enter the valid ADDRESS; Format: XX 11 XX");
		input(32,12,s.Address,"alphanumeric");
		yourInput();
		DisplayInfo(s);
		DrawStatusBar("SEM","Enter the valid SEM;Range : 1 - 8; Invalid: Anything out of range.");
		input(32,14,s.Semester,"digit","8","",0);
		yourInput();
		DisplayInfo(s);

		DrawStatusBar("BRANCH","Enter the valid BRANCH; Format: XXX; Invalid : Digits,Punc,Space");
		input(32,16,s.Branch,"alphabetic","","3",0);
		yourInput();
		DisplayInfo(s);

		DrawStatusBar("COLLEGE","Enter the valid COLLEGE; Format: XXXX; Invalid : Digits,Punc");
		input(32,18,s.College,"alphabetic");
		yourInput();
		DisplayInfo(s);

		int recaddr=s.Append(myfile);
		Dir.Insert(s.URN,recaddr);
		DrawStatusBar("SAVED","RECORD SAVED SUCCESSFULLY");
		getche();
		clearScr();
	 }
  }



void modify(char * myfile)
{
clearScr();
	Student s;
	Student g;
	inp:

	setcolor(CYAN);
	outtextxy(100,55,"ENTER THE REGNO OF THE RECORD TO BE MODIFIED");

	DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");
	input(32,6,s.URN,"alphanumeric","","10",1);
	clearScr();
	int addr=Dir.Search(s.URN);
	if(addr==-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("ERROR","This USN does not exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		goto inp;
		}
		else
		{
		clearScr();
		return;
		}
	}
		DelimFieldBuffer :: SetDefaultDelim('|');
		DelimFieldBuffer Buff;
		ifstream file(myfile,ios::in);
		Buff.DRead(file,addr);
		s.Unpack(Buff);

		setcolor(8);
		rectangle(100,70,400,300);
		rectangle(101,71,399,299);

		printfields();
		printvalues(s);

		setcolor(7);
		rectangle(410,70,550,300);
		rectangle(411,71,549,299);

		outtextxy(415,80,"1 : FNAME");
		outtextxy(415,110,"2 : LNAME");
		outtextxy(415,140,"3 : ADDRESS");
		outtextxy(415,170,"4 : SEMESTER");
		outtextxy(415,200,"5 : BRANCH");
		outtextxy(415,230,"6 : COLLEGE");
		outtextxy(415,260,"7 : EXIT");
		outtextxy(415,285,"OPTIONS");
		rectangle(411,280,549,300);

		yourInput();
		DisplayInfo(s);


		print(20,20,"ENTER THE FIELD NUMBER TO BE MODIFIED :");
		DrawStatusBar("CHOICE","ENTER THE FIELD TO BE MODIFIED");

		char *choice;
		g=copy(g,s);
		int modify=0;
		c=1;
		while(c !=7 )
		{
		   input(60,20,choice,"digit","7","",0);
		   c=atoi(choice);
		   char oldurn[11];
		   strcpy(oldurn,s.URN);
		   switch(c)
		   {
			case 7: clearScr();
				break;

			case 1:
				  DrawStatusBar("NAME","Enter the valid NAME; Format: XXXX; Invalid : Digits,Punc,Space");
				  input(32,8,g.Fname,"alphabetic");
				  yourInput();
				DisplayInfo(s);


				  break;
			case 2:
				  DrawStatusBar("NAME","Enter the valid NAME; Format: XXXX; Invalid : Digits,Punc,Space");
				  input(32,10,g.Lname,"alphabetic");
		yourInput();
		DisplayInfo(s);

				  break;
			case 3:
				  DrawStatusBar("ADDRESS","Enter the valid ADDRESS; Format: XX 11 XX");
				  input(32,12,g.Address,"alphanumeric");
						yourInput();
						DisplayInfo(s);

				  break;
			case 4:
				  DrawStatusBar("SEM","Enter the valid SEM;Range : 1 - 8; Invalid: Anything out of range.");
				  input(32,14,g.Semester,"digit","8","",0);
						yourInput();
						DisplayInfo(s);

				  break;
			case 5:
				  DrawStatusBar("BRANCH","Enter the valid BRANCH; Format: XXX; Invalid : Digits,Punc,Space");
				  input(32,16,g.Branch,"alphabetic","","3",0);
						yourInput();
						DisplayInfo(s);

				  break;
			case 6:
				  DrawStatusBar("COLLEGE","Enter the valid COLLEGE; Format: XXXX; Invalid : Digits,Punc");
				  input(32,18,g.College,"alphabetic");
					yourInput();
					DisplayInfo(s);

				  break;
		   }

		   if(c != 7)
			   modify=1;
		}

	  if(modify)
	  {
		c=0;
		deleterecord(myfile,s.URN);
		int newaddr=g.Append(myfile);
		Dir.Insert(g.URN,newaddr);
	  }
}

int display(char *myfile,char *m)
{

clearScr();
	Student s;
	inp:
	clearScr();
	if(c==10)
	{
		setcolor(CYAN);
		outtextxy(100,55,"ENTER THE REGNO OF THE RECORD TO BE DELETED:");
		DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");
	}
	else
	{
		setcolor(CYAN);
		outtextxy(100,55,"ENTER THE REGNO OF THE RECORD TO BE DISPLAYED:");
		DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");
	}
	input(60,4,m,"alphanumeric","","10",1);
	clearScr();

	strcpy(s.URN,m);
	int addr=Dir.Search(s.URN);
	if(addr==-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("ERROR","This USN does not exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		goto inp;
		}
		else
		{
		clearScr();
		return 0;
		}
	}
	else
	{
		DelimFieldBuffer :: SetDefaultDelim('|');
		DelimFieldBuffer Buff;
		fstream file(myfile,ios::in);
		Buff.DRead(file,addr);
		s.Unpack(Buff);

		setcolor(CYAN);
		outtextxy(50,55,"RECORD DETAILS");
		setcolor(8);
		rectangle(100,70,550,300);
		rectangle(101,71,549,299);
		printfields();
		yourInput();
		DisplayInfo(s);
		printvalues(s);
		file.close();
		DrawStatusBar("HELP","PRESS ANY KEY TO EXIT");
		return 1;
		//getche();
		//clearScr();

}
}


void SaveAs(char * myfile,char *m)
{
clearScr();
Student s;

	inp:
	setcolor(CYAN);
	outtextxy(100,55,"ENTER THE REGNO OF THE RECORD TO BE DISPLAYED:");
	DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");

	input(60,4,m,"alphanumeric","","10",1);
	clearScr();

	strcpy(s.URN,m);
	int addr=Dir.Search(s.URN);
	if(addr==-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("ERROR","This USN does not exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		goto inp;
		}
		else
		{
		clearScr();
		return;
		}
	}
	else
	{
		DelimFieldBuffer :: SetDefaultDelim('|');
		DelimFieldBuffer Buff;
		fstream file(myfile,ios::in);
		Buff.DRead(file,addr);
		s.Unpack(Buff);

		setcolor(CYAN);
		outtextxy(50,55,"RECORD DETAILS");
		setcolor(8);
		rectangle(100,70,550,300);
		rectangle(101,71,549,299);
		printfields();
		yourInput();
		DisplayInfo(s);
		printvalues(s);
	}
	DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
	getche();

	i1:

	strcpy(s.URN,"          ");
	yourInput();
	DisplayInfo(s);
	DisplayInfo(s);
	printvalues(s);



	DrawStatusBar("USN","Enter the valid USN; Format: 1XX11XX111; Invalid : Punctuations ");
	input(32,6,m,"alphanumeric","","10",1);

	yourInput();
	DisplayInfo(s);
	int res = Dir.Search(m);
	if(res!=-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("DUPLICATE","This USN already exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		printfields();
		goto i1;
		}
		else
		{
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		return;
		}

	}

	else
	{

	strcpy(s.URN,m);

	int recaddr=s.Append(myfile);
	Dir.Insert(s.URN,recaddr);
	DrawStatusBar("SAVED","RECORD SAVED SUCCESSFULLY");
	yourInput();
	DisplayInfo(s);
	DisplayInfo(s);
	printvalues(s);
	getche();
	clearScr();
	 }
  }



void deleterecord (char *myfile,char *m)
{
clearScr();
	Student s;

	strcpy(s.URN,m);
	int addr=Dir.Search(s.URN);
	if(addr==-1)
	{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("ERROR","This USN does not exists !","Continue with new USN ?");
		if(i==1)
		{
		clearScr();
		return;
		}
		else
		{
		clearScr();
		return;
		}
	}
	fstream ofile(myfile,ios::in|ios::out);
	ofile.seekp(addr,ios::beg);
	ofile.write("*",1);
	ofile.close();
	Dir.Remove(s.URN);
		if(c)
		{//if(c==10)
		setcolor(RED);
		clearScr();
		DrawStatusBar("DELETED","Record deleted successfully !  Press any key to continue");
		}

		else
		{
		clearScr();
		DrawStatusBar("MODIFIED","Record modified successfully !  Press any key to continue");
		return;
		}
}
void loaddir(char *myfile)
{
	  Student s;
	  fstream ifile(myfile,ios::in);
	  DelimFieldBuffer :: SetDefaultDelim('|');
	  DelimFieldBuffer Buff;
	  int recaddr;
	  while(1)
	  {
	      if((recaddr=Buff.Read(ifile))==-1)break;
	      if( Buff.getfirstchar() == '*') continue;
		s.Unpack(Buff);
		Dir.Insert(s.URN,recaddr);
	  }
	ifile.close();
}

void updatefile(char *myfile)
{
   fstream ifile(myfile,ios::in);
   fstream ofile("data.bak",ios::out);
   char ch;
   while(1){
       ifile >> ch;
       if(ifile.fail()) break;
       ofile << ch;
  }
  ifile.close();
  ofile.close();
  ifile.open("data.bak",ios::in);
  ofile.open(myfile,ios::out);
  DelimFieldBuffer :: SetDefaultDelim('|');
  DelimFieldBuffer Buff;
  while(1){
      if(Buff.Read(ifile)==-1)break;
       if(Buff.getfirstchar()=='*')continue;
       else
	Buff.Write(ofile);
     }
    ifile.close();
    ofile.close();
}

void displayall(char *myfile,int ch)
{
   size=0;
   usable=0;
   count=0;
   allcount=0;
   int i=0;
   int j=1;
   DelimFieldBuffer :: SetDefaultDelim('|');
   DelimFieldBuffer Buff;
   fstream file(myfile,ios::in);
   Student s;

   while(1)
   {
	if(Buff.Read(file)==-1)
	{
	file.close();
	goto exit;// return;
	}
	  allcount++;
	  size=size+150;
	  if( Buff.getfirstchar() == '*') continue;
	  s.Unpack(Buff);
	  count++;
	  usable=usable+strlen(s.URN);
	  usable=usable+strlen(s.Fname);
	  usable=usable+strlen(s.Lname);
	  usable=usable+strlen(s.Address);
	  usable=usable+strlen(s.Semester);
	  usable=usable+strlen(s.Branch);
	  usable=usable+strlen(s.College);

	  if(ch==1)
	  {
	 disp:   if(i<20)

	    {
		i++;
		setcolor(8);
		setlinestyle(0,0,2);
		rectangle(3,46,getmaxx()-3,430);
		line(3,90,getmaxx()-3,90);
		line(90,46,90,430);
		line(170,46,170,430);
		line(250,46,250,430);
		line(473,46,473,430);
		line(508,46,508,430);
		line(561,46,561,430);
		printcolumnheaders();
		setcolor(3);
		printstudentrecord(s,i+6);
		setfillstyle(0,RED);
		bar(3,431,getmaxx()-3,451);
		setfillstyle(0,LIGHTCYAN);
		bar(4,432,getmaxx()-4,450);
		int x1=15;
		int y1=440;
		setcolor(RED);
		outtextxy(x1,y1,"CURRENTLY DISPLAYING RECORDS ( ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS ( ");
		y1=440;
		gprintf(&x1,&y1,"%d",j);
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ");
		y1=440;
		outtextxy(x1,y1," TO      ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO      ");
		y1=440;
		gprintf(&x1,&y1,"%d",count);

		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO          ");
		y1=440;
		outtextxy(x1,y1,") FROM A TOTAL NUMBER OF ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO          ")+textwidth(") FROM A TOTAL NUMBER OF ");
		y1=440;
		gprintf(&x1,&y1,"%d",tcount);


	    }
	    else
	    {
		i=0;
		DrawStatusBar("HELP","DATA FILE C:\\NEGI\\DATA.TXT STILL HAS DATA ! PRESS ANY KEY");
		setfillstyle(0,RED);
		bar(3,431,getmaxx()-3,451);
		setfillstyle(0,LIGHTCYAN);
		bar(4,432,getmaxx()-4,450);
		int x1=15;
		int y1=440;
		setcolor(RED);
		outtextxy(x1,y1,"CURRENTLY DISPLAYING RECORDS ( ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS ( ");
		y1=440;
		gprintf(&x1,&y1,"%d",j);
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ");
		y1=440;
		outtextxy(x1,y1," TO      ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO      ");
		y1=440;
		gprintf(&x1,&y1,"%d",count-1);

		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO          ");
		y1=440;
		outtextxy(x1,y1,") FROM A TOTAL NUMBER OF ");
		x1=15+textwidth("CURRENTLY DISPLAYING RECORDS (     ")+textwidth(" TO          ")+textwidth(") FROM A TOTAL NUMBER OF ");
		y1=440;
		gprintf(&x1,&y1,"%d",tcount);


		j+=20;
		getche();
		clearScr();
		goto disp;
	    }
      }
	  else
	  continue;
     }
exit:
if(ch==1 && count==0)
{
	clearScr();
	rectangle(100,100,getmaxx()-100,getmaxy()-100);
	outtextxy(160,getmaxy()/2,"DATA FILE C:\\NEGI\\DATA.TXT IS EMPTY");
	DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
	getche();
	clearScr();
}

if(ch==1)
{
DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
getche();
clearScr();
}
return;
}


int main()
{

clrscr();

int flag=0;
int i;
int result;
int button,x,y;
int    GraphDriver;		/* The Graphics device driver		*/
int    GraphMode;		/* The Graphics mode value		*/
double AspectRatio;		/* Aspect ratio of a pixel on the screen*/
int    MaxX, MaxY;		/* The maximum resolution of the screen */
int    MaxColors;		/* The maximum # of colors available	*/
int    ErrorCode;		/* Reports any graphics errors		*/

//ShowStart();

   int gd=DETECT,gm;
   initgraph(&gd,&gm,"C:\\tc");

   remove("hash.dir");
   remove("hash.bkt");
   result = Dir . Create ("hash");
   char  *myfile="C:\\NEGI\\DATA.TXT",*m,ch;




	setviewport(0,0,getmaxx(),getmaxy(),1);
	if (initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		printf("\nMouse Driver not installed");
		exit(1);
	}
	cleardevice();
	showmouseptr();
	screen scrn(0,0,getmaxx(),getmaxy());
	PutTitle("FS PROJECT - EXTENDIBLE HASHING");
	DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");


   loaddir(myfile);
   if (result == 0)
     {
	DrawStatusBar("ERROR","Directory and Bucket couldn't be created");
	getch();
	return 0;
     }
again:
scrn.DrawAll();
DrawMenus(5,0);
PutTitle("FS PROJECT - EXTENDIBLE HASHING");

while(!kbhit())
{
	showmouseptr();

	getmousepos(&button,&x,&y);
	//click file menu
	if(((button&1)==1) && (x>2 && x<42 && y>24 && y<44))
	{
	selected=1;
	Edit(0);
	Search(0);
	Util(0);
	About(0);
	Help(0);
	File(1);
	}
	//click new record
	else if(((button&1)==1) && (x>3 && x<100 && y>46 && y<66) && selected==1)
	{
	newrecord:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("ADDING NEW RECORD");
			selected=7;
			File(0);
			DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
			append(myfile);
			DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
			goto again;

	}

	//click SaveAs
	else if(((button&1)==1) && (x>3 && x<100 && y>67 && y<87) && selected==2)
	{
	saveas:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("SAVING RECORD AS");
			selected=19;
			File(0);
		SaveAs(myfile,m);
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;
	}


	//click exit
	else if( ( (button&1)==1) && (((x>3 && x<100 && y>88 && y<107) && selected==1) || (x>619 && x<632 && y>6 && y<20)) )
	{
	 exit:
		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("QUITING APPLICATION");
		File(0);
		Edit(0);
		Search(0);
		Util(0);
		Help(0);
		clearScr();
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i=msgbox("CONFIRM","QUITING APPLICATION !","Are U Sure to exit ?");
		if(i==1)
		{
		cleardevice();
		closegraph();
		exit(0);
		}
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		clearScr();
		goto again;

	}

	//CLICK EDIT BUTTON
	else if(((button&1)==1) && (x>51 && x<90 && y>24 && y<44))
	{
	selected=2;
	File(0);
	Search(0);
	Util(0);
	About(0);
	Help(0);
	Edit(1);
	}
//click modify record
	else if(((button&1)==1) && (x>50 && x<170 && y>46 && y<66) && selected==2)
	{
	modrecord:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("MODIFYING A RECORD");
			selected=8;
			Edit(0);
			clearScr();
			modify(myfile);flag=1;
			DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
			goto again;



	}

	//click DELETE
	else if(((button&1)==1) && (x>50 && x<170 && y>67 && y<87) && selected==2)
	{
	delrecord:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("DELETING RECORD");
			selected=8;
			Edit(0);
	c=10;
		int p=display(myfile,m);
		if(p==1)
		{
		DrawStatusBar("HELP","PRESS ANY KEY TO ENABLE DELETE OPTION");
		getche();
		//if(strcmp(m,NULL))
		//{
		DrawStatusBar("HELP","PRESS <ENTER> OR (O/o) TO CONFIRM, <ESC> OR (C/c) TO CANCEL,CLICK");
		int i= msgbox("DELETE CONFIRMATION","Deleting the current record","Are you sure to delete ?");
		if(i==1)
		{
		deleterecord(myfile,m);flag=1;
		}
	       //	}
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;
		}

}

	//CLICK SEARCH
	else if(((button&1)==1) && (x>95 && x<151 && y>24 && y<44))
	{
	selected=3;
	File(0);
	About(0);
	Edit(0);
	Util(0);
	Search(1);
	}

//click display record
	else if(((button&1)==1) && (x>95 && x<200 && y>46 && y<66) && selected==3)
	{
	disrecord:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("DISPLAYING RECORD");
			selected=9;
			Search(0);
			clearScr();
			display(myfile,m);
			DrawStatusBar("HELP","PRESS ANY KEY");
			getche();
			clearScr();
			DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
			goto again;



	}

//click display all record
	else if(((button&1)==1) && (x>95 && x<200 && y>66 && y<86) && selected==3)
	{
	disallrecord:
			scrn.DrawAll();
			DrawMenus(5,0);
			PutTitle("DISPLAYING ALL RECORDS");
			selected=10;
			Search(0);
			clearScr();
			displayall(myfile,0);
			tcount=count;
			displayall(myfile,1);
			DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
			goto again;



	}

	//CLICK UTIL
	else if(((button&1)==1) && (x>160 && x<260 && y>24 && y<44))
	{
	selected=4;
	File(0);
	Edit(0);
	Search(0);
	About(0);
	Help(0);
	Util(1);
	}
//click om hashing
	else if(((button&1)==1) && (x>160 && x<290 && y>46 && y<66) && selected==4)
	{

	sho:

		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("DIRECTORY & BUCKET DISPLAY");
		selected=11;
		Util(0);

		Dir.Print();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;


	}
	else if(((button&1)==1) && (x>160 && x<290 && y>86 && y<106) && selected==4)
	{

	  uti:
		displayall(myfile,0);
		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("BUCKETS & DIRECTORY SPACE UTILIZATION");
		selected=13;
		Util(0);
		setcolor(RED);
		 clearScr();
		 setcolor(YELLOW);
		 line(getmaxx()/2,50,getmaxx()/2,getmaxy()-30);
		 setcolor(6);
		 settextstyle(1,0,2);
		 outtextxy(20,60,"BUCKET SPACE UTILIZATION");
		 outtextxy(getmaxx()/2+10,60,"DIRECTORY SPACE UTILIZATION");
		 settextstyle(0,0,0);
		 setcolor(LIGHTGRAY);
		 //get no of buckets
		 int p=Dir.Space_util(myfile);
		 //get directory depth
		 int dep=Dir.getdepth();
		 //get total directory space
		 int totalcells=pow(2,dep);
		 int max=Dir.getMaxBucketSize();


		 float space=(float)count*100/((float)p*(float)max);
		 float disk=0;
		 if(p>0)
		 {
		 disk=((float)(100/float(totalcells))*p);
		 }

		 int x=50;
		 int y=110;
		 outtextxy(50,y,"RECORDS PER BUCKET  : ");
		 x=50+textwidth("RECORDS PER BUCKET  : ");
		 y=110;

		 gprintf(&x,&y,"%d",max);
		 x=50+getmaxx()/2;
		 y=110;
		 outtextxy(50+getmaxx()/2,y,"DIRECTORY DEPTH       : ");
		 x=50+getmaxx()/2+textwidth("DIRECTORY DEPTH       : ");
		 y=110;
		 gprintf(&x,&y,"%d",dep);

		 y=130;
		 outtextxy(50,y,"TOTAL NO OF BUCKETS : ");
		 outtextxy(getmaxx()/2+50,y,"TOTAL DIRECTORY SPACE : ");
		 x=50+textwidth("TOTAL NO OF BUCKETS : ");
		 y=130;
		 gprintf(&x,&y,"%d",p);
		 x=getmaxx()/2+50+textwidth("TOTAL DIRECTORY SPACE : ");
		 y=130;
		 gprintf(&x,&y,"%d",totalcells);

		outtextxy(50,150,"TOTAL NO OF RECORDS : ");
		outtextxy(getmaxx()/2+50,150,"TOTAL NO OF BUCKETS   : ");
		x=50+textwidth("TOTAL NO OF RECORDS : ");
		y=150;
		gprintf(&x,&y,"%d",count);
		x=getmaxx()/2+50+textwidth("TOTAL NO OF BUCKETS   : ");
		y=150;
		gprintf(&x,&y,"%d",p);

		outtextxy(50,170,"BUCKET UTILIZATION  : ");
		outtextxy(50+getmaxx()/2,170,"DIRECTORY UTILIZATION : ");
		x=50+textwidth("BUCKET UTILIZATION  : ");
		y=170;
		gprintf(&x,&y,"%f",space);
		x=getmaxx()/2+50+textwidth("DIRECTORY UTILIZATION : ");
		y=170;
		gprintf(&x,&y,"%f",(float)disk);

		setcolor(CYAN);
		line(100,190,100,400);
		line(90,400,300,400);
		line(getmaxx()/2+100,190,getmaxx()/2+100,400);
		line(getmaxx()/2+90,400,getmaxx()/2+300,400);

		for(int i=200;i<=400;i+=20)
		{
		line(95,i,90+15,i);
		line(getmaxx()/2+95,i,90+15+getmaxx()/2,i);

		}
		int ypos=198;
		int xpos=50;
		int per=70;
		int x2pos=getmaxx()/2+50;
		setcolor(RED);
		for(int j=10;j>=0;j--)
		{
		gprintf(&xpos,&ypos,"%d",(j*10));
		outtextxy(per,ypos-10," % ");
		ypos+=10;
		}
		int per2=x2pos+20;
		ypos=198;
		for(j=10;j>=0;j--)
		{
		gprintf(&x2pos,&ypos,"%d",(j*10));
		outtextxy(per2,ypos-10," % ");
		ypos+=10;
		}

		setfillstyle(SOLID_FILL,CYAN);
		bar(120,200,155,400);
		bar(getmaxx()/2+120,200,getmaxx()/2+155,400);
		setcolor(BLUE);
		outtextxy(122,300,"100");
		outtextxy(148,300,"%");
		outtextxy(122+getmaxx()/2,300,"100");
		outtextxy(148+getmaxx()/2,300,"%");
		setcolor(8);
		outtextxy(122,410,"TOTAL");
		outtextxy(122+getmaxx()/2,410,"TOTAL");

		bar(180,400,215,400-(2*(int)space));
		bar(180+getmaxx()/2,400,215+getmaxx()/2,400-(2*(int)disk));

		setcolor(BLUE);
		int px=182;
		int q=(400+400-(2*(int)space))/2;
		gprintf(&px,&q,"%d",(int)space);
		q=(400+400-(2*(int)space))/2;
		outtextxy(208,q,"%");
		setcolor(8);
		outtextxy(182,410,"USED");

		setcolor(BLUE);
		px=182+getmaxx()/2;
		q=(400+400-(2*(int)disk))/2;
		gprintf(&px,&q,"%d",(int)disk);
		q=(400+400-(2*(int)disk))/2;
		outtextxy(208+getmaxx()/2,q,"%");
		setcolor(8);
		outtextxy(182+getmaxx()/2,410,"USED");


		bar(240,400,275,400-((100-(int)space))*2);
		setcolor(BLUE);
		px=242;
		q=(400+(400-((100-(int)space))*2))/2;
		gprintf(&px,&q,"%d",100-(int)space);
		q=(400+(400-((100-(int)space))*2))/2;
		outtextxy(268,q,"%");
		setcolor(8);
		outtextxy(242,410,"UNUSED");

		bar(240+getmaxx()/2,400,275+getmaxx()/2,400-((100-(int)disk))*2);
		setcolor(BLUE);
		px=242+getmaxx()/2;
		q=(400+(400-((100-(int)disk))*2))/2;
		gprintf(&px,&q,"%d",100-(int)disk);
		q=(400+(400-((100-(int)disk))*2))/2;
		outtextxy(268+getmaxx()/2,q,"%");
		setcolor(8);
		outtextxy(242+getmaxx()/2,410,"UNUSED");

		setcolor(12);
		outtextxy(50,430,"BUCKET SPACE UTILIZATION");
		setcolor(12);
		outtextxy(50+getmaxx()/2,430,"DIRECTORY SPACE UTILIZATION");

		DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
	 goto again;

	}

//click om space
	else if(((button&1)==1) && (x>160 && x<260 && y>66 && y<88) && selected==4)
	{
	spac:
		displayall(myfile,0);
		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("DISK SPACE UTILIZATION");
		 selected=12;
		 Util(0);
		 clearScr();
		 setcolor(RED);
		 clearScr();
		 setcolor(YELLOW);
		 line(getmaxx()/2,50,getmaxx()/2,getmaxy()-30);
		 setcolor(6);
		 settextstyle(1,0,2);
		 outtextxy(40,60,"DISK SPACE UTILIZATION");
		 outtextxy(getmaxx()/2+40,60,"DISK SPACE UTILIZATION");
		 settextstyle(0,0,0);
		 setcolor(LIGHTGRAY);
		 int p=Dir.Space_util(myfile);
		 int num=Dir.getnumcells();


		 float dsize=0;
		 if(size>0)
		 {
		 dsize=((float)(100/float(size))*usable);
		 }
		 float disk=0;
		 if(allcount>0)
		 {
		 disk=((float)(100/float(allcount))*count);
		 }

		 int x=50;
		 int y=130;

		 outtextxy(50,y,"TOTAL DISK SPACE USED : ");
		 outtextxy(getmaxx()/2+50,y,"NO OF RECORDS     : ");
		 x=50+textwidth("TOTAL DISK SPACE USED : ");
		 y=130;
		 gprintf(&x,&y,"%d",size);
		 x=getmaxx()/2+50+textwidth("NO OF RECORDS     : ");
		 y=130;
		 gprintf(&x,&y,"%d",allcount);

		outtextxy(50,150,"DISK SPACE IN USE     : ");
		outtextxy(getmaxx()/2+50,150,"USABLE RECORDS    : ");
		x=50+textwidth("DISK SPACE IN USE     : ");
		y=150;
		gprintf(&x,&y,"%d",usable);
		x=getmaxx()/2+50+textwidth("USABLE RECORDS    : ");
		y=150;
		gprintf(&x,&y,"%d",count);

		outtextxy(50,170,"DISK UTILIZATION      : ");
		outtextxy(50+getmaxx()/2,170,"DISK UTILIZATION  : ");
		x=50+textwidth("DISK UTILIZATION      : ");
		y=170;
		gprintf(&x,&y,"%f",(float)dsize);
		x=getmaxx()/2+50+textwidth("DISK UTILIZATION  : ");
		y=170;
		gprintf(&x,&y,"%f",(float)disk);

		setcolor(CYAN);
		line(100,190,100,400);
		line(90,400,300,400);
		line(getmaxx()/2+100,190,getmaxx()/2+100,400);
		line(getmaxx()/2+90,400,getmaxx()/2+300,400);

		for(int i=200;i<=400;i+=20)
		{
		line(95,i,90+15,i);
		line(getmaxx()/2+95,i,90+15+getmaxx()/2,i);

		}
		int ypos=198;
		int xpos=50;
		int per=70;
		int x2pos=getmaxx()/2+50;
		setcolor(RED);
		for(int j=10;j>=0;j--)
		{
		gprintf(&xpos,&ypos,"%d",(j*10));
		outtextxy(per,ypos-10," % ");
		ypos+=10;
		}
		int per2=x2pos+20;
		ypos=198;
		for(j=10;j>=0;j--)
		{
		gprintf(&x2pos,&ypos,"%d",(j*10));
		outtextxy(per2,ypos-10," % ");
		ypos+=10;
		}

		setfillstyle(SOLID_FILL,CYAN);
		bar(120,200,155,400);
		bar(getmaxx()/2+120,200,getmaxx()/2+155,400);
		setcolor(BLUE);
		outtextxy(122,300,"100");
		outtextxy(148,300,"%");
		outtextxy(122+getmaxx()/2,300,"100");
		outtextxy(148+getmaxx()/2,300,"%");
		setcolor(8);
		outtextxy(122,410,"TOTAL");
		outtextxy(122+getmaxx()/2,410,"TOTAL");

		bar(180,400,215,400-(2*(int)dsize));
		bar(180+getmaxx()/2,400,215+getmaxx()/2,400-(2*(int)disk));

		setcolor(BLUE);
		int px=182;
		int q=(400+400-(2*(int)dsize))/2;
		gprintf(&px,&q,"%d",(int)dsize);
		q=(400+400-(2*(int)dsize))/2;
		outtextxy(208,q,"%");
		setcolor(8);
		outtextxy(182,410,"USED");

		setcolor(BLUE);
		px=182+getmaxx()/2;
		q=(400+400-(2*(int)disk))/2;
		gprintf(&px,&q,"%d",(int)disk);
		q=(400+400-(2*(int)disk))/2;
		outtextxy(208+getmaxx()/2,q,"%");
		setcolor(8);
		outtextxy(182+getmaxx()/2,410,"USED");


		bar(240,400,275,400-((100-(int)dsize))*2);
		setcolor(BLUE);
		px=242;
		q=(400+(400-((100-(int)dsize))*2))/2;
		gprintf(&px,&q,"%d",100-(int)dsize);
		q=(400+(400-((100-(int)dsize))*2))/2;
		outtextxy(268,q,"%");
		setcolor(8);
		outtextxy(242,410,"WASTED");

		bar(240+getmaxx()/2,400,275+getmaxx()/2,400-((100-(int)disk))*2);
		setcolor(BLUE);
		px=242+getmaxx()/2;
		q=(400+(400-((100-(int)disk))*2))/2;
		gprintf(&px,&q,"%d",100-(int)disk);
		q=(400+(400-((100-(int)disk))*2))/2;
		outtextxy(268+getmaxx()/2,q,"%");
		setcolor(8);
		outtextxy(242+getmaxx()/2,410,"WASTED");

		setcolor(12);
		outtextxy(25,430,"USEFULL DATA BITS V/S OTHER BITS");
		setcolor(12);
		outtextxy(25+getmaxx()/2,430,"USEFULL RECORDS V/S DELETED RECORDS");


		DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;

	}

	//CLICK ABOUT
	else if(((button&1)==1) && (x>260 && x<315 && y>24 && y<44))
	{
	selected=5;
	File(0);
	Edit(0);
	Search(0);
	Util(0);
	Help(0);
	About(1);

	}
	else if(((button&1)==1) && (x>260 && x<395 && y>66 && y<88) && selected==5)
	{
	ab:
		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("DISPLAYING ABOUT US");
		selected=13;
		About(0);
		clearScr();


		int i;
//		char pattern[8] = {0x00, 0x70, 0x20, 0x27, 0x25, 0x27, 0x04, 0x04};

		setfillpattern(&pattern[1][8],RED);
		bar(4,46,getmaxx()-4,449);

		setfillstyle(SOLID_FILL,RED);

		bar(80,80,getmaxx()-80,getmaxy()-80);
		for(i=80;i<=90;i++)
		{
		delay(80);
		rectangle(i,i,getmaxx()-i,getmaxy()-i);
		}

		setfillpattern(&pattern[1][0],12);
		bar(91,150,getmaxx()-91,320);
		setfillstyle(1,12);
		bar(92+100,151+50,getmaxx()-92-100,319-50);

		setcolor(CYAN);
		settextstyle(8,0,0);

		outtextxy(200,100,"DEVELOPED BY");

		setcolor(14);

		settextstyle(0,0,0);
		outtextxy(200,(151+319)/2-15,"1RV03IS402  MANOHAR SINGH NEGI");
		outtextxy(200,(151+319)/2+10,"1RV02IS042  PRATOSH RAJKHOWA ");


		setcolor(12);
		settextstyle(0,0,0);
		outtextxy(150,350,"DEPARTMENT OF INFORMATION SCIENCE R.V.C.E.");
		outtextxy(150,370,"               2004 - 2005                ");
		DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;



	}

	else if(((button&1)==1) && (x>260 && x<395 && y>46 && y<66) && selected==5)
	{
	im:
		scrn.DrawAll();
		DrawMenus(5,0);
		PutTitle("DISPLAYING IMPLEMENTATION");
		selected=13;
		About(0);
		clearScr();
		imp();
		DrawStatusBar("HELP","PRESS ANY KEY TO CONTINUE");
		getche();
		clearScr();
		DrawStatusBar("HELP","PRESS ANY KEY [ F E S H or ESC ] OR CLICK ANY OPTION");
		goto again;



	}

	//CLICK HELP
	else if(((button&1)==1) && (x>315 && x<370 && y>24 && y<44))
	{
	selected=6;
	File(0);
	Edit(0);
	Search(0);
	Util(0);
	About(0);
	Help(1);

	}


	else if((button&1)==1 && selected==0)
	{
	clearScr();
	File(0);
	Edit(0);
	Search(0);
	Util(0);
	About(0);
	Help(0);
	}
	else if((button&2)==2)
	{
	showm(scrn);
	}

}

char d;
d=getch();
if(d==ESC && selected==0)
{
	goto exit;

}
else if(d==ESC && (selected==1||selected==2||selected==3||selected==4||selected==5))
{
File(0);
Util(0);
Edit(0);
Search(0);
About(0);
Help(0);
goto again;
}

else if((d=='F'||d=='f') && selected==0)
{

	//click file menu
	Edit(0);
	Search(0);
	Util(0);
	About(0);
	Help(0);
	File(1);
	goto again;
 }
else if((d=='n' || d=='N') && selected==1)
{
goto newrecord;
}
else if((d=='s' || d=='S') && selected==1)
{
		goto saveas;
}
else if((d=='X' || d=='x') && selected==1)
{
		goto exit;
}

else if((d=='E'||d=='e') && selected==0)
{

	//click edit menu
	Search(0);
	Util(0);
	File(0);
	About(0);
	Help(0);
	Edit(1);
	goto again;
 }
else if((d=='u' || d=='U') && selected==2)
{
		goto modrecord;
}

else if((d=='d' || d=='D') && selected==2)
{
		goto delrecord;
}

else if((d=='u' || d=='U') && selected==2)
{
//		goto undoDel;
}



else if((d=='S'||d=='s') && selected==0)
{

	//click search menu
	Util(0);
	File(0);
	Edit(0);
	About(0);
	Help(0);
	Search(1);
	goto again;
 }
else if((d=='F' || d=='f') && selected==3)
{
		goto disrecord;
}

else if((d=='D' || d=='d') && selected==3)
{
		goto disallrecord;
}

else if((d=='U'||d=='u') && selected==0)
{

	//click edit menu
	Search(0);
	File(0);
	Edit(0);
	About(0);
	Help(0);
	Util(1);
	goto again;
 }

 else if((d=='A'||d=='a') && selected==0)
{

	//click about menu
	Search(0);
	File(0);
	Edit(0);
	Util(0);
	Help(0);
	About(1);
	goto again;
 }

 else if((d=='H'||d=='h') && selected==0)
{

	//click about menu
	Search(0);
	File(0);
	Edit(0);
	Util(0);
	About(0);
	Help(1);
	goto again;
 }

else if((d=='U' || d=='u') && selected==4)
{
		goto uti;
}
else if((d=='D' || d=='d') && selected==4)
{
		goto spac;
}
else if((d=='V' || d=='v') && selected==4)
{
		goto sho;
}

else if((d=='A' || d=='a') && selected==5)
{
	goto ab;
}

else if((d=='I' || d=='i') && selected==5)
{
	goto im;
}

else
{
DrawStatusBar("INVALID","Press a valid key plz");
goto again;
}
}



void showm(screen &m)
{
int button,x,y;
settextstyle(0,0,0);
	 getmousepos(&button,&x,&y);
	 setcolor(0);
	 setfillstyle(1,7);
	 bar(440,m.my1,m.mx2,m.my2);
	 (button&1)==1?outtextxy(450,33,"DOWN"):outtextxy(450,33,"UP  ");
	 (button&2)==2?outtextxy(500,33,"DOWN"):outtextxy(500,33,"UP  ");
	 int xp,yp;
	 xp=550;yp=33;
	 gprintf(&xp,&yp,"X=%03d y=%03d",x,y);
}


void DisplayInfo(Student &st)
{
settextstyle(0,0,0);
setcolor(WHITE);

	int t1,t2;
			t1=55;t2=355;
			gprintf(&t1,&t2,"USN       %d",strlen(st.URN));
			t1=185;t2=355;
			gprintf(&t1,&t2,"%s",st.URN);
			t1=55,t2=365;
			gprintf(&t1,&t2,"FNAME     %d",strlen(st.Fname));
			t1=185;t2=365;
			gprintf(&t1,&t2,"%s",st.Fname);
			t1=55,t2=375;
			gprintf(&t1,&t2,"LNAME     %d",strlen(st.Lname));
			t1=185;t2=375;
			gprintf(&t1,&t2,"%s",st.Lname);
			t1=55,t2=385;
			gprintf(&t1,&t2,"ADDRESS   %d",strlen(st.Address));
			t1=185;t2=385;
			gprintf(&t1,&t2,"%s",st.Address);
			t1=55,t2=395;
			gprintf(&t1,&t2,"SEMESTER  %d",strlen(st.Semester));
			t1=185;t2=395;
			gprintf(&t1,&t2,"%s",st.Semester);
			t1=55,t2=405;
			gprintf(&t1,&t2,"BRANCH    %d",strlen(st.Branch));
			t1=185;t2=405;
			gprintf(&t1,&t2,"%s",st.Branch);
			t1=55,t2=415;
			gprintf(&t1,&t2,"COLLEGE   %d",strlen(st.College));
			t1=185;t2=415;
			gprintf(&t1,&t2,"%s",st.College);
}

