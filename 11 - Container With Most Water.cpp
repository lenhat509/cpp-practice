#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int max = 0;
        int front = 0;
        int back = height.size() - 1;
        while (front < back)
        {
            int waterAmount = (back - front) * min(height[front], height[back]);
            if (waterAmount > max)
                max = waterAmount;
            if (height[front] > height[back])
                back--;
            else
                front++;
        }
        return max;
    }
};