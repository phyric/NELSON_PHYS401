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
	float one = 1;
	p = 2;
	p_range = 8;
	
	float SumUpAS [p_range];
	float SumDownAS [p_range];
	float SumUp;
	float SumDown;
	float ln2s=(float) log (2); 

	N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp += one/float(count2);
				one *= float(-1);
			}
			SumUpAS[count] = SumUp;
			cout << "The SumUp for p value " << p << " gives:          " << SumUpAS[p - 2] << endl << endl;
			p++;

		}	
	
////////////////////////////////////////////////////

	double oned = 1;
	double SumUpA [p_range];
	double SumDownA [p_range];
	double SumUpD;
	double SumDownD;
	double ln2d=(double) log (2);
	float DifferenceUp [p_range];
	double DifferenceDown [p_range];

	N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUpD = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUpD += oned/double(count2);
				oned *= double(-1);
			}
			SumUpA[count] = SumUpD;
			cout << "The SumUp double for p value " << p << " gives:          " << SumUpA[p - 2] << endl << endl;
			p++;

		}	
		

    p = 2;

	for (count = 0; count < p_range; count++) {
			
			DifferenceUp[count] = float(abs(SumUpAS[count] - ln2s));
			DifferenceDown[count] = double(abs(SumUpA[count] - ln2d));
			cout << "The Difference SumUp single for p value " << p << " gives:     " << DifferenceUp[count] << endl << endl;
			cout << "The Difference SumUp double p value " << p << " gives:     " << DifferenceDown[count] << endl << endl;
			p++;
		}	

	ofstream outputFile;
	outputFile.open("UpSingle.txt");
	for (count = 0; count < p_range; count++) {
		outputFile << (2 + count) << "\t";						//the value for p
    	outputFile << DifferenceUp[count] << endl;
    }
    outputFile.close();

	ofstream outputFile2;
	outputFile2.open("UpDouble.txt");
	for (count = 0; count < p_range; count++) {
		outputFile2 << (2 + count) << "\t";						//the value for p
    	outputFile2 << DifferenceDown[count] << endl;
    }
    outputFile2.close();





return 0;
}