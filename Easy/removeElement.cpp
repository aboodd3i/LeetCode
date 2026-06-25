#include "iostream"
#include "vector"
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
            return 0;
        int curr = 0;
        int next = 0;
        for (next; next < nums.size(); next++)
        {
            if (nums[next] != val)
            {
                nums[curr] = nums[next];
                curr++;
            }
        }
        return curr;
    }
};

int main()
{
    Solution sol;

    vector<int> nums_1 = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6};
    int val = 3;

    int k1 = sol.removeElement(nums_1, val);
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