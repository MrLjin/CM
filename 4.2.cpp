#include <iostream>
#define row 4
#define col 5
using namespace std;

double eps = 1e-6;
double matrix[row][col] = {
	8,1,0,3,4,
	2,7,-1,1,1,
	3,-1,9,2,-3,
	-1,2,3,10,4
};
double result[row];
int n = 0;

void Jacobi() {
	double pre[row];
	while (1) {
		for (int i = 0; i < row; i++)
			pre[i] = result[i];
		for (int i = 0; i < row; i++) {
			result[i] = matrix[i][row];
			for (int j = 0; j < row; j++)
				if (j != i)
					result[i] -= pre[j] * matrix[i][j];
			result[i] /= matrix[i][i];
		}
		n++;
		double t = 0.0;
		for (int i = 0; i < row; i++) {
			if (fabs(result[i] - pre[i]) >= t)
				t = fabs(result[i] - pre[i]);
		}
		if (t <= eps)
			break;
	}
	printf("Die Dai Cishu wei:%d\n", n);
	for (int i = 0; i < row; i++) {
		printf("x[%d]=%.6lf\n", i, result[i]);
	}
}

void Seidel() {
	double pre[row];
	while (1) {
		for (int i = 0; i < row; i++)
			pre[i] = result[i];
		for (int i = 0; i < row; i++) {
			result[i] = matrix[i][row];
			for (int j = 0; j < row; j++)
				if (j != i)
					result[i] -= result[j] * matrix[i][j];
			result[i] /= matrix[i][i];
		}
		n++;
		double t = 0.0;
		for (int i = 0; i < row; i++) {
			if (fabs(result[i] - pre[i]) >= t)
				t = fabs(result[i] - pre[i]);
		}
		if (t <= eps)
			break;
	}
	printf("Die Dai Cishu wei:%d\n", n);
	for (int i = 0; i < row; i++) {
		printf("x[%d]=%.6lf\n", i, result[i]);
	}
}

void main() {
	cout << "Jacobi:" << endl;
	Jacobi();
	memset(result, 0, sizeof(result));
	n = 0;
	cout << "Seidel:" << endl;
	Seidel();
	system("pause");
}