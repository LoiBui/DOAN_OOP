#include "SinhVien.h"

ifstream SinhVien::FileIn;
ofstream SinhVien::FileOut;

SinhVien::SinhVien()
{
}


SinhVien::~SinhVien()
{
}

SinhVien::SinhVien(string mssv, string tensv, string lop, NgayS ns, vector<Diem> diem){
	this->MSSV = mssv;
	this->TenSV = tensv;
	this->Lop = lop;
	this->NgaySinh = ns;
	this->DiemThi = diem;
}

void SinhVien::GhiSinhVienVaoFile(){
	string str = "StartSV|" + MSSV + "|" + TenSV + "|" + Lop + "|" + NgaySinh._getDate();
	SinhVien::FileOut << str << "|";
	if (this->DiemThi.size() > 0){
		SinhVien::FileOut << "StartDiem" << "|";
		for each (Diem item in this->DiemThi)
		{
			string strDiem = item._Get_MaMH() + "|";
			SinhVien::FileOut << strDiem;
			SinhVien::FileOut << item._Get_DiemQT() << "|";
			SinhVien::FileOut << item._Get_DiemKT() << "|";
		}
		SinhVien::FileOut << "EndDiem|EndSV";
	}
	else{
		SinhVien::FileOut << "EndSV";
	}
}

void SinhVien::NhapDiem(){
	int z = whereX();
	int l = whereY();

	if (this->Lop == "Ban chua nhap") {
		MBox("Ban dang co gang nhap diem cho 1 sinh vien khong ton tai.\n					  Hay them sinh vien truoc khi nhap diem.", 2);
		exit(0);
	}

	gotoXY(z, l + 2); cout << " --------------------------------";
	gotoXY(z, l + 3); cout << "| Ho Ten: " << TenSV; gotoXY(33, l + 3); cout << "|";
	gotoXY(z, l + 4); cout << "| MaSV: " << TenSV; gotoXY(33, l + 4); cout << "|";
	gotoXY(z, l + 5); cout << "| Lop: " << Lop; gotoXY(33, l + 5); cout << "|";
	gotoXY(z, l + 6); cout << "| NgaySinh: " << NgaySinh; gotoXY(33, l + 6); cout << "|";
	gotoXY(z, l + 7); cout << " --------------------------------";

	TextColor(287); cout << "\n\n NHAP DIEM "; TextColor(15);

	int x = whereX();
	int y = whereY();

	gotoXY(x, y);
	vector<Diem> temp = DiemThi;

	while (true)
	{
		gotoXY(z, l);
		//MonHoc::_ShowDSMH();
		gotoXY(x, y + 1);
		Diem d;
		cin >> d;

		//check tồn tại của môn học
		bool check = true;
		for (int ch = 0; ch < temp.size(); ch++)
		{
			if (d._Get_MaMH() == temp[ch]._Get_MaMH()){
				check = false;
				break;
			}
		}

		//thông báo môn học không hợp lệ
		if (!check){
			cout << "	[Khong the them mon hoc Vi mon hoc da ton tai]\n";
		}

		cout << "------------------------------------";
		
		string LuaChon = DOWHILEYESNO("\nBan co muon them tiep khong ? (y/n): ");

		//nếu môn học không tồn tại thì push vào temp
		if (check) temp.push_back(d);
		if (LuaChon == "n" || LuaChon == "N"){
			break;
		}
		else cout << "------------------------------------";;
	}
	this->DiemThi = temp;
}

istream &operator >> (istream &i, SinhVien &sv){
	
	fflush(stdin);
	cout << "Nhap vao TenSV: ";
	sv.TenSV = DOWHILE1(8, 18, "=>Ho Ten khong duoc qua dai hoac qua ngan (8->18)");

	fflush(stdin);
	cout << "Nhap vao Lop: ";
	sv.Lop = DOWHILE1(1, 6, "=>Ten Lop khong duoc qua dai hoac qua ngan(1->6)");

	cout << "~Nhap Ngay Sinh~" << endl;
	cin >> sv.NgaySinh;

	string LuaChon = DOWHILEYESNO("\nThem luon DIEM cho sinh vien nay ? (y/n): ");
	if (LuaChon == "y" || LuaChon == "Y"){

		sv.NhapDiem();
	}

	
	return i;
}

