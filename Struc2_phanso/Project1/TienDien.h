#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std ;

class Tien_D
{
private:
	string name;
	float SoDien_ThangTruoc ;
	float SoDien_ThangNay;
	float SoDien_SD;
	float SoTienTra;
public:
	Tien_D(string name,float SoDien_ThangTruoc,float SoDien_ThangNay,float SoDien_SD,float SoTienTra){
		this->name = name;
		this->SoDien_ThangTruoc = SoDien_ThangTruoc;
		this->SoDien_ThangNay = SoDien_ThangNay;
		this->SoDien_SD = SoDien_SD;
		this->SoTienTra = SoTienTra;
	}

	string getname(){
		return name;
	}
	float getSoDien_ThangTruoc(){
		return SoDien_ThangTruoc;
	}
	float getSoDien_ThangNay(){
		return SoDien_ThangNay;
	}
	float getSoDien_SD(){
		return SoDien_SD;
	}
	float getSoTienTra(){
		return SoTienTra;
	}


	~Tien_D(){
	}
};

float SoDienDung(float SoDien_ThangTruoc,float SoDien_ThangNay);
float TienDien_SuDung(float SoDien_SD);
void Show_Detail(Tien_D Hogiadinh);
void Get_Infor_GD(vector<Tien_D> &DanhSach_GiaDinh ,ifstream &Filein );
void In_Infor_GD(vector<Tien_D> DanhSach_GiaDinh);
void Show_Infor_GD_100(vector<Tien_D> DanhSach);
void Show_Infor_GD_300(vector<Tien_D> DanhSach);
void Show_Infor_GD_100(vector<Tien_D> DanhSach);
