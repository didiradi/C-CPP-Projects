union REGS i,o;

/* mouse initialise */
initmouse()
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