#include <iostream>

using namespace std;

double f(double x, double y) {
	return x * x + y * y;
}

void Runge(double a, double b, double y0, int N) {
	double x = a;
	double y = y0;
	double k1, k2, k3, k4;
	double h = (b - a) / N;
	printf("x[0]=%.6lf\ty[0]=%.6lf\n", x, y);
	for (int i = 1; i <= N; i++) {
		k1 = f(x, y);
		k2 = f(x + h / 2, y + h * k1 / 2);
		k3 = f(x + h / 2, y + h * k2 / 2);
		k4 = f(x + h, y + h * k3);
		y += h * (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x = a + i * h;
		printf("x[%d]=%.6lf\ty[%d]=%.6lf\n", i, x, i, y);
	}
}

void main() {
	Runge(0, 1, 0, 10);
	system("pause");
}