void SinhVien::SuaDiem(){
	tieptucsua:
	system("cls");
	int z = whereX();
	int l = whereY();

	if (this->Lop == "Ban chua nhap") {
		MBox("Ban dang co gang nhap diem cho 1 sinh vien khong ton tai.\n					  Hay them sinh vien truoc khi nhap diem.", 2);
		exit(0);
	}

	gotoXY(0, 2); cout << " --------------------------------";
	gotoXY(0, 3); cout << "| Ho Ten: " << TenSV; gotoXY(33, 3); cout << "|";
	gotoXY(0, 4); cout << "| MSSV: " << MSSV; gotoXY(33, 4); cout << "|";
	gotoXY(0, 5); cout << "| Lop: " << Lop; gotoXY(33, 5); cout << "|";
	gotoXY(0, 6); cout << "| NgaySinh: " << NgaySinh; gotoXY(33, 6); cout << "|";
	gotoXY(0, 7); cout << " --------------------------------";

	if (this->DiemThi.size() == 0){
		string LuaChon = DOWHILEYESNO("\nSinh Vien nay khong co diem. Ban co muon them moi diem cho SV nay khong ? (y/n): ");
		if (LuaChon == "y" || LuaChon == "n"){
			this->NhapDiem();
		}
	}
	else{
		TextColor(287); cout << "\n\n DANH SACH DIEM CUA SINH VIEN\n"; TextColor(15);

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
		for each (Diem d in this->DiemThi)
		{
			cout << "|" << setw(4) << left << stt++ << "|" << setw(8) << left << d._Get_MaMH();
			cout << "|" << setw(25) << left << CatString(d.GetTenMonHoc(), 21);
			cout << "|" << setw(4) << left << d._Get_DiemQT() << "|" << setw(4) << left << d._Get_DiemKT() << "|" << setw(2) << left << d.TinhDiemChu() << "|" << setw(4) << left << d.TinhDiemHe4();

			gotoXY(58, whereY()); cout << "|";
			cout << endl;

		}
		for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;
	}

	
	string MaMH;
	bool ktmmh = true;
	cout << "\nNhap vao MaMH: ";
	nhaplai:
	TextColor(MauChu);
	getline(cin, MaMH);
	TextColor(7);
	for (int i = 0; i < this->DiemThi.size(); i++)
	{
		if (this->DiemThi[i]._Get_MaMH() == MaMH){
			ktmmh = false;

			cout << "\nBan muon sua gi ?";
			cout << "\n1. Diem Qua Trinh";
			cout << "\n2. Diem Kiem Tra";
			cout << "\n3. Ca Hai";
			cout << "\nLua Chon: ";
			int lc = DOWHILE2(1, 3, "Lua chon khong hop le, Xin Kiem Tra Lai.");
			if (lc == 1 || lc == 3){
				cout << "Nhap DiemQT: ";
				float dqt;
				cin >> dqt;
				this->DiemThi[i]._Set_DiemQT(dqt);
			}

			if (lc == 2 || lc == 3){
				cout << "Nhap DiemKT: ";
				float dkt;
				cin >> dkt;
				this->DiemThi[i]._Set_DiemKT(dkt);
			}

			break;
		}
	}
	if (ktmmh){
		TextCL(4, "	[MaMonHoc khong ton tai.]");
		cout << "\nNhap Lai: ";
		goto nhaplai;
	}

	string con = DOWHILEYESNO("\nBan co muon sua tiep Diem cho Sinh Vien Nay Khong ? (y/n): ");
	if (con == "y" || con == "Y"){
		goto tieptucsua;
	}
}

void SinhVien::XoaDiem(){
	system("cls");
	int z = whereX();
	int l = whereY();

	if (this->Lop == "Ban chua nhap") {
		MBox("Ban dang co gang nhap diem cho 1 sinh vien khong ton tai.\n					  Hay them sinh vien truoc khi nhap diem.", 2);
		exit(0);
	}

	gotoXY(0, 2); cout << " --------------------------------";
	gotoXY(0, 3); cout << "| Ho Ten: " << TenSV; gotoXY(33, 3); cout << "|";
	gotoXY(0, 4); cout << "| MSSV: " << MSSV; gotoXY(33, 4); cout << "|";
	gotoXY(0, 5); cout << "| Lop: " << Lop; gotoXY(33, 5); cout << "|";
	gotoXY(0, 6); cout << "| NgaySinh: " << NgaySinh; gotoXY(33, 6); cout << "|";
	gotoXY(0, 7); cout << " --------------------------------";

	if (this->DiemThi.size() == 0){
		cout << "\nSinh Vien nay khong co DIEM de xoa.";
	}
	else{
		TextColor(287); cout << "\n\n DANH SACH DIEM CUA SINH VIEN\n"; TextColor(15);

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
		for each (Diem d in this->DiemThi)
		{
			cout << "|" << setw(4) << left << stt++ << "|" << setw(8) << left << d._Get_MaMH();
			cout << "|" << setw(25) << left << CatString(d.GetTenMonHoc(), 21);
			cout << "|" << setw(4) << left << d._Get_DiemQT() << "|" << setw(4) << left << d._Get_DiemKT() << "|" << setw(2) << left << d.TinhDiemChu() << "|" << setw(4) << left << d.TinhDiemHe4();

			gotoXY(58, whereY()); cout << "|";
			cout << endl;

		}
		for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;
	}

	string MaMH;
	bool ktmmh = true;
	cout << "\nNhap vao MaMH de xoa: ";
	nhaplai:
	TextColor(MauChu);
	getline(cin, MaMH);
	TextColor(7);
	for (int i = 0; i < this->DiemThi.size(); i++)
	{
		if (this->DiemThi[i]._Get_MaMH() == MaMH){
			ktmmh = false;
			this->DiemThi.erase(this->DiemThi.begin() + i);
			break;
		}
	}
	if (ktmmh){
		TextCL(4, "	[MaMonHoc khong ton tai.]");
		cout << "\nNhap Lai: ";
		goto nhaplai;
	}
}

string SinhVien::_Get_MSSV(){
	return this->MSSV;
}
string SinhVien::_Get_TenSV(){
	return this->TenSV;
}
string SinhVien::_Get_NgaySinh(){
	return this->NgaySinh._getDate();
}
string SinhVien::_Get_Lop(){
	return this->Lop;
}
vector<Diem> SinhVien::_Get_DiemThi(){
	return this->DiemThi;
}

void SinhVien::_Set_Lop(string lop){
	this->Lop = lop;
}
void SinhVien::_Set_DiemThi(vector<Diem> diem){
	this->DiemThi = diem;
}
void SinhVien::_Set_MSSV(string mssv){
	this->MSSV = mssv;
}
void SinhVien::_Set_NgaySinh(NgayS ns){
	this->NgaySinh = ns;
}
void SinhVien::_Set_TenSV(string ten){
	this->TenSV = ten;
}