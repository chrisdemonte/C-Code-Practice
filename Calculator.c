#include<stdlib.h>
#include<stdio.h>

double add(double num1, double num2);
double sub(double num1, double num2);
double mult(double num1, double num2);
double divide(double num1, double num2);

int main() {
	int option = 0;
	double num1 = 0;
	double num2 = 0;
	double result = 0;
	printf("*** Simple Calculator ***\n");
	while (1) {
		printf("Enter a number:\n");
		scanf_s("%lf", &num1);
		printf("Enter an operator: \n (Operators: 1 = +, 2 = -, 3 = *, 4 = /, 0 = exit)\n");
		scanf_s("%d", &option);
		printf("Enter a number:\n");
		scanf_s("%lf", &num2);
		if (option == 1) {
			result = add(num1, num2);
		}
		else if (option == 2) {
			result = sub(num1, num2);
		}
		else if (option == 3) {
			result = mult(num1, num2);
		}
		else if (option == 4) {
			result = divide(num1, num2);
		}
		else if (option == 0) {
			break;
		}
		else {
			printf("Invalid Operator.\n");
			continue;
		}
		printf("Result = %lf \n", result);
	}
	printf("*** Exiting Calculator ***");
	return 0;
}
double add(double num1, double num2) {
	return num1 + num2;
}
double sub(double num1, double num2) {
	return num1 - num2;
}
double mult(double num1, double num2) {
	return num1 * num2;
}
double divide(double num1, double num2) {
	return num1 / num2;
}