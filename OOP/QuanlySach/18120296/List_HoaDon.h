#ifndef LISTHOADON_H_
#define LISTHOADON_H_
#include "HoaDon.h"

class List_HoaDon
{
public:
	vector<HoaDon> listhoadon;
	List_HoaDon();
	~List_HoaDon();
	void NhapHoaDon(List_Sach);
	float TongTien();
	void ThanhPhanTien(List_HoaDon);
};

#endif