#include<bits/stdc++.h>
using namespace std;

void extendedEuclid(int A, int B,int &x,int &y,int &d) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B,x,y,d);
        int temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}

int main() {
    int x,y,d;
extendedEuclid(17, 11,x,y,d);
cout << "The GCD of 17 and 11 is " << d << endl;
cout << "Coefficients x and y are "<< x <<  "and  " << y << endl;
return 0;   
}