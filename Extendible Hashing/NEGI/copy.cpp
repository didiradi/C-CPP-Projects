Student copy(Student g,Student s)
{         strcpy(g.URN,s.URN);
	  strcpy(g.Lname,s.Lname);
	  strcpy(g.Fname,s.Fname);
	  strcpy(g.Address,s.Address);
	  strcpy(g.Semester,s.Semester);
	  strcpy(g.Branch,s.Branch);
	  strcpy(g.College,s.College);
	  return g;
	  }