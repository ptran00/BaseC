#include<iostream>
using namespace std;

/*Enum trong C++ la kieu du lieu chua cac hang so co dinh
 No co the su dung cho cac ngay trong tuan
(SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY và SATURDAY), 
Cac huong
(DONG, TAY, NAM và BAC) v.v ... 
cac hang so enum C++ la static.
=============
Enum trong C++  co the duoc coi la cac lop co tap hop hang co dinh

Nhung diem can nho ve Enum trong C++
enum cai thien kieu an toan
enum dươc su dung trong cau lenh switch
enum co the duoc duyet
enum cung co the chua cac truong , phuong thuc va constructor 
*/
enum NgayTrongTuan { T2 ,T3,T4,T5,T6,T7,CN};

void Show_T2_Todo() {
	cout << "Thu 2 phai hoc den 12h dem " <<endl;
}
void Show_T3_Todo(){
	cout << "Thu 3 Do rac chay duoc "<<endl;
}
void Show_T4_Todo(){
	cout << "Thu 4 phai hoc den 12h dem "<<endl;
}

void Show_T5_Todo(){
	cout << "Thu 5 phai hoc den 12h dem "<<endl;
}
void Show_T6_Todo(){
		cout << "Thu 6 do rac chay duoc "<<endl;
}
void Show_T7_Todo(){
		cout << "Thu 7 phai hoc tu 10h sang den 8h toi "<<endl;
}
void Show_CN_Todo(){
		cout << "Thu CN phai hoc tu 10h sang den 8h toi "<<endl;
}

void menu(NgayTrongTuan chon){
		switch (chon)
	{
	case T2:
		Show_T2_Todo();
		break;
	case T3:
		Show_T3_Todo();
		break;
	case T4:
		Show_T4_Todo();
		break;
	case T5:
		Show_T5_Todo();
		break;
	case T6:
		Show_T6_Todo();
		break;
	case T7:
		Show_T7_Todo();
		break;
	case CN:
		Show_CN_Todo();
		break;
	default:
		break;
	}
}

int main ()
{
	NgayTrongTuan chon;
	chon = T2;
	menu(chon);
	
	system("pause");
	return 0;
}

