#include "iostream"
#include "vector"
using namespace std;

int countPrimes (int n){

    if (n <= 2)
        return 0;
    else if (n == 3)
        return 1;

    vector<bool> is_prime(n, true);
    
    int count = n - 2;
    for (int i = 2; i * i < n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                if (is_prime[j]) {
                    is_prime[j] = false;
                    count--;
                }
            }
        }
    }
    
    return count;
}

int main(){
    cout << countPrimes(13);
    return 0;
}