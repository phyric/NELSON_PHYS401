#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{

    string str[10000];
    ifstream myfile("data.txt");
    int a = 0;

    if(!myfile) //Always test the file open.
    {
                cout<<"Error opening output file"<<endl;
                
                return -1;
    }
    while(!myfile.eof())
    {
      getline(myfile,str[a]);
      if(a ==29)
      {
           a=0;
          
           getline(myfile,str[a]);
      }
      a++;
    }
   cout << "str" << endl << str << endl;   
}
