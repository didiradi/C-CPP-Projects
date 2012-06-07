//PROGRAM FOR LINEAR QUEUE

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<graphics.h>

// GLOBAL VARIABLE DECLARATION

int s[5]={0,0,0,0,0};
union REGS i,o;

// MAIN PROGRAM BEGINS HERE

void main()
{

// VARIABLE DECLARATIONS

int i=0,j=0,a,front=-1,rear=-1;
char ch,ch1;
int item;

// FUNCTION PROTOTYPE DECLARATIONS

void show();
void slidebar(int *rear,int *front);
void showqueuesize();
void slidebar();
void cpoiters();
void drawq();
void moveptrs(int *rear,int *front);
void insertq(int *rear,char c);
void deleteq(int *front);
void qdelete(int q[],int rear,int front);
void hidequeueinfo();
void shownumbers(int x1,int y1,int x2,int y2);
int initmouse();
void getmousepos(int *button,int *x,int *y);
void showmouseptr();
void restrictmouseptr(int a,int b,int c,int d);
void exitbutton(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y);
void zoomin();

// CHECKING THE GRAPHICS DRIVER

int gd=DETECT,gm,maxx,maxy,x,y,button;
initgraph(&gd,&gm,"c:\\TC");

// GET THE MAXIMUM X AND Y CO ORDINATES

	maxx=getmaxx();
	maxy=getmaxy();

// DRAW THE BORDER FOR THE WINDOW

	rectangle(0,0,maxx,maxy);

// SET THE AREA WITHIN THE SCREEN WHERE GRAPHICAL O/P DISPLAYED

	setviewport(1,1,maxx-1,maxy-1,1);

// WRITE THE HEADDING

	gotoxy(150,1);
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
	setcolor(WHITE);
	setbkcolor(216);
	settextjustify(0,2);
	outtextxy(220,2," LINEAR QUEUE ");
	setcolor(RED);
	settextstyle(8,HORIZ_DIR,3);
	outtextxy(40,35,"DEVELOPED IN 'C'  : IT'S A KVSM PRODUCT");
	settextstyle(0,HORIZ_DIR,0);

// INITIALIZE MOUSE,IF IT DOESN'T GET INITIALIZED CLOSE GRAPHICS MODE

	if (initmouse()==0)
	{
		closegraph();
		restorecrtmode();
		printf("\nMouse Driver not installed");
		exit(1);
	}

// IF MOUSE DRIVER INITIALISED THEN
// RESTRICT THE MOUSE POINTER WITHIN THE COORDINATES GIVEN GIVEN BELOW

	restrictmouseptr(1,57,maxx-1,maxy-1);

// SHOW THE MOUSE POINTER

	showmouseptr();

// SET THE TEXT COLOR TO WHITE

	setcolor(WHITE);
	line(0,70,getmaxx(),70);
	line(0,400,getmaxx(),400);

	setcolor(14);
	outtextxy(65,115,"QUEUE OPERATIONS                      QUEUE STATUS");
	outtextxy(140,440,"Press the Key that is Highlighted or use Mouse.");
	setcolor(CYAN);
	line(65,125,190,125);
	line(368,125,464,125);

// CALL THE SHOW FUNCTION TO DRAW THE VARIOUS BUTTONS

	show();

// DRAW THE QUEUE

	drawq();

// DRAW THE POINTERS THAT IS FRONT AND REAR

	moveptrs(&rear,&front);

// SET THE LABEL M THAT WILL BE USED LATER FOR UNCONDITIONAL JUMP

	m:

// GO ON CHECKING WHETHER A KEY IS PRESSED OR NOT

	while (i==0)
	       {
	       if (kbhit())
	       {
	       ch=getche();

	       // CHECK IF THE KEY PRESSED IS E OR e
	       switch(ch)
	       {
	       case 'e':
	       case 'E':

	       {
	       // CALL THE FUNCTION THAT WILL BE FOR EXIT
	       zoomin();
	       }
	       reset:
	       case 'R':
	       case 'r':
	       {
	       // CALL THE RESET QUEUE FUNCTION
	       hidequeueinfo();
	       // CALL THE PROGRESSBAR
	       slidebar(&rear,&front);
	       // AGAIN DRAW THE QUEUE
	       drawq();
	       restrictmouseptr(1,57,maxx-1,maxy-1);
	       goto m;
	       }
	       queueinfo:
	       case 'A' :
	       case 'a':
	       {
	       // CALL THE FUNCTION TO GIVE INFORMATION ABOUT QUEUE
	       hidequeueinfo();
	       showqueuesize();
	       goto m;
	       }
	       delet:
	       case 'D':
	       case 'd':
	       {
	       //  CALL THE DELETE QUEUE OPERATIONS
	       hidequeueinfo();
	       deleteq(&front);
	       // CHECK IF QUEUE IS EMPTY, IF SO PRINT THE MESSAGE
		       if(rear==-1 || front==5 ||rear<front)
			{
			// CLEAR THE INFO, THERE IN INFORMATION PART
			hidequeueinfo();
			// DISPLAY THE TEXT IN THE INFORMATION PART
			outtextxy(200,430,"Queue is empty, you can't delete");
			}
			else
			{
			front=front+1;
			moveptrs(&rear,&front);
			}
		goto m;
	       }
	       ins:
	       case 'I':
	       case 'i':
	       {
	       // HERE IS THE OPERATIONS FOR INSERTING AN ELEMENT
	       hidequeueinfo();
	       if(rear==4)
			{
			hidequeueinfo();
			outtextxy(200,430,"Queue is full, you can't insert");
			goto m;
			}

	       // SHOWS THE NUMBERS AND CANCEL BUTTON
	       shownumbers(20,430,60,470);
	       // CHECK FOR WHAT KEY PRESSED

	       n:

	       while(j==0)
	       {
		 if (kbhit())
		  {
		   ch1=getche();

			       if(front==-1)
			       {
			       front=front+1;
			       }
		   switch(ch1)
		   {
		   cancel:
		   case 'C':
		   case 'c':
		       {
		       hidequeueinfo();
		       restrictmouseptr(1,57,maxx-1,maxy-1);
		       goto m;
		       }
		   zero:
		   case '0':
		       {
			       insertq(&rear,'0');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   one:
		   case '1':
		       {
			       insertq(&rear,'1');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   two:
		   case '2':
		       {
			       insertq(&rear,'2');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   three:
		  case '3':
		       {
			       insertq(&rear,'3');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		  four:
		   case '4':
		       {
			       insertq(&rear,'4');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   five:
		   case '5':
		       {
			       insertq(&rear,'5');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   six:
		   case '6':
		       {
			       insertq(&rear,'6');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   seven:
		   case '7':
		       {
			       insertq(&rear,'7');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		  eight:
		   case '8':
		       {
			       insertq(&rear,'8');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   nine:
		   case '9':
		       {
			       insertq(&rear,'9');
			       rear=rear+1;
			       moveptrs(&rear,&front);
			       hidequeueinfo();
			       restrictmouseptr(1,57,maxx-1,maxy-1);
			       goto m;
		       }
		   default :
				hidequeueinfo();
				outtextxy(200,430,"Invalid Key Pressed ! Press a valid key");
				delay(550);
				hidequeueinfo();
				shownumbers(20,430,60,470);
				goto n;
		   }
		}
		else
		{
		//write code here to press the 0-----9 and cancel
		       getmousepos(&button,&x,&y);
		       if((button & 1)==1)
		       {
			       if(front==-1)
			       {
			       front=front+1;
			       }
		       }
		       if( (x>500 && x<getmaxx()-10 && y>445 && y<470) && (button & 1)==1)
			{
			goto cancel;
			}
		       if( (x>20 && x<60 && y>430 && y<470) && (button & 1)==1)
			{
			goto zero;
			}
		       if( (x>60 && x<100 && y>430 && y<470) && (button & 1)==1)
			{
			goto one;
			}
		       if( (x>100 && x<140 && y>430 && y<470) && (button & 1)==1)
			{
			goto two;
			}
		       if( (x>140 && x<180 && y>430 && y<470) && (button & 1)==1)
			{
			goto three;
			}
		       if( (x>180 && x<220 && y>430 && y<470) && (button & 1)==1)
			{
			goto four;
			}
		       if( (x>220 && x<260 && y>430 && y<470) && (button & 1)==1)
			{
			goto five;
			}
		       if( (x>260 && x<300 && y>430 && y<470) && (button & 1)==1)
			{
			goto six;
			}
		       if( (x>300 && x<340 && y>430 && y<470) && (button & 1)==1)
			{
			goto seven;
			}
		       if( (x>340 && x<380 && y>430 && y<470) && (button & 1)==1)
			{
			goto eight;
			}
		       if( (x>380 && x<420 && y>430 && y<470) && (button & 1)==1)
			{
			goto nine;
			}
		}
	}
	}
	 default :
			hidequeueinfo();
			outtextxy(220,420,"Please Press a Valid Key");
			goto m;
	 }
	 }
	 // ELSE CONDITION FOR THE IF AFTER THE FIRST WHILE
	 else
	       {

		  getmousepos(&button,&x,&y);
		  if( (x>50 && x<200 && y<370 && y>350) && (button & 1)==1)
			{
			//exit button click
			zoomin();
			}
		  if( (x>50 && x<200 && y>150 && y<170) && (button & 1)==1)
			{
			//clicked the queueinfo button
			goto queueinfo;
			}
		  if( (x>50 && x<200 && y>200 && y<220) && (button & 1)==1)
			{
			//clicked the insert button
			goto ins;
			}

		  if( (x>50 && x<200 && y>250 && y<270) && (button & 1)==1)
			{
			//clicked the delete button
			delay(500);
			goto delet;
			}
		  if( (x>50 && x<200 && y>300 && y<320) && (button & 1)==1)
			{
			//clicked the reset button
			goto reset;
			}

		}


	}

getche();
}
int initmouse()
{
	i.x.ax=0;
	int86(0x33,&i,&o);
	return(o.x.ax);
}

/* display mouse pointer*/
void showmouseptr()
{
	i.x.ax=1;
	int86(0x33,&i,&o);
}


/* restrict mouse movements */
void restrictmouseptr(int x1,int y1,int x2,int y2)
{
	i.x.ax=7;
	i.x.cx=x1;
	i.x.dx=x2;
	int86(0x33,&i,&o);

	i.x.ax=8;
	i.x.cx=y1;
	i.x.dx=y2;
	int86(0x33,&i,&o);

}

/* gets mouse cordinates and button status */
void getmousepos(int *button,int *x,int *y)
{
	i.x.ax=3;
	int86(0x33,&i,&o);
	*button=o.x.bx;
	*x=o.x.cx;
	*y=o.x.dx;
}

//function to be called when exit button pressed

void zoomin()
{
int m,rad=getmaxy()/2-40,x1=getmaxx()/2,y1=getmaxy()/2,i;
char pattern[8] = {0x00, 0x70, 0x20, 0x27, 0x25, 0x27, 0x04, 0x04};
clrscr();
setfillpattern(pattern,RED);
bar3d(0,0,getmaxx(),getmaxy(),2,2);
bar(1,1,getmaxx()-1,getmaxy()-1);
rectangle(2,2,getmaxx()-2,getmaxy()-2);
setfillstyle(SOLID_FILL,RED);
setcolor(WHITE);
bar(80,80,getmaxx()-80,getmaxy()-80);
for(i=80;i<=90;i++)
{
delay(80);
rectangle(i,i,getmaxx()-i,getmaxy()-i);
}
setcolor(BLACK);
settextstyle(1,0,5);
outtextxy(187,95,"Developed By");
outtextxy(187,330,"Developed By");
settextstyle(1,1,5);
setcolor(WHITE);
outtextxy(94,98,"Developed By");
outtextxy(475,98,"Developed By");
setcolor(WHITE);
settextstyle(8,0,3);
outtextxy(220,170," Manohar Negi");
outtextxy(220,210,"  III Semester");
outtextxy(220,250,"  Info. Science");
outtextxy(220,290,"     R.V.C.E. ");
setcolor(11);
rectangle(190,150,450,330);
delay(3000);
for(m=0;m<6;m++)
{
cleardevice();
setcolor(RED);
circle(x1,y1,rad);
circle(x1,y1,rad-2);
rad=rad-50;
delay(200);
}
exit(0);
}

//draw the exit button

void exitbutton(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y)
{       setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x1-20,y1-20,x2+10,y2+10);
	rectangle(x1-20,y1-20,x2+10,y2+10);
	setfillstyle(SOLID_FILL,7);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setcolor(BROWN);
	outtextxy(e_x,e_y,"E");
	setcolor(BLUE);
	outtextxy(xit_x,xit_y,"xit");

}
//draw the insert button

void insertbutton(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y)
{       setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x1-20,y1-20,x2+10,y2+10);
	rectangle(x1-20,y1-20,x2+10,y2+10);
	setfillstyle(SOLID_FILL,7);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setcolor(BROWN);
	outtextxy(e_x,e_y,"I");
	setcolor(BLUE);
	outtextxy(xit_x,xit_y,"nsert");

}

//draw the delete button

void delbutton(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y)
{       setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x1-20,y1-20,x2+10,y2+10);
	rectangle(x1-20,y1-20,x2+10,y2+10);
	setfillstyle(SOLID_FILL,7);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setcolor(BROWN);
	outtextxy(e_x,e_y,"D");
	setcolor(BLUE);
	outtextxy(xit_x,xit_y,"elete");


}

//draw the reset button

void dispbutton(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y)
{       setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x1-20,y1-20,x2+10,y2+10);
	rectangle(x1-20,y1-20,x2+10,y2+10);
	setfillstyle(SOLID_FILL,7);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setcolor(BROWN);
	outtextxy(e_x,e_y,"R");
	setcolor(BLUE);
	outtextxy(xit_x,xit_y,"eset Queue");

}

//draw the queuesize button

void queuesize(int x1,int y1,int x2,int y2,int e_x,int e_y,int xit_x,int xit_y)
{       setcolor(BLACK);
	setfillstyle(SOLID_FILL,BLACK);
	bar(x1-20,y1-20,x2+10,y2+10);
	rectangle(x1-20,y1-20,x2+10,y2+10);
	setfillstyle(SOLID_FILL,7);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	setcolor(BROWN);
	outtextxy(e_x,e_y,"A");
	setcolor(BLUE);
	outtextxy(xit_x,xit_y,"ssemption");

}

//call the above mentioned functions with their coordinates

void show()
{
queuesize(50,150,200,170,50+45,150+5,60+45,155);
insertbutton(50,200,200,220,50+45,200+5,60+45,205);
delbutton(50,250,200,270,50+45,250+5,60+45,255);
dispbutton(50,300,200,320,50+45,300+5,60+45,305);
exitbutton(50,350,200,370,50+45,350+5,60+45,355);
}

//what happens when the queue size button is pressed

void showqueuesize()
{
int i;
setcolor(GREEN);
outtextxy(50,440,"3: The number you insert should be single digit.");
outtextxy(100/2,430,"2: You can insert only numeric values to queue.");
outtextxy(100/2,420,"1: Queue size is assumed to be fixed and i.e. 5.");
outtextxy(100/2,450,"4: You can reset the queue to make it empty.");
setcolor(WHITE);
for(i=510;i<=590;i+=20)
{
rectangle(i,430,i+20,455);
}
}

//this function will clear the information that is there in information area

void hidequeueinfo()
{
setfillstyle(SOLID_FILL,BLACK);
bar(3,410,getmaxx(),getmaxy());
}

//this function will display the numbers and cancel button

void shownumbers(int x1,int y1,int x2,int y2)
{
int k;
restrictmouseptr(0,400,getmaxx(),getmaxy());
setcolor(12);
settextstyle(0,0,0);
outtextxy(20,410,"Enter the number or click any of the following");
setcolor(RED);
	for(k=0;k<=9;k++)
	{
	settextstyle(0,0,1);
	setfillstyle(SOLID_FILL,CYAN);
	bar(x1,y1,x2,y2);
	rectangle(x1,y1,x2,y2);
	if(k==0)
	{
	outtextxy(x1+20,y1+20,"0");
	}
	if(k==1)
	{
	outtextxy(x1+20,y1+20,"1");
	}
	if(k==2)
	{
	outtextxy(x1+20,y1+20,"2");
	}
	if(k==3)
	{
	outtextxy(x1+20,y1+20,"3");
	}
	if(k==4)
	{
	outtextxy(x1+20,y1+20,"4");
	}
	if(k==5)
	{
	outtextxy(x1+20,y1+20,"5");
	}
	if(k==6)
	{
	outtextxy(x1+20,y1+20,"6");
	}
	if(k==7)
	{
	outtextxy(x1+20,y1+20,"7");
	}
	if(k==8)
	{
	outtextxy(x1+20,y1+20,"8");
	}
	if(k==9)
	{
	outtextxy(x1+20,y1+20,"9");
	}
	x1=x2;
	x2=x2+40;
	}
	setfillstyle(SOLID_FILL,8);
	setcolor(BLUE);
	bar(x1+100,y1+15,getmaxx()-10,y2);
	rectangle(x1+100,y1+15,getmaxx()-10,y2);
	rectangle(x1+102,y1+17,getmaxx()-12,y2-2);
	setcolor(BLUE);
	outtextxy(x1+130,y1+25,"C");
	setcolor(LIGHTCYAN);
	outtextxy(x1+138,y1+25,"ancel");
}

//this is to draw the main queue

void drawq()
{
int l;
int m=170;
setcolor(9);
outtextxy(235,m+20,"Front End");
setfillstyle(SOLID_FILL,BLACK);
for(l=320;l<=500;l=l+40)
{
setcolor(10);
bar(l,m,l+40,m+40);
rectangle(l,m,l+40,m+40);
setcolor(RED);
outtextxy(320,155,"0");
outtextxy(360,155,"1");
outtextxy(400,155,"2");
outtextxy(440,155,"3");
outtextxy(480,155,"4");
}
setcolor(9);
outtextxy(l+20,m+20,"Rear End");
}

// this will clear the pointers

void cpoiters()
{
setfillstyle(SOLID_FILL,BLACK);
bar(250,211,getmaxx()-20,280);
}

//to move the pointers

void moveptrs(int *rear,int *front)
{

int rx1,fx1,ry1,fy1,z,i=40;
rx1=265;
fx1=245;
ry1=230;
fy1=230;
cpoiters();
setcolor(LIGHTRED);
for(z=-1;z<=5;z++)
{
		if(*rear==z)
		{
		line(rx1+i,ry1,rx1+i,ry1+20);
		line(rx1+i,ry1,rx1+i-5,ry1+5);
		line(rx1+i,ry1,rx1+i+5,ry1+5);
		outtextxy(rx1+i,260,"R");
		}

		if(*front==z)
		{
		line(fx1+i,fy1,fx1+i,fy1+20);
		line(fx1+i,fy1,fx1+i-5,fy1+5);
		line(fx1+i,fy1,fx1+i+5,fy1+5);
		outtextxy(fx1+i,260,"F");
		}
		fx1=fx1+i;
		rx1=rx1+i;
}
}

// draw the progressbar

void slidebar(int *rear,int *front)
{
setcolor(RED);
if(*rear!=-1 && *front!=-1)
{
int i;
hidequeueinfo();
rectangle(198,438,402,462);
outtextxy(220,420,"Resetting Please wait");
for(i=200;i<=400-20;i+=20)
{
delay(260);
setfillstyle(SOLID_FILL,YELLOW);
bar(i+2,441,i+20,460);
}
hidequeueinfo();
*rear=*front=-1;
moveptrs(&*rear,&*front);
}
else
{
outtextxy(220,420,"Queue is empty, Nothing to reset");
}
}

//insert into queue

void insertq(int *rear,char c)
{
int l=320,i,l2;
int m=170;
l2=l+40;
s[1]=4;
setcolor(GREEN);
setfillstyle(SOLID_FILL,WHITE);
if(*rear==-1)
{
bar3d(l,m,l2,m+40,1,0);
rectangle(l,m,l+40,m+40);
switch(c)
{
case '0':
	outtextxy(l+20,m+20,"0");
	break;
case '1':
	outtextxy(l+20,m+20,"1");
	break;
case '2':
	outtextxy(l+20,m+20,"2");
	break;
case '3':
	outtextxy(l+20,m+20,"3");
	break;
case '4':
	outtextxy(l+20,m+20,"4");
	break;
case '5':
	outtextxy(l+20,m+20,"5");
	break;
case '6':
	outtextxy(l+20,m+20,"6");
	break;
case '7':
	outtextxy(l+20,m+20,"7");
	break;
case '8':
	outtextxy(l+20,m+20,"8");
	break;
case '9':
	outtextxy(l+20,m+20,"9");
	break;
}
}
if(*rear==0)
{
bar3d(l+40,m,l2+40,m+40,1,0);
rectangle(l,m,l+40,m+40);
switch(c)
{
case '0':
	outtextxy(l+60,m+20,"0");
	break;
case '1':
	outtextxy(l+60,m+20,"1");
	break;
case '2':
	outtextxy(l+60,m+20,"2");
	break;
case '3':
	outtextxy(l+60,m+20,"3");
	break;
case '4':
	outtextxy(l+60,m+20,"4");
	break;
case '5':
	outtextxy(l+60,m+20,"5");
	break;
case '6':
	outtextxy(l+60,m+20,"6");
	break;
case '7':
	outtextxy(l+60,m+20,"7");
	break;
case '8':
	outtextxy(l+60,m+20,"8");
	break;
case '9':
	outtextxy(l+60,m+20,"9");
	break;
}
}
if(*rear==1)
{
bar3d(l+80,m,l2+80,m+40,1,0);
rectangle(l,m,l+40,m+40);
switch(c)
{
case '0':
	outtextxy(l+100,m+20,"0");
	break;
case '1':
	outtextxy(l+100,m+20,"1");
	break;
case '2':
	outtextxy(l+100,m+20,"2");
	break;
case '3':
	outtextxy(l+100,m+20,"3");
	break;
case '4':
	outtextxy(l+100,m+20,"4");
	break;
case '5':
	outtextxy(l+100,m+20,"5");
	break;
case '6':
	outtextxy(l+100,m+20,"6");
	break;
case '7':
	outtextxy(l+100,m+20,"7");
	break;
case '8':
	outtextxy(l+100,m+20,"8");
	break;
case '9':
	outtextxy(l+100,m+20,"9");
	break;
}
}
if(*rear==2)
{
bar3d(l+120,m,l2+120,m+40,1,0);
rectangle(l,m,l+40,m+40);
switch(c)
{
case '0':
	outtextxy(l+140,m+20,"0");
	break;
case '1':
	outtextxy(l+140,m+20,"1");
	break;
case '2':
	outtextxy(l+140,m+20,"2");
	break;
case '3':
	outtextxy(l+140,m+20,"3");
	break;
case '4':
	outtextxy(l+140,m+20,"4");
	break;
case '5':
	outtextxy(l+140,m+20,"5");
	break;
case '6':
	outtextxy(l+140,m+20,"6");
	break;
case '7':
	outtextxy(l+140,m+20,"7");
	break;
case '8':
	outtextxy(l+140,m+20,"8");
	break;
case '9':
	outtextxy(l+140,m+20,"9");
	break;
}
}
if(*rear==3)
{
bar3d(l+160,m,l2+160,m+40,1,0);
rectangle(l,m,l+40,m+40);
switch(c)
{
case '0':
	outtextxy(l+180,m+20,"0");
	break;
case '1':
	outtextxy(l+180,m+20,"1");
	break;
case '2':
	outtextxy(l+180,m+20,"2");
	break;
case '3':
	outtextxy(l+180,m+20,"3");
	break;
case '4':
	outtextxy(l+180,m+20,"4");
	break;
case '5':
	outtextxy(l+180,m+20,"5");
	break;
case '6':
	outtextxy(l+180,m+20,"6");
	break;
case '7':
	outtextxy(l+180,m+20,"7");
	break;
case '8':
	outtextxy(l+180,m+20,"8");
	break;
case '9':
	outtextxy(l+180,m+20,"9");
	break;
}
}
}

//delete from the queue

void deleteq(int *front)
{
int l=320,i,l2;
int m=170;
l2=l+40;
s[1]=4;
setcolor(LIGHTGREEN);
setfillstyle(SOLID_FILL,BLACK);
if(*front==0)
{
bar3d(l,m,l2,m+40,1,0);
rectangle(l,m,l+40,m+40);
}
if(*front==1)
{
bar3d(l+40,m,l2+40,m+40,1,0);
rectangle(l,m,l+40,m+40);
}
if(*front==2)
{
bar3d(l+80,m,l2+80,m+40,1,0);
rectangle(l,m,l+40,m+40);
}
if(*front==3)
{
bar3d(l+120,m,l2+120,m+40,1,0);
rectangle(l,m,l+40,m+40);
}
if(*front==4)
{
bar3d(l+160,m,l2+160,m+40,1,0);
rectangle(l,m,l+40,m+40);
}
}
