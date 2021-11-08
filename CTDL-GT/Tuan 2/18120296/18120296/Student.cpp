#include "Student.h"

Student::Student()
{
}

Student::Student(string a, string b, string c, string d, string e)
{
	this->mId = a;
	this->mSurname = b;
	this->mName = c;
	this->set_mDate_of_birth(d);
	this->set_mScores(e);
}

Student& Student::operator=(Student&a)
{
	if (this != &a)
	{
		this->mId = a.mId;
		this->mSurname = a.mSurname;
		this->mName = a.mName;
		this->set_mDate_of_birth(a.get_mDate_of_birth());
		this->set_mScores(a.get_mScores());
	}
	return *this;
}

Student::~Student()
{
}

void Student::set_mDate_of_birth(string a)
{
	this->mDate_of_birth = a;
}

string Student::get_mDate_of_birth()
{
	return this->mDate_of_birth;
}

void Student::set_mScores(string a)
{
	this->mScores = a;
}

string Student::get_mScores()
{
	return this->mScores;
}



ostream& operator<<(Student src, ostream &out)
{
	out << src.mId << src.mName << src.mSurname << src.get_mDate_of_birth() << src.get_mScores();
	return out;
}
