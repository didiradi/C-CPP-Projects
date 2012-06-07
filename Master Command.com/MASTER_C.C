#include<stdio.h>
#include<process.h>
#include<conio.h>
#include<string.h>
void frame1();
void mainframe();
void frame2();
void frameabout();
void findreplace(char *s1,char *s2);
void mani();
FILE *fp;
void main()
{
int c;
clrscr();
frame1();
c=getch();
if(c==27)
{
	exit(1);
}
else
{
	clrscr();
	mainframe();
}
getche();
}



void frame2()
{
int d;
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                            Master Command.com                               บ");
cprintf(" บ                                                         บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ    This program can change your DOS commands, if you are interested in      บ");
cprintf(" บ    doing so please go through the following carefully.                      บ");
cprintf(" บ                                                                             บ");
cprintf(" บ 1 . As your DOS commands are part of commamd.com, in order to change these  บ");
cprintf(" บ     commands the entire command.com will be changed.                        บ");
cprintf(" บ                                                                             บ");
cprintf(" บ 2.  Make sure that you know DOS and type the valid command only.            บ");
cprintf(" บ                                                                             บ");
cprintf(" บ 3.  If you try to change any command that doesn't exist, make a point clear บ");
cprintf(" บ     that you are going to commit big mistake.                               บ");
cprintf(" บ                                                                             บ");
cprintf(" บ 4.  Before proceeding please be sure that you are having bootable floppy.   บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                        Press any key to continue                            บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
d=getch();
if(d!=27)
{
mainframe();
}
}

void mani()
{
int ch=1;
char original[9],newcom[9];
textbackground(RED);
textcolor(WHITE);
_setcursortype(1);

loop:
while(ch)
{
		fp=fopen("C:\\windows\\command.com","rb+");
		clrscr();
		if(fp==NULL)
		{
		fp=fopen("c:\\command.com","rb+");
		clrscr();
		if(fp==NULL)
		{
		fp=fopen("c:\\windows\\system32\\command.com","rb+");
		clrscr();
		if(fp==NULL)
		{
		puts("Error opening file");
		puts("\nPress any key to exit");
		getche();
		exit(0);
		}
		}
		}
		gotoxy(100,200);
		printf("\n\n\nEnter the Dos command to change ?( For ex.  DIR )\n\n");
		scanf("%s",original);
		gotoxy(100,210);
		printf("\nEnter the new command name of the same length \n\n");
		scanf("%s",newcom);
		if(strlen(original)!=strlen(newcom))
		{
		printf("\tEnter an alternative of same length\n");
		delay(100);
		goto loop;
		}
		strupr(original);
		strupr(newcom);
		findreplace(original,newcom);
		fclose(fp);
gotoxy(200,300);
printf("\nDo you want to change other commands ?\n\nPress 1 or 0 \n");
scanf("%d",&ch);
}
}
void findreplace(char *s1,char *s2)
{
int length,flag=0,i;
char temp[25];

length=strlen(s1);
while(fread(temp,length,1,fp)!=0)
{
temp[length]='\0';
if(strcmp(temp,s1)==0)
{
fseek(fp,-(long)length,SEEK_CUR);
fwrite(s2,length,1,fp);
flag=1;
}

fseek(fp,-(long)(length-1),SEEK_CUR);
}
if(flag==1)
{
printf("\n\n\t\tPlease wait changing your command");
printf("\n\n\t\t");
for(i=0;i<33;i++)
{
printf("|");
delay(50);
}
printf("\n\n\tCommand changed from %s to %s",s1,s2);
printf("\n\tNow restart your system to see the changes\n");
}
else
printf("\n\tNo Such DOS Command\n\n");
}

void frame1()
{
textbackground(BLACK);
textcolor(RED);
_setcursortype(0);
clrscr();
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      ****************************************************************       บ");
cprintf(" บ      *                                                              *       บ");
cprintf(" บ      *                  Master Your Command.com                     *       บ");
cprintf(" บ      *                                                              *       บ");
cprintf(" บ      ****************************************************************       บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                        Press any key to continue                            บ");
cprintf(" บ                                Esc To Exit                                  บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                               DEVELOPED BY                                  บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                            MANOHAR SINGH NEGI                               บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
}



void mainframe()
{
char d;
textbackground(BLACK);
textcolor(RED);
_setcursortype(0);
clrscr();
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                        Master COMMAND.COM ver 1.0                           บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                            It's a KVSM Product                              บ");
cprintf(" บ                        -----------------------------                        บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                 1. Change Commands                                          บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                 2. Help                                                     บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                 3. About                                                    บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                 4. Exit                                                     บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                 press any key(1,2,3,4)      บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                               DEVELOPED BY                                  บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                            MANOHAR SINGH NEGI                               บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
scanf("%c",&d);
switch(d)
{
case '1':
	mani();
	mainframe();
	break;
case '2':
	frame2();
	break;
case '3':
	frameabout();
	break;
case '4':
	exit(1);
default:
	clrscr();
	cprintf("Please enter the valid choice");
	delay(300);
	mainframe();
}
}

void frameabout()
{
int d;
textbackground(BLACK);
textcolor(RED);
_setcursortype(0);
clrscr();
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ      ****************************************************************       บ");
cprintf(" บ      *                                                              *       บ");
cprintf(" บ      *                  Master Your Command.com                     *       บ");
cprintf(" บ      *                                                              *       บ");
cprintf(" บ      ****************************************************************       บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      OS Platform        : windows 98/2000/xp                                บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      Language Used      : C                                                 บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      Ver                : 1.0                                               บ");
cprintf(" บ                                                                             บ");
cprintf(" บ      Dated              : 23-12-2003                                        บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
cprintf(" ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
cprintf(" บ                               DEVELOPED BY                                  บ");
cprintf(" บ                                                                             บ");
cprintf(" บ                            MANOHAR SINGH NEGI                               บ");
cprintf(" บ                            Information Science Engg.                        บ");
cprintf(" บ                            R.V. College Of Engineering                      บ");
cprintf(" บ                            Bangalore-59                                     บ");
cprintf(" ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");
d=getch();
if(d!=27)
{
mainframe();
}

}
