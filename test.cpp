#include <iostream>
using namespace std;

double pi=3.14159;

double* getPointerToPi(double pi)
{
    double* ptr=& pi;
    return ptr;
}
int main()
{


  cout<< *getPointerToPi(pi);
}
