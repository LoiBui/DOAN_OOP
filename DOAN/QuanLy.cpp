#include "QuanLy.h"


ifstream QuanLy::FileIn;
ofstream QuanLy::FileOut;

vector<string> QuanLy::_ShowDSLop(){
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

void QuanLy::_LoadDSSVFile(){
	SinhVien sv;
	this->DSSV = sv._GetListSV();
	
}

void QuanLy::_Xem_Diem_Theo_MH(){

	int lcY = whereY();
	cout << "Nhap MaMonHoc:	";
	string mmh;
	bool check;
	while (true)
	{
		check = true;
		fflush(stdin);

		getline(cin, mmh);
		for (int i = 0; i < MonHoc::_DSMH.size(); i++)
		{
			if (MonHoc::_DSMH[i]._Get_MaMH() == mmh){
				check = false;
				break;
			}
		}
		if (check == true){
			TextCL(268, "    [Ma Mon Hoc khong ton tai. Xin vui long nhap lai !!!]");
			cout << endl << "	Nhap Lai: ";
			lcY--;
		}
		else {
			lcY += 5;
			break;
		}
	}

	//clr scr
	int lcX = whereX();
	
	gotoXY(0, lcY - 1);
	NoType(false);
	for (int i = 0; i < 15; i++){cout << "                                                                                                                              ";}
	NoType(true);
	gotoXY(lcX, lcY);

	TextCL(257, "\nDanh Sach Diem Cua MonHoc: ");
	TextCL(287, mmh + "\n");
	for (int i = 0; i < 25; i++){ cout << "---"; } cout << "---" << endl;
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
	cout << endl; for (int i = 0; i < 25; i++){ cout << "---"; } cout << "---" << endl;

	int stt = 1;
	for each (SinhVien item in this->DSSV)
	{
		Diem d;
		bool check = false;
		for each(Diem i in item._Get_DiemThi()){
			if (i._Get_MaMH() == mmh){
				d = i;
				check = true;
				break;
			}
		}
		if (check){
			cout << "|" << setw(3) << left << stt++ << "|" << setw(8) << left << item._Get_MSSV() << "|" << setw(19) << left << item._Get_TenSV() << "|" << setw(12) << left << item._Get_NgaySinh();
			cout << "|" << setw(6) << left << item._Get_Lop() << "|" << setw(5) << left << d._Get_DiemQT();
			cout << "|" << setw(5) << left << d._Get_DiemKT() << "|" << setw(5) << left << TinhDiemChu(d._Get_DiemKT() * 0.7 + d._Get_DiemQT() * 0.3) << "|" << setw(5) << left << TinhDiemHe4(d._Get_DiemKT() * 0.7 + d._Get_DiemQT() * 0.3);
			gotoXY(77, whereY()); cout << "|";
			cout << endl;
		}
	}
	for (int i = 0; i < 25; i++){ cout << "---"; } cout << "---" << endl;
	
}

string Get_TenMH_Tu_MaMH(string mmh){
	string kq = "Not Found";
	for (int i = 0; i < MonHoc::_DSMH.size(); i++)
	{
		string templateMMH = MonHoc::_DSMH[i]._Get_MaMH();
		if (templateMMH == mmh){
			string l = MonHoc::_DSMH[i]._Get_TenMH();
			kq = l;
			break;
		}
	}
	if (kq.length() > 22){
		kq.erase(22, kq.length() - 20);
		kq += "...";
	}
	return kq;
}

void QuanLy::_Xem_Diem_Theo_LOP(){
	int y = whereY();
	gotoXY(0, y - 1);
	vector<string> DSTL = this->_ShowDSLop();
	
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
	gotoXY(0, y); for (int i = 0; i < 10; i++){cout << "                                                         " << endl;}
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
					cout << "|" << setw(25) << left << Get_TenMH_Tu_MaMH(var._Get_MaMH()) << "|" << setw(4) << left << var._Get_DiemQT() << "|" << setw(4) << left << var._Get_DiemKT() << "|" << setw(4) << left << TinhDiemChu(var._Get_DiemKT()*0.7 + var._Get_DiemQT()*0.3) << "|" << setw(4) << left << TinhDiemHe4(var._Get_DiemKT()*0.7 + var._Get_DiemQT()*0.3);
					gotoXY(80, whereY()); cout << "|";
					cout<< endl;
					cline = false;
				}
				for (int i = 0; i < 27; i++){ cout << "---"; } cout << endl;
				index++;
			}
		}
	}

	

	
}

