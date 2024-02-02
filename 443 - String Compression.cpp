#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int count = 0;
        char current = chars[0];
        int writeIndex = 0;
        for (int i = 0; i <= chars.size(); i++)
        {
            if (i == chars.size() || current != chars[i])
            {
                chars[writeIndex++] = current;
                if (i != chars.size())
                    current = chars[i];
                if (count == 1)
                    continue;
                string countStr = to_string(count);
                for (auto c = countStr.begin(); c != countStr.end(); c++)
                    chars[writeIndex++] = *c;
                count = 1;
            }
            else
                count++;
        }
        chars.resize(writeIndex);
        return chars.size();
    }
};