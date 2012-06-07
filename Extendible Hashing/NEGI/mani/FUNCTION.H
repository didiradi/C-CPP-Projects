#include "C:\NEGI\mani\header.h"


//global variables
int selected=0;
void *img;

//function definitions

int gprintf( int *xloc, int *yloc, char *fmt, ... )
{
  va_list  argptr;			/* Argument list pointer	*/
  char str[140];			/* Buffer to build sting into	*/
  int cnt;				/* Result of SPRINTF for return */

  va_start( argptr, fmt );		/* Initialize va_ functions	*/

  cnt = vsprintf( str, fmt, argptr );	/* prints string to buffer	*/
  outtextxy( *xloc, *yloc, str );	/* Send string in graphics mode */
  *yloc += textheight( "H" ) + 2;       /* Advance to next line         */

  va_end( argptr );			/* Close va_ functions		*/

  return( cnt );			/* Return the conversion count	*/

}

void DrawMenus(int xpos,int ypos)
{
//DRAW THE MEMU ITEMS
 settextstyle(0,0,1);

//FILE MENU
 setcolor(RED);
  //give start position as 10
 outtextxy(xpos,ypos+32,"F");
 setcolor(0);
 outtextxy(xpos+textwidth("F"),ypos+32,"ile");

//EDIT MENU
 setcolor(RED);
 outtextxy(xpos+textwidth("File  "),ypos+32,"E");
 setcolor(0);
 outtextxy(xpos+textwidth("File  ")+textwidth("E"),ypos+32,"dit");

//SEARCH MENU
 setcolor(RED);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  "),ypos+32,"S");
 setcolor(0);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("S"),ypos+32,"earch");

//UTIL MENU
 setcolor(RED);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  "),ypos+32,"U");
 setcolor(0);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  ")+textwidth("U"),ypos+32,"tilization");

 //ABOUT MENU
 setcolor(RED);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  ")+textwidth("Utilization  "),ypos+32,"A");
 setcolor(0);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  ")+textwidth("Utilization  ")+textwidth("A"),ypos+32,"bout");

  //HELP MENU
 setcolor(RED);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  ")+textwidth("Utilization  ")+textwidth("About  "),ypos+32,"H");
 setcolor(0);
 outtextxy(xpos+textwidth("File  ")+textwidth("Edit  ")+textwidth("Search  ")+textwidth("Utilization  ")+textwidth("About  ")+textwidth("H"),ypos+32,"elp");

}



void File(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=1;
setfillstyle(1,1);
bar(2,45,101,108);

setfillstyle(1,1);
bar(2,45,101,67);
setfillstyle(1,7);
bar(3,46,100,66);
setcolor(4);
outtextxy(5,56," N");
setcolor(0);
outtextxy(5+textwidth(" N"),56,"ew Record");

setfillstyle(1,1);
bar(2,66,100,88);
setfillstyle(1,7);
bar(3,67,100,87);
setcolor(4);
outtextxy(5,77," S");
setcolor(0);
outtextxy(5+textwidth(" S"),77,"ave As");

setfillstyle(1,1);
bar(2,88,100,108);
setfillstyle(1,7);
bar(3,89,100,107);
setcolor(0);
outtextxy(5,98," E");
setcolor(4);
outtextxy(5+textwidth(" E"),98,"x");
setcolor(0);
outtextxy(5+textwidth(" Ex"),98,"it");
}
else
{
setfillstyle(1,0);
bar(2,45,101,108);
selected=0;
}
}



void Edit(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=2;
setfillstyle(1,1);
bar(50,45,171,108);

setfillstyle(1,1);
bar(50,45,171,67);
setfillstyle(1,7);
bar(51,46,170,66);
setcolor(4);
outtextxy(55,56," U");
setcolor(0);
outtextxy(55+textwidth(" U"),56,"pdate Record");

setfillstyle(1,1);
bar(50,66,170,88);
setfillstyle(1,7);
bar(51,67,170,87);
setcolor(4);
outtextxy(55,77," D");
setcolor(0);
outtextxy(55+textwidth(" D"),77,"elete Record");

setfillstyle(1,1);
bar(50,88,170,108);
setfillstyle(1,7);
bar(51,89,170,107);
setcolor(4);
outtextxy(55,98," U");
setcolor(0);
outtextxy(55+textwidth(" U"),98,"ndo Delete");
}
else
{
setfillstyle(1,0);
bar(50,45,171,108);
selected=0;
}
}

