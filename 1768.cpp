/*
You are given two strings word1 and word2.
Merge the strings by adding letters in alternating order, starting with word1.
If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
 */

#include <iostream>
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedString;
        int length = (word1.size() > word2.size()) ? word1.size() : word2.size();
        for (int i = 0; i < length; i++) {
            if (i < word1.size()) {
                mergedString += word1[i];
            }
            if (i < word2.size()) {
                mergedString += word2[i];
            }
        }
        return mergedString;
    }
};

int main() {
    Solution s;
    cout << s.mergeAlternately("rlvrpyrhcxbceffrgiy","ktqi");
    return 0;
}

