#include "Diem.h"

Diem::Diem()
{
}

Diem::Diem(string mmh, float diemqt, float diemkt){
	this->MaMH = mmh;
	this->DiemKT = diemkt;
	this->DiemQT = diemqt;
}

Diem::~Diem()
{
}

void Diem::NhapDiem(){
	bool check;
	cout << "\nNhap vao MaMH: ";
	while (true)
	{
		check = false;
		fflush(stdin);
		
		TextColor(MauChu);
		getline(cin, MaMH);
		TextColor(7);

		MonHoc::FileIn.close();
		MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
		while (!MonHoc::FileIn.eof()){
			string s;
			getline(MonHoc::FileIn, s, '|');
			if (MaMH == s){
				check = true;
				getline(MonHoc::FileIn, s, '|');
				cout << "==>Ten Mon Hoc: ";
				TextCL(MauChu, s);
				cout << endl;
				break;
			}
			getline(MonHoc::FileIn, s);
		}
		MonHoc::FileIn.close();
		MonHoc::FileIn.open("MONHOC.txt", ios_base::in);

		if (!check){
			TextCL(4, "	[Ma Mon Hoc KHONG ton tai] ");
			cout << "\n	Nhap Lai: ";
		}
		else break;
	}


	cout << "Nhap vao DiemQT: ";
	
	TextColor(MauChu);
	DiemQT = TryCatch1(0, 10);
	TextColor(7);

	cout << "Nhap vao DiemKT: ";
	TextColor(MauChu);
	DiemKT = TryCatch1(0, 10);
	TextColor(7);
	

}


void Diem::XuatDiem(){
	cout << "\nMaMH: " << MaMH;
	cout << "   Diem QT: " << DiemQT;
	cout << "   Diem KT: " << DiemKT;
}

float Diem::TinhDiemHe4(){
	float Diem = this->DiemKT * 0.7 + this->DiemQT * 0.3;
	if (Diem < 4) return 0;
	if (Diem >= 4 && Diem < 5){
		return 1;
	}
	if (Diem >= 5 && Diem < 5.5){
		return 1.5;
	}
	if (Diem >= 5.5 && Diem < 6.5){
		return 2;
	}
	if (Diem >= 6.5 && Diem < 7){
		return 2.5;
	}
	if (Diem >= 7 && Diem < 8){
		return 3;
	}
	if (Diem >= 8 && Diem < 8.5){
		return 3.5;
	}
	return 4;
}

string Diem::TinhDiemChu(){
	float Diem = this->TinhDiemHe4();
	if (Diem == 1){
		return "D";
	}
	if (Diem == 1.5){
		return "D+";
	}
	if (Diem == 2){
		return "C";
	}
	if (Diem == 2.5){
		return "C+";
	}
	if (Diem == 3){
		return "B";
	}
	if (Diem == 3.5){
		return "B+";
	}
	if (Diem == 4){
		return "A";
	}
	return "F";
}

string Diem::XepLoai(float Diem){
	if (Diem == 0) {
		return "Yeu";
	}
	if (Diem < 2.5){
		return "Trung Binh";
	}
	if (Diem < 3.2){
		return "Kha";
	}
	if (Diem < 3.6){
		return "Gioi";
	}
	return "Xuat Xac";
}

string Diem::GetTenMonHoc(){
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

int Diem::GetSoTinChi(){
	string s;
	MonHoc::FileIn.close();
	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
	while (!MonHoc::FileIn.eof()){
		getline(MonHoc::FileIn, s, '|');
		if (MaMH == s){
			getline(MonHoc::FileIn, s, '|');
			int stc;
			MonHoc::FileIn >> stc;
			return stc;
		}
		getline(MonHoc::FileIn, s);
	}
	MonHoc::FileIn.close();
	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
	return 0;
}
//////////GET - SET//////////
string Diem::_Get_MaMH()
{ 
	return this->MaMH; 
}
float Diem::_Get_DiemKT()
{ 
	return this->DiemKT; 
}
float Diem::_Get_DiemQT()
{ 
	return this->DiemQT; 
}

void Diem::_Set_DiemKT(float x){
	this->DiemKT = x;
}

void Diem::_Set_DiemQT(float x){
	this->DiemQT = x;
}

void Diem::_Set_MaMH(string x){
	this->MaMH = x;
}