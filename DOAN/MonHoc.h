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
	friend istream &operator >> (istream &, MonHoc &);
	friend ostream &operator << (ostream &, MonHoc);

	//delete//
	void XoaMonHoc();
	//////static//////////
	static vector<MonHoc> _DSMH;
	static ifstream FileIn;
	static ofstream FileOut;
	static MonHoc _Get_MH_byMaMH(string);
	static void _ShowDSMH();

	/////Get-Set///////
	string _Get_MaMH();
	string _Get_TenMH();
	int _Get_SoTC();
	

	void _Set_MaMH(string);
	void _Set_TenMH(string);
	void _Set_SoTC(int);
};

