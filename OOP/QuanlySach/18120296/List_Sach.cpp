#include "List_Sach.h"

List_Sach::List_Sach()
{
}

List_Sach::~List_Sach()
{

}

void List_Sach::DocDuLieuSach()
{
	ifstream f;
	f.open("D:/18120296/18120296/Data/ListSach.txt");
	while (!f.eof())
	{
		string ten;
		getline(f, ten, '\t');
		if (ten == "")
		{
			break;
		}
		string ma;
		getline(f, ma, '\t');
		string tg;
		getline(f, tg, '\t');
		string nxb;
		getline(f, nxb, '\t');
		float gia;
		f >> gia;
		f.get();
		int phanquyen;
		f >> phanquyen;
		f.get();
		Sach s(ten, ma, gia, tg, nxb, phanquyen);
		listsach.push_back(s);
	}
	f.close();
}

void List_Sach::GhiDuLieuSach()
{
	ofstream f;
	f.open("D:/18120296/18120296/Data/ListSach.txt", ios_base::out);
	for (int i = 0; i < listsach.size(); i++)
	{
		f << listsach[i].get_tensach() << "\t" << listsach[i].get_masach() << "\t" << listsach[i].get_tacgia() << "\t"
			<< listsach[i].get_NXB() << "\t" << listsach[i].get_giatien() << "\t" << listsach[i].get_PhanQuyen() << "\n";
	}
	f.close();
}


void List_Sach::ThemSach()
{
	string ten;
	cin.ignore();
	cout << "Nhap ten sach: ";
	getline(cin, ten);
	string ma;
	cout << "Nhap ma sach: ";
	getline(cin, ma);
	string tg;
	cout << "Nhap tac gia: ";
	getline(cin, tg);
	string nxb;
	cout << "Nhap nha xuat ban: ";
	getline(cin, nxb);
	float gia;
	cout << "Nhap gia sach: ";
	cin >> gia;
	Sach s(ten, ma, gia, tg, nxb, 0);
	listsach.push_back(s);
}

void List_Sach::SuaSach()
{	
	string tensach;
	cin.ignore();
	cout << "Nhap ten sach can tim: ";
	getline(cin, tensach);
	Sach s = this->TimKiemSach(tensach);
	for (int i = 0; i < listsach.size(); i++)
	{
		if (listsach[i] == s)
		{
			string a;
			cin.ignore();
			cout << "Sua ten sach: ";
			getline(cin, a);
		    listsach[i].set_tensach(a);
			string b;
			cout << "Sua ma sach: ";
			getline(cin, b);
			listsach[i].set_masach(b);
			string c;
			cout << "Sua tac gia: ";
			getline(cin, c);
			listsach[i].set_tacgia(c);
			string d;
			cout << "Sua NXB: ";
			getline(cin, d);
			listsach[i].set_NXB(d);
			float e;
			cout << "Sua gia sach: ";
			cin >> e;
			listsach[i].set_giatien(e);
		}
	}
}

void List_Sach::XoaSach()
{
	string tensach;
	cin.ignore();
	cout << "Nhap ten sach can tim: ";
	getline(cin, tensach);
	Sach s = this->TimKiemSach(tensach);
	for (int i = 0; i < listsach.size(); i++)
	{
		if (listsach[i] == s)
		{
			listsach.erase(listsach.begin() + i);
		}
	}
}

void List_Sach::XuatThongTinSach()
{
	for (int i = 0; i < listsach.size(); i++)
	{
		cout << "Thong tin sach thu " << i + 1 << " la:\n";
		cout << "Ten sach: " << listsach[i].get_tensach() << "\n";
		cout << "Ma sach: " << listsach[i].get_masach() << "\n";
		cout << "Tac gia: " << listsach[i].get_tacgia() << "\n";
		cout << "NXB: " << listsach[i].get_NXB() << "\n";
		cout << "Gia tien: " << listsach[i].get_giatien() << "\n";
		cout << "Phan quyen: " << listsach[i].get_PhanQuyen() << "\n";
	}
}

Sach List_Sach::TimKiemSach(string ten)
{
	Sach s;
	int soluong = 0;
	int a[100];
	for (int i = 0; i < listsach.size(); i++)
	{
		if (listsach[i].get_tensach() == ten)
		{
			a[soluong++] = i;
		}
	}
	if (soluong == 1)
	{
		cout << "Co 1 quyen sach\n";
		return listsach[a[0]];
	}
	if (soluong > 1)
	{
		cout << "Co nhieu cuon sach. Vui long nhan enter de tiep tuc\n";
		string ma;

		cout << "Nhap ma sach: ";
		getline(cin, ma);
		for (int j = 0; j < listsach.size(); j++)
		{
			if (ma == listsach[j].get_masach() && ten == listsach[j].get_tensach())
			{
				return listsach[j];
			}
		}
	}
	cout << "Khong tim thay sach\n";
	return s;
}