void Search(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=3;
setfillstyle(1,1);
bar(95,45,201,88);

setfillstyle(1,1);
bar(95,45,201,67);
setfillstyle(1,7);
bar(96,46,200,66);
setcolor(4);
outtextxy(101,56," F");
setcolor(0);
outtextxy(101+textwidth(" F"),56,"ind Record");

setfillstyle(1,1);
bar(95,66,201,88);
setfillstyle(1,7);
bar(96,67,200,87);
setcolor(4);
outtextxy(101,77," D");
setcolor(0);
outtextxy(101+textwidth(" D"),77,"isplay All");

}
else
{
setfillstyle(1,0);
bar(95,45,201,88);
selected=0;
}
}

void Util(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=4;
setfillstyle(1,1);
bar(160,45,260,88);

setfillstyle(1,1);
bar(160,45,261,67);
setfillstyle(1,7);
bar(161,46,260,66);
setcolor(4);
outtextxy(165,56," V");
setcolor(0);
outtextxy(165+textwidth(" V"),56,"iew Bucket");

setfillstyle(1,1);
bar(160,66,261,88);
setfillstyle(1,7);
bar(161,67,260,87);
setcolor(4);
outtextxy(165,77," D");
setcolor(0);
outtextxy(165+textwidth(" D"),77,"isk Space");

setfillstyle(1,1);
bar(160,86,261,108);
setfillstyle(1,7);
bar(161,87,260,107);
setcolor(4);
outtextxy(165,97," U");
setcolor(0);
outtextxy(165+textwidth(" U"),97,"tilization");

}
else
{
setfillstyle(1,0);
bar(160,45,261,108);
selected=0;
}
}

void About(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=5;
setfillstyle(1,1);
bar(260,45,399,88);

setfillstyle(1,1);
bar(260,45,399,67);
setfillstyle(1,7);
bar(261,46,398,66);
setcolor(4);
outtextxy(265,56," I");
setcolor(0);
outtextxy(265+textwidth(" I"),56,"mplementation");

setfillstyle(1,1);
bar(260,66,398,88);
setfillstyle(1,7);
bar(261,67,398,87);
setcolor(4);
outtextxy(265,77," A");
setcolor(0);
outtextxy(265+textwidth(" A"),77,"bout Developers");


}
else
{
setfillstyle(1,0);
bar(260,45,399,88);
selected=0;
}
}


void Help(int i)
{
settextstyle(0,0,0);
if(i==1)
{
selected=5;
setfillstyle(1,1);
bar(315,45,400,66);

setfillstyle(1,1);
bar(316,45,401,65);
setfillstyle(1,7);
bar(316,46,400,66);
setcolor(4);
outtextxy(320,56," C");
setcolor(0);
outtextxy(320+textwidth(" C"),56,"ontents");

}
else
{
setfillstyle(1,0);
bar(315,45,401,67);
selected=0;
}
}


