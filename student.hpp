//header file student.hpp to declare your classes
using namespace std; //use namespace std
#include <string> //you will have to use string in C++
#include <iostream>
#pragma once

class ToeflScore
{
public:
        // Constructors
        ToeflScore(int read, int write, int listen, int speak);
        ToeflScore();
        // Mutator functions
        void setreading(int read);
        void setwriting(int write);
        void setlistening(int listen);
        void setspeaking(int speak);
        void settotalscore();
        // Accessor functions
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
  // Constructor
  STUDENT(string first, string last, float cgpa, int score, int id);
  STUDENT();
  // Mutator functions
  void setfname(string);
  void setlname(string);
  void setCGPA(float);
  void setscore(int);
  void setID(int);
  //Accessor functions
  string getfname() const;
  string getlname() const;
  float getCGPA() const;
  int getscore() const;
  int getID() const;
  // Friend Functions
  friend string compareCGPA(STUDENT, STUDENT);
  /*Input: two student objects
    Output: a string saying if the first object's CGPA member variable is greater, equal, or less than the second object's*/
  friend string compareResearchScore(STUDENT overallscore1, STUDENT overallscore2);
  /*Input: two student objects
    Output: a string saying if the first object's ResearchScore member variable is greater, equal, or less than the second object's*/
  friend string compareFirstName(STUDENT, STUDENT);
  /*Input: two student objects
    Output: a string saying if the first object's fname member variable comes first in the alphabet from the second object's*/
  friend string compareLastName(STUDENT overalllname1, STUDENT overalllname2);
  /*Input: two student objects
    Output: a string saying if the first object's lname member variable comes first in the alphabet from the second object's*/

private:
        string fname;
        string lname;
        float CGPA;
        int SCORE;
        int ID;
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
        // Friend functions
        friend void Dswap(DomesticStudent*, DomesticStudent*);
        /*Input: Pointer to two objects of DomesticStudents type
          Output: Causes the pointers to switch addresses */
        friend void deleteDelement(InternationalStudent *arr, int n, int k);
        /*Input: Pointer to array of objects of DomesticStudents type, size of array, position of element to be deleted
          Output: Causes the pointers to switch addresses */
        friend void domesticOverallSort(DomesticStudent *arr, int n);
        /*Input: Pointer to an array of DomesticStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in the format step 5 of lab2 states */
        friend string compareProvince(DomesticStudent, DomesticStudent);
        /*Input: two DomesticStudent objects objects
          Output: a string saying if the first object's Province member variable comes first in the alphabet from the second object's*/
        friend void Dbubblesort_CGPA(DomesticStudent*, int);
        /*Input: Pointer to an array of DomesticStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in descending order of the value of the CGPA member variable */
        friend void Dbubblesort_ResearchScore(DomesticStudent*, int);
        /*Input: Pointer to an array of DomesticStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in descending order of the value of the ResearchScore member variable */
        friend void Dbubblesort_FirstName(DomesticStudent*, int);
        /*Input: Pointer to an array of DomesticStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in alphabetical order of the fname member variable */
        friend void Dbubblesort_LastName(DomesticStudent *arr , int n);
        /*Input: Pointer to an array of DomesticStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in alphabetical order of the lname member variable */
        friend ostream& operator<<(ostream& outs, const DomesticStudent& dstu);
        //overload the << (output) operator to allow a pre-set format of outputing the member variables of a DomesticStudent object to a ostream
private:
        string province;
};


class InternationalStudent : public STUDENT
{
public:
        //Constructors
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
        // Friend functions
        friend void Iswap(InternationalStudent*, InternationalStudent*);
        /*Input: Pointer to two objects of InternationalStudents type
          Output: Causes the pointers to switch addresses */
        friend void deleteIelement(InternationalStudent, int, int);
        /*Input: Pointer to array of objects of InternationalStudent type, size of array, position of element to be deleted
          Output: Causes the pointers to switch addresses */
        friend void internationalOverallSort(InternationalStudent *arr, int n);
        /*Input: Pointer to an array of InternationalStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in the format step 5 of lab2 states */
        friend string compareCountry(InternationalStudent, InternationalStudent);
        /*Input: two InternationalStudent objects
          Output: a string saying if the first object's Country member variable comes first in the alphabet from the second object's*/
        friend void Ibubblesort_CGPA(InternationalStudent*, int);
        /*Input: Pointer to an array of InternationalStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in descending order of the value of the CGPA member variable */
        friend void Ibubblesort_ResearchScore(InternationalStudent*, int);
        /*Input: Pointer to an array of InternationalStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in descending order of the value of the ResearchScore member variable */
        friend void Ibubblesort_FirstName(InternationalStudent*, int);
        /*Input: Pointer to an array of InternationalStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in alphabetical order of the fname member variable */
        friend void Ibubblesort_LastName(InternationalStudent *arr , int n);
        /*Input: Pointer to an array of InternationalStudents and the number of elements in the array
          Output: Causes the pointed array to be sorted in alphabetical order of the lname member variable */
        friend ostream& operator<<(ostream& outs, const InternationalStudent& istu);
        //overload the << (output) operator to allow a pre-set format of outputing the member variables of a InternationalStudent object to a ostream
private:
        string country;
        ToeflScore TOEFL;
};
