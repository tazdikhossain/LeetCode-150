class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1;
        stack<int> stk;
        int n = s.length();
        int i = 0;
        
        while (i < n) {
            char ch = s[i];
            
            if (isdigit(ch)) {
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                result += sign * num;
                continue; 
            } else if (ch == '+') {
                sign = 1;
            } else if (ch == '-') {
                sign = -1;
            } else if (ch == '(') {

                stk.push(result);
                stk.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                int prevSign = stk.top(); stk.pop();
                int prevResult = stk.top(); stk.pop();
                result = prevResult + prevSign * result;
            }
            i++;
        }
        
        return result;
    }
};
