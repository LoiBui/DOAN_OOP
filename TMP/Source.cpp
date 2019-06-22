#include "console.h"
#include "MonHoc.h"
#include "QuanLy.h"
#include "SinhVien.h"

void _initialization(){
	SetConsoleTitleW(L"Đồ Án OOP: Quản Lý Điểm Thi");
	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
	SinhVien::FileIn.open("DS_SINHVIEN.txt", ios_base::in);
}

int menu(){

	gotoXY(0, 1);
	for (int i = 0; i < 29; i++) { if (i == 14){ cout << " "; TextCL(31, "THEM"); cout << " "; } else{ TextCL(3, "="); } }
	TextColor(3);
	gotoXY(0, 2); cout << "|" << setw(4) << left << "Key";
	cout << "|" << setw(23) << left << " Noi Dung";
	gotoXY(33, 2); cout << "|";
	gotoXY(0, 3);
	for (int i = 0; i < 34; i++) { TextCL(3, "="); }

	gotoXY(0, 4); 
	TextCL(3, "|");
	cout << setw(4) << left << "1";
	TextCL(3, "|");
	cout << setw(23) << left << " Them Sinh Vien";
	gotoXY(33, 4); TextCL(3, "|");

	gotoXY(0, 5);
	TextCL(3, "|");
	cout << setw(4) << left << "2";
	TextCL(3, "|");
	cout << setw(23) << left << " Them Mon Hoc";
	gotoXY(33, 5); TextCL(3, "|");

	gotoXY(0, 6);
	TextCL(3, "|");
	cout << setw(4) << left << "3";
	TextCL(3, "|");
	cout << setw(23) << left << " Them Diem Cho Sinh Vien";
	gotoXY(33, 6); TextCL(3, "|");

	gotoXY(0, 7); for (int i = 0; i < 34; i++) { TextCL(3, "="); }




	gotoXY(44, 1);
	for (int i = 0; i < 29; i++) { if (i == 14){ cout << " "; TextCL(31, "SUA"); cout << " "; } else{ TextCL(3, "="); } }
	TextColor(3);
	gotoXY(44, 2); cout << "|" << setw(4) << left << "Key";
	cout << "|" << setw(23) << left << " Noi Dung";
	gotoXY(76, 2); cout << "|";
	gotoXY(44, 3);
	for (int i = 0; i < 33; i++) { TextCL(3, "="); }

	gotoXY(44, 4);
	TextCL(3, "|");
	cout << setw(4) << left << "4";
	TextCL(3, "|");
	cout << setw(23) << left << " Sua Sinh Vien";
	gotoXY(76, 4); TextCL(3, "|");

	gotoXY(44, 5);
	TextCL(3, "|");
	cout << setw(4) << left << "5";
	TextCL(3, "|");
	cout << setw(23) << left << " Sua Mon Hoc";
	gotoXY(76, 5); TextCL(3, "|");

	gotoXY(44, 6);
	TextCL(3, "|");
	cout << setw(4) << left << "6";
	TextCL(3, "|");
	cout << setw(23) << left << " Sua Diem Cho Sinh Vien";
	gotoXY(76, 6); TextCL(3, "|");
	gotoXY(44, 7); for (int i = 0; i < 33; i++) { TextCL(3, "="); }



	gotoXY(87, 1);
	for (int i = 0; i < 28; i++) { if (i == 14){ cout << " "; TextCL(31, "THEM"); cout << " "; } else{ TextCL(3, "="); } }
	TextColor(3);
	gotoXY(87, 2); cout << "|" << setw(4) << left << "Key";
	cout << "|" << setw(23) << left << " Noi Dung";
	gotoXY(119, 2); cout << "|";
	gotoXY(87, 3);
	for (int i = 0; i < 33; i++) { TextCL(3, "="); }

	gotoXY(87, 4);
	TextCL(3, "|");
	cout << setw(4) << left << "7";
	TextCL(3, "|");
	cout << setw(23) << left << " Xoa Sinh Vien";
	gotoXY(119, 4); TextCL(3, "|");

	gotoXY(87, 5);
	TextCL(3, "|");
	cout << setw(4) << left << "8";
	TextCL(3, "|");
	cout << setw(23) << left << " Xoa Mon Hoc";
	gotoXY(119, 5); TextCL(3, "|");

	gotoXY(87, 6);
	TextCL(3, "|");
	cout << setw(4) << left << "9";
	TextCL(3, "|");
	cout << setw(23) << left << " Xoa Diem Cho Sinh Vien";
	gotoXY(119, 6); TextCL(3, "|");
	gotoXY(87, 7); for (int i = 0; i < 33; i++) { TextCL(3, "="); }


	gotoXY(25, 9);
	for (int i = 0; i < 63; i++) { if (i == 32){ cout << " "; TextCL(31, "HIEN THI"); cout << " "; } else{ TextCL(3, "="); } }
	TextColor(3);
	gotoXY(25, 10); cout << "|" << setw(4) << left << "Key";
	cout << "|" << setw(23) << left << " Noi Dung";
	gotoXY(62, 10); cout << "|";

	gotoXY(62, 10); cout << "|" << setw(4) << left << "Key";
	cout << "|" << setw(23) << left << " Noi Dung";
	gotoXY(96, 10); cout << "|";

	gotoXY(25, 11);
	for (int i = 0; i < 72; i++) { TextCL(3, "="); }

	////////////////////
	gotoXY(25, 12);
	TextCL(3, "|");
	cout << setw(4) << left << "10";
	TextCL(3, "|");
	cout << setw(23) << left << "	Xem Diem Theo Mon Hoc";
	gotoXY(62, 12); TextCL(3, "|");

	gotoXY(25, 13);
	TextCL(3, "|");
	cout << setw(4) << left << "11";
	TextCL(3, "|");
	cout << setw(23) << left << "	Xem Diem Theo Lop Hoc";
	gotoXY(62, 13); TextCL(3, "|");

	gotoXY(25, 14);
	TextCL(3, "|");
	cout << setw(4) << left << "10";
	TextCL(3, "|");
	cout << setw(23) << left << "	Chi Tiet Diem Cua 1 Sinh Vien";
	gotoXY(62, 14); TextCL(3, "|");


	
	gotoXY(25, 15);for (int i = 0; i < 72; i++) { TextCL(3, "="); }
	cout << endl;
	
	cout << "\nLua Chon: ";
	int choose = TryCatch(0, 15);

	NoType(false); gotoXY(0, 17);
	for (int i = 0; i < 15; i++)
	{
		cout << "                                                                                           " << endl;
	}
	gotoXY(0, 17);
	NoType(true);

	return choose;
}

