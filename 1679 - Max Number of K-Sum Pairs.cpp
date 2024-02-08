#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> map;
        int maxOps = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int target = k - nums[i];
            if (map.count(target))
            {
                maxOps++;
                if (map[target] == 1)
                    map.erase(target);
                else
                    map[target]--;
            }
            else
            {
                if (map.count(nums[i]))
                    map[nums[i]]++;
                else
                    map.insert({nums[i], 1});
            }
        }
        return maxOps;
    }
};