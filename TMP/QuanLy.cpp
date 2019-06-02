﻿#include "QuanLy.h"


QuanLy::QuanLy()
{
}


QuanLy::~QuanLy()
{
}


//MOON HOCJ
void QuanLy::_GhiMonHocVaoFile(){
	MonHoc::FileOut.open("MONHOC.txt", ios_base::out);
	bool index = true;
	for each (MonHoc item in DSMH)
	{	
		if (index){
			index = false;
		}
		else{
			MonHoc::FileOut << endl;
		}
		item.GhiMonHocVaoFile();
	}
	MonHoc::FileOut.close();
}
void QuanLy::initDSMH(){
	while (!MonHoc::FileIn.eof())
	{
		string mamh, tenmh, tmp;
		int stc;
		getline(MonHoc::FileIn, mamh, '|');
		getline(MonHoc::FileIn, tenmh, '|');
		MonHoc::FileIn >> stc;
		getline(MonHoc::FileIn, tmp);

		MonHoc mh(mamh, tenmh, stc);
		this->DSMH.push_back(mh);
	}
}
string QuanLy::NhapMaMonHoc(int type){
	string MaMH;
	bool check;
	cout << "Nhap MaMonHoc: ";
	while (true)
	{
		check = true;
		MaMH = DOWHILE1(1, 10, "Do Dai 'MaMonHoc' Trong Khoang(1->10)");

		for each (MonHoc item in this->DSMH)
		{
			if (item._Get_MaMH() == MaMH){
				check = false;
				if (type == 1){
					return MaMH;
				}
				break;
			}
		}
		if (check == false){
			TextCL(4, "	[Ma Mon Hoc da ton tai. Xin vui long nhap lai !!!]");
			if (type == 1){
				label:
				TextCL(4, "	[Ma Mon Hoc Khong ton tai. Xin vui long nhap lai !!!]");
			}
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	if (type == 1){
		goto label;
	}
	return MaMH;
}
void QuanLy::XoaMonHoc(){
	string MaMH = this->NhapMaMonHoc(1);


	int index = 0;
	for each (MonHoc item in this->DSMH)
	{
		if (item._Get_MaMH() == MaMH){
			this->DSMH.erase(this->DSMH.begin() + index);
			break;
		}
		index++;
	}

	this->_GhiMonHocVaoFile();

}
void QuanLy::ThemMonHoc(){
	string MaMH = this->NhapMaMonHoc(0);
	MonHoc mh;
	cin >> mh;
	mh._Set_MaMH(MaMH);
	
	this->DSMH.push_back(mh);

	MonHoc::FileOut.open("MONHOC.txt", ios_base::app);
	MonHoc::FileOut << endl;
	mh.GhiMonHocVaoFile();
	MonHoc::FileOut.close();
}
void QuanLy::SuaMonHoc(){
	string MaMH = this->NhapMaMonHoc(1);
	for (int i = 0; i < this->DSMH.size(); i++){
		if (MaMH == this->DSMH[i]._Get_MaMH()){
			cout << "\nBan Muon Sua Gi ?";
			cout << "\n1.Sua TenMonHoc";
			cout << "\n2.Sua SoTinChi";
			cout << "\nLua Chon: ";
			int LuaChon = TryCatch(1, 2);

			if (LuaChon == 1){
				cout << "\nNhap TenMonHoc: ";
				this->DSMH[i]._Set_TenMH(DOWHILE1(1, 25, "Do Dai 'TenMonHoc' Trong Khoang(1->25)"));
			}
			else{
				cout << "\nNhap SoTinChi: ";
				this->DSMH[i]._Set_SoTC(DOWHILE2(1, 15, "SoTinChi Trong Khoang(1->15)"));
			}
			break;
		}
	}
	this->_GhiMonHocVaoFile();
}



//SINH VIEEN
void QuanLy::_GhiSinhVienVaoFile(){
	SinhVien::FileOut.open("DS_SINHVIEN.txt", ios_base::out);
	bool index = true;
	for each (SinhVien item in DSSV)
	{
		if (index){
			index = false;
		}
		else{
			SinhVien::FileOut << endl;
		}
		item.GhiSinhVienVaoFile();
	}
	SinhVien::FileOut.close();
}
string QuanLy::NhapMaSinhVien(int type){
	//type: 1: kiểm tra xem có tồn tại không
		//	0: kiểm tra xem mã SV có thỏa mãn không
	string MaSV;
	cout << "\nNhap vao MSSV: ";
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);

		MaSV = DOWHILE1(1, 7, "Ma so sinh vien khong duoc qua dai hoac qua ngan (1->7)");

		for each (SinhVien item in this->DSSV)
		{
			if (MaSV == item._Get_MSSV()){
				ktmssv = false;
				if (type == 1){
					return MaSV;
				}
				break;
			}
		}

		if (ktmssv == false){
			TextCL(4, "	[MSSV da ton tai. Xin vui long kiem tra lai !!!]");
			if (type == 1){
			label:
				TextCL(4, "	[MaSinhVien Khong ton tai. Xin vui long nhap lai !!!]");
			}
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	if (type == 1){
		goto label;
	}
	return MaSV;
}
void QuanLy::ThemSinhVien(){
	string MaSV;
	cout << "Nhap vao MSSV: ";
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);
		TextColor(MauChu);
		
		MaSV = DOWHILE1(1, 7, "=>Ma so sinh vien khong duoc qua dai hoac qua ngan (1->7)");

		for each (SinhVien item in this->DSSV)
		{
			if (MaSV == item._Get_MSSV()){
				ktmssv = false;
				break;
			}
		}

		if (ktmssv == false){
			TextCL(4, "	[MSSV da ton tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}

	SinhVien sv;
	cin >> sv;
	sv._Set_MSSV(MaSV);

	this->DSSV.push_back(sv);

	SinhVien::FileOut.open("DS_SINHVIEN.txt", ios_base::app);
	SinhVien::FileOut << endl;
	sv.GhiSinhVienVaoFile();
	SinhVien::FileOut.close();
}
void QuanLy::SuaSinhVien(){
	string MaSV = this->NhapMaSinhVien(1);
	for (int i = 0; i < this->DSSV.size(); i++){
		if (MaSV == this->DSSV[i]._Get_MSSV()){
			cout << "\nBan Muon Sua Gi ?";
			cout << "\n1.Sua TenSinhVien";
			cout << "\n2.Sua Lop Cho Sinh Vien";
			cout << "\n3.Sua Ngay Sinh Cho Sinh Vien";
			cout << "\n4.Sua Tat Ca";
			cout << "\nLua Chon: ";
			int LuaChon = TryCatch(1, 4);

			if (LuaChon == 1 || LuaChon == 4){
				cout << "Nhap TenSinhVien: ";
				this->DSSV[i]._Set_TenSV(DOWHILE1(8, 18, "Ho Ten khong duoc qua dai hoac qua ngan (8->18)"));
			}
			if (LuaChon == 2 || LuaChon == 4){
				cout << "Nhap Lop: ";
				this->DSSV[i]._Set_Lop(DOWHILE1(1, 6, "Ten Lop khong duoc qua dai hoac qua ngan(1->6)"));
			}
			if ((LuaChon == 3 || LuaChon == 4)){
				cout << "~Nhap Ngay Sinh~" << endl;
				NgayS ns;
				cin >> ns;
				this->DSSV[i]._Set_NgaySinh(ns);
			
			}
			break;
		}
	}
	
	this->_GhiSinhVienVaoFile();
}
void QuanLy::XoaSinhVien(){
	string MaSV = this->NhapMaSinhVien(1);

	for (int i = 0; i < this->DSSV.size(); i++)
	{
		if (MaSV == this->DSSV[i]._Get_MSSV()){
			this->DSSV.erase(this->DSSV.begin() + i);
		}
	}
	this->_GhiSinhVienVaoFile();
}
void QuanLy::initDSSV(){
	//đọc file
	while (!SinhVien::FileIn.eof())
	{
		string check;
		getline(SinhVien::FileIn, check, '|');

		//if (check == "") break;

		string mssv;
		getline(SinhVien::FileIn, mssv, '|');

		string tensv;
		getline(SinhVien::FileIn, tensv, '|');

		string lop;
		getline(SinhVien::FileIn, lop, '|');

		int ngay;
		SinhVien::FileIn >> ngay;
		SinhVien::FileIn.seekg(1, SEEK_CUR);

		int thang;
		SinhVien::FileIn >> thang;
		SinhVien::FileIn.seekg(1, SEEK_CUR);

		int nam;
		SinhVien::FileIn >> nam;
		SinhVien::FileIn.seekg(1, SEEK_CUR);

		NgayS ngaysinh(ngay, thang, nam);

		string checkDiem;
		getline(SinhVien::FileIn, checkDiem, '|');



		vector<Diem> DiemSV;
		if (checkDiem == "EndSV") {
			SinhVien sv(mssv, tensv, lop, ngaysinh, DiemSV);
			this->DSSV.push_back(sv);
			continue;
		}

		if (checkDiem == "StartDiem"){

			//đọc điểm từ file
			while (true)
			{
				string mmh;
				getline(SinhVien::FileIn, mmh, '|');

				float diemqt;
				SinhVien::FileIn >> diemqt;
				SinhVien::FileIn.seekg(1, SEEK_CUR);

				float diemkt;
				SinhVien::FileIn >> diemkt;
				SinhVien::FileIn.seekg(1, SEEK_CUR);

				Diem d(mmh, diemqt, diemkt);
				DiemSV.push_back(d);

				string checkBreak;
				getline(SinhVien::FileIn, checkBreak, '|');

				if (checkBreak == "EndDiem"){
					break;
				}
				else {
					int length = checkBreak.length();
					SinhVien::FileIn.seekg(-(length + 1), SEEK_CUR);
				}

			}
			string breakIf;
			getline(SinhVien::FileIn, breakIf);
		}
		else { //bên trên biến checkDeiem đọc đk là EndSV\nStartSV: StartSV có 7 kí tự lên ta lùi về 8 đề đọc đk full chữ StartSV
			SinhVien::FileIn.seekg(-8, SEEK_CUR);
		}


		SinhVien sv(mssv, tensv, lop, ngaysinh, DiemSV);
		this->DSSV.push_back(sv);

	}
}
void QuanLy::ThemDiemChoSinhVien(){
	string MaSV = this->NhapMaSinhVien(1);
	for (int i = 0; i < this->DSSV.size(); i++){
		if (this->DSSV[i]._Get_MSSV() == MaSV){
			this->DSSV[i].NhapDiem();
			break;
		}
	}
	this->_GhiSinhVienVaoFile();
}
void QuanLy::SuaDiemChoSinhVien(){
	string MaSV = this->NhapMaSinhVien(1);
	for (int i = 0; i < this->DSSV.size(); i++){
		if (this->DSSV[i]._Get_MSSV() == MaSV){
			this->DSSV[i].SuaDiem();
			break;
		}
	}
	this->_GhiSinhVienVaoFile();
}
void QuanLy::XoaDiemChoSinhVien(){
	string MaSV = this->NhapMaSinhVien(1);
	for (int i = 0; i < this->DSSV.size(); i++){
		if (this->DSSV[i]._Get_MSSV() == MaSV){
			this->DSSV[i].XoaDiem();
			break;
		}
	}
	this->_GhiSinhVienVaoFile();
}