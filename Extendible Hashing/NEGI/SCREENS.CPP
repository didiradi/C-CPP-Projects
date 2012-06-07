void printcolumnheaders();

void printfields()
{   int xc=15;
    print(xc,6,"STUDENT REGNO   ");
    print(xc,8,"FIRST NAME      ");
    print(xc,10,"LAST NAME       ");
    print(xc,12,"ADDRESS         ");
    print(xc,14,"SEMESTER        ");
    print(xc,16,"BRANCH          ");
    print(xc,18,"COLLEGE         ");
}

void printvalues(Student s)
{int  xc=32;
    print(xc,6,s.URN);
    print(xc,8,s.Fname);
    print(xc,10,s.Lname);
    print(xc,12,s.Address);
    print(xc,14,s.Semester);
    print(xc,16,s.Branch);
    print(xc,18,s.College);
 }


void printcolumnheaders()
{

 setcolor(RED);
 print(2,5,"REG NO   ");
 print(13,5,"FIRSTNAME");
 print(23,5,"LASTNAME");
 print(37,5,"ADDRESS             ");
 print(61,5,"SEM");
 print(65,5,"BRANCH");
 print(72,5,"COLLEGE");
 }

 void printstudentrecord(Student s,int cur)
 {
 setcolor(BLUE);

  print(2,cur,s.URN);
  print(13,cur,s.Fname);
  print(23,cur,s.Lname);
  print(37,cur,s.Address);
  print(62,cur,s.Semester);
  print(66,cur,s.Branch);
  print(73,cur,s.College);

 }
