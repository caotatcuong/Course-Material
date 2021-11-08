#ifndef USER_H_
#define USER_H_
#include "Khach.h"
#include "List_HoaDon.h"
#include "List_Sach.h"
class User :public Khach
{
protected:
	string Pass;
	string Name;
	string Age;
public:
	List_HoaDon lh;
	float tongtien;
	virtual string classname()
	{
		return "User.txt";
	}
	User();
	~User();
	User(string, string, string);
	void set_Pass(string);
	string get_Pass();
	void set_Name(string);
	string get_Ten();
	void set_Age(string);
	string get_Age();
	void MuaSach(List_Sach);
	void CapNhatDonhang(List_Sach);
	void XemHoaDon();
	void GhiHoaDon(float);
	void DocHoaDon();
	void DangKy(vector<User>&, User&);
	void DangNhap(vector<User>,User&);
	void GuiTinNhan(vector<User>);
};

#endif
