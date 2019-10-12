//student.cpp to implement your classes
#include "student.hpp"
#include <iostream>

//ToeflScore constructor
ToeflScore::ToeflScore(int read, int write, int listen, int speak)
{
  //Error checking to make sure the values are in range
  if(read <0 || read > 30)
  {
          cout << "Reading toeflScore is invalid, setting value to zero\n";
          reading = 0;
  }
  else
  {
          reading = read;
  }
  if(write <0 || write > 30)
  {
          cout << "Writing toeflScore is invalid, setting value to zero\n";
          writing = 0;
  }
  else
  {
          writing = write;
  }
  if(listen <0 || listen > 30)
  {
          cout << "Listening toeflScore is invalid, setting value to zero\n";
          listening = 0;
  }
  else
  {
          listening = listen;
  }
  if(speak <0 || speak > 30)
  {
          cout << "Speaking toeflScore is invalid, setting value to zero\n";
          speaking = 0;
  }
  else
  {
          speaking = speak;
  }
  totalscore = reading + writing + listening + speaking;
}
ToeflScore::ToeflScore()
{
        reading = 0;
        writing = 0;
        listening = 0;
        speaking = 0;
        totalscore = 0;
}
//Below are the mutator functions for the ToeflScore class
//Below are the mutator functions for the ToeflScore class
void ToeflScore::setreading(int read)
{
        if(read <0 || read > 30)
        {
                cout << "Reading toeflScore is invalid, setting value to zero\n";
                reading = 0;
        }
        else
        {
                reading = read;
        }
}
void ToeflScore::setwriting(int write)
{
        if(read <0 || read > 30)
        {
          cout << "Reading toeflScore is invalid, setting value to zero\n";
          reading = 0;
  }
  else
  {
          reading = read;
  }
}
void ToeflScore::setlistening(int listen)
{
  if(read <0 || read > 30)
  {
          cout << "Reading toeflScore is invalid, setting value to zero\n";
          reading = 0;
  }
  else
  {
          reading = read;
  }
}
void ToeflScore::setspeaking(int speak)
{
  if(read <0 || read > 30)
  {
          cout << "Reading toeflScore is invalid, setting value to zero\n";
          reading = 0;
  }
  else
  {
          reading = read;
  }
}
void ToeflScore::settotalscore()
{
        totalscore = reading + writing + listening + speaking;
}
//Below are the accessor functions for the ToeflScore class
int ToeflScore::getreading() const
{
        return(reading);
}
int ToeflScore::getwriting() const
{
        return(writing);
}
int ToeflScore::getlistening() const
{
        return(listening);
}
int ToeflScore::getspeaking() const
{
        return(speaking);
}
int ToeflScore::gettotalscore() const
{
        return(totalscore);
}

//Student constructor
STUDENT::STUDENT(string first, string last, float cgpa, int score, int id)
{
        //Error checking, making sure that the proper values are in range
        if(cgpa > 4.3 || cgpa < 0)
        {
                cout<<"sorry, but your CGPA is invalid";
        }
        if(score < 0 || score > 100)
        {
                cout<<"sorry, but your research score is invalid";
        }
        fname = first;
        lname = last;
        CGPA = cgpa;
        SCORE = score;
        ID = id;
}
STUDENT::STUDENT()
{
        fname = " ";
        lname = " ";
        CGPA = 0.0;
        SCORE = 0;
        ID = 0;
}
//Below are the mutator funtions for the Student class
void STUDENT::setfname(string first)
{
        fname = first;
}
void STUDENT::setlname(string last)
{
        lname = last;
}
void STUDENT::setCGPA(float cgpa)
{
        if(cgpa > 4.3 || cgpa < 0)
        {
                cout<<"CGPA value is invalid, setting value to zero";
                CGPA = 0.0;
        }
        else
        {
                CGPA = cgpa;
        }
}
void STUDENT::setscore(int score)
{
        if(score < 0 || score > 100)
        {
                cout<<"Research score is invalid, setting value to zero";
                SCORE = 0;
        }
        else
        {
                SCORE = score;
        }
}
void STUDENT::setID(int id)
{
        ID = id;
}
//Below are the accessor functions for the Student class
string STUDENT::getfname() const
{
        return(fname);
}
string STUDENT::getlname() const
{
        return(lname);
}
float STUDENT::getCGPA() const
{
        return(CGPA);
}
int STUDENT::getscore() const
{
        return(SCORE);
}
int STUDENT::getID() const
{
        return(ID);
}
//Constructor for the DomesticStudent class
DomesticStudent::DomesticStudent(string first, string last, float cgpa, int score, int id, string pv):
        STUDENT(first, last, cgpa, score, id)
{
        province = pv;
}
DomesticStudent::DomesticStudent():STUDENT()
{
        province = " ";
}
//Mutator function for DomesticStudent, it inherits all of the mutator functions in its parent class Student
void DomesticStudent::setprovince(string pv)
{
        province = pv;
}
//Accessor function for DomesticStudent
string DomesticStudent::getprovince() const
{
        return(province);
}