int QuanLy::_ShowDSSV(){
	int x = whereX();
	int y = whereY();
	gotoXY(68, 0); TextColor(287); cout << " DANH SACH SINH VIEN TOAN TRUONG "; TextColor(15);
	int _sp = 2;
	gotoXY(46, _sp);  for (int i = 0; i < 24; i++){ cout << "---"; } cout << endl;
	// STT MSSV HOTEN LOP NGAYSINH DIACHI DIEMTB
	//show header
	gotoXY(46, _sp + 1); cout << "|" << setw(4) << left;
	TextCL(9, "STT");
	cout << "|" << setw(7) << left;
	TextCL(9, "MSSV");
	cout << "|" << setw(18) << left;
	TextCL(9, "HoTen");
	cout << "|" << setw(7) << left;
	TextCL(9, "Lop");
	cout << "|" << setw(11) << left; 
	TextCL(9, "NgaySinh");
	cout << "|" << setw(7) << left;
	TextCL(9, "DTB(4)");
	cout << "|" << setw(7) << left;
	TextCL(9, "XepLoai");
	
	
	gotoXY(46, _sp+ 2);  for (int i = 0; i < 24; i++){ cout << "---"; } cout << endl;
	int index = 1;

	for each (SinhVien item in this->DSSV)
	{
		gotoXY(46, _sp + 2 + index);
		cout << "|" << setw(4) << left << index++;
		cout << item;
	}

	gotoXY(46, _sp + 2 + index);  for (int i = 0; i < 24; i++){ cout << "---"; } cout << endl;
	
	for (int i = 0; i < index + 1; i++){
		gotoXY(117, i + _sp + 1); 
		if (i != 1) cout << "|";
	}
	gotoXY(46, _sp + 4 + index); TextCL(257, "HUONG DAN: ");
	gotoXY(50, _sp + 5 + index); TextCL(263, "+ Nhan Phim Theo (KEY) O Ben Canh De Chon Chuc Nang Tuong Ung.");
	gotoXY(50, _sp + 6 + index); TextCL(263, "+ Nhan '0' De Thoat Chuong Trinh.");
	int tmpY = _sp + 9 + index;
	gotoXY(x, y);
	return tmpY;
}

