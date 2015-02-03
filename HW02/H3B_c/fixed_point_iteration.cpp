#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;



/*double function (double x) {
	double funx;
	funx = x*x*x - 4*x + 2;
	return funx;

}

double Bisection (
*/

int main() {
	double x0;			//x(n-1)
	double x1;			//x(n)

	double xl1;
	double xr1;
	double width;
	long count;
	long max_num_runs;
	double funx0;		//f(x(n-1))

	double derivative;
	double height;
	double tangent;
	double width_error;

	xl1 = 1.5;		// first starting point

	max_num_runs = 100000;
	width = 4.0E-15;
	x0 = xl1;

	width_error =(double) width + 1;

  
	for (count = 0; width_error > width; count++ ) {
		
		funx0 =(double) x0*x0 - 2;
		derivative =(double) 2*x1;
		width_error = abs(funx0/derivative);
		x1 =(double) 0.5*(x0 + 2/x0);
		x0 = x1;
		if (count > max_num_runs) {
			width_error = -1000;
			cout << "error" << endl;
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The first root is " << setprecision(14) << x1 << endl;











	return 0;
}