#include"Hocsinh.h"


class Emply : public Nguoi
{
private:
	std::string FactoryName;
	float Sogiolam;
	float Nghi;
public:
	Emply();
	Emply(string ,float ,float);
	Emply(string ,string ,string ,float ,float,string ,float ,float);



	void setFactoryName(string FactoryName);
	void setSogiolam(float Sogiolam);
	void setNghi(float Nghi);

	std::string getFactoryName();
	float getSogiolam();
	float getNghi();

	void Antrua () override{
		cout << "\nNhan vien an com trua tai truong " << FactoryName << endl;
		
	}
	void Show_Infor(){
		cout << setw(10) << getName() << setw(20) <<getNamsinh() << setw(10)<<getNhommau() <<setw(10)<< getChieucao() << setw(10) << getCannang() << setw(10) << FactoryName <<setw(10)<< Sogiolam <<setw(10) << Nghi << endl;
	}

	~Emply(){}

};

Emply::Emply()
{
		std::string name = '\0';
		std::string namsinh = '\0';
		std::string Nhommau = '\0';
		std::string FactoryName = '\0';
		float  Chieucao = 0;
		float Cannang = 0;
		float Sogiolam = 0;
		float Nghi = 0;
}
Emply::Emply(string FactoryName,float Sogiolam ,float Nghi) {
	this->FactoryName = FactoryName;
	this->Sogiolam  = Sogiolam;
	this->Nghi = Nghi;
}
Emply::Emply(string Name,string Namsinh,string Nhommau,float Chieucao,float Cannang,string FactoryName,float Sogiolam ,float Nghi) : Nguoi(Name,Namsinh,Nhommau,Chieucao,Cannang){
	this->FactoryName = FactoryName;
	this->Sogiolam  = Sogiolam;
	this->Nghi = Nghi;
}

void Emply::setFactoryName(string FactoryName){
	this->FactoryName = FactoryName;
}
void Emply::setSogiolam(float Sogiolam){
	this->Sogiolam = Sogiolam;
}
void Emply::setNghi(float Nghi){
	this->Nghi = Nghi;
}

string Emply::getFactoryName(){
	return FactoryName;
}
float Emply::getSogiolam(){
	return Sogiolam;
}
float Emply::getNghi(){
	return Nghi;
}


Emply Get_Mot_NV(){
			string Name, Namsinh,Nhommau,FactoryName;float Chieucao,Cannang,Sogiolam,Nghi;
			cout <<"\nnhap vao ten : " ; fflush(stdin); getline(cin,Name);
			cout <<"\nnhap vao nam sinh : " ; fflush(stdin); getline(cin,Namsinh);
			cout <<"\nnhap vao nhom mau : " ; fflush(stdin); getline(cin,Nhommau);
			cout <<"\nnhap vao chieu cao : " ; cin >> Chieucao;
			cout <<"\nnhap vao can nang : " ; cin >> Cannang;
			cout <<"\nnhap vao ten cong ty : " ; fflush(stdin); getline(cin,FactoryName);
			cout <<"\nnhap vao so gio lam : " ; cin >> Sogiolam;
			cout <<"\nnhap vao so gio nghi  : " ; cin >> Nghi;

			Emply tmp(Name, Namsinh, Nhommau, Chieucao, Cannang,FactoryName,Sogiolam,Nghi);
			return tmp;
		}
	
	void Get_DS_NV(vector<Nguoi> &DS , int n)
		{
			for (int i = 0; i < n; i++)
			{
			cout <<"\n\n\t====Thong tin  NV thu " << i+1 << "====" << endl;
			Emply tmp = Get_Mot_NV();
			DS.push_back(tmp);
			}
		}


