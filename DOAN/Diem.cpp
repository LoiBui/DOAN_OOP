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

istream &operator >> (istream &i, Diem &d){
	bool check;
	while (true)
	{
		check = true;
		fflush(stdin);
		cout << "\nNhap vao MaMH: ";
		getline(i, d.MaMH);
		for (int i = 0; i < MonHoc::_DSMH.size(); i++)
		{
			if (MonHoc::_DSMH[i]._Get_MaMH() == d.MaMH){
				check = false;
				cout << "==>Ten Mon Hoc: " << MonHoc::_DSMH[i]._Get_TenMH() << endl;
				break;
			}
		}
		if (check == true){
			TextCL(268, "    [Ma Mon Hoc KHONG ton tai] ");
			cout << "\n	Nhan 1: De nhap lai.\n	Nhan 2: De them MonHoc moi.";
			int LuaChon;
			do
			{
				cout << "\n	Lua Chon: ";
				cin >> LuaChon;
				if (LuaChon < 1 || LuaChon > 2){
					TextCL(268, "		[Lua chon khong hop le. Xin vui long nhap lai [1, 2]");
				}
			} while (LuaChon < 1 || LuaChon > 2);
			if (LuaChon == 2) {

				cout << "~~~~~ THEM MOI MON HOC ~~~~~\n";
				MonHoc mh;
				cin >> mh;
				cout << "====>  THEM THANH CONG <====\n";
				MonHoc::_DSMH.push_back(mh);

				d.MaMH = mh._Get_MaMH();
				break;
			}
		}
		else break;
	}
	

	cout << "Nhap vao DiemQT: ";
	i >> d.DiemQT;

	cout << "Nhap vao DiemKT: ";
	i >> d.DiemKT;

	return i;
}


ostream &operator << (ostream &o, Diem d){
	cout << "\nMaMH: " << d.MaMH;
	cout << "   Diem QT: " << d.DiemQT;
	cout << "   Diem KT: " << d.DiemKT;
	return o;
}



//////////GET - SET//////////
string Diem::_Get_MaMH(){ return this->MaMH; }
float Diem::_Get_DiemKT(){ return this->DiemKT; }
float Diem::_Get_DiemQT(){ return this->DiemQT; }