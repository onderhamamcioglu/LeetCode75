/*
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty,
and an integer n, return true if n new flowers can be planted in the flowerbed without violating
the no-adjacent-flowers rule and false otherwise.

Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false

Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
 */


#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (flowerbed.size() == 1 && flowerbed[0] == 0) {return true;}
        if (n == 0) {return true;}
        for (int i = 0; i < flowerbed.size(); i++) {
            bool leftEmpty = (i != 0 && flowerbed[i-1] == 0);
            bool rightEmpty = (i != flowerbed.size()-1 && flowerbed[i+1] == 0);
            bool currentEmpty = (flowerbed[i] == 0);

            if ( currentEmpty && (
            (i == 0 && rightEmpty) ||
            (i == flowerbed.size()-1 && leftEmpty) ||
            (leftEmpty && rightEmpty) ) ) {
                flowerbed[i] = 1;
                n--;
            }
            if (n == 0) {return true;}
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> flowerbed = {1,0,0,0,1,0,0};
    int n = 2;
    cout << s.canPlaceFlowers(flowerbed, n) << endl;
    return 0;
}
