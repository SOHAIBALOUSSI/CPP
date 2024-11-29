#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int i = 0, j = 0;
        for (int x = 0; x < strs.at(0).size(); x++)
        {
            char condidate = strs[0][x];
            i = 0;
            while (i < strs.size())
            {
                if (strs[i][x] == condidate)
                    i++;
                else
                    break;
            }
            if (i == strs.size() - 1)
                res += condidate;
            else
                return "";
        }
        return res;
    }
};

// ["dog","racecar","car"]
// ["flower","flow","flight"]
int main()
{
    vector<string> strs = {"flower","flow","flight"};

    Solution s;
    cout << s.longestCommonPrefix(strs);
}