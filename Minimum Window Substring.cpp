#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> need, window;
        for (char c : t) need[c]++;

        int haveCount = 0; // how many chars currently match desired count
        int needCount = need.size();

        int left = 0, right = 0;
        int minLen = INT_MAX, startIdx = 0;

        while (right < s.size()) {
            char c = s[right];
            window[c]++;

            if (need.count(c) && window[c] == need[c])
                haveCount++;

            // shrink from left while valid
            while (haveCount == needCount) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                char leftChar = s[left];
                window[leftChar]--;
                if (need.count(leftChar) && window[leftChar] < need[leftChar])
                    haveCount--;

                left++;
            }

            right++;
        }

        return minLen == INT_MAX ? "" : s.substr(startIdx, minLen);
    }
};
