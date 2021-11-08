#include "User.h"

User::User()
{
}

User::~User()
{
}

User::User(string ten, string pass, string tuoi)
{
	this->set_Name(ten);
	this->set_Pass(pass);
	this->set_Age(tuoi);
}

void User::set_Pass(string pass)
{
	this->Pass = pass;
}

string User::get_Pass()
{
	return this->Pass;
}

void User::set_Name(string name)
{
	this->Name = name;
}

string User::get_Ten()
{
	return this->Name;
}

void User::set_Age(string age)
{
	this->Age = age;
}

string User::get_Age()
{
	return this->Age;
}

void User::MuaSach(List_Sach GioHang)
{
	for (int i = 0; i < GioHang.listsach.size(); i++)
	{
		HoaDon h;
		cout << GioHang.listsach[i].get_tensach() << endl;
		h.ThemHoaDon(GioHang.listsach[i]);
		lh.listhoadon.push_back(h);
	}
}

void User::CapNhatDonhang(List_Sach ls)
{
	int n = 0;
	cout << "1. Them bot so luong sach\n";
	cout << "2. Them bot hoa don\n";
	cout << "Nhap lua chon: ";
	cin >> n;
	switch (n)
	{
		case 1:
		{
			string ten;
			cin.ignore();
			cout << "Nhap ten sach muon thay doi so luong: ";
			getline(cin, ten);
			for (int i = 0; i < lh.listhoadon.size(); i++)
			{
				if (lh.listhoadon[i].s.get_tensach() == ten)
				{
					int n;
					cout << "Nhap lai so luong sach muon mua: ";
					cin >> n;
					lh.listhoadon[i].Set_SoLuong(n);
					lh.listhoadon[i].Set_GiaTien(n * lh.listhoadon[i].s.get_giatien());
				}
			}
			break;
		}
		case 2:
		{
			int m = 0;
			cout << "1. Them hoa don.\n";
			cout << "2. Bot hoa don.\n";
			cout << "Nhap lua chon: ";
			cin >> m;
			switch (m)
			{
				case 1:
				{
					ls.XuatThongTinSach();
					lh.NhapHoaDon(ls);
					break;
				}
				case 2:
				{
					string ten;
					cin.ignore();
					cout << "Nhap ten sach muon xoa: ";
					getline(cin, ten);
					for (int i = 0; i < lh.listhoadon.size(); i++)
					{
						if (lh.listhoadon[i].s.get_tensach() == ten)
						{
							lh.listhoadon.erase(lh.listhoadon.begin() + i);
						}
					}
					break;
				}
			}
		}
	}
}

void User::XemHoaDon()
{
	lh.ThanhPhanTien(lh);
}

void User::GhiHoaDon(float uudai1)
{
	ofstream f;
	f.open("D:/18120296/18120296/Data/" + this->get_Ten() + ".txt", ios_base::app);
	for (int i = 0; i < lh.listhoadon.size(); i++)
	{
		f << lh.listhoadon[i].s.get_tensach() << "\t" << lh.listhoadon[i].s.get_giatien() << "\t"
			<< lh.listhoadon[i].Get_SoLuong() << "\t" << lh.listhoadon[i].Get_GiaTien() << endl;
	}
	f.close();
}

void User::DocHoaDon()
{
	ifstream f;
	f.open("D:/18120296/18120296/Data/" + this->get_Ten() + ".txt");
	while (!f.eof())
	{
		string ten;
		getline(f, ten, '\t');
		if (ten == "\n")
		{
			break;
		}
		float tien;
		f >> tien;
		int soluong;
		f >> soluong;
		float giatien;
		f >> giatien;
		HoaDon h(ten, tien, soluong, giatien);
		this->lh.listhoadon.push_back(h);
	}
	for (int i = 0; i < lh.listhoadon.size(); i++)
	{
		this->tongtien += lh.listhoadon[i].Get_GiaTien();
	}
}


void User::DangKy(vector<User>& luser,User& user)
{
	while (true)
	{
		bool check = true;
		string ten;
		cin.ignore();
		cout << "Nhap ten user: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		string tuoi;
		cout << "Nhap tuoi: ";
		getline(cin, tuoi);
		User u(ten, pass, tuoi);
		for (int i = 0; i < luser.size(); i++)
		{
			if (u.get_Ten() == luser[i].get_Ten())
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
		luser.push_back(u);
		user = u;
		break;
	}
}

void User::DangNhap(vector<User> luser,User& u)
{
	while (true)
	{
		bool check = false;
		string ten;
		cin.ignore();
		cout << "Nhap ten user: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		for (int i = 0; i < luser.size(); i++)
		{
			if (ten == luser[i].get_Ten() && pass == luser[i].get_Pass())
			{
				u = luser[i];
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

void User::GuiTinNhan(vector<User> luser)
{
	while (true)
	{
		bool check = false;
		string ten;
		cin.ignore();
		cout << "Nhap ten user: ";
		getline(cin, ten);
		for (int i = 0; i < luser.size(); i++)
		{
			if (ten == luser[i].get_Ten())
			{
				check = true;
				string message;
				cout << "Nhap tin nhan: ";
				getline(cin, message);
				ofstream f;
				f.open("D:/18120296/18120296/Data/"+ ten + "tinnhan.txt", ios_base::app);
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
}
