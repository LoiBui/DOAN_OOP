#include "console.h"

void NoType(bool tmp){
	CONSOLE_CURSOR_INFO inffo;
	inffo.bVisible = tmp;
	inffo.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inffo);
}

//

//-------------------------Screen-------------------------
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO	csbiInfo;
	HANDLE	hConsoleOut;
	COORD	Home = { 0, 0 };
	DWORD	dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
}


//screen: goto [x,y]
void gotoXY(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}


//screen: get [x]
int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}


//screen: get [y]
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}


void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Line(int x1, int y1, int x2, int y2, int color)
{
	bool check = false;

	int n = 0;
	int temp = 0;

	if (x1 == x2) {
		n = y2;
		temp = y1;
		check = true;
	}

	if (y1 == y2) {
		n = x2;
		temp = x1;
	}

	for (int i = temp; i < n; i++)
	{
		if (check){
			gotoXY(x1, y1++);
		}
		if (!check){
			gotoXY(x1 += 2, y1);
		}

		TextColor(color);
		color += 16;
		cout << "  ";
	}
}
void Khung(string content, int color)
{
	Line(25, 5, 25, 18, color);
	Line(25, 5, 60, 5, color + 16);
	Line(95, 5, 95, 18, color + 32);
	Line(23, 18, 59, 18, color + 48);

	gotoXY(56, 8);
	TextColor(9);
	cout << "THONG BAO";
	TextColor(15);
	gotoXY(35, 11);
	cout << content;



}

bool MBox(string content, int type)
{
	int color = 16;
	NoType(false);
	bool check = true;
	system("cls");
	while (true){

		Khung(content, color);
		color += 16;
		Sleep(100);

		if (_kbhit())
		{

			int key = _getch();
			if (key == 13)
			{
				return check;
			}
		}
		if (type == 1)
		{
			if (_kbhit())
			{

				int key = _getch();
				if (key == 77)
				{
					check = false;
				}
				if (key == 75)
				{
					check = true;
				}
			}

			if (check)
			{
				TextColor(31);
			}
			gotoXY(50, 15);
			cout << " CO ";

			TextColor(15);

			if (!check)
			{
				TextColor(31);
			}
			gotoXY(70, 15);
			cout << " KHONG ";
			TextColor(15);
		}
		if (type == 2)
		{
			TextColor(31);
			gotoXY(56, 15);
			cout << " -> OK <- ";
			TextColor(15);
		}
	}

	NoType(true);
	system("cls");
	return true;
}

//////////////////TÍNH ĐIỂM/////////////////////////
string TinhDiemChu(float tmp){
	float Diem = TinhDiemHe4(tmp);
	if (Diem == 1){
		return "D";
	}
	if (Diem == 1.5){
		return "D+";
	}
	if (Diem == 2){
		return "C";
	}
	if (Diem == 2.5){
		return "C+";
	}
	if (Diem == 3){
		return "B";
	}
	if (Diem == 3.5){
		return "B+";
	}
	if (Diem == 4){
		return "A";
	}
	return "F";
}
float TinhDiemHe4(float Diem){
	if (Diem < 4) return 0;
	if (Diem >= 4 && Diem < 5){
		return 1;
	}
	if (Diem >= 5 && Diem < 5.5){
		return 1.5;
	}
	if (Diem >= 5.5 && Diem < 6.5){
		return 2;
	}
	if (Diem >= 6.5 && Diem < 7){
		return 2.5;
	}
	if (Diem >= 7 && Diem < 8){
		return 3;
	}
	if (Diem >= 8 && Diem < 8.5){
		return 3.5;
	}
	return 4;
}

string XepLoai(float tmp){
	float Diem = TinhDiemHe4(tmp);
	if (Diem == 0) {
		return "Yeu";
	}
	if (Diem < 2.5){
		return "Trung Binh";
	}
	if (Diem < 3.2){
		return "Kha";
	}
	if (Diem < 3.6){
		return "Gioi";
	}
	return "Xuat Xac";
}


string DOWHILE1(int x, int y, string noidung){
	string s;
	do
	{
		fflush(stdin);
		TextColor(MauChu);
		getline(cin, s);
		TextColor(7);
		if (s.length() > y || s.length() < x){
			TextCL(4, "	[" + noidung + "]");
			cout << endl << "	Nhap Lai: ";
		}
	} while (s.length() > y || s.length() < x);
	return s;
}

int DOWHILE2(int x, int y, string noidung){
	int s;
	do
	{
		fflush(stdin);
		TextColor(MauChu);
		cin >> s;
		TextColor(7);
		
		if (s > y || s < x){
			TextCL(4, "	[" + noidung + "]");
			cout << endl << "	Nhap Lai: ";
		}
	} while (s > y || s < x);
	return s;
}

void TextCL(int MaMau, string text){
	TextColor(MaMau);
	cout << text;
	TextColor(15);
}




int TryCatch(int x, int y){
	string s;
	loop:
	TextColor(MauChu);
	getline(cin, s);
	TextColor(7);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < '0' || s[i] > '9'){
			TextCL(4, "	=> Du lieu nhap khong hop le !!!");
			loop1:
			cout << "\n	Nhap Lai: ";
			goto loop;
		}
	}

	if (s == "") {
		TextCL(4, "	=> Ban khong the chua nhap ma da nhan Enter");
		goto loop1;
	}

	int choose = stoi(s);
	while (true)
	{
		if (choose > y || choose < x){
			TextCL(4, "	=> Du lieu phai nam trong khoang [" + to_string(x) + "," + to_string(y) + "]. Xin kiem tra lai");
			goto loop1;
		}
		else{
			break;
		}
	}
	return choose;
}

