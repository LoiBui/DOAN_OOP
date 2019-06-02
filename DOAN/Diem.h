#pragma once
#include "console.h"
#include "MonHoc.h"
class Diem
{
private:
	float DiemKT, DiemQT;
	string MaMH;
public:
	Diem();
	Diem(string, float, float);
	~Diem();

	friend istream &operator >> (istream &, Diem &);
	friend ostream &operator << (ostream &, Diem);


	///////GET- SET//////
	string _Get_MaMH();
	float _Get_DiemKT();
	float _Get_DiemQT();
};

