#include "MonHoc.h"


MonHoc::MonHoc()
{
}
MonHoc::MonHoc(string MaMH, string TenMH, int stc){
	this->MaMH = MaMH;
	this->TenMH = TenMH;
	this->SoTinChi = stc;
}

MonHoc::~MonHoc()
{
}
ifstream MonHoc::FileIn;
ofstream MonHoc::FileOut;

istream &operator >> (istream &i, MonHoc &mh)
{
	cout << "Nhap TenMonHoc: ";
	mh.TenMH = DOWHILE1(5, 40, "Do Dai 'TenMonHoc' Trong Khoang(1->40)");

	cout << "Nhap SoTinChi: ";
	mh.SoTinChi = TryCatch(0, 10);

	return i;
}

ostream &operator << (ostream &o, MonHoc mh)
{
	cout << "Ma Mon Hoc: " << mh.MaMH;
	cout << "\nTen Mon Hoc: " << mh.TenMH;
	cout << "\nSo Tin Chi: " << mh.SoTinChi;
	return o;
}

void MonHoc::GhiMonHocVaoFile(){
	//ghi vào file
	string MH = MaMH + "|" + TenMH + "|" + to_string(SoTinChi);
	MonHoc::FileOut << MH;
}



//////GET-SET/////
string MonHoc::_Get_MaMH(){
	return this->MaMH;
}

string MonHoc::_Get_TenMH(){
	return this->TenMH;
}

int MonHoc::_Get_SoTC(){
	return this->SoTinChi;
}

void MonHoc::_Set_MaMH(string mamh){
	this->MaMH = mamh;
}

void MonHoc::_Set_TenMH(string tenmh){
	this->TenMH = tenmh;
}

void MonHoc::_Set_SoTC(int stc){
	this->TenMH = stc;
}