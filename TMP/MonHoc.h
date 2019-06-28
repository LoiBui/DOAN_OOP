#pragma once
#include "console.h"
class MonHoc
{
private:
	string MaMH, TenMH;
	int SoTinChi;
public:
	MonHoc();
	MonHoc(string, string, int);
	~MonHoc();
	static ifstream FileIn;
	static ofstream FileOut;
	void NhapMonHoc();
	void XuatMonHoc();
	void GhiMonHocVaoFile();

	/////Get-Set///////
	string _Get_MaMH();
	string _Get_TenMH();
	int _Get_SoTC();


	void _Set_MaMH(string);
	void _Set_TenMH(string);
	void _Set_SoTC(int);
};

