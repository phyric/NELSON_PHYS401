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
	int tmax = 200;
	double h = 0.125;					// step size
	int N =(int) tmax/h; 				// this is the number of steps needed to be taken
	double t;					// time
	double x;					// x coordinate
	double Vx;					// x velocity
	double X[N +1];                // array for the x values
	double VX[N +1];				// array for the y velocity values
	double T[N +1];				// array for the time values

	int count;					// counter
	double first_ode_x;			// the first order differential x function;
	double second_ode_x;			// the second order differential x function;
	
	double Vhalf;
	double F0;
	double F1; 

	t = 0.0;						// initial starting time
	x = 0.0;						// initial starting x point
	Vx = 10.0;						// starting velocity
	h = .125;
    X[0] = x;					// fills the values for the first number in the array
    VX[0] = Vx;
    T[0] = t;
    F0 = force(X[0]);


    for (count = 0; count < N; count++ ) {
    	t += h;
    	T[count + 1] = t;
    	
    	Vhalf =(double) VX[count] + h/2*F0;
    	X[count + 1] = X[count] + h*Vhalf;
    	F1 = force(X[count +1]);
    	VX[count + 1] = Vhalf + h/2*F1;
    	F0 = F1;



   	}

   	x = X[count + 1];
   	Vx = VX[count + 1];

   	ofstream outputFile;
	outputFile.open("X_VX_phase_data_H4B_b.txt");
	for (count = 0; count <= N; count++) {
    	outputFile << X[count] << "\t";
    	outputFile << VX[count] << endl;	
}
    outputFile.close();

ofstream outputFile2;
	outputFile2.open("Time_Energy_data.txt");
	for (count = 0; count <= N; count++) {
    	outputFile2 << T[count] << "\t";
    	outputFile2 << Potential(X[count]) + KE(VX[count]) << endl;	
}
    outputFile2.close();



	cout << "The time that has past is " << t << " seconds with " << N << " iterations preformed. \n";
	cout << "The step size was " << h << ". \n";
	cout << "The original energy of the system was " << Potential(X[0]) + KE(VX[0]) << " joules. \n";
	cout << "The final energy of the system was " << Potential(X[N -1]) + KE(VX[N -1]) << " joules. \n";
	cout << X[N] << endl;




   
	return 0;
}