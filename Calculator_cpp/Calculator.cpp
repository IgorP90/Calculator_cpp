#include "pch.h"
#include "Calculator.h"
#include <string>
#include "Decompositor.h"

std::stack<Double> stack_n;
std::stack<Char> stack_s;


String^ Calculator::Calc(String^ str)
{

	Decompositor decompositor;

	List<String^>^ decList = decompositor.GG(str);

	for (int i = 0; i < str->Length;)
	{

		if (str[i] == '(' || str[i] == ')')
		{
			if (stack_s.empty() || str[i] == '(' || stack_s.top() == ')')
			{
				stack_s.push(str[i]);
				i++;
			}
			else if (str[i] == ')')
			{
				if (stack_s.top() == '(')
				{
					stack_s.pop();
					i++;
				}
				else
				{
					Aa();
				}
			}
			else
			{
				stack_s.pop();
				i++;
			}
			OutS();
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{

			stack_n.push(str[i] - '0');
			i++;
			OutN();
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			if (stack_s.empty() || stack_s.top() == '(')
			{
				stack_s.push(str[i]);
				i++;
			}
			else
			{
				if ((str[i] == '*' || str[i] == '/') && (stack_s.top() == '+' || stack_s.top() == '-'))
				{
					stack_s.push(str[i]);
					i++;
				}
				else if ((str[i] == '*' || str[i] == '/') && (stack_s.top() == '*' || stack_s.top() == '/'))
				{
					Aa();
				}
				else if ((str[i] == '+' || str[i] == '-') && (stack_s.top() == '*' || stack_s.top() == '/')) 
				{
					Aa();
				}
				else if ((str[i] == '+' || str[i] == '-') && (stack_s.top() == '+' || stack_s.top() == '-'))
				{
					Aa();
				}

			}OutS();
		}
	}
	if (!stack_s.empty()) 
	{
		Aa();
		return stack_n.top().ToString();
	}
	else
	return stack_n.top().ToString();	
}

void Calculator::Aa()
{
	Double b = stack_n.top();
	stack_n.pop();
	Double a = stack_n.top();
	stack_n.pop();

	Char operant = stack_s.top();
	stack_s.pop();

	Double res;

	if (operant == '+')
	{
		res = a + b;
		Console::WriteLine(a +" + "+ b +" = " + res);
	}
	else if (operant == '-')
	{
		res = a - b;
		Console::WriteLine(a + " - " + b + " = " + res);
	}
	else if (operant == '*')
	{
		res = a * b;
		Console::WriteLine(a + " * " + b + " = " + res);
	}
	else if (operant == '/')
	{
		res = a / b;
		Console::WriteLine(a + " / " + b + " = " + res);
	}
	stack_n.push(res);
	OutN();
}

void Calculator::OutN()
{
	if (!stack_n.empty())
	Console::WriteLine(stack_n.top());
}
void Calculator::OutS()
{
	if (!stack_s.empty())
	Console::WriteLine(stack_s.top());
}
