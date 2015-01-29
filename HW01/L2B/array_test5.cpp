#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printarray (int arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main() {
    int array_size = 10000;
    int array [array_size]; 
    int count;
    int count2;
    int num_repeat_data_set = 1000;
    int y;
    int medianlo;
    int medianhi;
    float median;
    int bootarray [array_size];
    float median_array [num_repeat_data_set];
    double avg_median;
    double avg_median_squared;
    double sigma;

    ifstream inputFile;
    inputFile.open("data.txt");
    for (count = 0; count < array_size; count++)
	inputFile >> array[count];

    unsigned seed = time(0);
    srand(seed);

    for (count2 = 0; count2 < num_repeat_data_set; count2++) {
	for (count = 0; count < array_size; count++) { 
	    y = rand() % array_size;
	    bootarray[count] = array[y];
	}
	sort(bootarray, bootarray + array_size);
	medianlo = bootarray[array_size/2];
        medianhi = bootarray[array_size/2 + 1];
        median = (medianlo + medianhi)/2;
	median_array[count2] = median;
    }

    for (count2 = 0; count2 < num_repeat_data_set; count2++) {
	avg_median += median_array[count2];
	avg_median_squared += median_array[count2]*median_array[count2]; 
    }

    avg_median /= num_repeat_data_set;
    avg_median_squared /= num_repeat_data_set;
    sigma = sqrt(avg_median_squared - avg_median*avg_median);

    sort(array, array + array_size);
    medianlo = array[array_size/2];
    medianhi = array[array_size/2 + 1];
    median = (medianlo + medianhi)/2;

    cout << "The median of the original data set is " << median << "." << endl;
    cout << "The average median using the bootstrap method was found to be " << avg_median << "." << endl;
    cout << "The sigma error value using the bootstrap method was found to be " << sigma << "." << endl;

    return 0;
}
