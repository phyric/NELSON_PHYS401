#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



/*double function (double x) {
	double funx;
	funx = x*x*x - 4*x + 2;
	return funx;

}

double Bisection (
*/

int main() {
	double x;
	double xl1;
	double xl2;
	double xr1;
	double xr2;
	double width;
	long count;
	long max_num_runs;
	double funx;
	double funxl1;
	double funxr1;
	xl1 = 0.2;
	xr1 = 0.6;
	xl2 = 1.5;
	xr2 = 1.8;
	max_num_runs = 10000000;
	width = 0.00004;

	for (count = 0; (xr1-xl1) > width; count++ ) {
		x =(double) (xl1 + xr1)/2;
		funx =(double) x*x*x - 4*x + 2;
		funxl1 =(double) xl1*xl1*xl1 - 4*xl1 + 2;
		funxr1 =(double) xr1*xr1*xr1 - 4*xr1 + 2;
		if (funxl1*funxr1 > 0){
			xl1 = 0;
			xr1 = 0;
			cout << "Braketing error" << endl;
		}
		else {
			if ( funxl1*funx < 0 ) {
				xr1 = x;
			}
			else {
				xl1 = x;
			}
			if (count > max_num_runs) {
				xl1 = 0;
				xr1 = 0;
				cout << "error" << endl;
			}
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The left and right brackets for the first root are [ " << xl1 << " , " << xr1 << " ] " << endl;

	xl1 = xl2;
	xr1 = xr2;

	for (count = 0; (xr1-xl1) > width; count++ ) {
		x =(double) (xl1 + xr1)/2;
		funx =(double) x*x*x - 4*x + 2;
		funxl1 =(double) xl1*xl1*xl1 - 4*xl1 + 2;
		funxr1 =(double) xr1*xr1*xr1 - 4*xr1 + 2;
		if (funxl1*funxr1 > 0){
			xl1 = 0;
			xr1 = 0;
			cout << "Braketing error" << endl;
		}
		else {
			if ( funxl1*funx < 0 ) {
				xr1 = x;
			}
			else {
				xl1 = x;
			}
			if (count > max_num_runs) {
				xl1 = 0;
				xr1 = 0;
				cout << "error" << endl;
			}
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The left and right brackets for the second root are [ " << xl1 << " , " << xr1 << " ] " << endl;
	











	return 0;
}