#include <iostream>
#define esp 1e-6
using namespace std;

double f(double x, double y) {
	return x * x + y * y;
}

void T(int i, double last_x, double last_u, double h) {
	printf("x[%d]=%.6lf\ty[%d]=%.6lf\n", i, last_x, i, last_u);
	double x = last_x + h;
	double u = last_u + h * f(last_x,last_u);
	for (int i = 0; ; i++) {
		double temp = u;
		u = last_u + h / 2 * (f(last_x, last_u) + f(x, temp));
		if (u - temp <= esp)
			break;
	}
	//last_u + h / 2 * (f(last_x, last_u) + f(x, u));
	if (x > 1)
		return;
	if (u - last_u <= esp) {
		printf("x[%d]=%.6lf\ty[%d]=%.6lf\n", i, x, i, u);
		return;
	}
	T(i + 1, x, u, h);
}

void main() {
	T(0, 0, 0, 0.1);
	system("pause");
}