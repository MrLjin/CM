#include <iostream>

using namespace std;

double xr[5] = { 7,8,4,1,0 };
double yr[5] = { 1.30103,1.32222,1.20451,1.03535,0.98555 };

double fun(double x) {
	double y = 0;
	double t = 1;
	for (int k = 0; k < 5; k++) {
		t = yr[k];
		for (int i = 0; i < 5; i++) {
			if(i != k)
				t = t * ((x - xr[i]) / (xr[k] - xr[i]));
		}
		y = y + t;
	}
	return y;
}


void main() {

	double y = fun(3.14159);
	printf("x = 3.141590, y = %0.6f\n", y);
	system("pause");
	
}