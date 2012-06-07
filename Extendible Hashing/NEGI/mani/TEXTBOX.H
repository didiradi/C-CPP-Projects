#include "C:\tc\student\header.h"


class TextBox
{
public:
	char *text;
	int ForeColor;
	int BackColor;
	int BorderColor;
	int x1,y1,x2,y2;
	int MaxSize;
	int TextFont;
	int TextSize;
	int xval[255];
	int yval[255];



TextBox(int xpos1,int ypos1,int xpos2,int ypos2,int forcolor,int backcolor,int bordercolor,int tsize,int tfont,int maxsize)
{

	x1=xpos1;
	y1=ypos1;
	x2=xpos2;
	y2=ypos2;
	BackColor=backcolor;
	ForeColor=forcolor;
	BorderColor=bordercolor;
	TextFont=tfont;
	TextSize=tsize;
	text='\0';
	MaxSize=maxsize;
}

void drawbox(int n)
{

	setfillstyle(1,BorderColor);
	bar(x1,y1,x2,y2);
	if(n==1)
	{
	BackColor=LIGHTCYAN;
	setfillstyle(1,BackColor);
	}
	else
	{
	BackColor=WHITE;
	setfillstyle(1,BackColor);
	}
	bar(x1+2,y1+2,x2-2,y2-2);
	settextstyle(TextFont,0,TextSize);
}
void move()
{
moveto(x1+5,y1+2);
}
int isUSN()
{
if(strlen(text)==11 && isdigit(text[0])&&isalpha(text[1])&&isalpha(text[2])&&isdigit(text[3])&&isdigit(text[4])&&isalpha(text[5])&&isalpha(text[6])&&isdigit(text[7])&&isdigit(text[8])&&isdigit(text[9]))
return 1;
else
return 0;
}

int isPIN()
{
if(strlen(text)==1)
{return 1;
}
if(strlen(text)==7 && isdigit(text[0])&&isdigit(text[1])&&isdigit(text[2])&&isdigit(text[3])&&isdigit(text[4])&&isdigit(text[5]))
	return 1;
else
	return 0;
}
int isSEM()
{
if(strlen(text)==1)
{
return 1;
}

if(strlen(text)==2 && isdigit(text[0]) && (text[0]=='1'||text[0]=='2'||text[0]=='3'||text[0]=='4'||text[0]=='5'||text[0]=='6'||text[0]=='7'||text[0]=='8'))
	return 1;
else
	return 0;
}

void newline();
void cursor(int on);
void getstring();
void putstring(char *t);
int isname();
int issem();
int isaddress();
int ispin();

};





int TextBox::isaddress()
{
for(int i=0;i<strlen(text);i++)
{
if(text[i]=='|')
return 0;
}
return 1;
}


int TextBox::isname()
{

for(int i=0;i<strlen(text);i++)
{
if(ispunct(text[i]) || isdigit(text[i]))
return 0;
}
return 1;
}

void TextBox::putstring(char *t)
{
outtextxy(x1+5,gety(),t);
}

void TextBox::cursor(int on)
{
int curx,oldcolor;

char uBarStr[2]={'_',0};
if(!on)
{
	oldcolor=ForeColor;
	setcolor(BackColor);
}
//save the horiz pos before drawing cursor
curx=getx();
outtext(uBarStr);
moveto(curx,gety());

//if changed the color to erase the cursor, change with back color
if(!on)
setcolor(oldcolor);
}


void TextBox::newline()
{
moveto(0,gety()+textheight("A"));
}

void TextBox::getstring()
{
int stringindex=0,oldcolor;
char ch,outstring[2];
text=0;
settextstyle(TextFont,0,TextSize);
int xval[255];

outstring[1]=0;
xval[0]=getx();
sound(600);
delay(50);
nosound();

do
{

cursor(1);
ch=getch();
cursor(0);

if(ch==0)
	getch();
else
{
	if(ch==8)
	{
		sound(400);
		delay(50);
		nosound();

		--stringindex;
		if(stringindex<0)
			stringindex=0;

		moveto(xval[stringindex],gety());
		setcolor(BackColor);
		outstring[0]=text[stringindex];
		outtext(outstring);
		moveto(xval[stringindex],gety());
		setcolor(ForeColor*rand());
	}

	else if(ch==0x1b)
	{
		sound(500);
		delay(50);
		nosound();

		goto end;
	}
	else
	{
		sound(200);
		delay(50);
		nosound();

		setcolor(ForeColor);
		if(islower(ch))
			{
			text[stringindex]=toupper(ch);
			outstring[0]=toupper(ch);
			}
		else
			{
			text[stringindex]=ch;
			outstring[0]=ch;
			}
		outtext(outstring);
		++stringindex;
		xval[stringindex]=getx();

	}
      }
}

while(ch!=13&&ch!=10&&stringindex<=MaxSize);
end:
text[stringindex]=0;
}




TextBox usn(200,100,getmaxx()-100,120,1,WHITE,LIGHTGRAY,5,2,11);
TextBox fname(200,130,getmaxx()-100,150,1,WHITE,LIGHTGRAY,5,2,40);
TextBox lname(200,160,getmaxx()-100,180,1,WHITE,LIGHTGRAY,5,2,41);
TextBox address(200,190,getmaxx()-100,210,1,WHITE,LIGHTGRAY,5,2,41);
TextBox sem(200,220,getmaxx()-100,240,1,WHITE,LIGHTGRAY,5,2,25);
TextBox branch(200,250,getmaxx()-100,270,1,WHITE,LIGHTGRAY,5,2,7);
TextBox college(200,280,getmaxx()-100,300,1,WHITE,LIGHTGRAY,5,2,2);
