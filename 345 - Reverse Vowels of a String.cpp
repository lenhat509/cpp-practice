#include <string>
#include <stack>
using namespace std;

// class Solution {
// public:
//     string reverseVowels(string s) {
//         stack<char> vowels;
//         for(int i = 0; i < s.length(); i++) {
//             if(isVowels(s[i]))
//                 vowels.push(s[i]);
//         }
//         string reverse = "";
//         for(int i = 0; i < s.length(); i++) {
//             if(isVowels(s[i])) {
//                 reverse.push_back(vowels.top());
//                 vowels.pop();
//             }
//             else reverse.push_back(s[i]);
//         }
//         return reverse;
//     }
//     bool isVowels(char c) {
//         if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
//            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
//             return true;
//         return false;
//     }
// };

class Solution
{
public:
    string reverseVowels(string s)
    {
        int start = 0;
        int end = s.size() - 1;
        while (start < end)
        {
            if (isVowels(s[start]) && isVowels(s[end]))
            {
                char temp = s[start];
                s[start] = s[end];
                s[end] = temp;
                start++;
                end--;
            }
            if (!isVowels(s[start]))
                start++;
            if (!isVowels(s[end]))
                end--;
        }
        return s;
    }
    bool isVowels(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
};