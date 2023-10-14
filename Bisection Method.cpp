//Bisection Method
#include<bits/stdc++.h>
using namespace std;
#define EPSILON 0.0001

double func(double x)
{
	return x*x*x - 2*x*x + 3*x+4;
}

void bisection(double a, double b)
{
	if (func(a) * func(b) >= 0)
	{
		cout << "You have not assumed right a and b\n";
		return;
	}

	double c = a;
	while ((b-a) >= EPSILON)
	{
		c = (a+b)/2;

		if (func(c) == 0.0)
			break;

		else if (func(c)*func(a) < 0)
			b = c;
		else
			a = c;
	}
	cout << "The value of root is : " << c;
}

int main()
{
	double a =-200, b = 300;
	bisection(a, b);
	return 0;
}
