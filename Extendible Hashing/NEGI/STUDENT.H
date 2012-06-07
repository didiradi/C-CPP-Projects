#include "C:\NEGI\delim.cpp"
class Student{
  public:
     char URN[11];char Lname[11];char Fname[21];char Address[50];
     char Semester[4];char Branch[4];char College[14];

     Student();
     static int InitBuffer (DelimFieldBuffer &);
     void Clear ();
     int Unpack (IOBuffer &);
     int Pack (IOBuffer &) const;
     void Print (ostream &, char *label = 0) const;
     int Search(char *);
     int Append(char *);
     int Write(char *,int Adrr);
};
