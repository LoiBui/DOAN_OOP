#include "SinhVien.h"

ifstream SinhVien::FileIn;
ofstream SinhVien::FileOut;

//////////////////GET-LIST SV/////////////////////////
vector<SinhVien> SinhVien::_GetListSV(){
	vector<SinhVien> tmp;
	SinhVien::FileIn.open("DS_SINHVIEN.txt", ios_base::in);
	if (!SinhVien::FileIn){
		cout << "KHONG TIM THAY FILE DS_SINHVIEN.txt. XIN KIEM TRA LAI !!!!";
		system("pause");
		exit(0);
	}

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
			tmp.push_back(sv);
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
		tmp.push_back(sv);

	}
	SinhVien::FileIn.close();
	return tmp;
}



/////////////////Nhập Điểm Cho Sinh Viên////////////////
vector<Diem> SinhVien::NhapDiem(SinhVien sv){
	system("cls");
	int z = whereX();
	int l = whereY();

	if (sv.Lop == "Ban chua nhap") {
		MBox("Ban dang co gang nhap diem cho 1 sinh vien khong ton tai.\n					  Hay them sinh vien truoc khi nhap diem.", 2);
		exit(0);
	}

	gotoXY(0, 2); cout << " --------------------------------";
	gotoXY(0, 3); cout << "| Ho Ten: " << sv.TenSV; gotoXY(33, 3); cout << "|";
	gotoXY(0, 4); cout << "| MSSV: " << sv.MSSV; gotoXY(33, 4); cout << "|";
	gotoXY(0, 5); cout << "| Lop: " << sv.Lop; gotoXY(33, 5); cout << "|";
	gotoXY(0, 6); cout << "| NgaySinh: " << sv.NgaySinh; gotoXY(33, 6); cout << "|";
	gotoXY(0, 7); cout << " --------------------------------";

	TextColor(287); cout << "\n\n NHAP DIEM "; TextColor(15);

	int x = whereX();
	int y = whereY();
	
	gotoXY(x, y);
	vector<Diem> temp = sv.DiemThi;

	while (true)
	{
		gotoXY(z, l);
		MonHoc::_ShowDSMH();
		gotoXY(x, y+1);
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
		cout << "\nBan co muon them tiep khong ? (y/n): ";
		char LuaChon;
		while (true)
		{
			cin >> LuaChon;
			x = whereX();
			y = whereY();
			if (LuaChon == 'y' || LuaChon == 'n' || LuaChon == 'Y' || LuaChon == 'N') break;
			else {
				cout << "	[Lua chon khong hop le]\n	Nhap Lai: ";
				
			}
		}
		
		//nếu môn học không tồn tại thì push vào temp
		if (check) temp.push_back(d);
		if (LuaChon == 'n' || LuaChon == 'N'){
			break;
		}
		else cout << "------------------------------------";;
	}
	return temp;
}

