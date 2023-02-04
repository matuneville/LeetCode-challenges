#include "iostream"
using namespace std;

double myPow(double x, int n) {
    
    double output = 1;
    bool negative = false;

    if (n < 0){
        n = abs(n);
        negative = true;
    }
    

    while(n > 0){
        if(n % 2 == 1){
            output *= x;
            n /= 2;
            x *= x;
        }
        else{
            n /= 2;
            x *= x;
        }
    }

    if (negative){
        return 1/output;
    }

    return output;
}

int main(){
    cout << myPow(2,-2147483648);
}