// basic console functions, collected by Nguyen Trung Thanh
// abcxyz tcIT
#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <fstream>
#define MauChu 9
using namespace std;



//--------------------------------------------------------

#include <windows.h>

//--------------------------------------------------------

int inputKey();

//-------------------------Screen-------------------------
void clrscr();

//screen: goto [x,y]
void gotoXY(int column, int line);

//screen: get [x]
int whereX();

//screen: get [y]
int whereY();

void TextColor(int color);

// hide cursor
void NoType(bool);
//msg
bool MBox(string content, int type);
//end----------------------Screen----------------------end

float TinhDiemHe4(float);
string TinhDiemChu(float);
string XepLoai(float);
string DOWHILE1(int x, int y, string noidung);
int DOWHILE2(int x, int y, string noidung);
void TextCL(int, string);
string DOWHILEYESNO(string);

string CatString(string, int);
int TryCatch(int, int);
float TryCatch1(float, float);
void ThongBao(string, int);