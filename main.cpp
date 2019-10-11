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

//main.cpp, put your driver code here,
//you can manipulate your class objects here
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"

int main(){
  //Declare the varibles used throughout the program
  string line; //Used to retrieve a line in the files
	
  DomesticStudent *Dstudent = new DomesticStudent[100]; // Made an array of objects of DomesticStudent class
  InternationalStudent *Istudent= new InternationalStudent[100]; // Made an array of objects of InternationalStudent class
	
  //Read the domestic-stu.txt file and exit if failed
  ifstream domesticFile("domestic-stu.txt");
  if(!domesticFile.is_open()) {
    cout << "Unable to open file domestic-stu.txt" << endl;
    return -1;
  }
  getline(domesticFile, line);//this skips the first line which is about the file format
  //cout << "File format: " << line << endl; -- This line was from the origninal download file
  //This int is to keep track which domestic student is being displayed and how many domestic student are there
  int Dstu_count = 1;
  // This int will increment each loop to generate a unique id for each student
  int ID_count = 20200000;
	
  int counter = 0;
  while( getline(domesticFile, line) ) {
    /*process each line, get each field separated by a comma.
     *We use istringstream to handle it.
     *Note in this code here, we assume the file format
     *is perfect and do NOT handle error cases.*/

    //make the string from the line in the file into a istringstream to be able to parse the data
    istringstream ss(line);
    //Declare variables to hold the data parsed from the file/lines
    string firstName, lastName, province, s_cgpa, s_researchScore;
    float cgpa;
    int researchScore;

    //get firstName separated by comma
    getline(ss, firstName, ',');
    //get lastName separated by comma
    getline(ss, lastName, ',');
    //get province separated by comma
    getline(ss, province, ',');
    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());

    // Set all data to the Istudent object with mutator functions
    
    Dstudent[counter].setID(ID_count);
    Dstudent[counter].setfname(firstName);
    Dstudent[counter].setlname(lastName);
    Dstudent[counter].setCGPA(cgpa);
    Dstudent[counter].setscore(researchScore);
    Dstudent[counter].setID(ID_count);
    Dstudent[counter].setprovince(province);
    counter++;

    //print the student info to the screen
    cout << "Domestic student " << Dstu_count << " " << Dstudent.getfname() << " "
	 << Dstudent.getlname() << " from " << Dstudent.getprovince() << " province has cgpa of "
	 << Dstudent.getCGPA() << ", and research score of " << Dstudent.getscore() << ", the assigned ID is "
	 << Dstudent.getID() << endl;

    //Generate a new ID and prepare to the next iteration of the loop
    Dstu_count++;
    ID_count++;
  }
  //close your file
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

    //get firstName separated by comma
    getline(ss, firstName, ',');
    //get lastName separated by comma
    getline(ss, lastName, ',');
    //get country separated by comma
    getline(ss, country, ',');
    //get cpga separated by comma, and convert string to float
    getline(ss, s_cgpa, ',');
    cgpa = atof(s_cgpa.c_str());
    //get researchScore separated by comma, and convert it to int
    getline(ss, s_researchScore, ',');
    researchScore = atoi(s_researchScore.c_str());
    //get toeflscores, each seperated by commas, and convert each in to int
    getline(ss, s_read, ',');
    read = atoi(s_read.c_str());
    getline(ss, s_listen, ',');
    listen = atoi(s_listen.c_str());
    getline(ss, s_speak, ',');
    speak = atoi(s_speak.c_str());
    getline(ss, s_write, ',');
    write = atoi(s_write.c_str());

    // Set all data to the Istudent object with mutator functions
    Istudent.setfname(firstName);
    Istudent.setlname(lastName);
    Istudent.setCGPA(cgpa);
    Istudent.setscore(researchScore);
    Istudent.setID(ID_count);
    Istudent.setcountry(country);
    Istudent.settoefl(read,write,listen,speak);
    Istudent.setID(ID_count);

    //print the student info to the screen
    cout << "International student " << Istu_count << " " << Istudent.getfname() << " "
	 << Istudent.getlname() << " from " << Istudent.getcountry() << " country has cgpa of "
	 << Istudent.getCGPA() << ", and research score of " << Istudent.getscore()
	 << ", the assigned ID is " << Istudent.getID() << ", their toefl scores are: reading "
	 << Istudent.gettoeflread() << ", writing "<< Istudent.gettoeflwrite() << ", listening "
	 << Istudent.gettoefllisten() << ", speaking " << Istudent.gettoeflspeak() << ", and their total toefl score is "
	 << Istudent.gettotal() <<endl;

    //Generate a new ID and prepare to the next iteration of the loop
    Istu_count++;
    ID_count++;
  }
  //close your file
  internationalFile.close();

  return 0;
}
