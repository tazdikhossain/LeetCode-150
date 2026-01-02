class Solution {
public:
    vector<string> result;
    vector<string> keypad = {
        "", "", "abc", "def", "ghi",
        "jkl", "mno", "pqrs", "tuv", "wxyz"
    };

    void backtrack(string& digits, int idx, string& curr) {
        if (idx == digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = keypad[digits[idx] - '0'];
        for (char c : letters) {
            curr.push_back(c);
            backtrack(digits, idx + 1, curr);
            curr.pop_back(); // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string curr;
        backtrack(digits, 0, curr);
        return result;
    }
};
