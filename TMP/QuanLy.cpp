#include "QuanLy.h"


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


//HIEN THI
void QuanLy::XemDiemTheoMonHoc(){
	int y = whereY();
	gotoXY(90, y); for (int i = 0; i < 28; i++) { TextCL(9, "="); }
	gotoXY(90, y + 1);
	TextCL(9, "|");
	cout << setw(3) << left;
	TextCL(9, "STT");
	TextCL(9, "|");
	cout << setw(8) << left;
	TextCL(9, "MaMH");
	TextCL(9, "|");
	cout << setw(10) << left;
	TextCL(9, "TenMH"); 
	gotoXY(117, y + 1); TextCL(9, "|");
	gotoXY(90, y + 2); for (int i = 0; i < 28; i++) { TextCL(9, "="); }
	cout << endl;
	for (int i = 0; i < this->DSMH.size(); i++)
	{
		gotoXY(90, y + 3 + i);
		TextCL(9, "|");
		cout << setw(3) << left;
		TextCL(9,to_string(i+1));
		TextCL(9, "|");
		cout << setw(8) << left;
		TextCL(9, this->DSMH[i]._Get_MaMH());
		TextCL(9, "|");
		cout << setw(10) << left;
		TextCL(9, CatString(this->DSMH[i]._Get_TenMH(), 10));
		gotoXY(117, y + 3 + i); TextCL(9, "|");
	}
	gotoXY(90, y + 3 + this->DSMH.size()); for (int i = 0; i < 28; i++) { TextCL(9, "="); }
	

	gotoXY(0, y);
	string MaMH = this->NhapMaMonHoc(1);


	





	TextCL(257, "\nDanh Sach Diem Cua MonHoc: ");
	TextCL(287, MaMH + "\n");
	
	for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;
	cout << "|" << setw(3) << left;
	TextCL(9, "STT");
	cout << "|" << setw(8) << left;
	TextCL(9, "MSSV");
	cout << "|" << setw(19) << left;
	TextCL(9, "TenSV");
	cout << "|" << setw(12) << left;
	TextCL(9, "NgaySinh");
	cout << "|" << setw(6) << left;
	TextCL(9, "LopQL");
	cout << "|" << setw(5) << left;
	TextCL(9, "DQT");
	cout << "|" << setw(5) << left;
	TextCL(9, "DKT");
	cout << "|" << setw(5) << left;
	TextCL(9, "DC");
	cout << "|" << setw(5) << left;
	TextCL(9, "(4)"); cout << "|";
	cout << endl; for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;

	int stt = 1;
	for each (SinhVien item in this->DSSV)
	{
		Diem d;
		bool check = false;
		for each(Diem i in item._Get_DiemThi()){
			if (i._Get_MaMH() == MaMH){
				d = i;
				check = true;
				break;
			}
		}
		if (check){
			cout << "|" << setw(3) << left << stt++ << "|" << setw(8) << left << item._Get_MSSV() << "|" << setw(19) << left << item._Get_TenSV() << "|" << setw(12) << left << item._Get_NgaySinh();
			cout << "|" << setw(6) << left << item._Get_Lop() << "|" << setw(5) << left << d._Get_DiemQT();
			cout << "|" << setw(5) << left << d._Get_DiemKT() << "|" << setw(5) << left << d.TinhDiemChu() << "|" << setw(5) << left << d.TinhDiemHe4();
			gotoXY(77, whereY()); cout << "|";
			cout << endl;
		}
	}
	for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;
}


