#include "Sach.h"

void Sach::set_tensach(string ten)
{
	this->ten_sach = ten;
}

string Sach::get_tensach()
{
	return this->ten_sach;
}

void Sach::set_masach(string ma)
{
	this->ma_sach = ma;
}

string Sach::get_masach()
{
	return this->ma_sach;
}

void Sach::set_giatien(float gia)
{
	this->gia_tien = gia;
}

float Sach::get_giatien()
{
	return this->gia_tien;
}

void Sach::set_tacgia(string tg)
{
	this->tac_gia = tg;
}

string Sach::get_tacgia()
{
	return this->tac_gia;
}

void Sach::set_NXB(string nxb)
{
	this->NXB = nxb;
}

string Sach::get_NXB()
{
	return this->NXB;
}

void Sach::set_PhanQuyen(int p)
{
	this->PhanQuyen = p;
}

int Sach::get_PhanQuyen()
{
	return this->PhanQuyen;
}

Sach::Sach()
{
}

Sach::Sach(string ten, string ma, float gia, string tg, string nxb, int phanquyen)
{
	this->set_tensach(ten);
	this->set_masach(ma);
	this->set_giatien(gia);
	this->set_tacgia(tg);
	this->set_NXB(nxb);
	this->set_PhanQuyen(phanquyen);
}

Sach::Sach(const Sach& s)
{
	this->set_tensach(s.ten_sach);
	this->set_masach(s.ma_sach);
	this->set_giatien(s.gia_tien);
	this->set_tacgia(s.tac_gia);
	this->set_NXB(s.NXB);
	this->PhanQuyen = s.PhanQuyen;
}

Sach& Sach::operator=(const Sach& s)
{
	if (this != &s)
	{
		this->set_tensach(s.ten_sach);
		this->set_masach(s.ma_sach);
		this->set_giatien(s.gia_tien);
		this->set_tacgia(s.tac_gia);
		this->set_NXB(s.NXB);
		this->PhanQuyen = s.PhanQuyen;
	}
	return *this;
}

bool Sach::operator==(const Sach& s)
{
	if (this->get_tensach() == s.ten_sach && this->get_masach() == s.ma_sach)
	{
		return true;
	}
	return false;
}

Sach::~Sach()
{
}

