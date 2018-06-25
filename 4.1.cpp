#include <iostream>
#include <cmath>
#define row 4
#define col 5
using namespace std;

double matrix[row][col] = { 1,1,0,3,4,
							2,1,-1,1,1,
							3,-1,-1,2,-3,
							-1,2,3,-1,4 };
double result[row];
double maxE = 0;
int maxi;
void fun(int k) {
	maxE = matrix[k][k];
	maxi = k;
	for (int i = k + 1; i < row; i++) {
		if (fabs(matrix[i][k]) >= maxE) {
			maxE = matrix[i][k];
			maxi = i;
		}
	}
}

void Gauss() {
	for (int k = 0; k < row - 1; k++) {
		fun(k);

		if (matrix[maxi][k] == 0)
			return;
		if (maxi != k) {
			double t[col];
			for (int i = 0; i < col; i++) {
				t[i] = matrix[maxi][i];
			}
			for (int i = 0; i < col; i++) {
				matrix[maxi][i] = matrix[k][i];
			}
			for (int i = 0; i < col; i++) {
				matrix[k][i] = t[i];
			}
		}
		for (int i = k + 1; i < row; i++) {
			double temp = matrix[i][k] / matrix[k][k];
			for (int j = k; j < col; j++) {
				matrix[i][j] -= temp * matrix[k][j];
			}
		}
	}
	if (matrix[row - 1][row - 1] == 0)
		return;
	result[row - 1] = matrix[row - 1][row] / matrix[row - 1][row - 1];
	for (int i = row - 2; i >= 0; i--) {
		double t = 0.0;
		for (int j = i + 1; j < row; j++) {
			t += matrix[i][j] * result[j];
		}
		result[i] = (matrix[i][row] - t) / matrix[i][i];
	}
}

void main() {
	Gauss();
	for (int i = 0; i < row; i++) {
		printf("x[%d]=%.6lf\n", i, result[i]);
	}
	system("pause");
}