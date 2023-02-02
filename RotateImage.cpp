#include "iostream"
#include "vector"
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    vector<vector<int>> mTraspuesta;
    int n = matrix.size();
    for(int i = 0; i < n; i++){
        vector<int> v;
        for (int j = 0; j < n; ++j) {
            v.push_back(matrix[n-j-1][i]);
    }
    mTraspuesta.push_back(v);
    }
    matrix = mTraspuesta;
}