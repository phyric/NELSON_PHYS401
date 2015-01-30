#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main() {
	
	long int N;
	int p;
	int p_range;
	int count;
	long int count2;
	p = 2;
	p_range = 7;
	
	double one = 1;
	double SumUpA [p_range];
	double SumDownA [p_range];
	double DifferenceA [p_range];
	double SumUp;
	double SumDown;

	N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp += one/double(count2);
			}
			SumUpA[count] = SumUp;
			cout << "The SumUp for p value " << p << " gives:          " << SumUpA[p - 2] << endl << endl;
			p++;

		}	
		
    p = 2;
    N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumDown = 0.0;
			for (count2 = N; count2 >= 1; count2--) {
				SumDown += one/double(count2);
			}
			SumDownA[count] = SumDown;
			cout << "The SumDown for p value " << p << " gives:        " << SumDownA[p - 2] << endl << endl;
			p++;
		}	

    p = 2;

	for (count = 0; count < p_range; count++) {
			
			DifferenceA[count] = double(abs(SumUpA[count] - SumDownA[count]));
			cout << "The Difference for p value " << p << " gives:     " << DifferenceA[p - 2] << endl << endl;
			p++;
		}	
	ofstream outputFile;
	outputFile.open("double.txt");
	for (count = 0; count < p_range; count++) {
		outputFile << (2 + count) << "\t";
    	outputFile << DifferenceA[count] << endl;
    }	
    outputFile.close();
	

return 0;
}