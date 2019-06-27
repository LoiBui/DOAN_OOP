#pragma once
#include "console.h"
#include "NgaySinh.h"
#include "Diem.h"


class SinhVien
{
private:
	string TenSV, MSSV, Lop;
	NgayS NgaySinh;
	vector<Diem> DiemThi;
public:
	SinhVien();
	~SinhVien();
	SinhVien(string, string, string, NgayS, vector<Diem>);


	static ifstream FileIn;
	static ofstream FileOut;

	friend istream &operator >> (istream &, SinhVien &);
	friend ostream &operator << (ostream &, SinhVien);

	void GhiSinhVienVaoFile();
	void NhapDiem();
	void SuaDiem();
	void SuaDiemTruotMon(string, int, float, float);
	void XoaDiem();

	string _Get_MSSV();
	string _Get_TenSV();
	string _Get_NgaySinh();
	string _Get_Lop();
	vector<Diem> _Get_DiemThi();


	void _Set_MSSV(string);
	void _Set_TenSV(string);
	void _Set_NgaySinh(NgayS);
	void _Set_Lop(string);
	void _Set_DiemThi(vector<Diem>);
};

