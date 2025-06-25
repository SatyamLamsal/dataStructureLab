#include <iostream>
using namespace std;

class GrandFather
{
    private:
    int Money;
    int Age;
    string Name;
    int *GFMoney = new int;
    public:
    GrandFather(){Money = 10000; Age = 55; Name = "Lamsal";}
    GrandFather(int money, int age): Money(money), Age(age){Name = "Lamsal";}
    int getMoney(){cout << "Personal Money of Grandfather called " <<endl;return Money;}
    int getAge(){cout << "Age of Grandfather called "<<endl;return Age;}   
    int getFamilyCode(){cout << "Family Code Called "<<endl;return 234983;}
    string getFamilyName(){cout << "Family Name Called "<<endl;return Name;}
    int AfterDeathOfGrandFather(){cout << "Death of Grandfather Called "<<endl;(*GFMoney)=Money; Money = 0; return (*GFMoney);}
    ~GrandFather(){delete GFMoney;}
};

class Father : private GrandFather
{
    private:
    int Money;
    int Age;
    public:
    Father(){Money = 4000; Age = 22;}
    Father(int money, int age): Money(money), Age(age){}
    Father(int money, int age, int gMoney, int gAge): Money(money), Age(age), GrandFather(gMoney, gAge){}
    int getMoney(){cout << "Personal Money of Babin "<<endl;return Money;}
    int getAge(){cout << "Age of Babin Called "<<endl;return Age;}   
    void PassOnFamilyName(){cout << "Family Name : <code> "<< getFamilyName() <<endl;}
};



int main ()
{
    return 0;
}