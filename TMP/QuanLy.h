#pragma once
#include "SinhVien.h"
#include "NgaySinh.h"
#include "MonHoc.h"
#include "Diem.h"

class QuanLy
{
private:
	vector<SinhVien> DSSV;
	vector<MonHoc> DSMH;
public:
	QuanLy();
	~QuanLy();

	
	void initDSSV();

	//MONHOC
	void initDSMH();
	void _GhiMonHocVaoFile();
	string NhapMaMonHoc(int);
	void XoaMonHoc();
	void ThemMonHoc();
	void SuaMonHoc();


	//SINH VIEEN
	void ThemSinhVien();
	void _GhiSinhVienVaoFile();
	string NhapMaSinhVien(int);
	void SuaSinhVien();
	void XoaSinhVien();
	void ThemDiemChoSinhVien();
	void SuaDiemChoSinhVien();
	void XoaDiemChoSinhVien();


	//HIEN THI
	void XemDiemTheoMonHoc();
	void XemDiemTheoLopHoc();
	vector<string> GetVaHienThiDanhSachLop();
	void XemChiTietDiem1SinhVien();
	void LietKeSinhVienTruotMonTheoMonHoc();
};

