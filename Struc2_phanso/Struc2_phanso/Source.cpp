#include<iostream>
#include<fstream>

using namespace std;

// struct
struct ps
{
int tuso;
int mauso;
};
typedef struct ps PS;

struct danhsach
{
ps *arr;
float *ar1;
int n;

};
typedef struct danhsach DS;
// nhap phan so
void nhap(ps &x)
{
	ofstream danhsach_phanso;
	danhsach_phanso.open("DSPS.txt",ios_base::out);
    cout << "\nnhap tu so : "; cin >> x.tuso;
    cout << "\nnhap mau so : "; cin >> x.mauso;
	danhsach_phanso >> x.tuso;

	danhsach_phanso.close();
}

// xuat phan so
void xuat(ps x)
{
cout << x.tuso << "/" << x.mauso << endl;
}
// xuat gia thi so thuc cua PS
void xuat_giatri(danhsach x)
{
cout << "\nso thuc la : " << x.ar1;
}


//nhap danh sach ps
void nhap_danhsach(DS &x)
{
for (int i = 0; i < x.n; i++)
{
 cout << "\nnhap phan so thu " << i + 1;
 nhap(x.arr[i]);
}
}
// xuat danh sach ps
void xuat_danhsach(DS &x)
{
for (int i = 0; i < x.n; i++)
{
 cout << "\nphan so thu " << i + 1 << " : ";
 xuat(x.arr[i]);
}
}
// xuat danh sach so thuc
void xuat_danhsach_sothuc(DS &x)
{
for (int i = 0; i < x.n; i++)
{
 cout << "\nso thuc : " << i + 1 <<" : "<< x.ar1[i];
 
}
}


// uoc chung lon nhat
int UCLN(ps x)
{
if (x.tuso == 0 || x.mauso == 0)
{
 return x.mauso + x.mauso;
}
while (x.tuso != x.mauso)
{
 if (x.tuso > x.mauso)
 {
  x.tuso = x.tuso - x.mauso;
 }
 else
 {
  x.mauso = x.mauso - x.tuso;
 }
}
return x.tuso;
}

// rut gon phan so
void Rut_Gon_PS(ps &x)
{

int uoc = UCLN(x);

x.tuso = x.tuso / uoc;
x.mauso = x.mauso / uoc;


}

// rut gon cac phan so trong danh sach
void Rut_Gon_DanhSach_ps(danhsach &x)
{
for (int i = 0; i < x.n; i++)
{
 Rut_Gon_PS(x.arr[i]);
}
}

// cong 2 phan so
PS Cong_PS(ps a, ps b)
{
ps c;
c.tuso = (a.tuso*b.mauso) + (b.tuso*a.mauso);
c.mauso = a.mauso*b.mauso;
return c;
}

// cong danh sach cac phan so
ps Cong_danhsach_ps(danhsach x)
{
ps a = x.arr[0];
for (int i = 1; i < x.n; i++)
{
 a = Cong_PS(a, x.arr[i]);
}
return a;
}


// chuyen PS ve so thuc

void change_value_PS(danhsach &x)
{
	for (int i = 0; i < x.n; i++)
	 {
	 x.ar1[i] =(float)x.arr[i].tuso / x.arr[i].mauso;

	 }
}
// tinh tong so array so thuc 
float Tong_value_PS(danhsach x)
{
	float tong = 0;
	for (int i = 0; i < x.n; i++)
	{
		tong += x.ar1[i];
	}
	return tong;
}

//Tim so lon nhat
PS Tim_PS_lonnhat(danhsach x)
{
float max = x.ar1[0];
PS az;
if (x.n==1)
{
	az = x.arr[0];
	return az;

}
for (int i = 1; i < x.n; i++)
{
 if (max < x.ar1[i])
 {
  max = x.ar1[i];
  az = x.arr[i];
 }
}
return az;

}
//menu
void Menu()
{
danhsach x;
ps  z;
cout << "\n\n\t=====CAC THAO TAC TREN PHAN SO=====";
cout << "\n\tnhap so luong phan so "; cin >> x.n;
// khai bao cho mang phan so
x.arr = new ps[x.n];
x.ar1 = new float[x.n];
nhap_danhsach(x);
change_value_PS(x);
system("cls");
int select;
char comfirm;
do {
 system("cls");
 cout << "\n\n\t=====CAC THAO TAC TREN PHAN SO=====";
 cout << "\n1. Xuat phan so vua nhap";
 cout << "\n2. Rut gon cac phan so vua nhap";
 cout << "\n3. Cong danh sach vua nhap";
 cout << "\n4. Xuat phan so  sang gia tri so thuc";
 cout << "\n5. Tim phan so lon nhat";
 cout << "\n0. Thoat chuong trinh";
 cout << "\n\t==chon so tren menu de thao tac=="; cin >> select;
 switch (select)
 {
  case 1:
	  system("cls");
	  cout << "\n\n\t=====XUAT CAC PHAN SO VUA NHAP=====";
	  xuat_danhsach(x);

	  cout << "\nnhan 'N' hoac 'n' de tiep tuc : "; cin >> comfirm;
	  system("pause");
	  cout << endl;
	   break;
  case 2:
	  system("cls");
	  cout << "\n\n\t=====RUT GON CAC PHAN SO VUA NHAP=====";
	  Rut_Gon_DanhSach_ps(x);
	  xuat_danhsach(x);

	  cout << "\nnhan 'N' hoac 'n' de tiep tuc : "; cin >> comfirm;
	  system("pause");
	   cout << endl;
	   break;

  case 3:
	  system("cls");
	  cout << "\n\n\t=====CONG DANH SACH PHAN SO VUA NHAP=====";
	  PS cong;
	  float giatri;
	  cong = Cong_danhsach_ps(x);
	  cout<< "\nGia tri cong PS : "; xuat(cong);

	  
	  giatri  =(float)cong.tuso / cong.mauso;
	  cout << "gia tri tong phan so : " << giatri;
	  

	  cout << "\nnhan 'N' hoac 'n' de tiep tuc : "; cin >> comfirm;
	  system("pause");
	   cout << endl;
	  break;
  case 4:
	  system("cls");

	  cout << "\n\n\t=====XUAT PS SANG GIA TRI SO THUC =====";
	  xuat_danhsach_sothuc(x);
	  cout << "\nnhan 'N' hoac 'n' de tiep tuc : "; cin >> comfirm;
	  system("pause");
	   cout << endl;
	  break;
   case 5:
	  system("cls");
	  PS PSLN;

	  cout << "\n\n\t=====TIM PHAN SO LON NHAT====="<< endl;
	  PSLN = Tim_PS_lonnhat(x);
	  cout <<"\nphan so lon nhat la : ";xuat(PSLN);

	  cout << "\nnhan 'N' hoac 'n' de tiep tuc : "; cin >> comfirm;
	  system("pause");
	  cout << endl;
	  break;
   case 0:
      break;
 }
}while(comfirm =='N' || comfirm =='n');



}

int main()
{
	Menu();


	return 0;
}