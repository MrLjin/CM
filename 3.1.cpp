#include <iostream>
#include <cmath>
using namespace std;

double ep = 1e-6;
double last = 0.0;

double f(double x) {
	return 1 / (exp(x) + pow(x, 3));
}

double simp(int a, int b, int m) {
	double h = (double) (b - a) / m;
	double s;
	double s1 = 0.0, s2 = 0.0;
	s1 = f(a + h / 2);
	for (int k = 1; k < m; k++) {
		s1 += f(a + k * h + h / 2);
		s2 += f(a + k * h);
	}
	return h / 6 * (f(a) + 4 * s1 + 2 * s2 + f(b));
}



void main() {
	
	for (int i = 2; ; i += 2) {
		double x = simp(0, 1, i);
		printf("s<%d>=%.6lf\n", i, x);
		if (fabs(last - x) <= ep)
			break;
		last = x;
	}

	system("pause");
}