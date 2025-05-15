/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product
of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.


Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]


Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int products[nums.size()];
        int lefts[nums.size()];
        int rights[nums.size()];
        lefts[0] = 1;
        rights[nums.size() - 1] = 1;
        for(int i = 1; i < nums.size(); i++){
            lefts[i] = lefts[i - 1] * nums[i - 1];
        }

        for(int i = nums.size() - 2; i >= 0; i--){
            rights[i] = rights[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); i++) {
            products[i] = lefts[i] * rights[i];
        }

        return vector<int>(products, products + nums.size());
    }
};


int main() {
    Solution s;
    vector<int> nums = {1,2,3,4};
    vector<int> res = s.productExceptSelf(nums);
    for (int re : res) {
        cout << re << " ";
    }
    return 0;
}