int menu(){
	
	int x = whereX();
	int y = whereY();
	
	gotoXY(x + 15, y); TextColor(287); cout << " Chuc Nang "; TextColor(15);
	gotoXY(x, y + 2); for (int i = 0; i < 21; i++) cout << "--";
	gotoXY(x, y + 3); cout << "|" << setw(4) << left;
	TextCL(9, "Key");
	cout << "|" << setw(23) << left;
	TextCL(9, "Noi Dung");

	gotoXY(x, y + 4); for (int i = 0; i < 21; i++) cout << "--";
	gotoXY(x, y + 5); cout << "|" << setw(4) << left << "1" << "|" << setw(23) << left << "  Them MonHoc";
	gotoXY(x, y + 6); cout << "|" << setw(4) << left << "2" << "|" << setw(23) << left << "  Xoa 1 Mon Hoc";
	gotoXY(x, y + 7); cout << "|" << setw(4) << left << "3" << "|" << setw(23) << left << "  Xem Danh Sach Mon Hoc";
	gotoXY(x, y + 8); for (int i = 0; i < 21; i++) cout << "--";
	gotoXY(x, y + 9); cout << "|" << setw(4) << left << "4" << "|" << setw(23) << left << "  Them SinhVien";
	gotoXY(x, y + 10); cout << "|" << setw(4) << left << "5" << "|" << setw(23) << left << "  Xoa 1 SinhVien";
	gotoXY(x, y + 11); cout << "|" << setw(4) << left << "6" << "|" << setw(23) << left << "  Nhap Diem cho SV theo MSSV";
	gotoXY(x, y + 12); cout << "|" << setw(4) << left << "7" << "|" << setw(23) << left << "  Xoa Diem Cho 1 SinhVien";
	gotoXY(x, y + 13); for (int i = 0; i < 21; i++) cout << "--";
	gotoXY(x, y + 14); cout << "|" << setw(4) << left << "8" << "|" << setw(23) << left << "  Xem Chi Tiet Diem 1 Sinh Vien";
	gotoXY(x, y + 15); cout << "|" << setw(4) << left << "9" << "|" << setw(23) << left << "  Xem Diem SinhVien Theo MonHoc";
	gotoXY(x, y + 16); cout << "|" << setw(4) << left << "10" << "|" << setw(23) << left << "  Xem DS SinhVien Theo Lop";
	gotoXY(x, y + 17); for (int i = 0; i < 21; i++) cout << "--";
	gotoXY(x, y + 18); cout << "|" << setw(4) << left << "11" << "|" << setw(23) << left << "  Sua Mon Hoc";
	gotoXY(x, y + 19); cout << "|" << setw(4) << left << "12" << "|" << setw(23) << left << "  Sua Sinh Vien";
	

	gotoXY(0, y + 24); for (int i = 0; i < 19; i++)
	{
		gotoXY(x + 41, y + i + 3); if (i != 1 && i != 5 && i != 10 && i!= 14) cout << "|";
	}
	gotoXY(x, y + 20); for (int i = 0; i < 21; i++) cout << "--";
	int choose = 0;
	gotoXY(x, y + 21);  cout << "| Lua Chon: ";
	while (true)
	{
		choose = TryCatch();
		if (choose > 12 || choose < 0){
			TextCL(4, "	[Lua chon khong hop le.(0->12)]");
			cout << "\n	Nhap Lai: ";
		}
		else break;
	}
	
	if (choose == 0) exit(0);

	gotoXY(x, y + 21); for (int i = 0; i < 15; i++) cout << "                                     \n ";
	gotoXY(x, y + 21);  cout << "| Lua Chon: " << choose;
	gotoXY(x, y + 22); for (int i = 0; i < 21; i++) cout << "--";
	cout << endl << endl;
	
	TextColor(103);
	return choose;
}



