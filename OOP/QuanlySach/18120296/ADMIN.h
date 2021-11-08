#ifndef ADMIN_H_
#define ADMIN_H_
#include "NXB.h"
#include "User.h"
#include"File.h"

class ADMIN:public User
{
public:
	virtual string classname()
	{
		return "ADMIN.txt";
	}
	ADMIN(string, string, string);
	void set_Pass(string);
	string get_Pass();
	void set_Name(string);
	string get_Ten();
	void set_Age(string);
	string get_Age();
	vector<NXB> ListNXB;
	vector<TacGia> ListTacGia;
	vector<User> ListUser;
	List_Sach ListSach;
	ADMIN();
	~ADMIN();
	void DangNhap(vector<ADMIN>,ADMIN&);
	void Them();
	void Sua();
	void Xoa();
	void PhanQuyen();
	void GuiTinNhan();
	void DanhSachTaiKhoan();
	void XuatHoaDonCuaUser();
	void HoaDonCoTongTienCaoNhat();
};

#endif