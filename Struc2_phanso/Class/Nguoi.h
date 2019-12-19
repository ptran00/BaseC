#include<iostream>
#include<vector>
#include <ctime> 
#include<iomanip>
#include<string>
using namespace std;


class Nguoi
{
	private:
		string Name;
		string Namsinh;
		string Nhommau;
		float Chieucao;
		float Cannang;

	public:
		Nguoi();
		Nguoi(string ,string ,string ,float ,float );
		
		void setName(string Name);
		void setNamsinh(string Namsinh);
		void setNhommau(string Nhommau);
		void setChieucao(float Chieucao);
		void setCannang(float Cannang);

		string getName(void);
		string getNamsinh(void);
		string getNhommau(void);
		float getChieucao(void);
		float getCannang(void);
		
		virtual void Antrua(){
			cout<<"\nAn trua luc 12 h ";
		}

		 void Show_Infor(){
			 cout << setw(10) << Name << setw(20) <<Namsinh << setw(10)<<Nhommau <<setw(10)<< Chieucao << setw(10) << Cannang << endl ;
		}



		~Nguoi(){}

};
Nguoi::Nguoi(){
		string name = '\0';
		string namsinh = '\0';
		string Nhommau = '\0';
		float  Chieucao = 0;
		float Cannang = 0;
		}
Nguoi::Nguoi(string Name,string Namsinh,string Nhommau,float Chieucao,float Cannang){
			this->Name = Name;
			this->Namsinh = Namsinh;
			this->Nhommau = Nhommau;
			this-> Chieucao = Chieucao;
			this-> Cannang = Cannang;
}
		void Nguoi::setName(string Name){
			this-> Name = Name;
		}
		void Nguoi::setNamsinh(string Namsinh){
			this->Namsinh;
		}
		void Nguoi::setNhommau(string Nhommau){
			this->Nhommau = Nhommau;
		}
		void Nguoi::setChieucao(float Chieucao){
			this->Chieucao = Chieucao;
		}
		void Nguoi::setCannang(float Chieucao){
			this->Cannang = Cannang;
		}

		string Nguoi::getName(void){
			return Name;
		}

		string Nguoi::getNamsinh(void){
			return Namsinh;
		}
		string Nguoi::getNhommau(void){
			return Nhommau;
		}
		float Nguoi::getChieucao(void){
			return Chieucao;
		}
		float Nguoi::getCannang(void){
			return Cannang;
		}

		Nguoi Get_Mot_Nguoi(){
			string Name, Namsinh,Nhommau;float Chieucao,Cannang;
			cout <<"\nnhap vao ten : " ; fflush(stdin); getline(cin,Name);
			cout <<"\nnhap vao nam sinh : " ; fflush(stdin); getline(cin,Namsinh);
			cout <<"\nnhap vao nhom mau : " ; fflush(stdin); getline(cin,Nhommau);
			cout <<"\nnhap vao chieu cao : " ; cin >> Chieucao;
			cout <<"\nnhap vao can nang : " ; cin >> Cannang;
			Nguoi tmp(Name, Namsinh, Nhommau, Chieucao, Cannang);
			return tmp;
		}

	
		void Get_DS_Nguoi(vector<Nguoi> &DS , int n)
		{
			for (int i = 0; i < n; i++)
			{
			cout <<"\n\n\t====Thong tin hoc sinh thu " << i+1 << "====" << endl;
			Nguoi tmp = Get_Mot_Nguoi();
			DS.push_back(tmp);
			}
		}
 
