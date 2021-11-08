#ifndef DATA_H_
#define DATA_H_
#include "List_Sach.h"
#include "NXB.h"
#include "User.h"
#include "File.h"

class Data
{
public:
	void DocDuLieu(List_Sach&, vector<NXB>&, vector<TacGia>&, vector<User>&, vector<ADMIN>&);
};

#endif