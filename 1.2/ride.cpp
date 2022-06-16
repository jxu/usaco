/*
ID: jxu
TASK: ride
LANG: C++14                 
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string l1, l2;
    int n1 = 1, n2 = 1;
    fin >> l1 >> l2;

    for (size_t i=0; i<l1.size(); i++)
        n1 *= l1[i]-'A'+1;

    for (size_t i=0; i<l2.size(); i++)
        n2 *= l2[i]-'A'+1;

   fout << ((n1 % 47 == n2 % 47) ? "GO" : "STAY") << endl;

}
