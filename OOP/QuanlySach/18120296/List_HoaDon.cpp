#include "List_HoaDon.h"

List_HoaDon::List_HoaDon()
{
}

List_HoaDon::~List_HoaDon()
{
}

void List_HoaDon::NhapHoaDon(List_Sach ls)
{
	char a;
	cin.ignore();
	do
	{
		cout << "Ban co muon nhap hoa don. Neu co nhan Y, neu khong nhan N: ";
		cin >> a;
		if (a == 'Y' || a == 'y')
		{
			string tensach;
			cin.ignore();
			cout << "Nhap ten sach can mua: ";
			getline(cin, tensach);
			Sach s = ls.TimKiemSach(tensach);
			if (s.get_tensach() == "")
			{
				continue;
			}
			HoaDon h;
			h.ThemHoaDon(s);
			listhoadon.push_back(h);
		}
	} while (a == 'Y' || a == 'y');
}

float List_HoaDon::TongTien()
{
	float tong = 0;
	for (int i = 0; i < listhoadon.size(); i++)
	{
		tong += listhoadon[i].Get_GiaTien();
	}
	return tong;
}

void List_HoaDon::ThanhPhanTien(List_HoaDon lhd)
{
	cout << "Ten sach" << "\tDon gia" << "\t\tSo luong" << "\tThanh tien" << endl;
	for (int i = 0; i < listhoadon.size(); i++)
	{
		cout << listhoadon[i].s.get_tensach() << "\t\t" << listhoadon[i].s.get_giatien() << "\t\t" << listhoadon[i].Get_SoLuong() << "\t\t" << listhoadon[i].Get_GiaTien() << endl;
	}
}

