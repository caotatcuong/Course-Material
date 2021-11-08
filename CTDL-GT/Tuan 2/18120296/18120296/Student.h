#ifndef STUDENT_H_
#define STUDENT_H_
#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include<iomanip>
using namespace std;
class Student
{
private:
	string mDate_of_birth;
	string mScores;
public:
	string mId;
	string mSurname;
	string mName;
	Student();
	Student(string, string, string, string, string);
	Student& operator =(Student&);
	virtual~Student();
	void set_mDate_of_birth(string);
	string get_mDate_of_birth();
	void set_mScores(string);
	string get_mScores();
	friend ostream& operator<<(Student src, ostream &out);
};
#endif
