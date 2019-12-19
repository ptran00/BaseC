#include<iostream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

class SV
{
private:
	static int MSSV ;
	string name;
	string Namsinh;
	string Monhoc;
	float Diem;
public:
	SV()
	{
	this->name[0] = '\0';
	this->Namsinh[0] = '\0';
	this->Monhoc[0]= '\0';
	this->Diem = 0;
	
	}
	SV(string name,string Namsinh ,string Monhoc,float Diem)
	{
		
		this -> name = name;
		this->Namsinh = Namsinh;
		this->Monhoc = Monhoc;
		this->Diem = Diem;
		
	}

	void setname(string);
	void setNamsinh(string);
	void setMonhoc(string);
	void setDiem(float);
	static void setMSSV(int);
    
	string getname(void);
	string getNamsinh(void);
	string getMonhoc(void);
	float getDiem(void);
	void IN_Infor_SV();
	void Output_SV_Infor(ofstream &opfile,vector<SV> sv);



	~SV(){}
};
	void SV::setname(string name){
		this->name = name;
	}
	void SV::setNamsinh(string Namsinh){
		this->Namsinh = Namsinh;
	}
	void SV::setMonhoc(string  Monhoc){
		this->Monhoc = Monhoc;
	}
	void SV::setDiem(float Diem){
		this-> Diem = Diem;
	}


	string SV::getname(void){
		return name;
	}
	string SV::getNamsinh(void){
		return Namsinh;
	}
	string SV::getMonhoc(void){
		return Monhoc;
	}
	float SV::getDiem(void){
		return Diem;
	}
	

// Ham doc thong tin
	void SV::IN_Infor_SV()
	{
		cout <<"SV of name :"<< name << endl;
		cout <<"SV Of nam sinh :" <<Namsinh << endl;
		cout << "SV of Mon Hoc :" <<Monhoc << endl;
		cout << "Diem :"<<Diem << endl;

	}
	// Nhap thong tin nhieu SV
	void Input_Infor_SV(vector<SV> &DSSV,int n )
	{
		
		for (int i = 0; i < n; i++)
		{ 

			cout <<"\nNhap Thong Tin SV Thu : " << i+1 << endl;
			string name;
			cout << "\nNhap name cua sv : " ;fflush(stdin); getline(cin,name);
			string Namsinh;
			cout << "\nNhap nam sinh cua SV : " ;fflush(stdin);getline(cin,Namsinh);
			string Monhoc;
			cout << "\nNhap mon hoc cua SV : " ;fflush(stdin);getline(cin,Monhoc);
			float Diem;
			cout << "\nNhap diem mon hoc : " ;cin>>Diem;
			SV sv(name,Namsinh,Monhoc,Diem);
			cout << "============" << endl;
			DSSV.push_back(sv);
		}
	}
//==========
//Luu danh sach sv ra file 

	void SV::Output_SV_Infor(ofstream &opfile,vector<SV> sv){

	}


int main ()
{
	ofstream opfile;
	opfile.open("SV_Infor.txt",ios::out);

	vector <SV> DSSV;
	int Long;
	cout << "\nNhap so luong sinh vien :" ; cin >> Long;
	Input_Infor_SV(DSSV,Long);
	
	for (int i = 0; i < Long; i++)
	{
		DSSV[i].IN_Infor_SV();
		cout <<"============="<<endl;

	}
	// sua ten sinh vien thu 2 -> Nguyen Van Hai
	
	DSSV[1].setname("Nguyen Van Hai");
	for (int i = 0; i < Long; i++)
	{
		DSSV[i].IN_Infor_SV();
		cout <<"============="<<endl;

	}



	system("pause");

}



