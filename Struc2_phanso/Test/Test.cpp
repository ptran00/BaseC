
#include"Test3.h"
void main()
{

SVCN *a[3];
int i;
char name[30],lop[10];
float dtb,hb,hp;
for (i=0;i<3;i++)
{
cout <<"==Thong tin sinh vien thu : " <<i+1<<"==\n";
cout<<"Nhap ten: ";fflush(stdin);gets(name);
cout<<"Nhap lop: ";fflush(stdin);gets(lop);
cout<<"Nhap DTB: ";cin>>dtb;
cout<<"Nhap hoc bong: ";cin>>hb;
cout<<"Nhap hoc phi: ";cin>>hp;
a[i]=new SVCN(name,lop,dtb,hb,hp);
}
cout<<"\n=====THONG TIN SINH VIEN =======\n";
for (i=0;i<3;i++)
{
cout<<"\n";
a[i]->dsp();
}
getch();
}