#ifndef FILE_H_
#define FILE_H_
#include "ADMIN.h"

template<class T>
class File
{
public:
	void Ghi(vector<T> list, T object)
	{
		string filename;
		filename = object.classname();
		ofstream f;
		f.open("D:/18120296/18120296/Data/" + filename, ios_base::out);
		for (int i = 0; i < list.size(); i++)
		{
			f << list[i].get_Ten() << "\t" << list[i].get_Pass() << endl;
		}
		f.close();
	}
	void Ghi2(vector<T> list, T object)
	{
		string filename;
		filename = object.classname();
		ofstream f;
		f.open("D:/18120296/18120296/Data/" + filename, ios_base::out);
		for (int i = 0; i < list.size(); i++)
		{
			f << list[i].get_Ten() << "\t" << list[i].get_Pass() << "\t" << list[i].get_Age() << endl;
		}		
		f.close();
	}
	void Doc(vector<T>& list, T& object)
	{
		string filename;
		filename = object.classname();
		ifstream f;
		f.open("D:/18120296/18120296/Data/"+filename);
		while (!f.eof())
		{
			string ten;
			getline(f, ten, '\t');
			string pass;
			getline(f, pass, '\n');
			T object(ten, pass);
			list.push_back(object);
		}
		f.close();
	}
	void Doc2(vector<T>& list, T& object)
	{
		string filename;
		filename = object.classname();
		ifstream f;
		f.open("D:/18120296/18120296/Data/"+filename);
		while (!f.eof())
		{
			string ten;
			getline(f, ten, '\t');
			string pass;
			getline(f, pass, '\t');
			string tuoi;
			getline(f, tuoi, '\n');
			T object(ten, pass, tuoi);
			list.push_back(object);
		}
		f.close();
	}
};

#endif

