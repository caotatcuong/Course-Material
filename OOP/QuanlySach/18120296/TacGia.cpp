#include "TacGia.h"

void TacGia::set_Ten(string ten)
{
	this->Ten = ten;
}

string TacGia::get_Ten()
{
	return this->Ten;
}

void TacGia::set_Pass(string pass)
{
	this->Pass = pass;
}

string TacGia::get_Pass()
{
	return this->Pass;
}

TacGia::TacGia()
{
}


TacGia::~TacGia()
{
}

TacGia::TacGia(string ten, string pass)
{
	this->set_Ten(ten);
	this->set_Pass(pass);
}

void TacGia::LayDanhSachSach(List_Sach ls)
{
	for (int i = 0; i < ls.listsach.size(); i++)
	{
		if (ls.listsach[i].get_tacgia() == this->get_Ten())
		{
			if (ls.listsach[i].get_PhanQuyen() == 2)
			{
				continue;
			}
			tg.push_back(ls.listsach[i]);			
		}
	}
}

void TacGia::Them(List_Sach& ls)
{
	ls.ThemSach();
	tg.push_back(ls.listsach[ls.listsach.size() - 1]);
	cout << "Them sach thanh cong\n";
}

void TacGia::Xoa(List_Sach& ls)
{
	string ten;
	cin.ignore();
	cout << "Nhap ten sach can xoa: ";
	getline(cin, ten);
	Sach s = ls.TimKiemSach(ten);
	bool check = false;
	for (int i = 0; i < tg.size(); i++)
	{
		if (tg[i] == s)
		{
			for (int j = 0; j < ls.listsach.size(); j++)
			{
				if (ls.listsach[j] == s)
				{
					ls.listsach.erase(ls.listsach.begin() + j);
					tg.erase(tg.begin() + i);
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

void TacGia::Sua(List_Sach& ls)
{
	string ten;
	cin.ignore();
	cout << "Nhap ten sach can sua: ";
	getline(cin, ten);
	Sach s = ls.TimKiemSach(ten);
	bool check = false;
	for (int i = 0; i < tg.size(); i++)
	{
		if (tg[i] == s)
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
					tg[i].set_tensach(a);
					string b;
					cout << "Sua ma sach: ";
					getline(cin, b);
					ls.listsach[j].set_masach(b);
					tg[i].set_masach(b);
					int c;
					cout << "Sua gia sach: ";
					cin >> c;
					ls.listsach[j].set_giatien(c);
					tg[i].set_giatien(c);
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

void TacGia::DangKy(vector<TacGia>& ltg, TacGia& tacgia)
{
	while (true)
	{
		bool check = true;
		string ten;
		cin.ignore();
		cout << "Nhap ten tac gia: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		TacGia tg(ten, pass);
		for (int i = 0; i < ltg.size(); i++)
		{
			if (tg.get_Ten() == ltg[i].get_Ten())
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
		ltg.push_back(tg);
		tacgia = tg;
		break;
	}
}

void TacGia::DangNhap(vector<TacGia> ltg, TacGia& tacgia)
{
	while (true)
	{
		bool check = false;
		string ten;
		cin.ignore();
		cout << "Nhap ten tac gia: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		for (int i = 0; i < ltg.size(); i++)
		{
			if (ten == ltg[i].get_Ten() && pass == ltg[i].get_Pass())
			{
				tacgia = ltg[i];
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

void TacGia::PhanQuyen(List_Sach& ls)
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
			for (int i = 0; i < tg.size(); i++)
			{
				if (tg[i] == s)
				{
					for (int j = 0; j < ls.listsach.size(); j++)
					{
						if (ls.listsach[j] == s)
						{
							ls.listsach[j].set_PhanQuyen(3);
							tg[i].set_PhanQuyen(3);
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
			for (int i = 0; i < tg.size(); i++)
			{
				if (tg[i] == s)
				{
					for (int j = 0; j < ls.listsach.size(); j++)
					{
						if (ls.listsach[j] == s)
						{
							ls.listsach[j].set_PhanQuyen(0);
							tg[i].set_PhanQuyen(0);
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

void TacGia::GuiTinNhan(vector<TacGia> ListTacGia, vector<User> ListUser)
{
	int m;
	cout << "1. Nhan cho user\n";
	cout << "2. Nhan cho tac gia\n";
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
				cout << "Nhap ten tac gia: ";
				getline(cin, ten);
				for (int i = 0; i < ListTacGia.size(); i++)
				{
					if (ten == ListTacGia[i].get_Ten())
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
