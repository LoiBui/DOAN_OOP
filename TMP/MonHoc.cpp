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

void MonHoc::NhapMonHoc()
{
	cout << "Nhap TenMonHoc: ";
	TenMH = DOWHILE1(5, 40, "Do Dai 'TenMonHoc' Trong Khoang(1->40)");

	cout << "Nhap SoTinChi: ";
	SoTinChi = TryCatch(0, 10);
}

void MonHoc::XuatMonHoc()
{
	cout << "Ma Mon Hoc: " << MaMH;
	cout << "\nTen Mon Hoc: " << TenMH;
	cout << "\nSo Tin Chi: " << SoTinChi;
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