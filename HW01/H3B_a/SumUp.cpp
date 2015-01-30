#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

/*void printarray (float arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}*/

int main() {
	
	long int N;
	int p;
	int p_range;
	int count;
	long int count2;
	//float countdown;
	float one = 1;
	p = 2;
	p_range = 7;
	N = 10;
	float SumUpA [p_range];
	float SumDownA [p_range];
	float DifferenceA [p_range];
	float SumUp;
	float SumDown;

	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp = 0.0;
			SumDown = 0.0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp += one/float(count2);
				//countdown = float(N) - float(count2);
				//countdown += float(1);
				//SumDown = float(1)/float(countdown);
				//SumDown += float(1)/(float(N) + float(1) - float(count2)); //This gives an inf result for 10^8
				SumDown += one/(float(N) - float(count2)+ one);
			}
			SumUpA[count] = SumUp;
			SumDownA[count] = SumDown;
			DifferenceA[count] = float(abs(SumUp - SumDown));
			cout << "The SumUp for p value " << p << " gives:          " << SumUpA[p - 2] << endl;
			cout << "The SumDown for p value " << p << " gives:        " << SumDownA[p - 2] << endl;
			cout << "The Difference for p value " << p << " gives:     " << DifferenceA[p - 2] << endl << endl;
			p++;

		}	
		
	cout << "The SumUp array gives: \n" << SumUpA[1] << endl;
	//printarray (SumUp, 7);
	cout << "The SumDown array gives: \n" << SumDownA[1] << "    this is the N: " << count2 << endl;
	//printarray (SumDown, 7);
    cout << (SumUpA[4]-SumDownA[4]) << endl;

return 0;
}