#ifndef SACH_H_
#define SACH_H_
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

class Sach
{
private:
	string ten_sach;
	string ma_sach;
	float gia_tien;
	string tac_gia;
	string NXB;
	int PhanQuyen;
public:
	void set_tensach(string);
	string get_tensach();
	void set_masach(string);
	string get_masach();
	void set_giatien(float);
	float get_giatien();
	void set_tacgia(string);
	string get_tacgia();
	void set_NXB(string);
	string get_NXB();
	void set_PhanQuyen(int);
	int get_PhanQuyen();
	Sach();
	Sach(string, string, float, string, string, int);
	Sach(const Sach&);
	Sach& operator =(const Sach&);
	bool operator ==(const Sach&);
	~Sach();
};

#endif
