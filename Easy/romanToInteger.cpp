#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int value(char c)
    {
        if (c == 'I')
            return 1;
        if (c == 'V')
            return 5;
        if (c == 'X')
            return 10;
        if (c == 'L')
            return 50;
        if (c == 'C')
            return 100;
        if (c == 'D')
            return 500;
        return 1000; // returns M
    }

    int romanToInt(string s)
    {
        int total = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int current = value(s[i]);
            if (i < s.length() - 1 && current < value(s[i + 1]))
            {
                total -= current;
            }
            else
            {
                total += current;
            }
        }
        return total;
    }
};

int main()
{
    cout << "Starting program..." << endl;

    Solution sol;
    int result = sol.romanToInt("MCMXCIV");

    cout << "The integer value is: " << result << endl;

    return 0;
}