#include "iostream"
#include "vector"
using namespace std;

int countPrimes (int n){

    if (n <= 2) return 0;       //base cases
    else if (n == 3) return 1;

    int numberOfNotPrimes = 2;
    vector<bool> primeNumbers(n, true);

    for (int i = 2; i*i < n; i++){

        if(primeNumbers[i]){ //if this number is true, its because that number is prime, as it isnt multiple of the past numbers

            for (int j = i*i; j < n; j+=i){
                if(primeNumbers[j]){ //so i dont count twice the notPrimes
                    primeNumbers[j] = false;
                    numberOfNotPrimes++;
                }
            } 
        }
    }
    return n-numberOfNotPrimes;
}

int main(){
    cout << countPrimes(13);
    return 0;
}