#include <stdio.h>
#include <math.h>

int fac(int x);		//for factional numbers
int num_pairs(int n, int k);		//returns the possible pairs of using the formula N! / (K! * (N-K)!)
double Func1();
double Func2();
double Func3();
int Func4();

int main()
{
	int ch, r;
	do
	{
		printf("\n----MENU----\n");
		printf("[1]....Calculation the sine of an angle\n");
		printf("[2]....Calculation the cosine of the angle\n");
		printf("[3]....Raise a number to a power\n");
		printf("[4]....Pairs of elements\n");
		printf("[5]....Exit\n\n");
	
		printf("Enter your choice: ");
		r = scanf("%d", &ch);
	
		switch (ch)
		{
			case 1: Func1(); break;
			case 2: Func2(); break;
			case 3: Func3(); break;
			case 4: Func4(); break;
		} 
	}
	while (ch != 5); 
	
	return 0;
}

int factorial(int n)
{
    int i, fact = 1;
    for (i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int num_pairs(int n, int k) {
  return factorial(n) / (factorial(k) * factorial(n - k));
}

//function for calculating the sine of angle in degrees
double Func1() {
	
	double x, sine;
    int d, i, n;

    printf("Enter the angle (in degrees): ");
    scanf("%d", &d);
    
    x = d * (M_PI / 180);
    sine = 0;
    n = 7; 
    for (i = 0; i < n; i++)
    {
        sine += pow(-1, i) * pow(x, 2 * i + 1) / factorial(2 * i + 1);
    }
	printf("The sine of %d angle is %.2lf\n", d, sine);
	
    return sine;
} 

//function for calculating the cosine of angle in degrees
double Func2() {
	
	double x, cosine;
    int d, i, n;

    printf("Enter the angle (in degrees): ");
    scanf("%d", &d);

    x = d * (M_PI / 180); 
    cosine = 0;
    n = 7; 
    for (i = 0; i < n; i++)
    {
        cosine += pow(-1, i) * pow(x, 2 * i) / factorial(2 * i);
    }
    printf("The cosine of %d angle is %.2lf\n", d, cosine);

    return cosine;
}

//function for calculating the power of a number
double Func3() {
	
	int base, exponent;
	double result;
	printf("Write the base and the exponent: ");
	
	scanf("%d %d", &base, &exponent);
	result = pow(base, exponent);
	printf("%d raised the power of %d is %.2lf\n", base, exponent, result);
	
	return 0;
}

//function which gives the possible K pairs of N numbers
int Func4() {
	
	int n, k;
	printf("Give me the elements and the number of pairs: ");
	scanf("%d %d", &n, &k);
	int result = num_pairs(n, k);
	printf("There are %d pairs of %d that can be formed from %d elements.\n", result, k, n);
  
	return 0;
} 