void DrawStatusBar(char *title,char *msg)
{
settextstyle(0,0,0);
setfillstyle(1,1);
bar(2,getmaxy()-25,getmaxx()-2,getmaxy()-2);

setfillstyle(1,7);
bar(3,getmaxy()-24,getmaxx()-2,getmaxy()-3);
setcolor(8);
line(90,getmaxy()-24,90,getmaxy()-3);

setcolor(BLUE);
outtextxy(10,getmaxy()-15,title);
outtextxy(100,getmaxy()-15,msg);
}


 int msgbox(char *title,char *msg,char *desc)
 {
// restrictmouseptr(100,100,101,101);
  showmouseptr();
/* select drawing color */
 setcolor(9);
 //set the textstyle
settextstyle(0,0,0);

    /* select fill color */
    setfillstyle(SOLID_FILL, 9);

    /* draw a border around the screen */
    setcolor(7);
    setfillstyle(SOLID_FILL, 7);
    bar(getmaxx()/4,getmaxy()/3,getmaxx()-getmaxx()/4,getmaxy()/3+getmaxy()/3);
    restrictmouseptr(getmaxx()/4,getmaxy()/3,getmaxx()-getmaxx()/4,getmaxy()/3+getmaxy()/3);
    rectangle(getmaxx()/4,getmaxy()/3,getmaxx()-getmaxx()/4,getmaxy()/3+getmaxy()/3);
    setfillstyle(SOLID_FILL, 9);
    bar(getmaxx()/4,getmaxy()/3,getmaxx()-getmaxx()/4,getmaxy()/3+20);
    rectangle(getmaxx()/4,getmaxy()/3,getmaxx()-getmaxx()/4,getmaxy()/3+20);
    rectangle(getmaxx()-getmaxx()/4-17,getmaxy()/3+4,getmaxx()-getmaxx()/4-4,getmaxy()/3+16);
    setcolor(WHITE);
    outtextxy(getmaxx()-getmaxx()/4-13,getmaxy()/3+7,"X");
    outtextxy(getmaxx()/4+10,getmaxy()/3+5,title);
    line(getmaxx()/4+10,getmaxy()/3+getmaxy()/3-36,getmaxx()-getmaxx()/4-10,getmaxy()/3+getmaxy()/3-36);
    setfillstyle(SOLID_FILL, CYAN);
    bar(getmaxx()-getmaxx()/4-70,getmaxy()/3+getmaxy()/3-28,getmaxx()-getmaxx()/4-10, getmaxy()/3+getmaxy()/3-8);
    rectangle(getmaxx()-getmaxx()/4-70,getmaxy()/3+getmaxy()/3-28,getmaxx()-getmaxx()/4-10, getmaxy()/3+getmaxy()/3-8);
    setcolor(RED);
    outtextxy(getmaxx()-getmaxx()/4-45,getmaxy()/3+getmaxy()/3-22,"O");
    setcolor(BLACK);
    outtextxy((getmaxx()-getmaxx()/4-45)+textwidth("O"),getmaxy()/3+getmaxy()/3-22,"k");
    bar(getmaxx()-getmaxx()/4-140,getmaxy()/3+getmaxy()/3-28,getmaxx()-getmaxx()/4-80, getmaxy()/3+getmaxy()/3-8);
    setcolor(WHITE);
    rectangle(getmaxx()-getmaxx()/4-140,getmaxy()/3+getmaxy()/3-28,getmaxx()-getmaxx()/4-80, getmaxy()/3+getmaxy()/3-8);
    setcolor(RED);
    outtextxy(getmaxx()-getmaxx()/4-133,getmaxy()/3+getmaxy()/3-22,"C");
    setcolor(BLACK);
    outtextxy((getmaxx()-getmaxx()/4-133)+textwidth("C"),getmaxy()/3+getmaxy()/3-22,"ancel");
    setcolor(BLACK);
    outtextxy((getmaxx()/4)+10,getmaxy()/3+44+10,msg);
    setcolor(BLUE);
    outtextxy((getmaxx()/4)+10,getmaxy()/3+76,desc);

int i=0,button,x,y,flag=0;
char ch;
	while (i==0)
	       {
			getmousepos(&button,&x,&y);
	//		for the close button ( X )
			if( (x>464 && x<476 && y>164 && y<174)&& button==1)
			{
			      restrictmouseptr(0,0,getmaxx(),getmaxy());
			      flag=0;
			      goto restart;
			}

	//		for the ok button
				if( (x>411 && x<468 && y>291 && y<309) && button==1)
				{
				restrictmouseptr(0,0,getmaxx(),getmaxy());
				flag=1;
				goto restart;
				}
	//		for the cancel button
				if( (x>341 && x<399 && y>291 && y<309) && button==1)
				{
			       restrictmouseptr(0,0,getmaxx(),getmaxy());
			       flag=0;
			       goto restart;
				}

		       if(kbhit())
		       {
		       int key=getch();

			if(key=='C' || key=='c' || key==27/*esc*/)
			 {

			       restrictmouseptr(0,0,getmaxx(),getmaxy());
			       flag=0;
			       goto restart;
			  }

		       else if (key=='O' || key=='o' || key==13/*ENTER*/)
			  {
			       restrictmouseptr(0,0,getmaxx(),getmaxy());
			       flag=1;
			       goto restart;
			  }
		     }
	}
restrictmouseptr(0,0,getmaxx(),getmaxy());
restart:
restrictmouseptr(0,0,getmaxx(),getmaxy());
return flag;
}


void PutTitle(char *txt)
{
	settextstyle(0,0,0);
	setcolor(15);
	outtextxy(30,10,txt);

}


//COPY THE PORTION OF SCREEN AND REPAINT

