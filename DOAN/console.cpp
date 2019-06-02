#include "console.h"

void NoType(bool tmp){
	CONSOLE_CURSOR_INFO inffo;
	inffo.bVisible = tmp;
	inffo.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &inffo);
}



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
		getline(cin, s);
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
		cin >> s;
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


int TryCatch(){
	string input;
	
	while (true)
	{
		getline(cin, input);
		bool check = true;
		for (int i = 0; i < input.length(); i++){
			if (input[i] > '9' || input[i] < '0'){
				check = false;
				break;
			}
		}
		if (check == false){
			TextCL(4, "	[Du Lieu Nhap Khong Hop Le.]");
			cout << "\n	Nhap Lai: ";
		}
		else return atoi(input.c_str());
	}
	
	return 1;
}