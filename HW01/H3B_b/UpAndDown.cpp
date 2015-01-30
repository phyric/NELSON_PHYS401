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
	p_range = 7;
	
	float SumUpAS [p_range];
	float SumDownAS [p_range];
	float SumUp;
	float SumDown;

	N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp += one/float(count2);
			}
			SumUpAS[count] = SumUp;
			cout << "The SumUp for p value " << p << " gives:          " << SumUpAS[p - 2] << endl << endl;
			p++;

		}	
		
    p = 2;
    N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumDown = 0.0;
			for (count2 = N; count2 >= 1; count2--) {
				SumDown += one/float(count2);
			}
			SumDownAS[count] = SumDown;
			cout << "The SumDown for p value " << p << " gives:        " << SumDownAS[p - 2] << endl << endl;
			p++;
		}	

    p = 2;

	

////////////////////////////////////////////////////

	double one = 1;
	double SumUpA [p_range];
	double SumDownA [p_range];
	double SumUp;
	double SumDown;

	double DifferenceUp [p_range];
	double DifferenceDown [p_range];

	N = 10;
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp += one/double(count2);
			}
			SumUpA[count] = SumUp;
			cout << "The SumUp double for p value " << p << " gives:          " << SumUpA[p - 2] << endl << endl;
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
			cout << "The SumDown double for p value " << p << " gives:        " << SumDownA[p - 2] << endl << endl;
			p++;
		}	

    p = 2;

	for (count = 0; count < p_range; count++) {
			
			DifferenceUp[count] = double(abs(SumUpAS[count] - SumUpA[count]));
			DifferenceDown[count] = double(abs(SumDownAS[count] - SumDownA[count]));
			cout << "The Difference SumUp for p value " << p << " gives:     " << DifferenceUp[count] << endl << endl;
			cout << "The Difference SumDown for p value " << p << " gives:     " << DifferenceDown[count] << endl << endl;
			p++;
		}	

	ofstream outputFile;
	outputFile.open("Up.txt");
	for (count = 0; count < p_range; count++) {
		outputFile << (2 + count) << "\t";						//the value for p
    	outputFile << DifferenceUp[count] << endl;
    }
    outputFile.close();

	ofstream outputFile2;
	outputFile2.open("Down.txt");
	for (count = 0; count < p_range; count++) {
		outputFile << (2 + count) << "\t";						//the value for p
    	outputFile << DifferenceDown[count] << endl;
    }
    outputFile2.close();

    ofstream outputFile3;
	outputFile3.open("UpAndDown.txt");
	for (count = 0; count < p_range; count++) {
		outputFile << (2 + count) << "\t";						//the value for p
    	outputFile << DifferenceUp[count] << endl;
    	outputFile << (2 + count) << "\t";						//the value for p
    	outputFile << DifferenceDown[count] << endl;
    }
    outputFile3.close();




return 0;
}