
class screen
{

public:

int wx1,wy1,wx2,wy2;//for full window
int tx1,ty1,tx2,ty2;//for titlebar
int mx1,my1,mx2,my2;//for menubar
int sx1,sy1,sx2,sy2;//for status bar
//DRAW THE GRAPHICS SCREEN
screen(int x1,int y1,int x2,int y2)
//screen(0,0,getmaxx(),getmaxy())
{
wx1=x1;//initiailize cordinates of the screen
wy1=y1;
wx2=x2;
wy2=y2;

tx1=x1+2;
ty1=y1+2;
tx2=x2-2;
ty2=tx1+22;

mx1=tx1;
my1=ty2;
mx2=tx2;
my2=my1+20;

sx1=mx1;
sy1=wy2-35;
sx2=mx2;
sy2=wy2-2;

DrawScreen();
DrawTitleBar();
DrawMenuBar();
DrawCloseButton();
DrawHelpButton();
DrawApplIcon();
DrawMenus(5,0);
}

void DrawAll()
{
DrawTitleBar();
DrawMenuBar();
DrawCloseButton();
DrawHelpButton();
DrawApplIcon();
}


void DrawScreen()
{

setcolor(WHITE);
setbkcolor(BLACK);
//DRAW EXTREME BORDERS
setfillstyle(SOLID_FILL,BLUE);
bar(wx1,wy1,wx2,wy2);
setfillstyle(SOLID_FILL,RED);
bar(wx1+1,wy1+1,wx2-1,wy2-1);
//DRAW THE INNER RECTANGLE
setfillstyle(SOLID_FILL,0);
bar(wx1+2,wy1+2,wx2-2,wy2-2);
}


void DrawTitleBar()
{
//DRAW THE TITLE BAR
setfillstyle(SOLID_FILL,BLUE);
bar(tx1,ty1,tx2,ty2);
}

void DrawApplIcon()
{
setfillstyle(7,7);
fillellipse(((ty2-ty1)-4),((ty2+ty1)/2-1),((ty2+ty1)/2)-5,((ty2+ty1)/2)-4);
}

void DrawMenuBar()
{
//DRAW THE MENU BAR
setfillstyle(SOLID_FILL,RED);
bar(mx1,my1,mx2,my2);
setfillstyle(SOLID_FILL,LIGHTGRAY);
bar(mx1,my1,mx2,my2);
}



void DrawCloseButton()
{
//DRAW CLOSE BUTTON
 setfillstyle(SOLID_FILL,WHITE);
 bar(wx2-19,wy1+6,wx2-6,wy1+19);
 setfillstyle(SOLID_FILL,1);
 bar(wx2-18,wy1+7,wx2-7,wy1+18);
 setcolor(3);
 settextstyle(0,0,1);
 outtextxy(wx2-15,wy1+10,"X");

 }

void DrawHelpButton()
{
//DRAW HELP BUTTON
 setfillstyle(SOLID_FILL,WHITE);
 bar(wx2-26,wy1+6,wx2-39,wy1+19);
 setfillstyle(SOLID_FILL,1);
 bar(wx2-27,wy1+7,wx2-38,wy1+18);
 setcolor(3);
 settextstyle(0,0,1);
 outtextxy(wx2-36,wy1+10,"?");
}

 };
