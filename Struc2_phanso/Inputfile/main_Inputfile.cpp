#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include<string.h>
#include <fstream>

// struct monhoc
struct MonHoc
{
        string Mon;
        float Diem;
};
typedef struct MonHoc monhoc;
// struct sinhvien

struct SinhVien
{
        string name;
        string mssv;
        string namsinh;
        vector<monhoc> DS_MonHoc;
};
typedef struct SinhVien sinhvien;

// Docfile thong tin sv
void Doc_ThongTin_SV(ifstream &Filein, sinhvien &sv)
{
        getline(Filein, sv.name, ',');
        getline(Filein, sv.mssv, ',');
        getline(Filein, sv.namsinh,'\n');
}
//ham get thong tin mon hoc
void Doc_ThongTin_MonHoc(ifstream &Filein, monhoc &MH)
{       
		string tmp;
		getline(Filein,tmp,'\n');
        getline(Filein, MH.Mon, '-');
        Filein >> MH.Diem;
}
// thong tin toan bo sv
void Toan_ThongTin_SV(ifstream &Filein, vector<sinhvien> &DS_ThongTin_SV)
{
	while (!Filein.eof() == true)
        {
                sinhvien sv_tmp;
                Doc_ThongTin_SV(Filein, sv_tmp);
                int n;
                Filein >> n;
                for (int i = 0; i < n; i++)
                {
                        monhoc mon;
                        Doc_ThongTin_MonHoc(Filein, mon);
                        sv_tmp.DS_MonHoc.push_back(mon);
                }
                DS_ThongTin_SV.push_back(sv_tmp);
				string tmp;
		        getline(Filein,tmp);
        }
}

// xuat thong tin sv 
void xuat_thong_tin_sv(ofstream &Filein ,sinhvien sv)
{
	    Filein << "\nTen sinh vien : " << sv.name;
		cout << "\nTen sinh vien : " << sv.name;
        Filein << "\nMa so sinh vien : " << sv.mssv;
		cout << "\nMa so sinh vien : " << sv.mssv;
        Filein << "\nNgay thang nam sinh : " << sv.namsinh;
		cout << "\nNgay thang nam sinh : " << sv.namsinh;
}

// xuat thong tin mon hoc
void xuat_thong_tin_MonHoc(ofstream &Filein,monhoc mh)
{
    Filein << "\nTen mon hoc : " << mh.Mon <<"-"<< mh.Diem ;
	cout << "\nTen mon hoc : " << mh.Mon <<"-"<< mh.Diem ;
}

// xuat_DanhSach_SV
void xuat_DanhSach_SV(ofstream &FILE ,vector<sinhvien> sv)
{
        for (int i = 0; i < sv.size(); i++)
        {
			FILE << "\nSinh vien thu : " <<  i+1;
			cout << "\nSinh vien thu : " <<  i+1;
			xuat_thong_tin_sv(FILE,sv[i]);
                for (int j = 0; j <sv[i].DS_MonHoc.size(); j++)
                {
                   FILE << "\nMon hoc thu : " << j+1 ;
				   cout << "\nMon hoc thu : " << j+1;
                    xuat_thong_tin_MonHoc(FILE,sv[i].DS_MonHoc[j]);
                }
				cout <<"\n";
        }
}
// So sanh 2 chuoi giong nhau
void TimKien_Ten_SV(ofstream &File ,vector<sinhvien> DSSV, string timkiem)
{
	int n = DSSV.size();
	for (int i = 0; i <n; i++)
	 {
		 if(stricmp(DSSV[i].name.c_str(),timkiem.c_str()) == 0  || stricmp(DSSV[i].mssv.c_str(),timkiem.c_str()) == 0 )
		{
			xuat_thong_tin_sv(File,DSSV[i]);

			for (int j = 0; j < DSSV[i].DS_MonHoc.size(); j++)
			{
				xuat_thong_tin_MonHoc(File,DSSV[i].DS_MonHoc[j]);
			}
		}
	 }
}
// Tach nam sinh tu string
string Get_NamSinh_tu_User(string Namsinh)
{   
	string tmp;
	for (int i =Namsinh.length()-1; i >=0 ; i--)
	{	
	  if (Namsinh[i] >='0' && Namsinh[i] <='9')
		{ 
			string tam;
			tam = Namsinh[i];
			tmp.insert(0,tam);
		}else
		{
	  	 break;
		}
	}
	return tmp;
}
// Ghi thong tin mon hoc
void Ghi_ThongTin_MH(ofstream &Fileout_namsinh, monhoc mon)
{
	Fileout_namsinh << mon.Mon << "-" << mon.Diem << endl;
}

// Ghi thong tin sinh vien
void Ghi_ThongTin_SV(ofstream &Fileout_namsinh, sinhvien sv)
{
	Fileout_namsinh << sv.name << "," <<sv.mssv << "," << sv.namsinh << endl;
	Fileout_namsinh << sv.DS_MonHoc.size()<< endl;
	for (int i = 0; i < sv.DS_MonHoc.size(); i++)
	{
		Ghi_ThongTin_MH(Fileout_namsinh,sv.DS_MonHoc[i]);
	}
}

// tim SV_co cung namsinh
void Ghi_SV_Cung_NamSinh(ofstream &Fileout_namsinh ,vector<sinhvien> ds_sv , string Namsinh)
{
	string namsinh_input;
    namsinh_input = Get_NamSinh_tu_User(Namsinh);
	for (int i = 0; i <ds_sv.size(); i++)
	{  
		if ((namsinh_input.compare(Get_NamSinh_tu_User(ds_sv[i].namsinh))) == 0)
		{
			Ghi_ThongTin_SV(Fileout_namsinh,ds_sv[i]);
		}
	}
}


int main()
{
        ifstream Filein;
		ofstream Fileout;
		ofstream TimKiem;
		ofstream Fileout_NamSinh;

		Filein.open("svinfor.txt", ios_base::in);
        vector<sinhvien> danhsach_sinhvien;

      Toan_ThongTin_SV(Filein,danhsach_sinhvien);
	   Filein.close();

       Fileout.open("SVout.txt",ios_base::out);
	   xuat_DanhSach_SV(Fileout,danhsach_sinhvien);

	   Fileout.close();

	   string SVTK;
	   cout <<"nhap chuoi tim kiem : ";
	   getline(cin,SVTK);

	   TimKiem.open("TimKiem.txt",ios_base::out);
	   TimKien_Ten_SV(TimKiem,danhsach_sinhvien,SVTK);
	   TimKiem.close();
 
	    Fileout.close();
		Fileout_NamSinh.open("ThongTin_SV_cung_namsinh.txt",ios_base::out);
		string namsinh;
		cout << "\nnhap nam sinh Tim Kiem : " ; getline(cin,namsinh);
		Ghi_SV_Cung_NamSinh(Fileout_NamSinh,danhsach_sinhvien,namsinh);

		Fileout_NamSinh.close();
        system("pause");
}