#include "pch.h"
#pragma once
#include <stack>
using namespace System;
using namespace std;
using namespace System::Text::RegularExpressions;


ref class Calculator
{
public:
	String^ Calculator::Calc(String^ str);

private:
	void Aa();

	void OutN();
	void OutS();
};


struct MyStruct
{
	Double number;
	Char symbol;
};

