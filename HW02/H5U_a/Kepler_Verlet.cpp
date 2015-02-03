#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

// potential energy function x^4/4

double R (double x, double y) {
	double r =(double) sqrt(x*x + y*y);
	return r;
}
double force (double var, double r) {						// negative derivative of the potential function
	double funx;
	funx =(double) -1*var/(r*r*r);
	return funx;

}

double KE (double xvelocity, double yvelocity) {
		double energy;
		energy =(double) 0.5*(xvelocity*xvelocity + yvelocity*yvelocity);
		return energy;
}
// seting the zero of the potential energy at r = inf so all of the potentials will be negative
double Potential (double r) {
	double pot;
	pot =(double) -1/r;
	return pot;

}



int main() {
	int tmax = 2000;
	double h = 0.0125;					// step size
	int N =(int) tmax/h; 				// this is the number of steps needed to be taken
	double t;					// time
	double x;					// x coordinate
	double y;
	double r;
	double Vx;					// x velocity
	double Vy;					
	double X[N +1];             // array for the x values
	double Y[N+1];
	double R_array[N+1];
	double VX[N +1];			// array for the y velocity values
	double VY[N+1];
	double T[N +1];				// array for the time values

	int count;					// counter
	double first_ode_x;			// the first order differential x function;
	double second_ode_x;			// the second order differential x function;
	
	double Vxhalf;
	double Vyhalf;
	double Fx0;
	double Fx1;
	double Fy0;
	double Fy1; 

	t = 0.0;						// initial starting time
	x = 10.0;						// initial starting x point
	y = 0.0;
	Vx = 0.0;						// starting velocity
	Vy = 0.1;
	h = .125;
    X[0] = x;					// fills the values for the first number in the array
    Y[0] = y;
    VX[0] = Vx;
    VY[0] = Vy;
    T[0] = t;
    r = R(X[0], Y[0]);
    R_array[0] = r;
    Fx0 = force(X[0], R_array[0]);
    Fy0 = force(Y[0], R_array[0]);


    for (count = 0; count < N; count++ ) {
    	t += h;
    	T[count + 1] = t;
    	

    	Vxhalf =(double) VX[count] + h/2.0*Fx0;
    	Vyhalf =(double) VY[count] + h/2.0*Fy0;
    	X[count + 1] = X[count] + h*Vxhalf;
    	Y[count + 1] = Y[count] + h*Vxhalf;
    	R_array[count +1] =(double) R(X[count +1], Y[count +1]);
    	Fx1 = force(X[count +1], R_array[count +1]);
    	Fy1 = force(Y[count +1], R_array[count +1]);
    	VX[count + 1] = Vxhalf + h/2*Fx1;
    	VY[count + 1] = Vyhalf + h/2*Fy1;
    	Fx0 = Fx1;
    	Fy0 = Fy1;



   	}

   	x = X[count + 1];
   	Vx = VX[count + 1];

   	ofstream outputFile;
	outputFile.open("X_Y_trajectory_data_H4B_b.txt");
	for (count = 0; count <= N; count++) {
    	outputFile << X[count] << "\t";
    	outputFile << Y[count] << endl;	
}
    outputFile.close();

ofstream outputFile2;
	outputFile2.open("Time_Energy_data.txt");
	for (count = 0; count <= N; count++) {
    	outputFile2 << T[count] << "\t";
    	outputFile2 << Potential(R_array[count]) + KE(VX[count], VY[count]) << endl;	
}
    outputFile2.close();



	cout << "The time that has past is " << t << " seconds with " << N << " iterations preformed. \n";
	cout << "The step size was " << h << ". \n";
	cout << "The original energy of the system was " << Potential(R_array[0]) + KE(VX[0], VY[0]) << " joules. \n";
	cout << "The final energy of the system was " << Potential(R_array[N]) + KE(VX[N], VY[N]) << " joules. \n";
	cout << X[N] << endl;




   
	return 0;
}
