#include <iostream>
#include "Calculator.h"
using namespace std;


int main ()
{
    string exp = "3+5*2-(8/4)+1+9";
    Calculator Calc(exp);
    Calc.Calculate();
    Calc.displayResult();
    return 0;
}