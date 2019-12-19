#include"test2.h"

class SVCN : public SVSP {
private:
float hp;
public:
SVCN (char *ten=NULL,char *tlop=NULL,float ddtb=0,float thb=0,float thp=0):SVSP(ten,tlop,ddtb,thb)
{
hp=thp;
}
void dsp()
{ 
	cout<<setiosflags(ios::left);
SVSP::dsp();
cout<<setw(10)<<hp;
}
};