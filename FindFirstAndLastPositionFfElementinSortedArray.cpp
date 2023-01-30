#include "iostream"
#include "vector"
using namespace std;

typedef vector<int> arr;

int searchFirstPosition(arr& nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid = -1;

    while (low < high){
        mid = (low + high)/2;
        if (nums[mid] >= target)
            high = mid;
        else
            low = mid + 1;
        if (low == high)
            mid = low;
    }
    if (nums[mid] == target)
        return mid;
    return -1;
}

int searchLastPosition(arr& nums, int target){
    int low = 0;
    int high = nums.size()-1;
    int mid = -1;

    while (low < high){
        mid = (low + high + 1)/2;
        if (nums[mid] <= target)
            low = mid;
        else
            high = mid - 1;
        if (low == high)
            mid = high;
    }
    if (nums[mid] == target)
        return mid;
    return -1;
}

arr searchRange(arr& nums, int target) {
    if (nums.empty()) return {-1,-1};
    return {searchFirstPosition(nums, target), searchLastPosition(nums, target)};
}

int main (){
    arr test{1};
    arr answer = searchRange(test, 0);
    cout << answer[0] << answer[1]; 
    return 0;
}