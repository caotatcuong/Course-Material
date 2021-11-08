#include "HoaDon.h"

HoaDon::HoaDon()
{
}

HoaDon::HoaDon(const Sach& S, float giatien, int soluong)
{
	this->s = S;
	this->Set_GiaTien(giatien);
	this->Set_SoLuong(soluong);
}

HoaDon::HoaDon(string ten, float tien, int soluong, float giatien)
{
	this->s.set_tensach(ten);
	this->s.set_giatien(tien);
	this->Set_GiaTien(giatien);
	this->Set_SoLuong(soluong);
}

HoaDon::HoaDon(const HoaDon& h)
{
	this->s = h.s;
	this->Set_GiaTien(h.GiaTien);
	this->Set_SoLuong(h.SoLuong);
}

HoaDon& HoaDon::operator=(const HoaDon& h)
{
	if (this != &h)
	{
		this->s = h.s;
		this->Set_GiaTien(h.GiaTien);
		this->Set_SoLuong(h.SoLuong);
	}
	return *this;
}

HoaDon::~HoaDon()
{
}

void HoaDon::Set_GiaTien(float t)
{
	this->GiaTien = t;
}

float HoaDon::Get_GiaTien()
{
	return this->GiaTien;
}

void HoaDon::Set_SoLuong(int sl)
{
	this->SoLuong = sl;
}

int HoaDon::Get_SoLuong()
{
	return this->SoLuong;
}

void HoaDon::ThemHoaDon(Sach s)
{
	int soluong;
	cout << "Nhap so luong sach muon mua: ";
	cin >> soluong;
	HoaDon h(s, soluong * s.get_giatien(), soluong);
	*this = h;
}
