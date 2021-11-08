#include "Student.h"

Student::Student()
{
}

Student::Student(string a, string b, string c, float d)
{
	this->mMSSV = a;
	this->mHo = b;
	this->mTen = c;
	this->set_mDiem(d);
}

Student& Student::operator=(Student& a)
{
	if (this != &a)
	{
		this->mMSSV = a.mMSSV;
		this->mHo = a.mHo;
		this->mTen = a.mTen;
		this->set_mDiem(a.get_mDiem());
	}
	return *this;
}

Student::~Student()
{
}

void Student::set_mDiem(float a)
{
	this->mDiem = a;
}

float Student::get_mDiem()
{
	return this->mDiem;
}


ostream& operator<<(Student src, ostream& out)
{
	out << src.mMSSV << src.mHo << src.mTen << src.get_mDiem();
	return out;
}

