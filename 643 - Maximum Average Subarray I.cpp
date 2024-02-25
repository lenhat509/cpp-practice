#include <vector>
#include <limits>
using namespace std;

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int sum = nums[0];
        double maxAverage = numeric_limits<double>().lowest();
        int left = 0;
        int right = 0;
        while (right < nums.size())
        {
            if (right - left + 1 < k)
            {
                right++;
                if (right < nums.size())
                    sum += nums[right];
                continue;
            }
            // length == k;
            double currentAverage = (double)sum / k;
            maxAverage = max(currentAverage, maxAverage);
            left++;
            right++;
            if (right < nums.size())
                sum += nums[right];
            sum -= nums[left - 1];
        }
        return maxAverage;
    }
};