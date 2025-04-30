/*
Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:

Input: s = "IceCreAm"

Output: "AceCreIm"

Explanation:

The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".


Example 2:

Input: s = "leetcode"

Output: "leotcede"


Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
*/

#include <iostream>
using namespace std;

class Solution {
    bool isVowel(char c) {
        string vowels = "aeiouAEIOU";
        for (char vowel : vowels) {
            if (vowel == c){return true;}
        }
        return false;
    }
public:
    string reverseVowels(string s) { // Possible to implement with a lower time complexity
        string vowelsInside;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                vowelsInside.insert(vowelsInside.begin(),s[i]);
            }
        }
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isVowel(s[i])) {
                s[i] = vowelsInside[j];
                j++;
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    cout << s.reverseVowels("leetcode");
}