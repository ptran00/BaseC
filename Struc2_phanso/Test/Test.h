#include<iostream>
#include<stdio.h>
#include<iomanip>
#include<string.h>
#include<conio.h>
using namespace std;

class SV {
private:
char *name,*lop;
public:
SV (char *ten=NULL,char *tlop=NULL)
{
name=strdup(ten);
lop=strdup(tlop);
}
~SV()
{
delete name;
delete lop;
}
void dsp ()
{
cout<<setw(20)<<name<<setw(10)<<lop;
}
};