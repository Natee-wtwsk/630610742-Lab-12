#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}

void stat(const double A[],int size,double B[])
{
    B[4] = A[0];  //set begin of Max
    B[5] = A[0];  //set begin of Min
    B[2] = 1; //set begin of Geometric Mean for multiples

    for(int i = 0;i < size;i++)
    {
        B[0] += A[i];
        B[1] += pow(A[i],2);
        B[2] *= A[i];
        B[3] += 1/A[i];
        if(A[i] > B[4]) B[4] = A[i]; //find Max -done
        if(A[i] < B[5]) B[5] = A[i]; //find Min -done
    }

    B[1] = pow((size*(B[1])-pow(B[0],2))/(pow(size,2)),0.5); //find Standard Deviation -done
    B[2] = pow(B[2],(double)1/size); //find Geometric Mean - done
    B[3] = size/B[3]; //find Harmonic Mean -done
    B[0] = B[0]/size; //find Arithmetic Mean -done
}
