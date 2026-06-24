#include "iostream"
#include "vector"
#include "cassert"
using namespace std;

class Solution
{
public:
    int removeDublicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int unique_ptr = 0;
        int scan_ptr = 1; // first char is always unique. we start checking for more unique characters from the 2nd char

        for (scan_ptr; scan_ptr < nums.size(); scan_ptr++)
        {
            if (nums[scan_ptr] != nums[unique_ptr])
            {
                unique_ptr++;
                nums[unique_ptr] = nums[scan_ptr];
            }
        }

        return unique_ptr + 1;
    }
};

int main()
{
    Solution sol;

    vector<int> nums_1 = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6};
    vector<int> nums_2 = {0, 1, 2, 3, 4, 5, 6, 6, 7};

    int k1 = sol.removeDublicates(nums_1);
    cout << "k = " << k1 << endl;
    cout << "nums = [";
    for (int i = 0; i < nums_1.size(); i++)
    {
        cout << nums_1[i];
        if (i < nums_1.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    cout << "First " << k1 << " elements: ";
    for (int i = 0; i < k1; i++)
    {
        cout << nums_1[i] << " ";
    }

    cout << endl;

    return 0;
}