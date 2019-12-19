#include <iostream>
#include <string> 
#include <vector>

using namespace std;
 
class Account {
public:
    int accNo; //data member (bien instance)
    string name; //data member(bien instance)
    static float rateOfInterest;
	static int Dem;

    Account(int accNo, string name) {
        this->accNo = accNo;
        this->name = name;
		Dem++;
    }
    void display() {
        cout << accNo << " " << name << " " << " lai xuat "<<rateOfInterest << endl;   
    }
};
 
float Account::rateOfInterest = 6.8f;
int Account::Dem = 0;
int main(void)
{
	
	vector <Account> KS; 
    Account a1 = Account(201, "Phan Van Vinh"); //tao doi tuong Account
    Account a2 = Account(202, "Dao Van Hoa"); //tao doi tuong Account
	KS.push_back(a1);
	KS.push_back(a2);
	for (int i = 0; i < KS.size(); i++)
	{
		KS[i].display();
	}

	cout << "\n Doi tuong duoc tao : " << Account::Dem <<endl;


	system("pause");
    return 0;
}