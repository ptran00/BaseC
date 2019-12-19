#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std ;
/*
Sử dụng mảng cấu trúc lưu họ tên chủ hộ,
số điện tháng trước, số điện tháng này, 
số tiền phải trả. 
Lập trình nhập dữ liệu cần thiết,
tiền điện dựa trên số điện trong tháng s=số điện tháng trước-số điện tháng này.
 Đơn giá quy định: 100 số đầu giá 550, 50 số tiếp theo giá 900, 
 50 số tiếp theo giá 1210, 50 số tiếp theo giá 1340, 
 50 số tiếp theo giá 1500, các số điện >300 theo giá 2000.
 In ra bảng thống kê thanh toán tiền điện của tất cả các thuê bao; 
 bảng thống kê những hộ sử dụng theo từng loại: <=100 số, từ 101 đến 300 số và trên 300 số.
*/ 


class Tien_D
{
private:
	string name;
	double SoDien_ThangTruoc ;
	double SoDien_ThangNay;
	double SoDien_SD;
	double SoTienTra;
public:
	Tien_D(string name,double SoDien_ThangTruoc,double SoDien_ThangNay,double SoDien_SD,double SoTienTra){
		this->name = name;
		this->SoDien_ThangTruoc = SoDien_ThangTruoc;
		this->SoDien_ThangNay = SoDien_ThangNay;
		this->SoDien_SD = SoDien_SD;
		this->SoTienTra = SoTienTra;
	}

	string getname(){
		return name;
	}
	double getSoDien_ThangTruoc(){
		return SoDien_ThangTruoc;
	}
	double getSoDien_ThangNay(){
		return SoDien_ThangNay;
	}
	double getSoDien_SD(){
		return SoDien_SD;
	}
	double getSoTienTra(){
		return SoTienTra;
	}


	~Tien_D(){
	}
};
//tinh so dien da dung
double SoDienDung(double SoDien_ThangTruoc,double SoDien_ThangNay);
//tinh tien dien da dung
double TienDien_SuDung(double SoDien_SD);
//show thong tin 1 ho 
void Show_Detail(Tien_D Hogiadinh);
//ghi file thong tin 1 ho gia dinh
void Wirte_Detail(Tien_D Hogiadinh,ofstream &Fileout);
//Get infor of GD in DS_GD.txt
void Get_Infor_GD(vector<Tien_D> &DanhSach_GiaDinh ,ifstream &Filein );
//In danh sach 
void In_Infor_GD(vector<Tien_D> DanhSach_GiaDinh);
//show Infor of GD <=100
void Show_Infor_GD_100(vector<Tien_D> DanhSach,ofstream &Fileout);
//show Infor of GD 101 ~ 300
void Show_Infor_GD_1_300(vector<Tien_D> DanhSach,ofstream &Fileout);
//show Infor of GD > 300
void Show_Infor_GD_300(vector<Tien_D> &DanhSach,ofstream &Fileout);






