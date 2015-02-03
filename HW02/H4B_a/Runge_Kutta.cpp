#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>

using namespace std;

// potential energy function x^4/4

double force (double var) {						// negative derivative of the potential function
	double funx;
	funx =(double) -1*var*var*var;
	return funx;

}

double KE (double velocity) {
		double energy;
		energy =(double) 0.5*velocity*velocity;
		return energy;
}

double Potential (double x) {
	double pot;
	pot =(double) x*x*x*x/4.0;
	return pot;

}


int main() {

	int N = 1000; 				// this is the number of steps needed to be taken
	double t;					// time
	double x;					// x coordinate
	double Vx;					// x velocity
	double X[N +1];                // array for the x values
	double VX[N +1];				// array for the y velocity values
	double h;					// step size
	int count;					// counter
	double first_ode_x;			// the first order differential x function;
	double second_ode_x;			// the second order differential x function;
	
	double kx1;
	double kx2;
	double kx3;
	double kx4;
	double kv1;
	double kv2;
	double kv3;
	double kv4;

	t = 0.0;						// initial starting time
	x = 0.0;						// initial starting x point
	Vx = 10.0;						// starting velocity
	h = .01;
    X[0] = x;					// fills the values for the first number in the array
    VX[0] = Vx;


    for (count = 0; count < N; count++ ) {
    	t += h;

    	kx1 = VX[count];
    	kv1 = force(X[count]);
    	kx2 =(double) VX[count] +h/2.0*kv1;
    	kv2 =(double) force(X[count] + h/2.0*kx1);
    	kx3 =(double) VX[count] +h/2.0*kv2;
    	kv3 =(double) force(X[count] + h/2.0*kx2);
    	kx4 =(double) VX[count] +h*kv3;
    	kv4 =(double) force(X[count] + h*kx3);



   		X[count + 1] =(double) X[count] + h/6.0*(kx1 + 2*kx2 + 2*kx3 + kx4);
   		VX[count + 1] =(double) VX[count] + h/6.0*(kv1 + 2*kv2 + 2*kv3 + kv4);


   	}

   	x = X[count + 1];
   	Vx = VX[count + 1];

   	ofstream outputFile;
	outputFile.open("X_VX_phase_data.txt");
	for (count = 0; count <= N; count++) {
    	outputFile << X[count] << "\t";
    	outputFile << VX[count] << endl;	
}
    outputFile.close();

	cout << "The time that has past is " << t << " seconds with " << N << " iterations preformed. \n";
	cout << "The step size was " << h << ". \n";
	cout << "The original energy of the system was " << Potential(X[0]) + KE(VX[0]) << " joules. \n";
	cout << "The final energy of the system was " << Potential(X[N]) + KE(VX[N]) << " joules. \n";
	cout << X[N] << endl;




   
	return 0;
}