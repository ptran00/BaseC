#include"Nguoi.h"

class Hocsinh:public Nguoi {
private:
	string Tentruong;
	float Diemtrungbinh;
	int Somonhoc;
	string Tenmonhoc;
	float Diem;
public:
	Hocsinh();
	Hocsinh(string,float);
	Hocsinh(string ,string ,string ,float ,float,string,float);

	void setTentruong(string Tentruong);
	void setDiemtrungbinh(float Diemtrungbinh);

	string getTentruong();
	float getDiemtrungbinh();

	void Antrua () override{
		cout << "\nHoc sinh an com trua tai truong " << Tentruong << endl;
		
	}
	void Input_Infor_Hocsinh();
	
	void Show_Infor(){
		cout << setw(10) << getName() << setw(20) <<getNamsinh() << setw(10)<<getNhommau() <<setw(10)<< getChieucao() << setw(10) << getCannang() << setw(10) << Tentruong <<setw(10)<< Diemtrungbinh << endl; 
		
		}

	void Ancom(time_t &tm);
	
	~Hocsinh(){}
};
	Hocsinh::Hocsinh(){
		string name = '\0';
		string namsinh = '\0';
		string Nhommau = '\0';
		string Tentruong = '\0';
		float  Chieucao = 0;
		float Cannang = 0;
		float Diemtrungbinh = 0;
	}

	Hocsinh::Hocsinh(string Tentruong,float Diemtrungbinh){
			this->Tentruong =Tentruong;
			this->Diemtrungbinh = Diemtrungbinh;
}
	Hocsinh::Hocsinh(string Name,string Namsinh,string Nhommau,float Chieucao,float Cannang,string Tentruong,float Diemtrungbinh) :Nguoi (Name,Namsinh,Nhommau,Chieucao,Cannang ){
		this->Tentruong =Tentruong;
		this->Diemtrungbinh = Diemtrungbinh;
	}



	void Hocsinh::setTentruong(string Tentruong){
		this->Tentruong = Tentruong;
	}
	void Hocsinh::setDiemtrungbinh(float Diemtrungbinh){
		this-> Diemtrungbinh = Diemtrungbinh;
	}
	string Hocsinh:: getTentruong(){
		return Tentruong;
	}
	float Hocsinh::getDiemtrungbinh(){
		return Diemtrungbinh;
	}
	
	Hocsinh Get_Mot_HS(){
			string Name, Namsinh,Nhommau,Tentruong;float Chieucao,Cannang,Diemtrungbinh;
			cout <<"\nnhap vao ten : " ; fflush(stdin); getline(cin,Name);
			cout <<"\nnhap vao nam sinh : " ; fflush(stdin); getline(cin,Namsinh);
			cout <<"\nnhap vao nhom mau : " ; fflush(stdin); getline(cin,Nhommau);
			cout <<"\nnhap vao chieu cao : " ; cin >> Chieucao;
			cout <<"\nnhap vao can nang : " ; cin >> Cannang;
			cout <<"\nnhap vao ten truong : " ; fflush(stdin); getline(cin,Tentruong);
			cout <<"\nnhap vao diem trung binh : " ; cin >> Diemtrungbinh;

			Hocsinh tmp(Name, Namsinh, Nhommau, Chieucao, Cannang,Tentruong,Diemtrungbinh);
			return tmp;
		}
	
	void Get_DS_HS(vector<Nguoi> &DS , int n)
		{
			for (int i = 0; i < n; i++)
			{
			cout <<"\n\n\t====Thong tin hoc sinh thu " << i+1 << "====" << endl;
			Hocsinh tmp = Get_Mot_HS();
			DS.push_back(tmp);
			}
		}