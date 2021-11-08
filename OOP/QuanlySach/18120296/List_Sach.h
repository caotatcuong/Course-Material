#ifndef LISTSACH_H_
#define LISTSACH_H_
#include "Sach.h"

class List_Sach
{
public:
	vector<Sach> listsach;
	void DocDuLieuSach();
	void GhiDuLieuSach();
	void ThemSach();
	void SuaSach();
	void XoaSach();
	void XuatThongTinSach();
	Sach TimKiemSach(string);
	List_Sach();
	~List_Sach();
};

#endif