#include "UuDai.h"

UuDai::UuDai(string tuoi, float giamgiatuoi)
{
	this->tuoi = tuoi;
	this->GiamGiaTuoi = giamgiatuoi;
	this->tensach = "";
	this->GiamGiaSach = 1;
}

UuDai::UuDai(float giamgiasach, string tensach)
{
	this->tuoi = "";
	this->GiamGiaTuoi = 1;
	this->tensach = tensach;
	this->GiamGiaSach = giamgiasach;
}

float UuDai::UuDaiTuoi(User u)
{
	if (stoi(u.get_Age()) <= stoi(tuoi))
	{
		return 1 - GiamGiaTuoi;
	}
	else
	{
		return 1;
	}
}

float UuDai::UuDaiSach(string tensach)
{
	if (tensach == this->tensach)
	{
		return 1 - GiamGiaSach;
	}
	else
	{
		return 1;
	}
}
