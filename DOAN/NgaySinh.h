#pragma once
#include "console.h"
class NgayS
{
private:
	int Ngay, Thang, Nam;
public:
	NgayS();
	~NgayS();
	NgayS(int, int, int);

	friend istream &operator >> (istream &, NgayS &);
	friend ostream &operator << (ostream &, NgayS);

	string _getDate();
	NgayS _ReadFile();
};