void CopyImage(int x1,int y1,int x2,int y2)
{
  int size;

  size = imagesize(x1,y1,x2,y2);

  img = malloc( size );
  getimage(x1,y1,x2,y2,img);
}

void PasteImage(int x1,int y1)
{
putimage(x1,y1, img, COPY_PUT);
}

//SHOW THE MAIN SCREEN

void ShowStart()
{
textbackground(BLACK);
textcolor(RED);
_setcursortype(0);
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      ");
textcolor(WHITE);
cprintf("*****************************************************************");
textcolor(RED);
cprintf("      บ");
cprintf(" บ      ");
textcolor(WHITE);
cprintf("*                                                               *      ");
textcolor(RED);
cprintf("บ");
cprintf(" บ");
textcolor(WHITE);
cprintf("      *                      ");
textcolor(CYAN);
cprintf(" Student Project                         ");
textcolor(WHITE);
cprintf("*      ");
textcolor(RED);
cprintf("บ");
cprintf(" บ      ");
textcolor(WHITE);
cprintf("*                                                               *      ");
textcolor(RED);
cprintf("บ");
cprintf(" บ");
textcolor(WHITE);
cprintf("      *****************************************************************      ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
textcolor(6);
cprintf("     INCLUDES   :                       FEATURES   :                         ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
cprintf("            ");
textcolor(11);
cprintf("1.  ADD NEW RECORD                 1.  TEXT MODE                 ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
cprintf("            ");
textcolor(12);
cprintf("2.  UPDATE A RECORD                2.  GRAPHICS MODE             ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
cprintf("            ");
textcolor(13);
cprintf("3.  DELETE A RECORD                3.  MOUSE DRIVEN              ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
cprintf("            ");
textcolor(14);
cprintf("4.  FIND RECORD                    4.  MENU DRIVEN               ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
cprintf("            ");
textcolor(8);
cprintf("5.  DISPLAY ALL RECORDS            5.  PORTABLE                  ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ");
textcolor(3);
cprintf("                               DEVELOPED BY                                  ");
textcolor(RED);
cprintf("บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                             ");
textcolor(rand()+BLINK);
cprintf("MANOHAR & PRATOSH");
textcolor(RED);
cprintf("                               บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                   ");
textcolor(LIGHTGRAY);
cprintf("Press any key to continue");
textcolor(RED);
cprintf(" บ");
cprintf(" บ                                                                             บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
getche();
}

void yourInput()
{
settextstyle(0,0,0);
setcolor(CYAN);
outtextxy(50,320,"Record Information");
setfillstyle(1,7);
bar(50,340,getmaxx()-50,getmaxy()-50);
setfillstyle(1,0);
bar(52,342,getmaxx()-50-2,getmaxy()-50-2);
setcolor(8);
setlinestyle(1,0,8);
line(52,351,getmaxx()-50-2,351);
line(120,342,120,getmaxy()-50-2);
line(170,342,170,getmaxy()-50-2);
setcolor(4);
outtextxy(55,(342+2),"FIELD");
outtextxy(125,(342+2),"SIZE");
outtextxy(205,(342+2),"TEXT");
setlinestyle(1,0,15);

}

void imp()
{

clearScr();
setfillpattern(&pattern[1][2],RED);
bar(3,45,getmaxx()-3,450);

setfillstyle(SOLID_FILL,WHITE);
bar(10,49,getmaxx()-10,85);
setfillstyle(SOLID_FILL,12);
bar(4+5,101,(getmaxx()/2)-11,420);
bar((getmaxx()/2)+21,101,getmaxx()-10,420);


setfillstyle(SOLID_FILL,LIGHTBLUE);
bar(4+5,101,(getmaxx()/2)-11,131);
bar((getmaxx()/2)+21,101,getmaxx()-10,131);


settextstyle(1,0,0);
setcolor(GREEN);
outtextxy(110,46,"PROJECT IMPLEMENTATION");
settextstyle(0,0,0);

setcolor(BLACK);
outtextxy((getmaxx()/4)-45,115,"PART - I");
outtextxy((getmaxx()/4)*3-45,115,"PART - II");

int y1=135;
int x1=10;


setcolor(BLUE);
outtextxy(x1,y1,"DATA MEMBERS OF STUDENT CLASS");
y1+=20;
x1+=20;
setcolor(14);
outtextxy(x1,y1,"char* URN[11],Lname[11],Fname[21]");
y1+=10;
outtextxy(x1,y1,"char* Address[50],Semester[4]");
y1+=10;
outtextxy(x1,y1,"char* Branch[4],College[14]");

y1+=20;
x1-=20;
setcolor(BLUE);
outtextxy(x1,y1,"METHODS OF STUDENT CLASS");
x1+=20;
y1+=20;
setcolor(14);
outtextxy(x1,y1,"1 INSERT NEW RECORD");
y1+=10;
outtextxy(x1,y1,"2 DELETE A RECORD");
y1+=10;
outtextxy(x1,y1,"3 UPDATE A RECORD");
y1+=10;
outtextxy(x1,y1,"4 SEARCH A RECORD");
y1+=10;
outtextxy(x1,y1,"5 DISPLAY ALL RECORDS");
y1+=10;
outtextxy(x1,y1,"6 PACK THE DATA");
y1+=10;
outtextxy(x1,y1,"7 UNPACK THE DATA");



setcolor(BLUE);
y1+=20;
x1-=20;
outtextxy(x1,y1,"IOBUFFER CLASS");
x1+=20;
y1+=20;
setcolor(14);
outtextxy(x1,y1,"1 FIXED length RECORDS   ( 150 )");
y1+=10;
outtextxy(x1,y1,"2 FIXED number of FIELDS ( 7 )");
y1+=10;
outtextxy(x1,y1,"3 VARIABLE length FIELDS (   )");
y1+=10;
outtextxy(x1,y1,"4 FIELD Delimiter used   ( | )");
y1+=10;
outtextxy(x1,y1,"5 RECORD Delimiter used  ( # )");


setcolor(BLUE);
y1+=20;
x1-=20;
outtextxy(x1,y1,"DATA FILE IMPLEMENTATION");
x1+=20;
y1+=20;
setcolor(14);
outtextxy(x1,y1,"1 DELETE (used * as delete marker)");
y1+=10;
outtextxy(x1,y1,"2 UPDATE (first delete then append");







y1=135;
x1=getmaxx()/2+20;

setcolor(BLUE);
outtextxy(x1,y1,"BUCKET CLASS");
y1+=20;
x1+=20;
setcolor(14);
outtextxy(x1,y1,"1  INSERT         2  REMOVE");
y1+=10;
outtextxy(x1,y1,"3  SPLIT          4  NEW RANGE");
y1+=10;
outtextxy(x1,y1,"5  REDISTRIBUTE   6  FIND BUDDY");
y1+=10;
outtextxy(x1,y1,"7  TRY COMBINE    8  COMBINE");
y1+=10;
outtextxy(x1,y1,"9  RET MAX KEYS   10 RET NUM KEYS");
y1+=10;
outtextxy(x1,y1,"11 RET REC ADDR   12 KEYS ");

y1+=20;
x1-=20;
setcolor(BLUE);
outtextxy(x1,y1,"DIRECTORY CLASS");
x1+=20;
y1+=20;
setcolor(14);
outtextxy(x1,y1,"1  OPEN           2  CREATE");
y1+=10;
outtextxy(x1,y1,"3  CLOSE          4  INSERT");
y1+=10;
outtextxy(x1,y1,"5  REMOVE         6  SEARCH");
y1+=10;
outtextxy(x1,y1,"7  DOUBLE SIZE    8  COLLAPSE");
y1+=10;
outtextxy(x1,y1,"9  INSERT BUCKET  10 REMOVE BUCKET");
y1+=10;
outtextxy(x1,y1,"11 STORE BUCKET   12 LOAD BUCKET ");
y1+=10;
outtextxy(x1,y1,"13 FIND BUCKET    14 PRINT ");

setcolor(BLUE);
y1+=20;
x1-=20;
outtextxy(x1,y1,"SPECIAL GUI IMPLEMENTATION ");
x1+=20;
y1+=20;
setcolor(14);
outtextxy(x1,y1,"1 DISPLAYING ALL RECORDS");
y1+=10;
outtextxy(x1,y1,"2 DISPLAYING ALL BUCKETS & DIR");
y1+=10;
outtextxy(x1,y1,"3 DIRECTORY SPACE UTILIZATION");
y1+=10;
outtextxy(x1,y1,"4 BUCKET SPACE UTILIZATION");
y1+=10;
outtextxy(x1,y1,"5 DISK SPACE UTILIZATION");

}

