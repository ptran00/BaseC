#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

struct SV
{
	string Name;
	string MSSV;
	string NS;
	std::vector <monhoc> Danhsach_MH ;
};
typedef struct SV sv;
struct Monhoc
{
	string mon;
	float Diem;
};
typedef struct Monhoc monhoc;
void Doc_SV_infor(ifstream &Filein,sv &dsv)
{   
	
	getline(Filein,dsv.Name,',');
	getline(Filein,dsv.MSSV,',');
	getline(Filein,dsv.NS);
}
void Doc_SV_Diem(ifstream &Filein,monhoc &mon)
{   
	
	getline(Filein,mon.mon,'-');
	Filein >> mon.Diem ;
}
void Doc_file_SV(ifstream &Filein, vector<sv> &DS_sv)
{
	while (Filein.eof() == false)
	{
		sv mot_sv;
		Doc_SV_infor(Filein,mot_sv);
		DS_sv.push_back(mot_sv);
        int soluongmonhoc;
		Filein >> soluongmonhoc;
		for (int i = 0; i < soluongmonhoc; i++)
		{
			monhoc mon;
			Doc_SV_Diem(Filein,mon);
			mot_sv.Danhsach_MH.push_back(mon);
		}

	}

}




int main()
{
	ifstream Filein;
	vector <sv> dsthongtin_sv;
	Filein.open("thongtin.txt",ios::in);
	Doc_file_SV(Filein,dsthongtin_sv);




	Filein.close();

}