#pragma once
#include "console.h"
#include "MonHoc.h"
#include "SinhVien.h"
class TruotMon
{
private:
	string MaSV, MaMH;
	int type;
public:
	TruotMon();
	~TruotMon();

	static ifstream FileIn;
	static ofstream FileOut;

	TruotMon(string, string, int);
	void GhiVaoFile();
	string GetTenMonHoc();
	string GetTenSinhVien();
};

