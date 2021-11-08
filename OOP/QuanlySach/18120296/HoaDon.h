#ifndef HOADON_H_
#define HOADON_H
#include "List_Sach.h"

class HoaDon
{
private:
	float GiaTien;
	int SoLuong;
public:
	Sach s;
	HoaDon();
	HoaDon(const Sach&, float giatien, int soluong);
	HoaDon(string, float, int, float);
	HoaDon(const HoaDon&);
	HoaDon& operator=(const HoaDon&);
	~HoaDon();
	void Set_GiaTien(float);
	float Get_GiaTien();
	void Set_SoLuong(int);
	int Get_SoLuong();
	void ThemHoaDon(Sach);
};
#endif 