ostream& operator <<(ostream& outs, const DomesticStudent& p)
{
        outs << "Domestic student" << " " << p.getfname() << " "
	 << p.getlname() << " from " << p.getprovince() << " province has cgpa of "
	 << p.getCGPA() << ", and research score of " << p.getscore() << ", the assigned ID is "
	 << p.getID() << endl;
}
//Constructor for the InternationalStudent class
InternationalStudent::InternationalStudent(string first, string last, float cgpa, int score, int id, string co, int read, int write , int listen, int speak):
        STUDENT(first, last, cgpa, score, id)
{
        country = co;
        //Since TOEFL is a seperate object of a different class, we will have to use the ToeflScore mutator functions
        TOEFL.setreading(read);
        TOEFL.setwriting(write);
        TOEFL.setlistening(listen);
        TOEFL.setspeaking(speak);
}
InternationalStudent::InternationalStudent():STUDENT(), country(""){ }
//Mutator functions for the InternationalStudent class
void InternationalStudent::setcountry(string co)
{
        country = co;
}
//This mutator function need call on the TOEFL private members, so ToeflScore's mutator functions are used
void InternationalStudent::settoefl(int read, int write, int listen, int speak)
{
        TOEFL.setreading(read);
        TOEFL.setwriting(write);
        TOEFL.setlistening(listen);
        TOEFL.setspeaking(speak);
        TOEFL.settotalscore();
}
//As the same situation as above, to access the values of the TOEFL object, ToeflScore's accessor functions are used in these accessor functions
int InternationalStudent::gettoeflread() const
{
        return TOEFL.getreading();
}
int InternationalStudent::gettoeflwrite() const
{
        return TOEFL.getwriting();
}
int InternationalStudent::gettoefllisten() const
{
        return TOEFL.getlistening();
}
int InternationalStudent::gettoeflspeak() const
{
        return TOEFL.getspeaking();
}
int InternationalStudent::gettotal() const
{
        return TOEFL.gettotalscore();
}
//Accessor Functions for the InternationalStudent class
string InternationalStudent::getcountry() const
{
        return(country);
}
ostream& operator <<(ostream& outs, const InternationalStudent& p)
{
	outs << "International student" << " " << p.getfname() << " "
	 << p.getlname() << " from " << p.getcountry() << " country has cgpa of "
	 << p.getCGPA() << ", and research score of " << p.getscore()
	 << ", the assigned ID is " << p.getID() << ", their toefl scores are: reading "
	 << p.gettoeflread() << ", writing "<< p.gettoeflwrite() << ", listening "
	 << p.gettoefllisten() << ", speaking " << p.gettoeflspeak() << ", and their total toefl score is "
	 << p.gettotal() <<endl;
}

string compareCGPA(const STUDENT& overallgpa1, const STUDENT& overallgpa2)
{
        STUDENT result1,result2;
        result1.CGPA = overallgpa1.CGPA;
        result2.CGPA = overallgpa2.CGPA;
        if (result1.CGPA < result2.CGPA)
        {
                return "less";
        }
        else if (result1.CGPA > result2.CGPA)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
string compareResearchScore(const STUDENT& overallscore1, const STUDENT& overallscore2)
{
        STUDENT result1,result2;
        result1.SCORE = overallscore1.SCORE;
        result2.SCORE = overallscore2.SCORE;
        if (result1.SCORE < result2.SCORE)
        {
                return "less";
        }
        else if (result1.SCORE > result2.SCORE)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
string compareFirstName(const STUDENT& overallfname1, const STUDENT& overallfname2)
{
        STUDENT result1,result2;
        result1.fname = overallfname1.fname;
        result2.fname = overallfname2.fname;
        if (result1.fname < result2.fname)
        {
                return "less";
        }
        else if (result1.fname > result2.fname)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
string compareLastName(const STUDENT& overalllname1, const STUDENT& overalllname2)
{
        STUDENT result1,result2;
        result1.lname = overalllname1.lname;
        result2.lname = overalllname2.lname;
        if (result1.lname< result2.lname)
        {
                return "less";
        }
        else if (result1.lname > result2.lname)
        {
                return "greater";
        }
        else
        {
                return "equal";
        }
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void bubblesort_CGPA(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);
}
