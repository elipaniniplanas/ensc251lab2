/*
	AUTHORS: ELI PLANAS AND CHENNY CAO
	THIS CODE WAS COMPLETED ON SEPT. 25, 2019

	This program opens two files (one domestic and the other international student applicants)
	and puts their information (names and academic scores) into objects of child classes of the
	parent class STUDENT.
	The two child classes created are for domestic student and the other for international students.
	Each child class have different class members and member functions except for the members and
	member functions derived from the parent class.
	An additional class was used (particularly in use with the international student class) called
	ToeflScore, in which has members that held data about international students' toefl scores and
	their totals.
*/
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"

int main(){
  //Declare the varibles used throughout the program
  string line; //Used to retrieve a line in the files
  string userInStu;
  string userInComp;
  DomesticStudent Dstudent[100];
  InternationalStudent Istudent[100];
  int sizeD;
  int sizeI;
  //DomesticStudent *Dstudent = new DomesticStudent[100]; // Made an array of objects of DomesticStudent class
  //InternationalStudent *Istudent= new InternationalStudent[100]; // Made an array of objects of InternationalStudent class

  //Read the domestic-stu.txt file and exit if failed
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);//this skips the first line which is about the file format
  int Dstu_count = 1;
  int ID_count = 20200000;
  int counter1 = 0;
  int counter2 = 0;

  while( getline(domesticFile, line) ) {
    //make the string from the line in the file into a istringstream to be able to parse the data
    istringstream ss(line);
    //Declare variables to hold the data parsed from the file/lines
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, province, ',');
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    // Set all data to the Istudent object with mutator functions

    Dstudent[counter1].setID(ID_count);
    Dstudent[counter1].setfname(firstName);
    Dstudent[counter1].setlname(lastName);
    Dstudent[counter1].setCGPA(cgpa);
    Dstudent[counter1].setscore(researchScore);
    Dstudent[counter1].setID(ID_count);
    Dstudent[counter1].setprovince(province);

    //cout << counter1+1 << " " << Dstudent[counter1];
    //print the student info to the screen
    /*cout << "Domestic student " << Dstu_count << " " << Dstudent.getfname() << " "
	 << Dstudent.getlname() << " from " << Dstudent.getprovince() << " province has cgpa of "
	 << Dstudent.getCGPA() << ", and research score of " << Dstudent.getscore() << ", the assigned ID is "
	 << Dstudent.getID() << endl;*/
    //Generate a new ID and prepare to the next iteration of the loop
    counter1++;
    Dstu_count++;
    ID_count++;
  }
  domesticFile.close();

  //Here begins the proccess of getting and setting the data for international students
  //accessing the international-stu.txt
  ifstream internationalFile("international-stu.txt");
  if(!internationalFile.is_open()) {
    cout << "Unable to open file international-stu.txt" << endl;
    return -1;
  }
  getline(internationalFile, line);//this skips the first line which is about the file format
  //This is used to keep track of which student is being printed out and keeps track of how many international students there are
  int Istu_count = 1;
  while( getline(internationalFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this example code here, we assume the file format
     *is perfect and do NOT handle error cases.*/
    //make the string from the line in the file into a istringstream to be able to parse the data
    istringstream ss(line);
    //Declair variables to hold the data parsed from the file/lines
    string firstName, lastName, s_cgpa, s_researchScore, country, s_read, s_listen, s_speak, s_write;
    float cgpa;
    int researchScore, read, listen, speak, write;

    getline(ss, firstName, ',');
    getline(ss, lastName, ',');
    getline(ss, country, ',');
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    getline(ss, s_read, ',');
    read = atoi(s_read.c_str());
    getline(ss, s_listen, ',');
    listen = atoi(s_listen.c_str());
    getline(ss, s_speak, ',');
    speak = atoi(s_speak.c_str());
    getline(ss, s_write, ',');
    write = atoi(s_write.c_str());
    // Set all data to the Istudent object with mutator functions
    Istudent[counter2].setfname(firstName);
    Istudent[counter2].setlname(lastName);
    Istudent[counter2].setCGPA(cgpa);
    Istudent[counter2].setscore(researchScore);
    Istudent[counter2].setID(ID_count);
    Istudent[counter2].setcountry(country);
    Istudent[counter2].settoefl(read,write,listen,speak);
    Istudent[counter2].setID(ID_count);

    //cout << counter2+1 << " " << Istudent[counter2];
    //print the student info to the screen
    /*cout << "International student " << Istu_count << " " << Istudent.getfname() << " "
	 << Istudent.getlname() << " from " << Istudent.getcountry() << " country has cgpa of "
	 << Istudent.getCGPA() << ", and research score of " << Istudent.getscore()
	 << ", the assigned ID is " << Istudent.getID() << ", their toefl scores are: reading "
	 << Istudent.gettoeflread() << ", writing "<< Istudent.gettoeflwrite() << ", listening "
	 << Istudent.gettoefllisten() << ", speaking " << Istudent.gettoeflspeak() << ", and their total toefl score is "
	 << Istudent.gettotal() <<endl;*/

    //Generate a new ID and prepare to the next iteration of the loop
    counter2++;
    Istu_count++;
    ID_count++;
  }
  //close your file
  internationalFile.close();
  sizeD = sizeof(Dstudent)/sizeof(Dstudent[0]);
  sizeI = sizeof(Istudent)/sizeof(Istudent[0]);
  retry:
  cout << "Sort:\nDomestic students; type 'D' or 'd'\nInternational students; type 'I' or 'i'\nINPUT: ";
  cin >> userInStu;
  cout << endl;
  if ((userInStu == "d")||(userInStu == "D"))
  {
    tryagain1:
    cout << "Sort by:\nCGPA; type 'C' or 'c'\nResearch Score; type 'R' or 'r'\nFirst name; type 'F' or 'f'\nLast name; type 'L' or 'l'\nINPUT: ";
    cin >> userInComp;
    cout << endl;
    if ((userInComp == "c")||(userInComp == "C"))
    {
      bubblesort_CGPA(Dstudent, sizeD);
      for(int k=0; k < sizeD; k++)
      {
        cout << (Dstudent+k);
      }
    }
    else if ((userInComp == "r")||(userInComp == "R"))
    {
      bubblesort_ResearchScore(Dstudent, sizeD);
      for(int k=0; k < sizeD; k++)
      {
        cout << (Dstudent+k);
      }
    }
    else if ((userInComp == "f")||(userInComp == "F"))
    {
      bubblesort_FirstName(Dstudent, sizeD);
      for(int k=0; k < sizeD; k++)
      {
        cout << (Dstudent+k);
      }
    }
    else if ((userInComp == "l")||(userInComp == "L"))
    {
      bubblesort_LastName(Dstudent, sizeD);
      for(int k=0; k < sizeD; k++)
      {
        cout << (Dstudent+k);
      }
    }
    else
    {
      cout << "INPUT ERROR\n";
      goto tryagain1;
    }
  }
  else if ((userInStu == "i")||(userInStu == "I"))
  {
    tryagain2:
    cout << "Sort by:\nCGPA; type 'C' or 'c'\nResearch Score; type 'R' or 'r'\nFirst name; type 'F' or 'f'\nLast name; type 'L' or 'l'\nINPUT: ";
    cin >> userInComp;
    cout << endl;
    if ((userInComp == "c")||(userInComp == "C"))
    {
      bubblesort_CGPA(Istudent, sizeI);
      for(int k=0; k < sizeI; k++)
      {
        cout << (Istudent+k);
      }
    }
    else if ((userInComp == "r")||(userInComp == "R"))
    {
      bubblesort_ResearchScore(Istudent, sizeI);
      for(int k=0; k < sizeI; k++)
      {
        cout << (Istudent+k);
      }
    }
    else if ((userInComp == "f")||(userInComp == "F"))
    {
      bubblesort_FirstName(Istudent, sizeI);
      for(int k=0; k < sizeI; k++)
      {
        cout << (Istudent+k);
      }
    }
    else if ((userInComp == "l")||(userInComp == "L"))
    {
      cout << "test if\n";
      bubblesort_LastName(Istudent, sizeI);
      cout << "test sort\n";
      for(int k=0; k < sizeI; k++)
      {
        cout << "test loop\n";
        cout << (Istudent+k);
      }
    }
    else
    {
      cout << "INPUT ERROR\n";
      goto tryagain2;
    }
  }
  else
  {
    cout << "INPUT ERROR\n";
    goto retry;
  }
  return 0;
}
