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
	double x2;			//x(n+1)
	double xl1;
	double xr1;
	double width;
	long count;
	long max_num_runs;
	double funx0;		//f(x(n-1))
	double funx1;		//f(x(n))
	double derivative;
	double height;
	double tangent;
	double width_error;

	xl1 = 1.3;		// first starting left point
	xr1 = 1.5;     	// first starting right point
	max_num_runs = 100000;
	width = 4.0E-15;
	x0 = xl1;
	x1 = xr1;
	width_error =(double) width + 1;

  
	for (count = 0; width_error > width; count++ ) {
		
		funx0 =(double) x0*x0 - 2;
		funx1 =(double)	x1*x1 - 2;
		derivative =(double) 2*x1;
		width_error = abs(funx1/derivative);
		x2 = x1 - (funx1*(x1 - x0))/(funx1 - funx0);
		x0 = x1;
		x1 = x2;
		if (count > max_num_runs) {
			width_error = -1000;
			cout << "error" << endl;
		}
	}
	cout << "The following algorithm found the first root within " << width << " in " << count << " iterations. \n";
	cout << "The first root is " << setprecision(14) << x2 << endl;











	return 0;
}