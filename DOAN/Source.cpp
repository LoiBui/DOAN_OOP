#include "console.h"
#include "MonHoc.h"
#include "Diem.h"
#include "SinhVien.h"
#include "QuanLy.h"

void _initialization(){
	SetConsoleTitleW(L"Đồ Án OOP: Quản Lý Điểm Thi");

	SinhVien sv;

}

int main(){
	

	
	
	_initialization();

	MonHoc::FileIn.open("MONHOC.txt", ios_base::in);
	


	QuanLy ql;
	
	ql.func();

	/*SinhVien sv;
	cin >> sv;*/

	/*MonHoc mh;
	mh._ShowDSMH();*/








	MonHoc::FileIn.close();
	
	
	system("pause");
	return 0;
}