float TryCatch1(float x, float y){
	string s;
loop:
	TextColor(MauChu);
	getline(cin, s);//9.8
	TextColor(7);
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] < 46 || s[i] > 57 || s[i] == 47 || s[0] == '.' || s[s.length()-1] == '.'){
			TextCL(4, "	=> Du lieu nhap khong hop le !!!");
		loop1:
			cout << "\n	Nhap Lai: ";
			goto loop;
		}
	}

	if (s == "") {
		TextCL(4, "	=> Ban khong the chua nhap ma da nhan Enter");
		goto loop1;
	}

	float choose = stof(s);

	while (true)
	{
		if (choose > y || choose < x){
			cout.precision(4);
			TextColor(4);
			cout << "	=> Du lieu phai nam trong khoang [" << x << "," << y << "]. Xin kiem tra lai";
			TextColor(15);
			goto loop1;
		}
		else{
			break;
		}
	}
	return choose;
}

string DOWHILEYESNO(string noidung){
	string LuaChon;
	while (true)
	{
		fflush(stdin);
		cout << noidung;
		TextColor(MauChu);
		getline(cin, LuaChon);
		TextColor(7);

		if (LuaChon == "y" || LuaChon == "n" || LuaChon == "Y" || LuaChon == "N"){
			break;
		}
		else{
			TextCL(268, "	[Lua chon khong hop le. Xin kiem tra lai !!!]");
		}

	}

	return LuaChon;
}

string CatString(string s, int DoDai){
	if (DoDai >= s.length()){
		return s;
	}
	s.erase(DoDai, s.length() - DoDai);
	s += "...";
	return s;
}


void ThongBao(string noidung, int type){
	//1:success 0:faild
	int x = whereX();
	int y = whereY();
	gotoXY(90,0);
	for (int i = 0; i < 22; i++)
	{
		if (i == 11){
			TextCL(31, "THONG BAO");
		}
		else {
			TextCL(31, "=");
		}
		
	}
	gotoXY(90, 5);
	for (int i = 0; i < 30; i++)
	{
		TextCL(31, "=");
	}

	if (type == 0){
		TextColor(4);
	}
	else{
		TextColor(10);
	}
	gotoXY(90, 1); TextCL(273, "  ");
	gotoXY(90, 2); TextCL(273, "  ");
	gotoXY(90, 3); TextCL(273, "  ");
	gotoXY(90, 4); TextCL(273, "  ");

	gotoXY(118, 1); TextCL(273, "  ");
	gotoXY(118, 2); TextCL(273, "  ");
	gotoXY(118, 3); TextCL(273, "  ");
	gotoXY(118, 4); TextCL(273, "  ");
	
	/*for (int i = 0; i < noidung.length(); i++){
		if (i < 26){
			gotoXY(92+i, 1);
			cout << noidung[i];
		}
	}*/
	if (type == 1){
		TextColor(10);
	}
	else{
		TextColor(4);
	}
	if (noidung.length() <= 26){
		gotoXY(92, 1); cout << noidung;
	}
	else if (noidung.length() > 26 && noidung.length() <= 52){
		string tmp = noidung;
		gotoXY(92, 1); cout << tmp.erase(26, tmp.length() - 26);
		noidung.erase(0, 26);
		gotoXY(92, 2); cout << noidung;
	}
	else if (noidung.length() > 52 && noidung.length() <= 78){
		string tmp = noidung;
		gotoXY(92, 1); cout << tmp.erase(26, tmp.length() - 26);
		string tmp1 = noidung;
		tmp1.erase(0, 26);
		gotoXY(92, 2); cout << tmp1.erase(26, tmp1.length() - 26);

		noidung.erase(0, 52);
		gotoXY(92, 3); cout << noidung;
	}
	else if (noidung.length() > 78 && noidung.length() <= 104){
		string tmp = noidung;
		gotoXY(92, 1); cout << tmp.erase(26, tmp.length() - 26);
		string tmp1 = noidung;
		tmp1.erase(0, 26);
		gotoXY(92, 2); cout << tmp1.erase(26, tmp1.length() - 26);

		string tmp2 = noidung;
		tmp2.erase(0, 52);
		gotoXY(92, 3); cout << tmp2.erase(26, tmp2.length() - 26);

		noidung.erase(0, 78);
		gotoXY(92, 4); cout << noidung;
	}
	else{
		string tmp = noidung;
		gotoXY(92, 1); cout << tmp.erase(26, tmp.length() - 26);
		string tmp1 = noidung;
		tmp1.erase(0, 26);
		gotoXY(92, 2); cout << tmp1.erase(26, tmp1.length() - 26);

		string tmp2 = noidung;
		tmp2.erase(0, 52);
		gotoXY(92, 3); cout << tmp2.erase(26, tmp2.length() - 26);

		noidung.erase(0, 78);
		gotoXY(92, 4); cout << noidung.erase(23, noidung.length() - 23) + "...";
	}
	TextColor(15);
	gotoXY(x, y);

}