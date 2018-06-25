#include <iostream>
#define DEL 1e-5
using namespace std;

float f(float x) {
	return x * x*x - exp(x) - 1;
}

float fd(float x) {
	return 3 * x * x - exp(x);
}

int i = 0;

float fun(float x0) {
	printf("x0=%0.6f\n", x0);
	for (int j = 0; j < 100; j++) {
		int d = fd(x0);
		if (d == 0) {
			i = -1;
			break;
		}
		float x = x0 - (f(x0) / fd(x0));
		if (fabs(x - x0) < DEL) {
			i = 1;
			break;
		}
		x0 = x;
		printf("x<%d>=%0.6f\n", j + 1, x0);
	}
	if (i == 0)
		i = -2;
	else
		return x0;
}


void main() {

	float res = fun(3);
	printf("the root of the equation is x = %0.6f\n", res);
	system("pause");

}