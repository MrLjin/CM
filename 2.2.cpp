#include <iostream>

using namespace std;


double mex[6][5];


void main() {
	mex[0][0] = 7;
	mex[1][0] = 1.30103;
	mex[0][1] = 8;
	mex[1][1] = 1.32222;
	mex[0][2] = 4;
	mex[1][2] = 1.20451;
	mex[0][3] = 1;
	mex[1][3] = 1.03535;
	mex[0][4] = 0;
	mex[1][4] = 0.98555;

	for (int i = 2; i < 6; i++) {
		for (int j = 0; j < 6 - i; j++) {
			mex[i][j] = (mex[i - 1][j] - mex[i - 1][j + 1]) / (mex[0][j] - mex[0][j + i - 1]);
		}
	}

	double x = 3.14159;
	double res = mex[1][0] + mex[2][0] * (x - mex[0][0]) + mex[3][0] * (x - mex[0][0])*(x - mex[0][1]) + mex[4][0] * (x - mex[0][0])*(x - mex[0][1])*(x - mex[0][2]) + mex[5][0] * (x - mex[0][0])*(x - mex[0][1])*(x - mex[0][2])*(x - mex[0][3]);

	printf("x = 3.141590, y = %0.6f\n", res);
	system("pause");
}