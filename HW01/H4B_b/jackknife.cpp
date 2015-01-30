#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


int main() {
    long p = 1;
    long array_size = 1000*p;
    double array_size_minus = double(array_size) - double(1);
    double original_array; 
    long count;
    long count2;
    double sum = 0;
    double sum2 = 0;
    double sumSqr = 0;
    double inverse_number_entries;
    double one = 1;
    double N = array_size;
    double original_average;
    double jackknife_avg;
    double avg_jackknife_avg;
    double avg_jackknife_sqr;
    double sigma;
    inverse_number_entries = one/array_size_minus;
  

    ifstream inputFile;
    inputFile.open("data.txt");
    for (count = 0; count < array_size; count++){
	    inputFile >> original_array;
        sum += original_array;
    }
    inputFile.close();   
    original_average = sum/double(array_size);
    cout << original_average << endl;
    
    ifstream inputFile2;
    inputFile2.open("data.txt");
    for (count = 0; count < array_size; count++){
        inputFile2 >> original_array;
        jackknife_avg = sum - original_array;
        jackknife_avg *= inverse_number_entries;
        sum2 += jackknife_avg;
        sumSqr += jackknife_avg*jackknife_avg;
    }
    inputFile2.close();
    cout << sum2 << "\t" << sumSqr << endl;

    avg_jackknife_avg = sum2/array_size;
    avg_jackknife_sqr = sumSqr/array_size;
     cout << avg_jackknife_avg << "\t" << avg_jackknife_sqr << endl;
    
    sigma = sqrt ( abs (avg_jackknife_sqr - avg_jackknife_avg*avg_jackknife_avg));

    cout << "done   " << avg_jackknife_avg << endl;
    cout << "the sigma value for p = " << p << " is " << sigma << endl;



    return 0;
}
