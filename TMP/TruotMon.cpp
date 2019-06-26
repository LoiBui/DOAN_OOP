#include "TruotMon.h"

ifstream TruotMon::FileIn;
ofstream TruotMon::FileOut;

TruotMon::TruotMon()
{
	this->trangthai = 0;
}


TruotMon::~TruotMon()
{
}


TruotMon::TruotMon(string MaSV, string MaMH, int type){
	this->MaSV = MaSV;
	this->MaMH = MaMH;
	this->type = type;
	this->trangthai = 0;
}

void TruotMon::GhiVaoFile(){
	string tm = MaSV + "|" + MaMH + "|" + to_string(type) + " " + to_string(this->trangthai);
	TruotMon::FileOut << tm;
}

string TruotMon::GetTenMonHoc(){
	string s;

	MonHoc::FileIn.close();
	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
	while (!MonHoc::FileIn.eof()){
		getline(MonHoc::FileIn, s, '|');
		if (MaMH == s){
			getline(MonHoc::FileIn, s, '|');
			return s;
		}
		getline(MonHoc::FileIn, s);
	}
	MonHoc::FileIn.close();
	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);

	return "Mon Hoc Nay Da Bi Xoa";
}

string TruotMon::GetTenSinhVien(){
	string s;

	SinhVien::FileIn.close();
	SinhVien::FileIn.open("DS_SINHVIEN.txt", ios_base::in);
	while (!SinhVien::FileIn.eof()){
		getline(SinhVien::FileIn, s, '|');
		getline(SinhVien::FileIn, s, '|');
		if (MaSV == s){
			getline(SinhVien::FileIn, s, '|');
			return s;
		}
		getline(SinhVien::FileIn, s);
	}
	SinhVien::FileIn.close();
	SinhVien::FileIn.open("DS_SINHVIEN.txt", ios_base::in);

	return "Sinh Vien Nay Da Bi Xoa";
}

string TruotMon::GetMSSV(){
	return this->MaSV;
}

int TruotMon::GetType(){
	return this->type;
}

int TruotMon::GetTrangThai(){
	return this->trangthai;
}