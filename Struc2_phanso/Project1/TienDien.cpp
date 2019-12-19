#include"TienDien.h"

double SoDienDung(double SoDien_ThangTruoc,double SoDien_ThangNay){
	return SoDien_ThangNay-SoDien_ThangTruoc;
}

 
double TienDien_SuDung(double SoDien_SD){
	if (SoDien_SD <= 100 ){ return SoDien_SD * 550;}
	if (SoDien_SD >100 && SoDien_SD <=150){return (SoDien_SD - 100)*900 + (100*550) ;}
	if (SoDien_SD>150 && SoDien_SD <=200){return (SoDien_SD - 150)*1210 + (50*900) + (100*550) ;}
	if (SoDien_SD >200 && SoDien_SD <=250){return (SoDien_SD - 200)*1340 + (50*1210)+(50*900) + (100*550) ;}
	if (SoDien_SD >250 && SoDien_SD <=300){return ((SoDien_SD - 250))*1500 + ((50*1340))+(50*1210)+(50*900) + (100*550) ;}
	if(SoDien_SD >300){ return ((SoDien_SD - 300)*2000)+ (50*1500) + (50*1340)+(50*1210)+(50*900) + (100*550) ;}
}

void Show_Detail(Tien_D Hogiadinh){
	cout <<"\n Ho gia dinh : " << Hogiadinh.getname();
	cout <<"\nSo dien thang Truoc : " << Hogiadinh.getSoDien_ThangTruoc();
	cout <<"\nSo dien thang nay : " << Hogiadinh.getSoDien_ThangNay();
	cout <<"\nSo dien dung trong thang : " << Hogiadinh.getSoDien_SD();
	cout <<"\nSo tien phai tra trong thang : " <<Hogiadinh.getSoTienTra();
	cout <<"\n========" << endl;

}
void Wirte_Detail(Tien_D Hogiadinh,ofstream &Fileout){
	Fileout << Hogiadinh.getname() << " , " << Hogiadinh.getSoDien_ThangTruoc() << "  " << Hogiadinh.getSoDien_ThangNay() << " " << Hogiadinh.getSoDien_SD() << " " << Hogiadinh.getSoTienTra();

}


void Get_Infor_GD(vector<Tien_D> &DanhSach_GiaDinh ,ifstream &Filein ){
	while (!Filein.eof() == true )
	{
		string name;
		double SoDien_ThangTruoc,SoDien_ThangNay,SoDien_SD,SoTienTra ;
		getline(Filein,name,',');
		Filein >> SoDien_ThangTruoc;
		Filein >> SoDien_ThangNay;
		SoDien_SD = SoDienDung(SoDien_ThangTruoc,SoDien_ThangNay);
		SoTienTra =TienDien_SuDung(SoDien_SD);
		
		string tmp;
		getline(Filein,tmp,'\n');

		Tien_D GD(name,SoDien_ThangTruoc,SoDien_ThangNay,SoDien_SD,SoTienTra);
		DanhSach_GiaDinh.push_back(GD);
	}
}

void In_Infor_GD(vector<Tien_D> DanhSach_GiaDinh ){

	for (int i = 0; i<DanhSach_GiaDinh.size(); i++)
	{
		Show_Detail(DanhSach_GiaDinh[i]);
	}
}



void Show_Infor_GD_100(vector<Tien_D> DanhSach,ofstream &Fileout){
	for (int i = 0; i < DanhSach.size(); i++)
	{
		if (DanhSach[i].getSoDien_SD() <= 100)
		{
			Wirte_Detail(DanhSach[i],Fileout);
			Fileout <<"\n";
		}
	}
	Fileout << "=======================" << endl;
}

void Show_Infor_GD_1_300(vector<Tien_D> DanhSach,ofstream &Fileout){
	for (int i = 0; i < DanhSach.size(); i++)
	{
		if (DanhSach[i].getSoDien_SD() > 100 && DanhSach[i].getSoDien_SD() <=300)
		{
			Wirte_Detail(DanhSach[i],Fileout);
			Fileout <<"\n";
		}
	}
	Fileout << "=======================" << endl;

}

void Show_Infor_GD_300(vector<Tien_D> &DanhSach,ofstream &Fileout){
	for (int i = 0; i < DanhSach.size(); i++)
	{
		if (DanhSach[i].getSoDien_SD() > 300)
		{
			Wirte_Detail(DanhSach[i],Fileout);
			Fileout <<"\n";
		}
	}
	Fileout << "=======================" << endl;
}




int main(){
	ifstream Filein;
	ofstream Fileout;
	Filein.open("DS_GD.txt",ios_base::in);
    vector <Tien_D> DanhSach_GiaDinh;
	// get ds thue bao tu file
	Get_Infor_GD(DanhSach_GiaDinh,Filein);
	//in ra danh sach thua bao
	Filein.close();
	//In_Infor_GD(DanhSach_GiaDinh);
	Fileout.open("DS_GD_100.txt",ios_base::out);
	Show_Infor_GD_100(DanhSach_GiaDinh,Fileout);
	Show_Infor_GD_1_300(DanhSach_GiaDinh,Fileout);
	Show_Infor_GD_300(DanhSach_GiaDinh,Fileout);

	Fileout.close();
	system("pause");
	return 0;
}


 
