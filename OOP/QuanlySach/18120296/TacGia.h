#ifndef TACGIA_H_
#define TACGIA_H_
#include "List_Sach.h"
#include "User.h"

class TacGia
{
protected:
	string Ten;
	string Pass;
public:
	virtual string classname()
	{
		return "TacGia.txt";
	}
	vector<Sach> tg;
	void set_Ten(string);
	string get_Ten();
	void set_Pass(string);
	string get_Pass();
	TacGia();
	~TacGia();
	TacGia(string, string);
	void LayDanhSachSach(List_Sach);
	void Them(List_Sach&);
	void Xoa(List_Sach&);
	void Sua(List_Sach&);
	void DangKy(vector<TacGia>&, TacGia&);
	void DangNhap(vector<TacGia>, TacGia&);
	void PhanQuyen(List_Sach&);
	void GuiTinNhan(vector<TacGia> ListTacGia, vector<User> ListUser);
};

#endif