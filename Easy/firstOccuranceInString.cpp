#include "iostream"
#include "string"
using namespace std;

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty() || haystack.empty())
            return 0;

        int n = haystack.length();
        int m = needle.length();

        for (int i = 0; i <= n - m; i++)
        {
            bool found = true;
            for (int j = 0; j < m; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
                return i;
        }
        return -1;
    }
};

int main()
{
    Solution sol;
    string haystack = "racecar";
    string needle = "car";

    int pos = sol.strStr(haystack, needle);
    if (pos > 0)
    {
        cout << "String found starting at position: " << pos << endl;
    }
    else if (pos == 0)
    {
        cout << "String Empty." << endl;
    }
    else
    {
        cout << "String not found :(" << endl;
    }
}