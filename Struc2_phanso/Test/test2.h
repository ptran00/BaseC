#include"Test.h"

class SVSP: public SV {
private:
float dtb, hb;
public:
SVSP (char *ten=NULL,char *tlop=NULL,float ddtb=0,float thb=0):SV (ten,tlop)
{
dtb=ddtb;
hb=thb;
}
void dsp()
{
SV::dsp();
cout<<setw(5)<<dtb<<setw(10)<<hb;
}
};