#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	int N = 1000; 				// this is the number of steps needed to be taken
	double t;					// time
	double x;					// x coordinate
	double y;					// y coordinate			
	double Vx;					// x velocity
	double Vy;					// y velocity
	double V0;					// initial velocity
	double Vy0; 				// initial y velocity
	double X[N + 1];                // array for the x values
	double Y[N + 1]; 				// array for the y values
	double VX[N + 1];				// array for the y velocity values
	double VY[N + 1];				// array for the x velocity values (not necessary for this function)
	double h;					// step size
	int count;					// counter
	double first_ode_x;			// the first order differential x function;
	double second_ode_x;			// the second order differential x function;
	double first_ode_y;			// the first order differential y function;
	double second_ode_y;			// the second order differential y function;
	double pi = 3.14159265359;
	// the original equation was given as a double differntail equation

	double alpha;				// initial starting angle of launch
	double g = 1;

	t = 0.0;						// initial starting time
	x = 0.0;						// initial starting x point
	y = 1.0;						// initial starting y point
	alpha =(double) 0.0;
	V0 = 1;
	Vx = V0*cos(alpha);				// initial x velocity
	Vy = V0*sin(alpha);				// initial y velocity
	h = .01;
    X[0] = x;					// fills the values for the first number in the array
    Y[0] = y;					// fills the values for the first number in the array
    VX[0] = Vx;
    VY[0] = Vy;


    for (count = 0; y >= 0; count++ ) {
    	t += h;
   		X[count + 1] = X[count] + h*Vx;
   		Y[count + 1] = Y[count] + h*VY[count];
   		VY[count + 1] = VY[count] - h*(g);
   		y = Y[count + 1];
   		x = X[count + 1];




   		if ( count >= N ) {
   			cout << "ERROR y= " << y << " Allocate more memory to preform this function \n";
   			y = -1;
   		}
   	}

   	ofstream outputFile;
	outputFile.open("part_b_trajectory.txt");
	for (count = 0; count <= t/h + 1; count++) {
    	outputFile << X[count] << "\t";
    	outputFile << Y[count] << endl;	
}
    outputFile.close();

	cout << "The time that has past is " << t << " seconds with " << t/h << " iterations preformed. \n";



    return 0;
}