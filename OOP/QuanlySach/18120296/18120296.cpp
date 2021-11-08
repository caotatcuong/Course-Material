#include "Data.h"
#include "List_HoaDon.h"
#include "List_Sach.h"
#include "Khach.h"
#include "User.h"
#include "File.h"
#include "ADMIN.h"
#include "UuDai.h"

int main()
{
	List_Sach lsach;
	vector<NXB> lnxb;
	vector<TacGia> ltg;
	vector<User> luser;
	vector<ADMIN> lad;

	Khach khachhang;
	User user;
	List_Sach GioHang;

	NXB nxb;

	TacGia tacgia;

	ADMIN ad;

	UuDai uudaitheotuoi("14", 0.3);
	float uudai1;
	UuDai uudaitheosach(0.2, "Mat Biec");
	float uudai2;
	int n;
	do
	{
		system("cls");
		lsach.listsach.clear();		
		lnxb.clear();
		ltg.clear();
		luser.clear();
		Data data;
		data.DocDuLieu(lsach, lnxb, ltg, luser, lad);
		cout << "THAY LUU Y EM DOC FILE DATA BANG DUONG DAN NEN THAY DE Y DUM EM. Duong dan: D:/18120296/18120296/Data/" << endl << endl;
		cout << "1. Nguoi dung\n";
		cout << "2. NXB\n";
		cout << "3. Tac gia\n";
		cout << "4. ADMIN\n";
		cout << "5. Thoat\n";
		cout << "Nhap lua chon: ";
		cin >> n;
		switch (n)
		{
			case 1:
			{
				system("cls");
				bool check = false;
				int m;
				do
				{
					system("cls");
					cout << "-----------------------Menu----------------------\n";
					cout << "1. Chon sach.\n";
					cout << "2. Dang ky.\n";
					cout << "3. Dang nhap.\n";
					cout << "4. Mua sach.\n";
					cout << "5. Cap nhat hoa don.\n";
					cout << "6. Xem hoa don\n";
					cout << "7. Gui tin nhan\n";
					cout << "8. Thoat\n";
					cout << "Nhap lua chon: ";
					cin >> m;
					switch (m)
					{						
						case 1:
						{
							system("cls");
							lsach.XuatThongTinSach();
							GioHang = khachhang.ChonSach(lsach);	
							system("pause");
							break;
						}
						case 2:
						{
							system("cls");
							user.DangKy(luser, user);
							File<User> write;
							write.Ghi2(luser, user);
							system("pause");
							break;
						}
						case 3:
						{
							system("cls");
							user.DangNhap(luser, user);
							check = true;
							system("pause");
							break;
						}
						case 4:
						{
							system("cls");
							if (check == true)
							{
								user.MuaSach(GioHang);								
							}							
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 5:
						{
							system("cls");
							if (check == true)
								user.CapNhatDonhang(lsach);
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 6:
						{
							system("cls");
							if (check == true)
							{
								for (int i = 0; i < user.lh.listhoadon.size(); i++)
								{
									uudai2 = uudaitheosach.UuDaiSach(user.lh.listhoadon[i].s.get_tensach());									
									user.lh.listhoadon[i].Set_GiaTien(user.lh.listhoadon[i].Get_GiaTien() * uudai2);
								}
								user.XemHoaDon();
								uudai1 = uudaitheotuoi.UuDaiTuoi(user);
								cout << "Tong tien ban phai thanh toan la: " << user.lh.TongTien() * uudai1 << endl;
								user.GhiHoaDon(uudai1);
							}
							else
								cout << "Ban chua dang nhap";
							system("pause");
							break;
						}
						case 7:
						{
							system("cls");
							if (check == true)
								user.GuiTinNhan(luser);
							else
								cout << "Ban chua dang nhap";
							system("pause");
							break;
						}
					}
				} while (m >= 1 && m <= 7);
				break;
			}
			case 2:
			{
				system("cls");
				bool check = false;	
				int m;
				do
				{
					system("cls");
					cout << "-----------------------Menu----------------------\n";
					cout << "1. Dang ky.\n";
					cout << "2. Dang nhap.\n";
					cout << "3. Lay danh sach sach cua nxb.\n";
					cout << "4. Them sach\n";
					cout << "5. Sua sach.\n";
					cout << "6. Xoa sach.\n";
					cout << "7. Phan quyen.\n";
					cout << "8. Gui tin nhan\n";
					cout << "9. Sach mua nhieu nhat\n";
					cout << "10. Thoat\n";		
					cout << "Nhap lua chon: ";					
					cin >> m;
					switch (m)
					{
						case 1:
						{
							system("cls");
							nxb.DangKy(lnxb, nxb);
							File<NXB> write;
							write.Ghi(lnxb,nxb);
							system("pause");
							break;
						}
						case 2:
						{
							system("cls");
							nxb.DangNhap(lnxb, nxb);
							check = true;
							system("pause");
							break;
						}
						case 3:
						{
							system("cls");
							if (check == true)
							{
								nxb.nxb.clear();
								nxb.LayDanhSachSach(lsach);
								cout << "Lay danh sach thanh cong\n";
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 4:
						{
							system("cls");
							if (check == true)
							{
								nxb.Them(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;						
						}
						case 5:
						{
							system("cls");
							if (check == true)
							{
								nxb.Sua(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 6:
						{
							system("cls");
							if (check == true)
							{
								nxb.Xoa(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 7:
						{
							system("cls");
							if (check == true)
							{
								nxb.PhanQuyen(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}				
						case 8:
						{
							system("cls");
							if (check == true)
							{
								nxb.GuiTinNhan(lnxb, luser);
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 9:
						{
							system("cls");
							if (check == true)
							{
								for (int i = 0; i < luser.size(); i++)
								{
									luser[i].DocHoaDon();
								}
								nxb.XemSachbanNhieuNhat(luser);
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
					}
				} while (m >= 1 && m <= 9);
				break;
			}
			case 3:
			{
				system("cls");
				bool check = false;
				int m;
				do
				{
					system("cls");
					cout << "-----------------------Menu----------------------\n";
					cout << "1. Dang ky.\n";
					cout << "2. Dang nhap.\n";
					cout << "3. Them sach.\n";
					cout << "4. Sua sach.\n";
					cout << "5. Xoa sach.\n";
					cout << "6. Lay danh sach sach cua tac gia.\n";
					cout << "7. Phan quyen.\n";
					cout << "8. Gui tin nhan\n";
					cout << "9. Thoat\n";
					cout << "Nhap lua chon: ";
					cin >> m;
					switch (m)
					{
						case 1:
						{
							system("cls");
							tacgia.DangKy(ltg, tacgia);
							File<TacGia> write;
							write.Ghi(ltg, tacgia);
							system("pause");
							break;
						}
						case 2:
						{
							system("cls");
							tacgia.DangNhap(ltg, tacgia);
							check = true;
							system("pause");
							break;
						}
						case 3:
						{
							system("cls");
							if (check == true)
							{
								tacgia.tg.clear();
								tacgia.LayDanhSachSach(lsach);
								cout << "Lay danh sach sach thanh cong\n";
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 4:
						{
							system("cls");
							if (check == true)
							{
								tacgia.Them(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;							
						}
						case 5:
						{
							system("cls");
							if (check == true)
							{
								tacgia.Sua(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;							
						}
						case 6:
						{
							system("cls");
							if (check == true)
							{
								tacgia.Xoa(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 7:
						{
							system("cls");
							if (check == true)
							{								
								tacgia.PhanQuyen(lsach);
								lsach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 8:
						{
							system("cls");
							if (check == true)
							{
								tacgia.GuiTinNhan(ltg, luser);
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
					}
				} while (m >= 1 && m <= 8);
				break;
			}
			case 4:
			{
				system("cls");
				bool check = false;
				int m;
				do
				{
					system("cls");
					cout << "-----------------------Menu----------------------\n";
					cout << "1. Dang nhap.\n";
					cout << "2. Them.\n";
					cout << "3. Sua.\n";
					cout << "4. Xoa.\n";
					cout << "5. Phan quyen\n";
					cout << "6. Gui tin nhan.\n";
					cout << "7. Danh sach tai khoan\n";
					cout << "8. Danh sach hoa don\n";
					cout << "9. Hoa don co tong tin cao nhat\n";					
					cout << "Nhap lua chon: ";
					cin >> m;
					switch (m)
					{
						case 1:
						{
							system("cls");
							ad.DangNhap(lad, ad);	
							ad.ListSach = lsach;
							ad.ListNXB = lnxb;
							ad.ListTacGia = ltg;
							ad.ListUser = luser;
							for (int i = 0; i < ad.ListUser.size(); i++)
							{								
								ad.ListUser[i].DocHoaDon();
							}
							check = true;
							system("pause");
							break;
						}
						case 2:
						{
							system("cls");
							if (check == true)
								ad.Them();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 3:
						{
							system("cls");
							if (check == true)
								ad.Sua();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 4:
						{
							system("cls");
							if (check == true)
								ad.Xoa();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 5:
						{
							system("cls");
							if (check == true)
							{
								ad.PhanQuyen();
								ad.ListSach.GhiDuLieuSach();
							}
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}	
						case 6:
						{
							system("cls");
							if (check == true)
								ad.GuiTinNhan();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 7:
						{
							system("cls");
							if (check == true)
								ad.DanhSachTaiKhoan();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 8:
						{
							system("cls");
							if (check == true)
								ad.XuatHoaDonCuaUser();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
						case 9:
						{
							system("cls");
							if (check == true)
								ad.HoaDonCoTongTienCaoNhat();
							else
								cout << "Ban chua dang nhap\n";
							system("pause");
							break;
						}
					}
				} while (m >= 1 && m <= 9);
				break;
			}
			case 5:
			{
				exit(0);
				break;
			}
		}
	} while (n >= 1 && n <= 5);
	system("pause");
	return 0;
}