vector<string> QuanLy::GetVaHienThiDanhSachLop(){
	int x = whereX();
	int y = whereY();
	int _sp = whereY() + 1;
	gotoXY(90, _sp);  for (int i = 0; i < 5; i++){ cout << "---"; } cout << endl;
	gotoXY(90, _sp + 1); cout << "|" << setw(4) << left;
	TextCL(9, "STT");
	cout << "|" << setw(7) << left;
	TextCL(9, "Ten Lop");
	cout << " |";
	gotoXY(90, _sp + 2); for (int i = 0; i < 5; i++){ cout << "---"; }

	vector<string> tenLop;

	for each (SinhVien item in this->DSSV)
	{
		bool check = true;
		for each(string tl in tenLop){
			if (tl == item._Get_Lop()){
				check = false;
				break;
			}
		}
		if (check) tenLop.push_back(item._Get_Lop());
	}

	int stt = 1;
	for each (string item in tenLop)
	{
		gotoXY(90, _sp + 2 + stt); cout << "|" << setw(4) << left << stt << "|" << setw(7) << left << item;
		gotoXY(104, _sp + 2 + stt++); cout << "|";
	}
	gotoXY(90, _sp + 2 + stt); for (int i = 0; i < 5; i++){ cout << "---"; }
	//return old pt
	gotoXY(x, y);
	return tenLop;
}
void QuanLy::XemDiemTheoLopHoc(){
	int y = whereY();
	gotoXY(0, y - 1);
	vector<string> DSTL = this->GetVaHienThiDanhSachLop();

	string TenLop;
	cout << "\nNhap Ten Lop: ";
	while (true)
	{
		fflush(stdin);
		getline(cin, TenLop);
		bool check = false;
		for each (string item in DSTL)
		{
			if (item == TenLop){
				check = true;
				break;
			}
		}
		if (!check){
			TextCL(268, "	[Ten Lop Khong Ton Tai!]");
			cout << "\n	Nhap Lai: ";
			y--;
		}
		else{
			y += 3;
			break;
		}
	}
	gotoXY(0, y); for (int i = 0; i < 10; i++){ cout << "                                                         " << endl; }
	gotoXY(0, y);

	// STT MSSV HOTEN LOP NGAYSINH DIACHI DIEMTB
	//show header
	for (int i = 0; i < 27; i++){ cout << "---"; } cout << endl;
	cout << "|" << setw(4) << left;
	TextCL(9, "STT");
	cout << "|" << setw(7) << left;
	TextCL(9, "MSSV");
	cout << "|" << setw(20) << left;
	TextCL(9, "HoTen");
	cout << "|" << setw(25) << left;
	TextCL(9, "TenMonHoc");
	cout << "|" << setw(4) << left;
	TextCL(9, "DQT");
	cout << "|" << setw(4) << left;
	TextCL(9, "DKT");
	cout << "|" << setw(4) << left;
	TextCL(9, "DC");
	cout << "|" << setw(4) << left;
	TextCL(9, "(4)");
	cout << "|";


	cout << endl;  for (int i = 0; i < 27; i++){ cout << "---"; } cout << endl;
	int index = 1;


	for each (SinhVien item in this->DSSV)
	{
		if (item._Get_Lop() == TenLop){
			if (item._Get_DiemThi().size() > 0){
				bool cline = true;
				for each (Diem var in item._Get_DiemThi())
				{
					if (cline){
						cout << "|" << setw(4) << left << index << "|" << setw(7) << left << item._Get_MSSV() << "|" << setw(20) << left << item._Get_TenSV();
					}
					else{
						cout << "|" << setw(4) << left << " " << " " << setw(7) << left << " " << " " << setw(20) << left << " ";
					}
					cout << "|" << setw(25) << left << CatString(var.GetTenMonHoc(), 22) << "|" << setw(4) << left << var._Get_DiemQT() << "|" << setw(4) << left << var._Get_DiemKT() << "|" << setw(4) << left << var.TinhDiemChu() << "|" << setw(4) << left << var.TinhDiemHe4();
					gotoXY(80, whereY()); cout << "|";
					cout << endl;
					cline = false;
				}
				for (int i = 0; i < 27; i++){ cout << "---"; } cout << endl;
				index++;
			}
		}
	}
}

void QuanLy::XemChiTietDiem1SinhVien(){

	string MaSV = this->NhapMaSinhVien(1);

	int stcdat = 0;
	float diemtrungbinhhe10 = 0;
	float diemtrungbinhhe4 = 0;
	for each (SinhVien item in this->DSSV)
	{
		if (MaSV == item._Get_MSSV()){
			
			///////////////show table
			cout << "\n --------------------------------";
			cout << "\n| Ho Ten: " << item._Get_TenSV(); gotoXY(33, whereY()); cout << "|";
			cout << "\n| MSSV: " << item._Get_MSSV(); gotoXY(33, whereY()); cout << "|";
			cout << "\n| Lop: " << item._Get_Lop(); gotoXY(33, whereY()); cout << "|";
			cout << "\n| NgaySinh: " << item._Get_NgaySinh(); gotoXY(33, whereY()); cout << "|";
			cout << "\n --------------------------------\n\n";

			if (item._Get_DiemThi().size() > 0){
				TextCL(257, "\nDanh Sach Diem Cua Sinh Vien: " + item._Get_TenSV() + "\n");
				for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;
				cout << "|" << setw(4) << left;
				TextCL(9, "STT");
				cout << "|" << setw(8) << left;
				TextCL(9, "MAMH");
				cout << "|" << setw(25) << left;
				TextCL(9, "TenMH");
				cout << "|" << setw(4) << left;
				TextCL(9, "DQT");
				cout << "|" << setw(4) << left;
				TextCL(9, "DKT");
				cout << "|" << setw(2) << left;
				TextCL(9, "DC");
				cout << "|" << setw(4) << left;
				TextCL(9, "(4)"); cout << "|";
				cout << endl; for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;

				int stt = 1;
				for each (Diem d in item._Get_DiemThi())
				{
					cout << "|" << setw(4) << left << stt++ << "|" << setw(8) << left << d._Get_MaMH();
					cout << "|" << setw(25) << left << CatString(d.GetTenMonHoc(), 22);
					float diem4 = (d._Get_DiemKT() * 0.7 + d._Get_DiemQT() * 0.3);
					cout << "|" << setw(4) << left << d._Get_DiemQT() << "|" << setw(4) << left << d._Get_DiemKT() << "|" << setw(2) << left << TinhDiemChu(diem4) << "|" << setw(4) << left << TinhDiemHe4(diem4);

					gotoXY(58, whereY()); cout << "|";
					cout << endl;

					//SO TIN CHI DAT
					if (d.TinhDiemHe4() > 0){
						stcdat += d.GetSoTinChi();
						diemtrungbinhhe10 += (d._Get_DiemQT() * 0.3 + d._Get_DiemKT()*0.7) * d.GetSoTinChi();
						diemtrungbinhhe4 += (d.TinhDiemHe4()) * d.GetSoTinChi();
					}
				}
				for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;
			}
			else{
				TextCL(268, "	[SINH VIEN NAY KHONG CO DIEM DE HIEN THI]");
			}
			///////////////end
			break;
		}
	}

	TextCL(257, "\nDiem Trung Binh He 10: "); TextCL(15, to_string(diemtrungbinhhe10 / stcdat));
	TextCL(257, "\nDiem Trung Binh He 4: "); TextCL(15, to_string(diemtrungbinhhe4 / stcdat));
	TextCL(257, "\nSo Tin Chi Tich Luy: "); TextCL(15, to_string(stcdat));
	TextCL(257, "\nXep Loai: "); TextCL(15, Diem::XepLoai(diemtrungbinhhe4 / stcdat));
}


