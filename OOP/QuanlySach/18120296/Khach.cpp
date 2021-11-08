#include "Khach.h"

Khach::Khach()
{
}

Khach::~Khach()
{
}

List_Sach Khach::ChonSach(List_Sach ls)
{
	List_Sach GioHang;
	char a;
	do
	{
		cout << "Nhan Y de chon sach. Neu khong nhan N: ";
		cin >> a;
		if (a == 'y' || a == 'Y')
		{
			string tensach;
			cin.ignore();
			cout << "Nhap ten sach can tim: ";
			getline(cin, tensach);
			Sach s = ls.TimKiemSach(tensach);
			if (s.get_PhanQuyen() == 1 || s.get_PhanQuyen() == 2 || s.get_PhanQuyen() == 3)
			{
				cout << "Sach da bi khoa\n";
			}
			else
			{
				GioHang.listsach.push_back(s);
			}		
		}
	} while (a == 'y' || a == 'Y');
	return GioHang;
}