void LuaChon(){

	QuanLy ql;
	ql.initDSSV();
	ql.initDSMH();
	

	int LuaChon = menu();
	switch (LuaChon)
	{
	case 1:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "THEM 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap day du thong tin SinhVien de them.\n	+Ban cung co the them luon diem cho sinh vien do o day.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.ThemSinhVien();
		break;

	case 2:
		for (int i = 0; i < 21; i++) if (i == 11) TextCL(63, "THEM MON HOC"); else TextCL(63, "-----"); TextCL(63, "--------"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap day du thong tin cua MON HOC de them.";
		TextCL(4, "\n	+MaMH phai khong ton tai trong Du Lieu\n\n");
		ql.ThemMonHoc();
		break;

	case 3:
		for (int i = 0; i < 19; i++) if (i == 10) TextCL(63, "THEM DIEM CHO SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-------"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.ThemDiemChoSinhVien();
		break;

	case 4:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.SuaSinhVien();
		break;

	case 5:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.SuaMonHoc();
		break;

	case 6:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.SuaDiemChoSinhVien();
		break;

	case 7:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XoaSinhVien();
		break;

	case 8:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XoaMonHoc();
		break;

	case 9:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XoaDiemChoSinhVien();
		break;

	case 10:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XemDiemTheoMonHoc();
		break;

	case 11:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XemDiemTheoLopHoc();
		break;

	case 12:
		for (int i = 0; i < 21; i++) if (i == 10) TextCL(63, "SUA 1 SINH VIEN"); else TextCL(63, "-----"); TextCL(63, "-----"); cout << endl;
		cout << "HUONG DAN: ";
		cout << "\n	+Nhap MSSV cua SinhVien can them.";
		TextCL(4, "\n	+MaSV phai khong ton tai trong Du Lieu\n\n");
		ql.XemChiTietDiem1SinhVien();
		break;
	default:
		break;
	}

}
int main(){
	
	_initialization();
	
	LuaChon();

	MonHoc::FileIn.close();	
	SinhVien::FileIn.close();
	system("pause");
	return 0;
}