void QuanLy::LietKeSinhVienTruotMonTheoMonHoc(){
	int y = whereY();
	gotoXY(90, y); for (int i = 0; i < 28; i++) { TextCL(9, "="); }
	gotoXY(90, y + 1);
	TextCL(9, "|");
	cout << setw(3) << left;
	TextCL(9, "STT");
	TextCL(9, "|");
	cout << setw(8) << left;
	TextCL(9, "MaMH");
	TextCL(9, "|");
	cout << setw(10) << left;
	TextCL(9, "TenMH");
	gotoXY(117, y + 1); TextCL(9, "|");
	gotoXY(90, y + 2); for (int i = 0; i < 28; i++) { TextCL(9, "="); }
	cout << endl;
	for (int i = 0; i < this->DSMH.size(); i++)
	{
		gotoXY(90, y + 3 + i);
		TextCL(9, "|");
		cout << setw(3) << left;
		TextCL(9, to_string(i + 1));
		TextCL(9, "|");
		cout << setw(8) << left;
		TextCL(9, this->DSMH[i]._Get_MaMH());
		TextCL(9, "|");
		cout << setw(10) << left;
		TextCL(9, CatString(this->DSMH[i]._Get_TenMH(), 10));
		gotoXY(117, y + 3 + i); TextCL(9, "|");
	}
	gotoXY(90, y + 3 + this->DSMH.size()); for (int i = 0; i < 28; i++) { TextCL(9, "="); }


	gotoXY(0, y);
	string MaMH = this->NhapMaMonHoc(1);








	TextCL(257, "\nDanh Sach Diem Cua MonHoc: ");
	TextCL(287, MaMH + "\n");

	for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;
	cout << "|" << setw(3) << left;
	TextCL(9, "STT");
	cout << "|" << setw(8) << left;
	TextCL(9, "MSSV");
	cout << "|" << setw(19) << left;
	TextCL(9, "TenSV");
	cout << "|" << setw(12) << left;
	TextCL(9, "NgaySinh");
	cout << "|" << setw(6) << left;
	TextCL(9, "LopQL");
	cout << "|" << setw(5) << left;
	TextCL(9, "DQT");
	cout << "|" << setw(5) << left;
	TextCL(9, "DKT");
	cout << "|" << setw(5) << left;
	TextCL(9, "DC");
	cout << "|" << setw(5) << left;
	TextCL(9, "(4)"); cout << "|";
	cout << endl; for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;

	int stt = 1;
	for each (SinhVien item in this->DSSV)
	{
		Diem d;
		bool check = false;
		for each(Diem i in item._Get_DiemThi()){
			if (i._Get_MaMH() == MaMH && i.TinhDiemHe4() == 0){
				d = i;
				check = true;
				break;
			}
		}
		if (check){
			cout << "|" << setw(3) << left << stt++ << "|" << setw(8) << left << item._Get_MSSV() << "|" << setw(19) << left << item._Get_TenSV() << "|" << setw(12) << left << item._Get_NgaySinh();
			cout << "|" << setw(6) << left << item._Get_Lop() << "|" << setw(5) << left << d._Get_DiemQT();
			cout << "|" << setw(5) << left << d._Get_DiemKT() << "|" << setw(5) << left << d.TinhDiemChu() << "|" << setw(5) << left << d.TinhDiemHe4();
			gotoXY(77, whereY()); cout << "|";
			cout << endl;
		}
	}
	for (int i = 0; i < 25; i++){ cout << "==="; } cout << "===" << endl;
}