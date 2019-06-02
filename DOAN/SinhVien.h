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
	
	vector<SinhVien> _GetListSV();

	friend istream &operator >> (istream &, SinhVien &);
	friend ostream &operator << (ostream &, SinhVien);

	vector<Diem> NhapDiem(SinhVien MSSV);

	void _Show_DSSV();
	void _Xoa_SinhVien();
	void _Nhap_Diem_SinhVien();
	void _GhiFile(vector<SinhVien>);
	void _Xoa_Diem_Cho_SV();
	void _Xem_Diem();


	string _Get_MSSV();
	string _Get_TenSV();
	string _Get_NgaySinh();
	string _Get_Lop();
	vector<Diem> _Get_DiemThi();
	
};

