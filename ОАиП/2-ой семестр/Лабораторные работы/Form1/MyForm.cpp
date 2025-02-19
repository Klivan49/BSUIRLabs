#include "MyForm.h"
#include <iostream>
#include <math.h>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Form1::MyForm form;
	Application::Run(%form);
}

double power(double x, int n)
{
	if (n == 0) return 1;
	else if (n % 2 == 0)
	{
		double halfPower = power(x, n/2);
		return halfPower * halfPower;
	}
	else return x * power(x, n - 1);
}