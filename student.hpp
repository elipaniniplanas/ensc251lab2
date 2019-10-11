//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#pragma once

class ToeflScore
{
public:
        ToeflScore(int read, int write, int listen, int speak);
        //Constructor function for ToeflScore
        ToeflScore();
        //Other Constructor for ToeflScore (blank inputs, sets 0 for all members)
        void setreading(int read);
        //This is the mutator function for the reading score
        void setwriting(int write);
        //This is the mutator function for the writing score
        void setlistening(int listen);
        //This is the mutator function for the listening score
        void setspeaking(int speak);
        //This is the mutator function for the speaking score
        void settotalscore();
        //This is the mutator function for the sum of all of the scores in an object
        int getreading() const;
        //This is the accessor function for the reading score
        int getwriting() const;
        //This is the accessor function for the writing score
        int getlistening() const;
        //This is the accessor function for the listening score
        int getspeaking() const;
        //This is the accessor function for the speaking score
        int gettotalscore() const;
        //This is the accessor function for the sum of all of the scores in an object

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
        //This is the constructor function
        STUDENT();
        //here
        void setfname(string first);
        //This is the mutator function for first name (takes datatype string for input)
        void setlname(string last);
        //This is the mutator function for last name (takes datatype string for input)
        void setCGPA(float cgpa);
        //This is the mutator function for gpa (takes datatype float for input)
        void setscore(int score);
        //This is the mutator function for the research-score (takes datatype int for input)
        void setID(int id);
        //This is the mutator function for id (takes datatype int for input)
        string getfname() const;
        //This is the accessor function for first name (returns a string datatype)
        string getlname() const;
        //This is the accessor function for last name (returns a string datatype)
        float getCGPA() const;
        //This is the accessor function for gpa (returns a float datatype)
        int getscore() const;
        //This is the accessor function for gpa (returns an int datatype)
        int getID() const;
        //This is the accessor function for id (returns an int datatype)
        friend string compareCGPA(const STUDENT&,const STUDENT&);
        friend string compareResearchScore(const STUDENT&,const STUDENT&);
        friend string compareFirstName(const STUDENT&,const STUDENT&);
        friend string compareLastName(const STUDENT&,const STUDENT&);
        friend void bubblesort(const STUDENT&,const STUDENT&);

private:
        string fname;//first name
        string lname;//last name
        float CGPA;//GPA
        int SCORE;//research score
        int ID;//id
        //the id value will be set in the main.cpp
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
        friend ostream& operator <<(ostream& outs,  DomesticStudent& p);
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
        //Accessor functions
        string getcountry(); 
        //gets toefl value from Toeflscore class
        void settoefl(int read, int write, int listen, int speak);
        //outputs toefl values and total
        int gettoeflread() const;
        int gettoeflwrite() const;
        int gettoefllisten() const;
        int gettoeflspeak() const;
        int gettotal(); const
        
private:
        string country;
        ToeflScore TOEFL;
};
