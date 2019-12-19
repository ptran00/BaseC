#include<iostream>
using namespace std;

int main(){

	int a,b,*c,*d,*e;
	cout << "dia chi con tro c :" << &c << endl;
	cout << "dia chi con tro d :" << &d << endl;
	a=10;
	b=20;
	c= &a;
	d = c;


	cout << "dia chi bien a :" << &a << endl;
	cout << "dia chi bien b :" << &b << endl;

	cout << "dia chi con tro c  chua:" << c << endl;
	cout << "dia chi con tro d  chua:" << d << endl;
	
	cout << "gia trị con tro  c  chua:" << *c << endl;
	cout << "gia trị con tro  d  chua:" << *d << endl;



	cout << "dia chi con tro c :" << &c << endl;
	cout << "dia chi con tro d :" << &d << endl;

	//cout << "dia chi con tro e chua:" << &e << endl;


	system("pause");
}