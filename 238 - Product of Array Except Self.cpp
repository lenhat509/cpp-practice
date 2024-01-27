#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> result(nums.size());
        result[0] = 1;
        for (int i = 1; i < result.size(); i++)
            result[i] = result[i - 1] * nums[i - 1];
        int rightProduct = 1;
        for (int i = result.size() - 2; i >= 0; i--)
        {
            rightProduct = rightProduct * nums[i + 1];
            result[i] = result[i] * rightProduct;
        }
        return result;
    }
};