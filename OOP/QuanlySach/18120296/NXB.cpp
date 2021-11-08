#include "NXB.h"

NXB::NXB()
{
}

NXB::~NXB()
{
}

NXB::NXB(string ten, string pass) :TacGia(ten, pass)
{
}

void NXB::set_Ten(string ten) 
{
	this->Ten = ten;
}

string NXB::get_Ten()
{
	return this->Ten;
}

void NXB::set_Pass(string pass)
{
	this->Pass = pass;
}

string NXB::get_Pass()
{
	return this->Pass;
}

void NXB::LayDanhSachSach(List_Sach ls)
{
	for (int i = 0; i < ls.listsach.size(); i++)
	{
		if (ls.listsach[i].get_NXB() == this->get_Ten())
		{
			if (ls.listsach[i].get_PhanQuyen() == 3)
			{
				continue;
			}
			nxb.push_back(ls.listsach[i]);
		}
	}
}

void NXB::Them(List_Sach& ls)
{
	ls.ThemSach();
	nxb.push_back(ls.listsach[ls.listsach.size() - 1]);
	cout << "Them sach thanh cong\n";
}

void NXB::Xoa(List_Sach& ls)
{
	string ten;
	cin.ignore();
	cout << "Nhap ten sach can xoa: ";
	getline(cin, ten);
	Sach s = ls.TimKiemSach(ten);
	bool check = false;
	for (int i = 0; i < nxb.size(); i++)
	{
		if (nxb[i] == s)
		{
			for (int j = 0; j < ls.listsach.size(); j++)
			{
				if (ls.listsach[j] == s)
				{
					ls.listsach.erase(ls.listsach.begin() + j);
					nxb.erase(nxb.begin() + i);
					cout << "Xoa sach thanh cong\n";
					check = true;
					break;
				}
			}
		}
		if (check == true)
			break;
	}
	if (check == false)
		cout << "Sach da bi khoa. Khong the xoa\n";
}

void NXB::Sua(List_Sach& ls)
{
	string ten;
	cin.ignore();
	cout << "Nhap ten sach can sua: ";
	getline(cin, ten);
	Sach s = ls.TimKiemSach(ten);
	bool check = false;
	for (int i = 0; i < nxb.size(); i++)
	{
		if (nxb[i] == s)
		{
			for (int j = 0; j < ls.listsach.size(); j++)
			{
				if (ls.listsach[j] == s)
				{
					string a;
					cin.ignore();
					cout << "Sua ten sach: ";
					getline(cin, a);
					ls.listsach[j].set_tensach(a);
					nxb[i].set_tensach(a);
					string b;
					cout << "Sua ma sach: ";
					getline(cin, b);
					ls.listsach[j].set_masach(b);
					nxb[i].set_masach(b);
					int c;
					cout << "Sua gia sach: ";
					cin >> c;
					ls.listsach[j].set_giatien(c);
					nxb[i].set_giatien(c);
					cout << "Sua sach thanh cong\n";
					check = true;
					break;
				}
			}
		}
		if (check == true)
			break;
	}
	if (check == false)
		cout << "Sach da bi khoa. Khong the sua\n";
}

void NXB::DangKy(vector<NXB>& lnxb, NXB& Nxb)
{
	while (true)
	{
		bool check = true;
		string ten;
		cin.ignore();
		cout << "Nhap ten NXB: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		NXB nxb(ten, pass);
		for (int i = 0; i < lnxb.size(); i++)
		{
			if (nxb.get_Ten() == lnxb[i].get_Ten())
			{
				cout << "Ten tai khoa bi trung vui long dang ky lai. Nhan enter de tiep tuc\n";
				check = false;
				break;
			}
		}
		if (check == false)
		{
			continue;
		}
		cout << "Dang ky thanh cong\n";
		lnxb.push_back(nxb);
		Nxb = nxb;
		break;
	}
}

void NXB::DangNhap(vector<NXB> lnxb, NXB& nxb)
{
	while (true)
	{
		bool check = false;
		string ten;
		cin.ignore();
		cout << "Nhap ten NXB: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		for (int i = 0; i < lnxb.size(); i++)
		{
			if (ten == lnxb[i].get_Ten() && pass == lnxb[i].get_Pass())
			{
				nxb = lnxb[i];
				cout << "Dang nhap thanh cong\n";
				check = true;
				break;
			}
		}
		if (check == true)
		{
			break;
		}
		else
		{
			cout << "Thong tin khong chinh xac. Vui long dang nhap lai. Nhan enter de tiep tuc\n";
		}
	}
}

