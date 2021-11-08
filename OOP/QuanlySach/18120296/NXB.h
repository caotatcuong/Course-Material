#ifndef NXB_H_
#define NXB_H_
#include "TacGia.h"

class NXB:public TacGia
{
public:
	virtual string classname()
	{
		return "NXB.txt";
	}
	vector<Sach> nxb;
	void set_Ten(string);
	string get_Ten();
	void set_Pass(string);
	string get_Pass();
	NXB();
	~NXB();
	NXB(string, string);
	void LayDanhSachSach(List_Sach);
	void Them(List_Sach&);
	void Xoa(List_Sach&);
	void Sua(List_Sach&);
	void DangKy(vector<NXB>&, NXB&);
	void DangNhap(vector<NXB>, NXB&);
	void PhanQuyen(List_Sach&);
	void GuiTinNhan(vector<NXB> ListNXB, vector<User> ListUser);
	void XemSachbanNhieuNhat(vector<User> luser);
};

#endif