void QuanLy::func(){
loi:
	this->_LoadDSSVFile();
	int y = this->_ShowDSSV();

	int choose = menu();
	
	if (y > whereY()){
		gotoXY(whereX(), y);
	}

	MonHoc mh;
	SinhVien sv;

	//gotoXY(x, y + 20);
	if (choose == 1){
		//system("cls");
		for (int i = 0; i < 22; i++) if (i == 10) cout << "THEM MON HOC"; else cout << "-----"; cout << "---" << endl;
		TextColor(15);
		cout << "HUONG DAN: \n+ Nhap Thong Tin Mon Hoc De Them. ";
		TextCL(268, "\n	[MA MON HOC KHONG THE TRUNG]");

		cout << endl << endl;
		

		
		mh._ShowDSMH();
		cin >> mh;
		TextCL(258, "	[Them Mon Hoc Thanh Cong]");
	}
	else if (choose == 2){
		for (int i = 0; i < 22; i++) if (i == 10) cout << "XOA 1 MON HOC"; else cout << "-----"; cout << "--" << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaMonHoc] De Xoa\n";
		TextCL(268, "           + [Ma Mon Hoc Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		mh._ShowDSMH();
		mh.XoaMonHoc();
	}
	else if (choose == 3){
		for (int i = 0; i < 21; i++) if (i == 10) cout << "DANH SACH MON HOC"; else cout << "-----"; cout << "---" << endl;
		TextColor(15);
		cout << "HUONG DAN: + Day La Bang Danh Sach Cac Mon Hoc.\n";
		cout << "           + Danh Sach Hien Thi Gom 'MaMH' Va 'TenMonHoc'";
		cout << endl << endl;
		mh._ShowDSMH();
	}
	else if (choose == 4){
		for (int i = 0; i < 21; i++) if (i == 10) cout << "THEM 1 SINH VIEN"; else cout << "-----"; cout << "----" << endl;
		TextColor(15);
		cout << "HUONG DAN: \n+ Nhap Thong Tin Sinh Vien De Them. ";
		TextCL(268, "\n	[MA SO SINH VIEN KHONG THE TRUNG]");
		cout << endl << endl;

		sv._Show_DSSV();
		cin >> sv;
	}
	else if (choose == 5){
		for (int i = 0; i < 22; i++) if (i == 10) cout << "XOA 1 SINH VIEN"; else cout << "-----"; cout << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaSinhVien] De Xoa\n";
		TextCL(268, "           + [Ma SinhVien Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		sv._Show_DSSV();
		sv._Xoa_SinhVien();
	}
	else if (choose == 6){
		for (int i = 0; i < 20; i++) if (i == 10) cout << "NHAP DIEM CHO 1 SINH VIEN"; else cout << "-----"; cout << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaSinhVien] De Them Diem\n";
		TextCL(268, "           + [Ma SinhVien Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		sv._Show_DSSV();
		sv._Nhap_Diem_SinhVien();
	}
	else if (choose == 7){
		for (int i = 0; i < 20; i++) if (i == 10) cout << "XOA DIEM CHO 1 SINH VIEN"; else cout << "-----"; cout << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaSinhVien] De Xoa Diem\n";
		TextCL(268, "           + [Ma SinhVien Phai Trung Trong Bang Ben]\n");
		TextCL(268, "           + [MaMH Phai Co Trong Danh Sach Diem Cua Sinh Vien]");
		cout << endl << endl;

		sv._Show_DSSV();
		sv._Xoa_Diem_Cho_SV();
	}
	else if (choose == 8){
		for (int i = 0; i < 19; i++) if (i == 10) cout << "XEM CHI TIET DIEM 1 SINH VIEN"; else cout << "-----"; cout << "-" << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaSinhVien] De Xem Diem\n";
		TextCL(268, "           + [MaSinhVien Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		sv._Show_DSSV();
		sv._Xem_Diem();
	}
	else if (choose == 9){
		for (int i = 0; i < 19; i++) if (i == 10) cout << "XEM SINH VIEN THEO MON HOC"; else cout << "-----"; cout << "-" << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaMH] De Xem Diem\n";
		TextCL(268, "           + [MaMH Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		mh._ShowDSMH();
		this->_Xem_Diem_Theo_MH();
	}
	else if (choose == 10){
		for (int i = 0; i < 19; i++) if (i == 10) cout << "XEM DIEM SINH VIEN THEO LOP"; else cout << "-----"; cout << "--" << endl;
		TextColor(15);
		cout << "HUONG DAN: + Nhap [MaMH] De Xem Diem\n";
		TextCL(268, "           + [MaMH Phai Trung Trong Bang Ben]");
		cout << endl << endl;

		this->_Xem_Diem_Theo_LOP();
	}
	else if (choose == 11){

	}

	string LuaChon;
	while (true)
	{
		fflush(stdin);
		TextCL(266, "\nThuc Hien Cac Chuc Nang Khac ? (y/n): ");

		getline(cin, LuaChon);
		if (LuaChon == "y" || LuaChon == "n" || LuaChon == "Y" || LuaChon == "N"){
			break;
		}
		else{
			cout << "	[Lua chon khong hop le. Xin kiem tra lai !!!]";
		}
	}
	if (LuaChon == "y" || LuaChon == "Y"){
		system("cls");
		goto loi;
	}
}

QuanLy::QuanLy()
{
}


QuanLy::~QuanLy()
{
}


vector<SinhVien> QuanLy::_Get_DSSV(){
	return this->DSSV;
}
