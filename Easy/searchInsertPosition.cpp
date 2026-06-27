#include "iostream"
#include "vector"
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left; // the left pointer points to where the number "should" be placed because it now points at the position that is exactly at the positon greater than the target number
    }
};

int main()
{
    vector<int> nums = {1, 2, 4, 5, 7, 9, 11, 13};
    int target = 6;
    Solution sol;
    int result = sol.searchInsert(nums, target);
    if (nums[result] == target)
    {
        cout << "Target found. at index: " << result << endl;
    }
    else
    {
        cout << "Target not found. Target should be at index: " << result << endl;
    }
}