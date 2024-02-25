#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int sum = nums[0];
        int left = 0;
        int right = 0;
        int minLength = 0;
        while (right < nums.size())
        {
            if (sum < target)
            {
                right++;
                if (right < nums.size())
                    sum += nums[right];
                continue;
            }
            // sum >= target
            // within this subarray, is there a shorter target array?
            // dropping front elements to until sum < target
            while (sum >= target)
            {
                int length = right - left + 1;
                minLength = minLength == 0 ? length : min(minLength, length);
                sum -= nums[left++];
            }
        }
        return minLength;
    }
};