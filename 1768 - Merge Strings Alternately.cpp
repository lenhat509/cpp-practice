#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int i = 0;
        string mergedString = "";
        while (i < word1.length() || i < word2.length())
        {
            if (i < word1.length())
                mergedString += word1[i];
            if (i < word2.length())
                mergedString += word2[i];
            i++;
        }
        return mergedString;
    }
};