istream &operator >> (istream &i, SinhVien &sv){
	vector<SinhVien> tmp = sv._GetListSV();
	
	cout << "\nNhap vao MSSV: ";
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);
		
		sv.MSSV = DOWHILE1(1, 7, "Ma so sinh vien khong duoc qua dai hoac qua ngan (1->7)");
		
		for each (SinhVien item in tmp)
		{
			if (sv.MSSV == item.MSSV){
				ktmssv = false;
				break;
			}
		}

		if (ktmssv == false){
			TextCL(268, "	[MSSV da ton tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	

	fflush(stdin);
	cout << "Nhap vao TenSV: ";
	sv.TenSV = DOWHILE1(8, 18, "Ho Ten khong duoc qua dai hoac qua ngan (8->18)");

	fflush(stdin);
	cout << "Nhap vao Lop: ";
	sv.Lop = DOWHILE1(1, 6, "Ten Lop khong duoc qua dai hoac qua ngan(1->6)");

	cout << "~Nhap Ngay Sinh~" << endl;
	cin >> sv.NgaySinh;

	string LuaChon;
	while (true)
	{
		fflush(stdin);
		cout << "\n[Them luon DIEM cho sinh vien nay ? (y/n): ";
		
		getline(cin, LuaChon);
		if (LuaChon == "y" || LuaChon == "n" || LuaChon == "Y" || LuaChon == "N"){
			break;
		}
		else{
			TextCL(268, "	[Lua chon khong hop le. Xin kiem tra lai !!!]");
		}
		
	}

	vector<Diem> vt;
	if (LuaChon == "y" || LuaChon == "Y"){
		
		vt = sv.NhapDiem(sv);
	}
	sv.DiemThi = vt;

	// ghi vào file DS_SINHVIEN
	SinhVien::FileOut.open("DS_SINHVIEN.txt", ios_base::app);
	
	string str = "StartSV|" + sv.MSSV + "|" + sv.TenSV + "|" + sv.Lop + "|" + sv.NgaySinh._getDate();
	SinhVien::FileOut << endl << str << "|";
	if (vt.size() > 0){
		SinhVien::FileOut << "StartDiem" << "|";
		for each (Diem item in vt)
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

	SinhVien::FileOut.close();
	return i;
}

ostream &operator << (ostream &o, SinhVien sv){
	
	cout << "|" << setw(7) << left << sv.MSSV << "|" << setw(18) << left << sv.TenSV << "|" << setw(7) << left << sv.Lop << "|" << setw(11) << left << sv.NgaySinh;
	if (sv.DiemThi.size() == 0){
		cout << "|" << setw(7) << left << "Null" << "|" << setw(7) << left << "Null" << endl;
	}
	else{
		float DiemTB = 0;
		float x = 0;
		for (int j = 0; j < sv.DiemThi.size(); j++){
			float tempt = (sv.DiemThi[j]._Get_DiemQT() * 0.3 + sv.DiemThi[j]._Get_DiemKT() * 0.7);
			if (TinhDiemHe4(tempt) != 0){
				int tm = MonHoc::_Get_MH_byMaMH(sv.DiemThi[j]._Get_MaMH())._Get_SoTC();
				DiemTB += tempt*tm;

				x += tm;
			}
			
		}
		DiemTB /= x;
		cout << "|" << setw(7) << left << DiemTB * 0.4 << "|" << setw(7) << left << XepLoai(DiemTB) << endl;
	}
	/*cout << "\nMSSV: " << sv.MSSV;
	cout << "\nTenSV: " << sv.TenSV;
	cout << "\nLop: " << sv.Lop;
	cout << "\nNgay Sinh: " << sv.NgaySinh;
	for each (Diem item in sv.DiemThi)
	{
		cout << "\nDiem Thi: " << item;
	}*/
	return o;
}

void SinhVien::_Show_DSSV(){
	int x = whereX();
	int y = whereY();

	vector<SinhVien> sv = this->_GetListSV();

	int _pc = 0;

	TextColor(287); gotoXY(76, y); cout << " DANH SACH CAC SINH VIEN "; TextColor(15);
	gotoXY(60, y + 1); for (int i = 0; i < 19; i++){ cout << "---"; } int getX = whereX(); cout << endl;
	gotoXY(60, y + 2); cout << "|" << setw(7) << left;
	TextCL(9, "STT");
	cout << "|" << setw(10) << left;
	TextCL(9, "MSSV");
	cout << "|" << setw(10) << left;
	TextCL(9, "LOP");
	cout << "|" << setw(25) << left;
	TextCL(9, "TenSV");
	gotoXY(60, y + 3); for (int i = 0; i < 19; i++){ cout << "---"; } cout << endl;

	int i = 0;
	for each (SinhVien item in sv)
	{
		gotoXY(60, y + i + 4); cout << "|" << setw(7) << left << i + 1 << "|" << setw(10) << left << item.MSSV << "|" << setw(10) << left << item.Lop << setw(25) << left << item.TenSV; //fix lỗi dòng kẻ
		while (true)
		{
			if (getX == whereX()){
				break;
			}
			cout << " ";
		}

		i++;
	}
	if (sv.size() > 0){
		gotoXY(60, y + i + 4); for (int i = 0; i < 19; i++){ cout << "---"; } cout << endl;
	}

	gotoXY(x, y);
}

void SinhVien::_GhiFile(vector<SinhVien> tmp){
	//ghi lại vào file
	SinhVien::FileOut.open("DS_SINHVIEN.txt", ios_base::out);

	for (int i = 0; i < tmp.size(); i++){
		string str = "StartSV|" + tmp[i].MSSV + "|" + tmp[i].TenSV + "|" + tmp[i].Lop + "|" + tmp[i].NgaySinh._getDate();
		if ( i > 0 ) SinhVien::FileOut << endl << str << "|";
		else SinhVien::FileOut << str << "|";
		if (tmp[i].DiemThi.size() > 0){
			SinhVien::FileOut << "StartDiem" << "|";
			for each (Diem item in tmp[i].DiemThi)
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
	SinhVien::FileOut.close();
}

void SinhVien::_Xoa_SinhVien(){

	string MSSV;
	vector<SinhVien> tmp = this->_GetListSV();
	cout << "\nNhap vao MSSV: ";

	int ind = 0;
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);

		getline(cin, MSSV);
		int index = 0;
		for each (SinhVien item in tmp)
		{
			if (MSSV == item.MSSV){
				ktmssv = false;
				ind = index;
				break;
			}
			index++;
		}

		if (ktmssv == true){
			TextCL(268, "	[MSSV KHONG Ton Tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}

	tmp.erase(tmp.begin() + ind);
	TextCL(266, "	XOA SINH VIEN CO MSSV '" + MSSV + "' THANH CONG");
	this->_GhiFile(tmp);
}

void SinhVien::_Nhap_Diem_SinhVien(){
	string MSSV;
	vector<SinhVien> tmp = this->_GetListSV();
	
	cout << "\nNhap vao MSSV: ";

	int ind = 0;
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);

		getline(cin, MSSV);
		int index = 0;
		for each (SinhVien item in tmp)
		{
			if (MSSV == item.MSSV){
				
				ktmssv = false;
				vector<Diem> diem = this->NhapDiem(item);
				tmp[index].DiemThi = diem;
				ind = index;
				break;
			}
			index++;
		}

		if (ktmssv == true){
			TextCL(268, "	[MSSV KHONG Ton Tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	this->_GhiFile(tmp);
	
}

void SinhVien::_Xoa_Diem_Cho_SV(){
	string MSSV;
	vector<SinhVien> tmp = this->_GetListSV();

	cout << "\nNhap vao MSSV: ";

	
	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);

		getline(cin, MSSV);
		int index = 0;
		for each (SinhVien item in tmp)
		{
			if (MSSV == item.MSSV){
			lb:
				if (tmp[index].DiemThi.size() == 0) {
					TextCL(268, "	[Sinh Vien Nay Khong Co Diem Cua Mon Hoc Nao]");
					return;
				}
				TextCL(257, "DANH SACH MON HOC CUA SINH VIEN");
				for each (Diem item in tmp[index].DiemThi)
				{
					cout << "\n --------------------------------";
					cout << "\n|";
					TextCL(267, " MaMH: ");
					cout << item._Get_MaMH(); gotoXY(33, whereY()); cout << "|";
					cout << "\n|";
					TextCL(267, " DQT: ");
					cout << item._Get_DiemQT(); gotoXY(33, whereY()); cout << "|";
					cout << "\n|";
					TextCL(267, " DKT: ");
					cout << item._Get_DiemKT(); gotoXY(33, whereY()); cout << "|";
					cout << "\n --------------------------------";
				}
				ktmssv = false;
				string MaMH;
				cout << "\nNhap MaMonHoc: ";
				while (true)
				{
					getline(cin, MaMH);
					bool check_valid = false;
					int indexD = 0;
					for each (Diem item in tmp[index].DiemThi)
					{
						if (MaMH == item._Get_MaMH()){
							check_valid = true;
							tmp[index].DiemThi.erase(tmp[index].DiemThi.begin() + indexD);
							TextCL(258, "	[XOA THANH CONG]\n");
							if (tmp[index].DiemThi.size() > 0){
								TextCL(266, "	Ban co muon tiep tuc xoa khong ?(y/n):");

								string LuaChon;
								while (true)
								{
									fflush(stdin);
									getline(cin, LuaChon);
									if (LuaChon == "y" || LuaChon == "n" || LuaChon == "Y" || LuaChon == "N"){
										break;
									}
									else{
										cout << "	[Lua chon khong hop le. Xin kiem tra lai !!!]";
									}
								}
								if (LuaChon == "Y" || LuaChon == "y"){
									goto lb;
								}
							}
							

							break;
						}
						indexD++;
					}
					if (!check_valid){
						TextCL(4, "	[MaMH khong ton tai trong danh sach diem cua ban]");
						cout << "\n	Nhap Lai: ";
					}
					else break;
				}
				
				break;
			}
			index++;
		}

		if (ktmssv == true){
			TextCL(268, "	[MSSV KHONG Ton Tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
	this->_GhiFile(tmp);
}

void SinhVien::_Xem_Diem(){
	string MSSV;
	vector<SinhVien> tmp = this->_GetListSV();
	cout << "\nNhap vao MSSV: ";

	while (true)
	{
		bool ktmssv = true;
		fflush(stdin);

		getline(cin, MSSV);
		int index = 0;
		for each (SinhVien item in tmp)
		{
			if (MSSV == item.MSSV){
				ktmssv = false;
				
				///////////////show table
				cout << "\n --------------------------------";
				cout << "\n| Ho Ten: " << item.TenSV; gotoXY(33, whereY()); cout << "|";
				cout << "\n| MSSV: " << item.MSSV; gotoXY(33, whereY()); cout << "|";
				cout << "\n| Lop: " << item.Lop; gotoXY(33, whereY()); cout << "|";
				cout << "\n| NgaySinh: " << item.NgaySinh; gotoXY(33, whereY()); cout << "|";
				cout << "\n --------------------------------\n\n";

				if (item.DiemThi.size() > 0){
					TextCL(257, "\nDanh Sach Diem Cua Sinh Vien: " + item.TenSV + "\n");
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
					for each (Diem d in item.DiemThi)
					{
						cout << "|" << setw(4) << left << stt++ << "|" << setw(8) << left << d._Get_MaMH();
						string tmh;
						for (int i = 0; i < MonHoc::_DSMH.size(); i++)
						{
							string templateMMH = MonHoc::_DSMH[i]._Get_MaMH();
							if (templateMMH == d._Get_MaMH()){
								string l = MonHoc::_DSMH[i]._Get_TenMH();
								tmh = l;
								break;
							}
						}
						if (tmh.length() > 22){
							tmh.erase(22, tmh.length() - 20);
							tmh += "...";
						}
						cout << "|" << setw(25) << left << tmh;
						float diem4 = (d._Get_DiemKT() * 0.7 + d._Get_DiemQT() * 0.3);
						cout << "|" << setw(4) << left << d._Get_DiemQT() << "|" << setw(4) << left << d._Get_DiemKT() << "|" << setw(2) << left << TinhDiemChu(diem4) << "|" << setw(4) << left << TinhDiemHe4(diem4);

						gotoXY(58, whereY()); cout << "|";
						cout << endl;

					}
					for (int i = 0; i < 19; i++){ cout << "---"; } cout << "--" << endl;
				}
				else{
					TextCL(268, "	[SINH VIEN NAY KHONG CO DIEM DE HIEN THI]");
				}
				///////////////end
				break;
			}
			index++;
		}

		if (ktmssv == true){
			TextCL(268, "	[MSSV KHONG Ton Tai. Xin vui long kiem tra lai !!!]");
			cout << endl << "	Nhap Lai: ";
		}
		else break;
	}
}







//---------------------------------------

SinhVien::SinhVien()
{
	this->TenSV = "Ban chua nhap Ten";
	this->MSSV = "Ban chua nhap";
	this->Lop = "Ban chua nhap";
}

SinhVien::SinhVien(string mssv, string tensv, string lop, NgayS ns, vector<Diem> diem){
	this->MSSV = mssv;
	this->TenSV = tensv;
	this->Lop = lop;
	this->NgaySinh = ns;
	this->DiemThi = diem;
}
SinhVien::~SinhVien()
{
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