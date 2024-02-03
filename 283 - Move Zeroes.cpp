#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    // void moveZeroes(vector<int>& nums) {
    //     int first = 0;
    //     int second = 0;
    //     while(true) {
    //         while(first < nums.size() && nums[first] != 0)
    //             first++;
    //         if(first >= nums.size())
    //             return;
    //         if(second < first)
    //             second = first + 1;
    //         while(second < nums.size() && nums[second] == 0)
    //             second++;
    //         if(second >= nums.size())
    //             return;
    //         // swap elements at first and second
    //         int temp = nums[first];
    //         nums[first] = nums[second];
    //         nums[second] = temp;
    //     }
    // }
    void moveZeroes(vector<int> &nums)
    {
        int firstZero = 0;
        for (int firstNonZero = 0; firstNonZero < nums.size(); firstNonZero++)
        {
            if (nums[firstNonZero] != 0)
                swap(nums[firstNonZero], nums[firstZero++]);
        }
    }
};