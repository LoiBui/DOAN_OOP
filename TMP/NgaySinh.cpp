#include "NgaySinh.h"
#include "SinhVien.h"

NgayS::NgayS()
{
	this->Ngay = 24;
	this->Thang = 11;
	this->Nam = 1998;
}

NgayS::NgayS(int ngay, int thang, int nam){
	this->Ngay = ngay;
	this->Thang = thang;
	this->Nam = nam;
}

NgayS::~NgayS()
{
}

int DayInMonth(int month, int year){
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

		if (isLeapYear == 0)
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

istream &operator >> (istream &i, NgayS &ns){
	cout << "	Nhap NamSinh: ";
	ns.Nam = TryCatch(1990, 2019);
	cout << "	Nhap ThangSinh: ";
	ns.Thang = TryCatch(1, 12);
	cout << "	Nhap NgayS: ";
	ns.Ngay = TryCatch(1, DayInMonth(ns.Thang, ns.Nam));

	return i;
}

ostream &operator << (ostream &o, NgayS ns){
	cout << to_string(ns.Ngay) + "/" + to_string(ns.Thang) + "/" + to_string(ns.Nam);
	return o;
}

string NgayS::_getDate(){
	return to_string(this->Ngay) + "/" + to_string(this->Thang) + "/" + to_string(this->Nam);
}

//NgayS NgayS::_ReadFile(){
//
//}