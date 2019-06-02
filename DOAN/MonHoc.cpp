#include "MonHoc.h"

ifstream MonHoc::FileIn;
ofstream MonHoc::FileOut;
vector<MonHoc> MonHoc::_DSMH;
void _getListMH();

istream &operator >> (istream &i, MonHoc &mh)
{
	_getListMH();
	cout << "Nhap MaMonHoc:	";
	bool check;
	while (true)
	{
		check = true;
		fflush(stdin);
		
		mh.MaMH = DOWHILE1(1, 10, "Do Dai 'MaMonHoc' Trong Khoang(1->10)");
		for (int i = 0; i < MonHoc::_DSMH.size(); i++)
		{
			if (MonHoc::_DSMH[i]._Get_MaMH() == mh.MaMH){
				check = false;
				break;
			}
		}
		if (check == false){    	
			TextCL(268, "    [Ma Mon Hoc da ton tai. Xin vui long nhap lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	

	fflush(stdin);
	cout << "Nhap TenMonHoc: ";
	mh.TenMH = DOWHILE1(1, 25, "Do Dai 'TenMonHoc' Trong Khoang(1->25)");

	cout << "Nhap SoTinChi: ";
	mh.SoTinChi = DOWHILE2(1, 15, "SoTinChi Trong Khoang(1->15)");

	//ghi vào file
	MonHoc::FileOut.open("MONHOC.txt", ios_base::app);
	string MH = mh.MaMH + "|" + mh.TenMH + "|" + to_string(mh.SoTinChi);
	MonHoc::FileOut << endl << MH;
	MonHoc::FileOut.close();

	return i;
}

ostream &operator << (ostream &o, MonHoc mh)
{
	cout << "Ma Mon Hoc: " << mh.MaMH;
	cout << "\nTen Mon Hoc: " << mh.TenMH;
	cout << "\nSo Tin Chi: " << mh.SoTinChi;
	return o;
}
void _getListMH(){
	while (!MonHoc::FileIn.eof())
	{
		string mamh, tenmh, tmp;
		int stc;
		getline(MonHoc::FileIn, mamh, '|');
		getline(MonHoc::FileIn, tenmh, '|');
		MonHoc::FileIn >> stc;
		getline(MonHoc::FileIn, tmp);

		MonHoc mh(mamh, tenmh, stc);
		MonHoc::_DSMH.push_back(mh);
	}
}

void MonHoc::_ShowDSMH(){
	int x = whereX();
	int y = whereY();

	int _pc = 0;
	_getListMH();
	TextColor(287); gotoXY(76, y); cout << " DANH SACH CAC MON HOC "; TextColor(15);
	gotoXY(60, y + 1); for (int i = 0; i < 19; i++){ cout << "---"; } int getX = whereX(); cout << endl;
	gotoXY(60, y + 2); cout << "|" << setw(7) << left;
	TextColor(9); 
	cout << "STT";
	TextColor(15); 
	cout << "|" << setw(10) << left;
	TextColor(9); 
	cout << "MaMH";
	TextColor(15); 
	cout << "|" << setw(32) << left;
	TextColor(9); 
	cout << "TenMH";
	TextColor(15);
	cout << "|" << setw(5) << left;
	TextColor(9);
	cout << "STC";
	TextColor(15);
	gotoXY(60, y + 3); for (int i = 0; i < 19; i++){ cout << "---"; } cout << endl;

	int i = 0;
	for each (MonHoc item in MonHoc::_DSMH)
	{
		gotoXY(60, y + i + 4); cout << "|" << setw(7) << left << i + 1 << "|" << setw(10) << left << item._Get_MaMH() << "|" << setw(32) << left << item._Get_TenMH() << "|" << setw(5) << left << item._Get_SoTC(); //fix lỗi dòng kẻ
		while (true)
		{
			if (getX == whereX()){
				break;
			}
			cout << " ";
		}
		
		i++;
	}
	if (MonHoc::_DSMH.size() > 0){
		gotoXY(60, y + i + 4); for (int i = 0; i < 19; i++){ cout << "---"; } cout << endl;
	}

	gotoXY(x, y);
}

MonHoc::MonHoc()
{
	_getListMH();
}

MonHoc::MonHoc(string MaMH, string TenMH, int stc){
	this->MaMH = MaMH;
	this->TenMH = TenMH;
	this->SoTinChi = stc;
}


MonHoc MonHoc::_Get_MH_byMaMH(string maMH){
	_getListMH();
	for each (MonHoc item in MonHoc::_DSMH)
	{
		if (item.MaMH == maMH){
			return item;
		}
	}
	MonHoc mh;
	return mh;
}
MonHoc::~MonHoc()
{
}

//delete//
void MonHoc::XoaMonHoc(){

	_getListMH();
	string MaMH;

	cout << "Nhap MaMonHoc:	";
	bool check1;
	while (true)
	{
		check1 = true;
		fflush(stdin);

		getline(cin, MaMH);

		for (int i = 0; i < MonHoc::_DSMH.size(); i++)
		{
			if (MonHoc::_DSMH[i]._Get_MaMH() == MaMH){
				check1 = false;
				break;
			}
		}
		if (check1 == true){
			TextCL(268, "    [MaMonHoc KHONG ton tai. Xin vui long nhap lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	

	int index = 0;
	for each (MonHoc item in MonHoc::_DSMH)
	{
		if (item.MaMH == MaMH){
			MonHoc::_DSMH.erase(MonHoc::_DSMH.begin() + index);
			break;
		}
		index++;
	}
	

	MonHoc::FileOut.open("MONHOC.txt", ios_base::out);
	bool check = true;
	for each (MonHoc item in MonHoc::_DSMH)
	{
		string MH = item.MaMH + "|" + item.TenMH;
		if (check == true){
			MonHoc::FileOut << MH;
		}
		else{
			MonHoc::FileOut << endl << MH;
		}
		check = false;
		
	}
	MonHoc::FileOut.close();
}

//////GET-SET/////
string MonHoc::_Get_MaMH(){
	return this->MaMH;
}

string MonHoc::_Get_TenMH(){
	return this->TenMH;
}

int MonHoc::_Get_SoTC(){
	return this->SoTinChi;
}

void MonHoc::_Set_MaMH(string mamh){
	this->MaMH = mamh;
}

void MonHoc::_Set_TenMH(string tenmh){
	this->TenMH = tenmh;
}

void MonHoc::_Set_SoTC(int stc){
	this->TenMH = stc;
}
