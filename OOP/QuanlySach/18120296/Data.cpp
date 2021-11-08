#include "Data.h"

void Data::DocDuLieu(List_Sach& ls, vector<NXB>& lnxb, vector<TacGia>& ltg, vector<User>& luser, vector<ADMIN>& lad)
{
	ls.DocDuLieuSach();
	NXB nxb;
	File<NXB> read1;
	read1.Doc(lnxb, nxb);
	TacGia tg;
	File<TacGia> read2;
	read2.Doc(ltg, tg);
	User u;
	File<User> read3;
	read3.Doc2(luser, u);
	ADMIN ad;
	File<ADMIN> read4;
	read4.Doc2(lad, ad);
}
