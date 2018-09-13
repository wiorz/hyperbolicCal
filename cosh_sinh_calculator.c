//ko, ivan
//Feb 06th, 2017
//input: userIn, conIn, sinN = 39, cosN = 38;
//output: watSum
//purpose: Using the given values of N, ask the user for the value of x (userIn), and do the calculations 
//base on the user choice (conIn).

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


double factorial(int n) {
	double product = 1.0;   
	int i;   
	for (i = 2; i <= n; i++) {
		product = product*i;
	}

	return (product);
}

double my_cosh(double x, int n) {
	int i;
	double tempPow = 0.0, cosSum = 0.0;

	for (i = 2; i <= n; i += 2) {
		//printf("this is product %lf at i = %d\n", factorial(i), i);
		//tempPow = pow(x, i);
		tempPow = pow(x, i)/ factorial(i);
		//printf("this is tempPow %lf\n", tempPow);
		cosSum += tempPow;
	}
	cosSum += 1;
	return (cosSum);

}

double my_sinh(double x, int n) {
	int i;
	double tempPow = 0.0, sinSum = 0.0;

	for (i = 3; i <= n; i += 2) {
		//printf("this is product %lf at i = %d\n", factorial(i), i);
		tempPow = pow(x, i) / factorial(i);
		sinSum += tempPow;
	}
	sinSum += x;
	return (sinSum);
}

int main() {
	int cosN = 38, sinN = 39;
	double x, watSum;
	char userIn = '0', conIn = 'y';

	while (conIn != 'q') {

		printf("Option Function\n");
		printf("1 sinh(x)\n");
		printf("2 cosh(x)\n");
		printf("3 sinh(2x)\n");
		printf("4 cosh(2x)\n");
		printf("\n");

		printf("Enter 1-4:");
		scanf(" %c", &userIn);

		while (userIn != '1' && userIn != '2' && userIn != '3' && userIn != '4') {
			printf("Option Function\n");
			printf("1 sinh(x)\n");
			printf("2 cosh(x)\n");
			printf("3 sinh(2x)\n");
			printf("4 cosh(2x)\n");

			printf("Enter 1-4:");
			scanf(" %c", &userIn);
		}

		if (userIn == '1') {
			printf("Enter value of x:");
			scanf("%lf", &x);

			watSum = my_sinh(x, sinN);
			printf("sinh(%.3lf) = %.5lf\n", x, watSum);
		}

		else if (userIn == '2') {
			printf("Enter value of x:");
			scanf("%lf", &x);

			watSum = my_cosh(x, cosN);
			printf("cosh(%.3lf) = %.5lf\n", x, watSum);
		}

		else if (userIn == '3') {
			printf("Enter value of x:");
			scanf("%lf", &x);

			watSum = 2 * my_sinh(x, sinN) * my_cosh(x, cosN);
			printf("sinh(%.3lf) = %.5lf\n", 2 * x, watSum);
		}

		else if (userIn == '4') {
			printf("Enter value of x:");
			scanf("%lf", &x);

			watSum = 2 * pow(my_sinh(x, sinN), 2) + 1;
			printf("cosh(%.3lf) = %.5lf\n", 2 * x, watSum);
		}

			
		printf("Do you want to continue (q to quit)?");
		scanf(" %c", &conIn);
		
	}

	return(0);
}