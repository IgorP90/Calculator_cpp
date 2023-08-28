#include "pch.h"
#include "Calculator.h"
#include <iostream>
#include "Decompositor.h"
using namespace System::Collections::Generic;
using namespace System;

int main()
{
    Calculator cl;

    /*String^ str = "2+3*(7/2-(4*2))+9";
    String^ str_2 = "1+-2*(3+4/2-(1+2))*2+1";
    String^ str_3 = "1+2*(3+4/2-(1+2))*2+1";
    String^ str_4;*/

    cout << "input number..." << endl;
    String^ ss = Console::ReadLine();
    Decompositor dec;
    cl.Calc(ss);
}
