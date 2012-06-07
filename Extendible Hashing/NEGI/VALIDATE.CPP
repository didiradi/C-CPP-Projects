#include<string.h>
#include<ctype.h>


#define ESC	0x1b			/* Define the escape key	*/

void print(int x,int y,char *stt);

void input(int x,int y,char *stt,char *type,char *max,char *length,int insist)
{
	int i,j,f,l;
	if(!(l=strlen(stt)))
	l=1;
	*stt=NULL;
	while(*stt==NULL)
	{
		  strncat(stt,"                    ",l);
		  print(x,y,stt);
		  gotoxy(x,y);
		  setcolor(BLUE);
		  cout<<"_ ";
		  gotoxy(x,y);
		  strupr(gets(stt));
		  print(24,28,"                                                       ");

		  if(stt[0]==ESC)
		  {
		  return;
		  }

		  if(*stt==NULL)

		  {
			print(24,28,"THE FIELD CANNOT BE NULL:");


		  }
		  j=strlen(stt);
		  f=0;
		  for(i=0;i<j;i++)
		  {
			    if(!strcmp(type,"digit"))
			    {
				if(!isdigit(stt[i]))
				{
				     print(24,28,"THE FIELD SHOULD CONTAIN ONLY DIGITS");
				     f=1;
				     break;
				}
			    }
			    else
			     if(!strcmp(type,"alphabetic"))
			     {
				if(!isalpha(stt[i]))
				{
					print(24,28,"THE FIELD SHOULD CONTAIN ALPHABET ONLY");
					f=1;
					break;
				}

			     }
			    else
			    if(!strcmp(type,"alphanumeric"))
			    {
				     if(!isalnum(stt[i])&&!isspace(stt[i])&&stt[i]!='-'&&stt[i]!=','||stt[i]=='#'||stt[i]=='|')
				     {
					print(24,28,"THE FIELD SHOULDN'T CONTAIN '#'AND '|'");
					f=1;
					break;
				     }
			   }
	    }

  if((type[0]=='d')&& (atoi(stt)>atoi(max) || atoi(stt)<1))
  {
	   print(24,28,"THE VALUE SHOULD BE IN RANGE 1 TO  ");
	   print(66,28,max);
	   f=1;
   }
  l=strlen(stt);

  if(atoi(length)<l && atoi(length)!=0 )
  {
	    print(24,28,"SHOULD NOT EXCEED MAXIMUM LENGTH:");
	    print(66,28,length);
	    f=1;
  }
   else
    if(atoi(length)!=l && insist)
   {
	    print(24,28,"SHOULD BE EQUAL TO MAXIMUM LENGTH:");
	    print(66,28,length);
	    f=1;
    }

  if(f)
      *stt=NULL;

  }
}





void input(int x,int y,char *stt,char *type)
{
	int i,j,f,l;
	 if(!(l=strlen(stt)))
	    l=1;
	 *stt=NULL;
	 while(*stt==NULL)
	 {
		strncat(stt,"                    ",l);
	  print(x,y,stt);
	  gotoxy(x,y);
	  cout<<"_ ";
	  gotoxy(x,y);
	  strupr(gets(stt));
	  print(24,25,"                                                    ");

	  if(stt[0]==ESC)
		  {
		  return;
		  }


	  if(*stt==NULL)
	  {
	    print(24,28,"THE FIELD CANNOT BE NULL:");
	  }
	  j=strlen(stt);
	  f=0;
	  for(i=0;i<j;i++)
	  {
	    if(!strcmp(type,"digit"))
	     {
		if(!isdigit(stt[i]))
		{
		       print(24,28,"THE FIELD SHOULD CONTAIN ONLY DIGITS");
			f=1;
			break;
		}
	     }
	     else
	     if(!strcmp(type,"alphabetic"))
		{
		      if(!isalpha(stt[i]))
		       {
			  print(24,28,"THE FIELD SHOULD CONTAIN ONLY ALPHABETS");
			  f=1;
			  break;
			}
		}
	      else
		if(!strcmp(type,"alphanumeric"))
		{
			//if(!isalnum(stt[i])||stt[i]=='#'||stt[i]=='|')
			if(!isalnum(stt[i])&&!isspace(stt[i])&&stt[i]!='-'&&stt[i]!=','||stt[i]=='#'||stt[i]=='|')
			{
				print(24,28,"THE FIELD SHOULD CONTAIN ALPHABET,DIGITS ");
				f=1;
				break;
			}
		 }
	  }
	l=strlen(stt);
	  if(f)
	      *stt=NULL;
   }
}

void print(int x,int y,char *stt)
{
textcolor(RED);
 gotoxy(x,y);
 puts(stt);
 }