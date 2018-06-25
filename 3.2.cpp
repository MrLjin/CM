#include <iostream>
#include <cmath>

using namespace std;

double last = 0.0;
double ep = 1e-6;

double f(double x) {
	return 1 / (exp(x) + pow(x, 3));
}

double T(double a, double b, int n) {
	double h = (b - a) / n;
	double s = 0.0;
	for (int k = 1; k < n; k++) {
		s += f(a + k * h);
	}
	return h / 2 * (f(a) + 2 * s + f(b));
}

void main() {
	double res;
	for (int i = 4; ; i *= 2) {
		double x = T(0, 1, i);
		printf("T<%d>=%.6lf\n", i, x);
		if (fabs(x - last) / 3 < ep) {
			res = x + (x - last) / 3;
			break;
		}
		last = x;
	}
	printf("Result=%.6lf\n", res);
	system("pause");
}