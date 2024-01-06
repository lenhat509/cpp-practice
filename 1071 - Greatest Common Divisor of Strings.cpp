#include <string>
#include <numeric>
using namespace std;
class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string answer = "";
        // Condition for the GCD to exist among the inputs
        // str1 = mGCD, str2 = nGCD
        // str1 + str2 = (m + n)GCD = str2 + str1
        if (str1 + str2 == str2 + str1)
        {
            int lengthGCD = gcd(str1.length(), str2.length());
            answer = str1.substr(0, lengthGCD);
        }
        return answer;
    }
};