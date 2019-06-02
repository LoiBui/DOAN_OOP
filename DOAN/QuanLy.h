#pragma once
#include "SinhVien.h"
#include "NgaySinh.h"

class QuanLy
{
private:
	vector<SinhVien> DSSV;
public:
	QuanLy();
	~QuanLy();

	////static
	static ifstream FileIn;
	static ofstream FileOut;
	

	friend istream &operator >> (istream &, QuanLy &);
	friend ostream &operator << (ostream &, QuanLy);

	int _ShowDSSV();
	vector<string> _ShowDSLop();
	void _LoadDSSVFile();
	vector<SinhVien> _Get_DSSV();
	void _Xem_Diem_Theo_MH();
	void _Xem_Diem_Theo_LOP();

	void func();
};

