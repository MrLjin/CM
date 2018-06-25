#include <iostream>
#include <cmath>
#define DEL 1e-5
using namespace std;

float f(float x) {
	return x * exp(x) - x * x - 1;
}

float fun(float a, float b) {
	cout << "the number\t\t" << "c\t\t\t" << "f<c>" << endl;
	float x, e;
	for (int i = 0; i < 100; i++) {

		x = (a + b) / 2;
		printf("%d\t\t\t%0.6f\t\t%0.6f\n", i + 1, x, f(x));
		if (fabs(f(x)) <= DEL)
			break;
		if (f(a) * f(x) < 0)
			b = x;
		else
			a = x;

	}
	return x;
}


void main() {


	float res = fun(0, 1);

	cout << "the root of the equation is " << res << endl;

	system("pause");


}























