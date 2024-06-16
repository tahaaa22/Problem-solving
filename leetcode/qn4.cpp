#include <iostream>
using namespace std;
#include <vector>
#include <string>

/*978. Longest Turbulent Subarray
Given an integer array arr, return the length of a maximum size turbulent subarray of arr.

A subarray is turbulent if the comparison sign flips between each adjacent pair of elements in the subarray.

More formally, a subarray [arr[i], arr[i + 1], ..., arr[j]] of arr is said to be turbulent if and only if:

For i <= k < j:
arr[k] > arr[k + 1] when k is odd, and
        arr[k] < arr[k + 1] when k is even.
Or, for i <= k < j:
arr[k] > arr[k + 1] when k is even, and
        arr[k] < arr[k + 1] when k is odd.
        note: equal operation is not consider however it is a breaking condition.
        */
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int leftP = 0;
        int rightP = 1;
        auto op = "";
        int sum = 1;
        while (rightP < arr.size()) {
            if (arr[rightP] < arr[rightP - 1] && op != "<") {
                sum = max(sum, rightP - leftP + 1);
                rightP += 1;
                op = "<";
            } else if (arr[rightP] > arr[rightP - 1] && op != ">") {
                sum = max(sum, rightP - leftP + 1);
                rightP += 1;
                op = ">";
            } else {

                if (arr[rightP] == arr[rightP - 1])
                {
                    leftP = rightP;
                    rightP = rightP + 1;
                }
                else
                    leftP = rightP - 1;

                op = "";
            }

        }
        return sum;
    }
};


int main() {
    Solution solution;
    vector<int> arr = {9,4,2,10,7,8,8,1,9};
    int result = solution.maxTurbulenceSize(arr);
    cout << "Result: " << result << endl;
    return 0;
}