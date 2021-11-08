#include "ADMIN.h"

ADMIN::ADMIN(string ten, string pass, string tuoi) :User(ten, pass, tuoi)
{
}

void ADMIN::set_Pass(string pass)
{
	this->Pass = pass;
}

string ADMIN::get_Pass()
{
	return this->Pass;
}

void ADMIN::set_Name(string name)
{
	this->Name = name;
}

string ADMIN::get_Ten()
{
	return this->Name;
}

void ADMIN::set_Age(string age)
{
	this->Age = age;
}

string ADMIN::get_Age()
{
	return this->Age;
}

ADMIN::ADMIN()
{
}


ADMIN::~ADMIN()
{
}


void ADMIN::DangNhap(vector<ADMIN> lad, ADMIN& ad)
{
	while (true)
	{
		bool check = false;
		string ten;
		cin.ignore();
		cout << "Nhap ten admin: ";
		getline(cin, ten);
		string pass;
		cout << "Nhap pass: ";
		getline(cin, pass);
		for (int i = 0; i < lad.size(); i++)
		{
			if (ten == lad[i].get_Ten() && pass == lad[i].get_Pass())
			{
				ad = lad[i];
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

void ADMIN::Them()
{
	int n;
	do
	{
		cout << "1. Them Sach\n";
		cout << "2. Them NXB\n";
		cout << "3. Them Tac gia\n";
		cout << "4. Them User\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n)
		{
			case 1:
			{
				ListSach.ThemSach();
				cout << "Them thanh cong\n";
				ListSach.GhiDuLieuSach();
				break;
			}
			case 2:
			{
				bool check = true;
				string ten;
				cin.ignore();
				cout << "Nhap ten NXB muon them: ";
				getline(cin, ten);
				string pass;
				cout << "Nhap pass: ";
				getline(cin, pass);
				NXB nxb(ten, pass);
				for (int i = 0; i < ListNXB.size(); i++)
				{
					if (ten == ListNXB[i].get_Ten())
					{
						cout << "Ten NXB da ton tai\n";
						check = false;
						break;
					}					
				}
				if (check == true)
				{
					this->ListNXB.push_back(nxb);
					File<NXB> write;
					write.Ghi(ListNXB, nxb);
					cout << "Them thanh cong\n";
				}			
				break;
			}
			case 3:
			{
				bool check = true;
				string ten;
				cin.ignore();
				cout << "Nhap ten tac gia muon them: ";
				getline(cin, ten);
				string pass;
				cout << "Nhap pass: ";
				getline(cin, pass);
				TacGia tg(ten, pass);
				for (int i = 0; i < ListTacGia.size(); i++)
				{
					if (ten == ListTacGia[i].get_Ten())
					{
						cout << "Ten tac gia da ton tai\n";
						check = false;
						break;
					}					
				}
				if (check == true)
				{
					this->ListTacGia.push_back(tg);
					File<TacGia> write;
					write.Ghi(ListTacGia, tg);
					cout << "Them thanh cong\n";
				}			
				break;
			}
			case 4:
			{
				bool check = true;
				string ten;
				cin.ignore();
				cout << "Nhap ten user muon them: ";
				getline(cin, ten);
				string pass;
				cout << "Nhap pass: ";
				getline(cin, pass);
				string tuoi;
				cout << "Nhap tuoi: ";
				getline(cin, tuoi);
				User u(ten, pass, tuoi);
				for (int i = 0; i < ListUser.size(); i++)
				{
					if (ten == ListUser[i].get_Ten())
					{
						cout << "Ten ten user da ton tai\n";
						check = false;
						break;
					}					
				}
				if (check == true)
				{
					ListUser.push_back(u);
					File<User> write;
					write.Ghi2(ListUser, u);
					cout << "Them thanh cong\n";
				}				
				break;
			}
		}
	} while (n >= 1 && n <= 4);
}

void ADMIN::Sua()
{
	int n;
	do
	{
		cout << "1. Sua Sach\n";
		cout << "2. Sua NXB\n";
		cout << "3. Sua Tac gia\n";
		cout << "4. Sua User\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n)
		{
			case 1:
			{
				ListSach.SuaSach();
				cout << "Sua thanh cong\n";
				ListSach.GhiDuLieuSach();
				break;
			}
			case 2:
			{
				bool check = false;
				string ten;
				cin.ignore();
				cout << "Nhap ten NXB muon sua: ";
				getline(cin, ten);
				for (int i = 0; i < ListNXB.size(); i++)
				{
					if (ten == ListNXB[i].get_Ten())
					{
						cout << "Nhap ten NXB moi: ";
						getline(cin, ten);
						ListNXB[i].set_Ten(ten);
						string pass;
						cin.ignore();
						cout << "Nhap pass moi: ";
						getline(cin, pass);
						ListNXB[i].set_Pass(pass);
						check = true;
						cout << "Sua thanh cong\n";
						NXB nxb;
						File<NXB> write;
						write.Ghi(ListNXB, nxb);
						break;
					}
				}
				if (check == false)
					cout << "Khong ton tai NXB do\n";
				break;
			}
			case 3:
			{
				bool check = false;
				string ten;
				cin.ignore();
				cout << "Nhap ten tac gia muon sua: ";
				getline(cin, ten);
				for (int i = 0; i < ListTacGia.size(); i++)
				{
					if (ten == ListTacGia[i].get_Ten())
					{
						cout << "Nhap ten tac gia moi: ";
						getline(cin, ten);
						ListTacGia[i].set_Ten(ten);
						string pass;
						cin.ignore();
						cout << "Nhap pass moi: ";
						getline(cin, pass);
						ListTacGia[i].set_Pass(pass);
						check = true;
						cout << "Sua thanh cong\n";
						TacGia tg;
						File<TacGia> write;
						write.Ghi(ListTacGia, tg);
						break;
					}
				}
				if (check == false)
					cout << "Khong ton tai tac gia do\n";
				break;
			}
			case 4:
			{
				bool check = false;
				string ten;
				cin.ignore();
				cout << "Nhap ten user muon sua: ";
				getline(cin, ten);
				for (int i = 0; i < ListUser.size(); i++)
				{
					if (ten == ListUser[i].get_Ten())
					{
						cout << "Nhap ten user moi: ";
						getline(cin, ten);
						ListUser[i].set_Name(ten);
						string pass;
						cin.ignore();
						cout << "Nhap pass moi: ";
						getline(cin, pass);
						ListUser[i].set_Pass(pass);
						string tuoi;
						cout << "Nhap tuoi moi: ";
						getline(cin, tuoi);
						ListUser[i].set_Age(tuoi);
						check = true;
						cout << "Sua thanh cong\n";
						User u;
						File<User> write;
						write.Ghi2(ListUser, u);
						break;
					}
				}
				if (check == false)
					cout << "Khong ton tai user do\n";
				break;
			}
		}
	} while (n >= 1 && n <= 4);
}

void ADMIN::Xoa()
{
	int n;
	do
	{
		cout << "1. Xoa Sach\n";
		cout << "2. Xoa NXB\n";
		cout << "3. Xoa Tac gia\n";
		cout << "4. Xoa User\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n)
		{
			case 1:
			{
				ListSach.XoaSach();
				cout << "Xoa thanh cong\n";
				ListSach.GhiDuLieuSach();
				break;
			}
			case 2:
			{
				string ten;
				cin.ignore();
				cout << "Nhap ten NXB muon xoa: ";
				getline(cin, ten);
				for (int i = 0; i < this->ListNXB.size(); i++)
				{
					if (ten == this->ListNXB[i].get_Ten())
					{
						ListNXB.erase(ListNXB.begin() + i);
						cout << "Xoa thanh cong\n";
						NXB nxb;
						File<NXB> write;
						write.Ghi(ListNXB, nxb);
						break;
					}
				}
				break;
			}
			case 3:
			{
				string ten;
				cin.ignore();
				cout << "Nhap ten tac gia muon xoa: ";
				getline(cin, ten);
				for (int i = 0; i < this->ListTacGia.size(); i++)
				{
					if (ten == this->ListTacGia[i].get_Ten())
					{
						ListTacGia.erase(ListTacGia.begin() + i);
						cout << "Xoa thanh cong\n";
						TacGia tg;
						File<TacGia> write;
						write.Ghi(ListTacGia, tg);
						break;
					}
				}
				break;
			}
			case 4:
			{
				string ten;
				cin.ignore();
				cout << "Nhap ten user muon xoa: ";
				getline(cin, ten);
				for (int i = 0; i < this->ListUser.size(); i++)
				{
					if (ten == this->ListUser[i].get_Ten())
					{
						ListUser.erase(ListUser.begin() + i);
						cout << "Xoa thanh cong\n";
						User u;
						File<User> write;
						write.Ghi2(ListUser, u);
						break;
					}
				}
				break;
			}
		}
	} while (n >= 1 && n <= 4);
}

void ADMIN::PhanQuyen()
{
	int n;
	cout << "1. Khoa quyen\n";
	cout << "2. Mo quyen\n";
	cout << "Nhap lua chon: ";
	cin >> n;
	switch (n)
	{
		case 1:
		{
			string ten;
			cin.ignore();
			cout << "Nhap ten sach muon phan quyen: ";
			getline(cin, ten);
			Sach s = ListSach.TimKiemSach(ten);
			for (int i = 0; i < ListSach.listsach.size(); i++)
			{
				if (ListSach.listsach[i] == s)
				{
					ListSach.listsach[i].set_PhanQuyen(1);
					cout << "Phan quyen thanh cong\n";
				}				
			}			
			break;
		}
		case 2:
		{
			string ten;
			cin.ignore();
			cout << "Nhap ten sach muon phan quyen: ";
			getline(cin, ten);
			Sach s = ListSach.TimKiemSach(ten);
			for (int i = 0; i < ListSach.listsach.size(); i++)
			{
				if (ListSach.listsach[i] == s)
				{
					ListSach.listsach[i].set_PhanQuyen(0);
					cout << "Phan quyen thanh cong\n";
				}
			}
			break;
		}
	}
}
	

void ADMIN::GuiTinNhan()
{
	int n;
	cout << "1. Nhan cho 1 nguoi\n";
	cout << "2. Nhan cho toan bo nguoi trong he thong\n";
	cout << "Nhap lua chon: ";
	cin >> n;
	switch (n)
	{
		case 1:
		{
			int m;
			cout << "1. Nhan cho user\n";
			cout << "2. Nhan cho NXB\n";
			cout << "3. Nhan cho tac gia\n";
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
				case 3:
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
			break;
		}
		case 2:
		{
			string message;
			cin.ignore();
			cout << "Nhap tin nhan: ";
			getline(cin, message);
			ofstream f;
			for (int i = 0; i < ListNXB.size(); i++)
			{
				f.open("D:/18120296/18120296/Data/" + ListNXB[i].get_Ten() + "tinnhan.txt", ios_base::app);
				f << "Nguoi gui: " << this->get_Ten() << endl << message << endl;
				f.close();
			}
			for (int i = 0; i < ListTacGia.size(); i++)
			{
				f.open("D:/18120296/18120296/Data/" + ListTacGia[i].get_Ten() + "tinnhan.txt", ios_base::app);
				f << "Nguoi gui: " << this->get_Ten() << endl << message << endl;
				f.close();
			}
			for (int i = 0; i < ListUser.size(); i++)
			{
				f.open("D:/18120296/18120296/Data/" + ListUser[i].get_Ten() + "tinnhan.txt", ios_base::app);
				f << "Nguoi gui: " << this->get_Ten() << endl << message << endl;
				f.close();
			}
			cout << "Da gui thanh cong\n";
			break;
		}
	}
	
}

void ADMIN::DanhSachTaiKhoan()
{
	cout << "Co " << ListUser.size() << " khach hang" << endl;
	for (int i = 0; i < ListUser.size(); i++)
	{
		cout << "User name: " << ListUser[i].get_Ten() << "\tPassword: ";
		for (int j = 0; j < ListUser[i].get_Pass().length(); j++)
		{
			cout << "*";
		}
		cout << "\tAge: " << ListUser[i].get_Age() << endl;
	}
	cout << "Co " << ListTacGia.size() << " tac gia" << endl;
	for (int i = 0; i < ListTacGia.size(); i++)
	{
		cout << "User name: " << ListTacGia[i].get_Ten() << "\tPassword: ";
		for (int j = 0; j < ListTacGia[i].get_Pass().length(); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "Co " << ListNXB.size() << " nha xuat ban" << endl;
	for (int i = 0; i < ListNXB.size(); i++)
	{
		cout << "User name: " << ListNXB[i].get_Ten() << "\tPassword: ";
		for (int j = 0; j < ListNXB[i].get_Pass().length(); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}

void ADMIN::XuatHoaDonCuaUser()
{
	for (int i = 0; i < ListUser.size(); i++)
	{
		ListUser[i].XemHoaDon();
		cout << "Tong tien: " << ListUser[i].tongtien << endl;
	}
}

void ADMIN::HoaDonCoTongTienCaoNhat()
{
	float tongtien = 0;
	for (int i = 0; i < ListUser.size(); i++)
	{
		if (ListUser[i].tongtien > tongtien)
		{
			tongtien = ListUser[i].tongtien;
		}
	}
	for (int i = 0; i < ListUser.size(); i++)
	{
		if (ListUser[i].tongtien == tongtien)
		{
			ListUser[i].XemHoaDon();
		}
	}
}

