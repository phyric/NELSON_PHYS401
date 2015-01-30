#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printarray (long arg[], long length) {
  for (long n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main() {
    long array_size = 100000;
    int array [array_size]; 
    int count;
    int count2;
    int num_repeat_data_set = 1000;
    long y;
    int medianlo;
    int medianhi;
    float median;
    long bootarray [array_size];
    float median_array [num_repeat_data_set];
    double avg_median;
    double avg_median_squared;
    double sigma;

    
    unsigned seed = time(0);
    srand(seed);

    for (count2 = 0; count2 < num_repeat_data_set; count2++) {
	for (count = 0; count < array_size; count++) { 
	    y = rand() % array_size;
	    bootarray[count] = y;
	   }
    }

	
    printarray(bootarray, long(30));

    return 0;
}
