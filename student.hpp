//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#pragma once

class ToeflScore
{
public:
        ToeflScore(int read, int write, int listen, int speak);
        ToeflScore();
        void setreading(int read);
        void setwriting(int write);
        void setlistening(int listen);
        void setspeaking(int speak);
        void settotalscore();
        int getreading() const;
        int getwriting() const;
        int getlistening() const;
        int getspeaking() const;
        int gettotalscore() const;

private:
        int reading;
        int writing;
        int listening;
        int speaking;
        int totalscore;
};

class STUDENT
{
public:
  STUDENT(string first, string last, float cgpa, int score, int id);
  STUDENT();
  void setfname(string);
  void setlname(string);
  void setCGPA(float);
  void setscore(int);
  void setID(int);
  string getfname() const;
  string getlname() const;
  float getCGPA() const;
  int getscore() const;
  int getID() const;

  friend string compareCGPA(STUDENT, STUDENT);
  friend string compareResearchScore(STUDENT overallscore1, STUDENT overallscore2);
  friend string compareFirstName(STUDENT, STUDENT);
  friend string compareLastName(STUDENT overalllname1, STUDENT overalllname2);

  friend void swap(STUDENT*, STUDENT*);
  friend void bubblesort_CGPA(STUDENT*, int);
  friend void bubblesort_ResearchScore(STUDENT*, int);
  friend void bubblesort_FirstName(STUDENT*, int);
  friend void bubblesort_LastName(STUDENT*, int);

private:
        string fname;//first name
        string lname;//last name
        float CGPA;//GPA
        int SCORE;//research score
        int ID;//id
};

class DomesticStudent : public STUDENT
{
public:
        //Constructors
        DomesticStudent(string first, string last, float cgpa, int score, int id, string pv);
        DomesticStudent();
        //Mutator functions
        void setprovince(string pv);
        //Accessor functions
        string getprovince() const;
        friend void domesticOverallSort(DomesticStudent *arr, int n);
        friend string compareProvince(DomesticStudent, DomesticStudent);
        friend ostream& operator<<(ostream& outs, const DomesticStudent& dstu);
private:
        string province;
};


class InternationalStudent : public STUDENT
{
public:
        //Constructors for InternationalStudent
        InternationalStudent(string first, string last, float cgpa, int score, int id, string co, int read, int write , int listen, int speak);
        InternationalStudent();
        //Mutator functions
        void setcountry(string co);
        void settoefl(int read, int write, int listen, int speak);
        //Accessor functions
        string getcountry() const;
        int gettoeflread() const;
        int gettoeflwrite() const;
        int gettoefllisten() const;
        int gettoeflspeak() const;
        int gettotal() const;

        friend void internationalOverallSort(InternationalStudent *arr, int n);
        friend void deleteElement(InternationalStudent, int, int);
        friend string compareCountry(InternationalStudent, InternationalStudent);
        friend ostream& operator<<(ostream& outs, const InternationalStudent& istu);

private:
        string country;
        ToeflScore TOEFL;
};
