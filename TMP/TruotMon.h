#pragma once
#include "console.h"
#include "MonHoc.h"
#include "SinhVien.h"
class TruotMon
{
private:
	string MaSV, MaMH;
	int type, trangthai;
	float DQT, DKT;
public:
	TruotMon();
	~TruotMon();

	static ifstream FileIn;
	static ofstream FileOut;

	TruotMon(string, string, int, float, float, int);
	void GhiVaoFile();
	string GetTenMonHoc();
	string GetTenSinhVien();

	string GetMSSV();
	string GetMaMH();
	int GetType();
	int GetTrangThai();
	float GetDQT();
	float GetDKT();

	void SetDQT(float);
	void SetDKT(float);
	void SetTrangThai(int);
};

