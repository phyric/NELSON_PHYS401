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
	double funx = 99999999999999;
	double derivative = 1;
	double height;
	double tangent;
	double width_error;
	xl1 = 0.2;
	xr1 = 0.6;     // first starting point
	xl2 = 1.5;
	xr2 = 1.8;		// second starting point
	max_num_runs = 10000000;
	width = 4.0E-15;


	width_error =(double) width + 1;
	x = xr1;
  
	for (count = 0; width_error > width; count++ ) {
		
		funx =(double) x*x*x - 4*x + 2;
		derivative =(double) 3*x*x - 4;
		width_error = abs(funx/derivative);
		x -= funx/derivative;

		if (count > max_num_runs) {
			xl1 = 0;
			xr1 = 0;
			cout << "error" << endl;
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The first root is " << x << endl;

	width_error =(double) width + 1;
	x = xr2;

for (count = 0; width_error > width; count++ ) {
		
		funx =(double) x*x*x - 4*x + 2;
		derivative =(double) 3*x*x - 4;
		width_error = abs(funx/derivative);
		x -= funx/derivative;

		if (count > max_num_runs) {
			xl1 = 0;
			xr1 = 0;
			cout << "error" << endl;
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The second root is " << x << endl;










	return 0;
}