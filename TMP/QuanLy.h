#pragma once
#include "SinhVien.h"
#include "NgaySinh.h"
#include "MonHoc.h"
#include "Diem.h"
#include "TruotMon.h"


class QuanLy
{
private:
	vector<SinhVien> DSSV;
	vector<MonHoc> DSMH;
	vector<TruotMon> DSTM;
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
	void DanhSachMonHoc();

	//SINH VIEEN
	void ThemSinhVien();
	void _GhiSinhVienVaoFile();
	string NhapMaSinhVien(int);
	void SuaSinhVien();
	void XoaSinhVien();
	void ThemDiemChoSinhVien();
	void SuaDiemChoSinhVien();
	void XoaDiemChoSinhVien();
	void DanhSachSinhVien();


	//HIEN THI
	void XemDiemTheoMonHoc();
	void XemDiemTheoLopHoc();
	vector<string> GetVaHienThiDanhSachLop();
	void XemChiTietDiem1SinhVien();
	void LietKeSinhVienTruotMonTheoMonHoc();
	void DanhSachMonHocVaSinhVien();
	void DanhSachSinhVienDuDieuKienDatHocBong();


	//TRUOT
	void initTruotMon();
	void _GhiTruotMonVaoFile();
	void DangKiThiLaiorHocLai();
	void DanhSachThiLaiorHocLai();
	void CapNhatDiemTruotMon();
};

