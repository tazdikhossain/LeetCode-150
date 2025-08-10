#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) 
    {
        if (numRows == 1 || numRows >= (int)s.size())
            return s;

        vector<string> rows(min(numRows, (int)s.size()));
        int curRow = 0;
        bool goingDown = false;

        for (int i = 0; i < (int)s.size(); i++) 
        {
            rows[curRow] += s[i];
            if (curRow == 0 || curRow == numRows - 1)
                goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }

        string result = "";
        for (int i = 0; i < (int)rows.size(); i++) 
        {
            result += rows[i];
        }
        return result;
    }
};
