#include <stdio.h>
#include <math.h>
double arcsin(double x);
int main()
{
	double x ;
	printf("Enter the value of x : ");
	scanf("%lf", &x);
	printf("\n");
	printf("Actual value of arcsin(x) : %0.16lf\n", asin(x));
	printf("Calculated value of arcsin(x) : %0.16lf\n", arcsin(x));
	printf("Absolute error : %0.16lf\n", asin(x)-arcsin(x));
	printf("Relative error(%c) : %0.6f%c", 37, 100.0*(1-(arcsin(x)/asin(x))), 37);
}
double d0(double x)
{
	return arcsin(x);
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
static double (*derivatives[])(double) = {d0, d1, d2, d3, d4, d5, d6, d7, d8};
static int const n_derivatives = 9;
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
	if(x > 1.0)
		return -2;

	double x0 = 0;
	if(x > sqrt(0.75))
		x0 = sqrt(0.75);
	else if(x > sqrt(0.5))
		x0 = sqrt(0.5);
	else if(x > 0.5)
		x0 = 0.5;
	else
		x0 = 0.0;

	double res = 0;
	double factorial = 1;	
	for(int i = 0; i < n_derivatives;) {
		res += pow(x-x0, i) * (derivatives[i])(x0) / factorial;
		factorial *= ++i;
	}
	return res ;
}
