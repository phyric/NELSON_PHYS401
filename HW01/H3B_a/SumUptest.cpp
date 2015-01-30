#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

void printarray (float arg[], int length) {
  for (int n=0; n<length; ++n)
    cout << arg[n] << ' ';
  cout << '\n';
}

int main() {
	
	double N;
	double p;
	double p_range;
	double count;
	double count2;

	p = 2;
	p_range = 7;
	N = 10;
	double SumUp[p_range];
	double SumDown[p_range];
	for (count = 0; count < p_range; count++) {
			N *= 10;
			SumUp[count] = 0;
			SumDown[count] = 0;
			for (count2 = 1; count2 <= N; count2++) {
				SumUp[count] += 1/count2;
				SumDown[count] += 1/(N + 1 - count2);
			}
			p++;
		}	
	cout << "The SumUp array gives: \n";
	printarray (SumUp, 7);
	cout << "The SumDown array gives: \n";
	printarray (SumDown, 7);

return 0;
}