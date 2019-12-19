#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*: Hãy khai báo cấu trúc dữ liệu cho danh sách liên kết đơn các phòng trong khách sạn (PHONG).
Giả sử phòng khách sạn gồm những thông tin như sau:
– Mã phòng: tối đa 5 ký tự
– Tên phòng: tối đa 30 ký tự
– Đơn giá thuê: kiểu số thực
– Số lượng giường: kiểu số nguyên
– Tình trạng giường: 0 rảnh 1 bận
SourceCode
while (x.RoomID.size()>5){
		cout <<"\nnhap lai ID : ";
	}
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




    
