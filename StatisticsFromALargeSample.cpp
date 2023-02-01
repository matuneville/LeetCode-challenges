#include "iostream"
#include "vector"
using namespace std;

typedef vector<double> arr;

vector<double> sampleStats(vector<int>& count) {
    double  minimum = -1,
            maximum = 0,
            mean = 0,
            median = 0,
            mode = 0;
    
    double  mostAppear = 0,
            mostAppearNum = 0;
    
    long  totalSum = 0;
    long  totalElements = 0;

    for (int i = 0; i < count.size(); i++){
        if (count[i] != 0){

            if (minimum == -1)
                minimum = i;

            maximum = i;

            totalSum += long (count[i]) * i;

            totalElements += count[i];

            if (count[i] > mostAppear){
                mostAppear = count[i];
                mostAppearNum = i;
            }
        }
    }

    mode = mostAppearNum;
    mean = totalSum / (double) totalElements;

    int i = 0, tempSum = 0;
    bool divideBy2 = false;
    for (int i = 0; i < count.size(); i++){
        if (count[i] != 0){
            tempSum += count[i];
            if (totalElements % 2 == 1 && tempSum >= (totalElements / 2)+1){
                median = i;
                break;
            }
            else if(totalElements % 2 == 0 && tempSum >= totalElements / 2){
                if (tempSum > totalElements / 2){
                    median += i;
                    break;
                }
                else if(tempSum == totalElements / 2){
                    median = i;
                    divideBy2 = true;
                }
            }
        }
    }

    if (divideBy2)
        median *= 0.5;
    
    return {minimum, maximum, mean, median, mode};
}


int main(){
    vector<int> v {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    arr b = sampleStats(v);
    cout <<b[0]<< endl;
    cout << b[1]<< endl;
    cout << b[2]<< endl;
    cout << b[3]<< endl;
    cout << b[4]<< endl;

    return 0;
}