void NXB::PhanQuyen(List_Sach& ls)
{
	int n;
	cout << "1. Khoa quyen\n";
	cout << "2. Mo quyen\n";
	cout << "Nhap lua chon: ";
	cin >> n;
	bool check = false;
	switch (n)
	{
		case 1:
		{
			string ten;
			cin.ignore();
			cout << "Nhap ten sach muon phan quyen: ";
			getline(cin, ten);
			Sach s = ls.TimKiemSach(ten);
			for (int i = 0; i < nxb.size(); i++)
			{
				if (nxb[i] == s)
				{
					for (int j = 0; j < ls.listsach.size(); j++)
					{
						if (ls.listsach[j] == s)
						{
							ls.listsach[j].set_PhanQuyen(2);
							nxb[i].set_PhanQuyen(2);
							cout << "Phan quyen thanh cong\n";
							check = true;
							break;
						}
					}
				}
				if (check == true)
					break;
			}
			if (check == false)
				cout << "Sach da bi khoa. Khong the phan quyen\n";
			break;
		}
		case 2:
		{
			string ten;
			cin.ignore();
			cout << "Nhap ten sach muon phan quyen: ";
			getline(cin, ten);
			Sach s = ls.TimKiemSach(ten);
			for (int i = 0; i < nxb.size(); i++)
			{
				if (nxb[i] == s)
				{
					for (int j = 0; j < ls.listsach.size(); j++)
					{
						if (ls.listsach[j] == s)
						{
							ls.listsach[j].set_PhanQuyen(0);
							nxb[i].set_PhanQuyen(0);
							cout << "Phan quyen thanh cong\n";
							check = true;
							break;
						}
					}
				}
				if (check == true)
					break;
			}
			if (check == false)
				cout << "Sach da bi khoa. Khong the phan quyen\n";
			break;
		}
	}
}

void NXB::GuiTinNhan(vector<NXB> ListNXB, vector<User> ListUser)
{
	int m;
	cout << "1. Nhan cho user\n";
	cout << "2. Nhan cho NXB\n";
	cout << "Nhap lua chon: ";
	cin >> m;
	switch (m)
	{
		case 1:
		{
			while (true)
			{
				bool check = false;
				string ten;
				cin.ignore();
				cout << "Nhap ten user: ";
				getline(cin, ten);
				for (int i = 0; i < ListUser.size(); i++)
				{
					if (ten == ListUser[i].get_Ten())
					{
						check = true;
						string message;
						cout << "Nhap tin nhan: ";
						getline(cin, message);
						ofstream f;
						f.open("D:/18120296/18120296/Data/" + ten + "tinnhan.txt", ios_base::app);
						f << "Nguoi gui: " << this->get_Ten() << endl << message << endl;
						f.close();
						cout << "Da gui thanh cong\n";
						break;
					}
				}
				if (check == true)
				{
					break;
				}
				else
				{
					cout << "Thong tin nguoi nhan khong chinh xac. Vui long dang nhap lai. Nhan enter de tiep tuc\n";
				}
			}
			break;
		}
		case 2:
		{
			while (true)
			{
				bool check = false;
				string ten;
				cin.ignore();
				cout << "Nhap ten NXB: ";
				getline(cin, ten);
				for (int i = 0; i < ListNXB.size(); i++)
				{
					if (ten == ListNXB[i].get_Ten())
					{
						check = true;
						string message;
						cout << "Nhap tin nhan: ";
						getline(cin, message);
						ofstream f;
						f.open("D:/18120296/18120296/Data/" + ten + "tinnhan.txt", ios_base::app);
						f << "Nguoi gui: " << this->get_Ten() << endl << message << endl;
						f.close();
						cout << "Da gui thanh cong\n";
						break;
					}
				}
				if (check == true)
				{
					break;
				}
				else
				{
					cout << "Thong tin nguoi nhan khong chinh xac. Vui long dang nhap lai. Nhan enter de tiep tuc\n";
				}
			}
			break;
		}
	}		
}

void NXB::XemSachbanNhieuNhat(vector<User> luser)
{
	for (int i = 0; i < luser.size(); i++)
	{
		cout << "Em khong lam duoc";
	}
}

