//
// Created by Nhat Le on 1/15/24.
//
#include <string>
#include <vector>
using namespace std;

//class Solution {
//public:
//    string reverseWords(string s) {
//        vector<string> words;
//        int index = 0;
//        string word = "";
//        while(index < s.size()) {
//            if(s[index] == ' ') {
//                if (word.size() != 0)
//                    words.push_back(word);
//                word = "";
//                index++;
//                continue;
//            }
//            word.push_back(s[index++]);
//        }
//        if(word.size() != 0)
//            words.push_back(word);
//
//        string result = "";
//        for(int i = words.size() - 1; i >= 0; i--) {
//            result.append(words[i]);
//            if(i != 0)
//                result.push_back(' ');
//        }
//        return result;
//    }
//};
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int current = 0;
        int left = 0;
        int right = 0;
        while(right < s.size()) {
            while(right < s.size() && s[right] != ' ')
                s[current++] = s[right++];
            if(left < right) {
                reverse(s.begin() + current + left - right, s.begin() + current);
                if(right < s.size())
                    s[current++] = ' ';
                else current++;
                left = right;
            } else {
                left++;
                right++;
            }
        }
        if(current <= s.size())
            s.erase(current - 1);
        return s;
    }
};

int main() {
    Solution sol;
    sol.reverseWords(" asdasd df f");
    return 0;
}
