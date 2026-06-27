#include "iostream"
#include "string"
using namespace std;

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int index = s.length() - 1;
        int count = 0;
        while (index >= 0 && s[index] == ' ') // this helps get rid of any trailing spaces
        {
            index--;
        }
        while (index >= 0 && s[index] != ' ')
        { // also manages scenerios where s is a single word
            count++;
            index--;
        }
        return count;
    }
};

int main()
{
    string s = "text";
    Solution sol;
    int result = sol.lengthOfLastWord(s);
    cout << "The length of the last word is: " << result << " characters." << endl;

    return 0;
}