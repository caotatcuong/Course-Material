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
	float mDiem;
public:
	string mMSSV;
	string mHo;
	string mTen;
	Student();
	Student(string, string, string, float);
	Student& operator =(Student&);
	virtual~Student();
	void set_mDiem(float);
	float get_mDiem();
	friend ostream& operator<<(Student src, ostream& out);
};
#endif

