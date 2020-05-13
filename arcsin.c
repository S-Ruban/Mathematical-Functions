#include <stdio.h>
#include <math.h>
int fact(int n);
double arcsin(double x);
double d1(double x);
double d2(double x);
double d3(double x);
double d4(double x);
double d5(double x);
double d6(double x);
double d7(double x);
double d8(double x);
int main()
{
	double x ;
	printf("Enter the value of x : ");
	scanf("%Lf", &x);
	printf("\n");
	printf("Actual value of arcsin(x) : %0.16Lf\n", asin(x));
	printf("Calculated value of arcsin(x) : %0.16Lf\n", arcsin(x));
	printf("Absolute error : %0.16Lf\n", asin(x)-arcsin(x));
	printf("Relative error(%c) : %0.6f%c", 37, 100.0*(1-(arcsin(x)/asin(x))), 37);
}
int fact(int n)
{
	if(n == 0)
		return 1 ;
	else
		return (n*fact(n-1));
}
double d1(double x)
{
	return (1/sqrt(1-x*x));
}
double d2(double x)
{
	return ((x)/sqrt(pow(1-x*x, 3)));
}
double d3(double x)
{
	return ((2*x*x+1)/sqrt(pow(1-x*x, 5)));
}
double d4(double x)
{
	return ((6*pow(x, 3)+9*x)/sqrt(pow(1-x*x, 7)));
}
double d5(double x)
{
	return ((24*pow(x, 4)+72*x*x+9)/sqrt(pow(1-x*x, 9)));
}
double d6(double x)
{
	return ((120*pow(x, 5)+600*pow(x, 3)+225*x)/sqrt(pow(1-x*x, 11)));
}
double d7(double x)
{
	return ((720*pow(x, 6)+5040*pow(x, 4)+4050*x*x+225)/sqrt(pow(1-x*x, 13)));
}
double d8(double x)
{
	return ((5040*pow(x, 7)+52920*pow(x, 5)+66150*pow(x, 3)+11025*x)/sqrt(pow(1-x*x, 15)));
}
double arcsin(double x)
{
	if(x == 0.0)
		return 0 ;
	if(x == 1.0)
		return M_PI_2 ;
	if(x == 0.5)
		return M_PI / 6.0 ;
	if(x == sqrt(0.5))
		return M_PI_4 ;
	if(x == sqrt(0.75))
		return M_PI / 3.0 ;
	if(x < 0)
		return (-1.0*arcsin((-1.0)*x));
	double res ;
	int i ;
	if((x > 0.0) && (x < 0.5))
		res = arcsin(0.0) + x*d1(0.0) + x*x*d2(0.0)/fact(2) + pow(x, 3)*d3(0.0)/fact(3) + pow(x, 4)*d4(0.0)/fact(4) + pow(x, 5)*d5(0.0)/fact(5) + pow(x, 6)*d6(0.0)/fact(6) + pow(x, 7)*d7(0.0)/fact(7) + pow(x, 8)*d8(0.0)/fact(8);
	if((x > 0.5) && (x < sqrt(0.5)))
		res = arcsin(0.5) + (x-0.5)*d1(0.05) + (x-0.5)*(x-0.5)*d2(0.5)/fact(2) + pow(x-0.5, 3)*d3(0.5)/fact(3) + pow(x-0.5, 4)*d4(0.5)/fact(4) + pow(x-0.5, 5)*d5(0.5)/fact(5) + pow(x-0.5, 6)*d6(0.5)/fact(6) + pow(x-0.5, 7)*d7(0.5)/fact(7) + pow(x-0.5, 8)*d8(0.5)/fact(8);
	if((x > sqrt(0.5)) && (x < sqrt(0.75)))
		res = arcsin(sqrt(0.5)) + (x-sqrt(0.5))*d1(sqrt(0.5)) + (x-sqrt(0.5))*(x-sqrt(0.5))*d2(sqrt(0.5))/fact(2) + pow(x-sqrt(0.5), 3)*d3(sqrt(0.5))/fact(3) + pow(x-sqrt(0.5), 4)*d4(sqrt(0.5))/fact(4) + pow(x-sqrt(0.5), 5)*d5(sqrt(0.5))/fact(5) + pow(x-sqrt(0.5), 6)*d6(sqrt(0.5))/fact(6) + pow(x-sqrt(0.5), 7)*d7(sqrt(0.5))/fact(7) + pow(x-sqrt(0.5), 8)*d8(sqrt(0.5))/fact(8);
	if((x > sqrt(0.75)) && (x < 1.0))
		res = arcsin(sqrt(0.75)) + (x-sqrt(0.75))*d1(sqrt(0.75)) + (x-sqrt(0.75))*(x-sqrt(0.75))*d2(sqrt(0.75))/fact(2) + pow(x-sqrt(0.75), 3)*d3(sqrt(0.75))/fact(3) + pow(x-sqrt(0.75), 4)*d4(sqrt(0.75))/fact(4) + pow(x-sqrt(0.75), 5)*d5(sqrt(0.75))/fact(5) + pow(x-sqrt(0.75), 6)*d6(sqrt(0.75))/fact(6) + pow(x-sqrt(0.75), 7)*d7(sqrt(0.75))/fact(7) + pow(x-sqrt(0.75), 8)*d8(sqrt(0.75))/fact(8);
	return res ;
}
