#pragma once
#include "Sach.h"
#include "User.h"
class UuDai
{
private:
	string tuoi;
	string tensach;
	float GiamGiaTuoi;
	float GiamGiaSach;
public:
	UuDai(string, float);
	UuDai(float, string);
	float UuDaiTuoi(User);
	float UuDaiSach(string);
};

