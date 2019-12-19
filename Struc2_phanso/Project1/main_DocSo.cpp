#include<iostream>
#include<string>
#include<vector>
using namespace std;

/* H?y khai b?o c?u tr?c d? li?u cho danh s?ch li?n k?t ??n c?c ph?ng trong kh?ch s?n (PHONG).
Gi? s? ph?ng kh?ch s?n g?m nh?ng th?ng tin nh? sau:
? M? ph?ng: t?i ?a 5 k? t?
? T?n ph?ng: t?i ?a 30 k? t?
? ??n gi? thu?: ki?u s? th?c
? S? l??ng gi??ng: ki?u s? nguy?n
? T?nh tr?ng gi??ng: 0 r?nh 1 b?n
*/
struct Ro_Infor
{
	string RoomID;
	string RoomName;
	float  Fee ;
	int    Bed;
	int    Room_Status;
};

//nhap thong tin phong
void Input_Ro_Infor(Ro_Infor &x){
	cout << "\nNhap ID : " ;
	fflush(stdin);
	getline(cin,x.RoomName);
	cout << "\nNhap Ten phong : " ;
	fflush(stdin);
	getline(cin,x.RoomName);
	cout << "\nNhap so giuong : " ;
	cin >> x.Bed;
	cout << "\nNhap tien phong : " ;
	cin >> x.Fee;
	cout << "\nNhap tinh trang phong 1-Phong kin,0-Phong trong : " ;
	cin >> x.Room_Status;
}


// status :
string R_S(Ro_Infor x){
	if (x.Room_Status == 1)
	{
		return "Phong dang cho thue" ;
	}else {
		return "Phong dang trong " ;
	}  
}
// output thong tin phong
void Output_Ro_Infor(Ro_Infor &x){
	cout << "\nID : " << x.RoomID;
	cout << "\nName : " << x.RoomName;
	cout << "\nSo phong : " << x.Bed;
	cout << "\nTien phong : " << x.Fee;
	cout << "\nTinh trang phong : " << R_S(x);
}
// Input Room list
void Input_DS(vector<Ro_Infor> &x,int n){
	for (int i = 0; i < n; i++)
	{
		Ro_Infor tmp ;
		Input_Ro_Infor(tmp);
		x.push_back(tmp);
	}
}
//output room list
void Output_DS(vector<Ro_Infor> &x){
	cout << "============ thong Tin phong ============";
	for (int i = 0; i < x.size(); i++)
	{
		Output_Ro_Infor(x[i]);
	}
}



int main()
{
	vector <Ro_Infor> DS;
	int n;
	cout << "\nnhap so phong : " ;
	cin >> n;
	Input_DS(DS,n);
	Output_DS(DS);


	system("pause");
}