class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        string curr;
        stringstream ss(path);

        // Split the path by '/'
        while (getline(ss, curr, '/')) {
            if (curr == "" || curr == ".") {
                continue;
            } else if (curr == "..") {
                if (!stack.empty()) {
                    stack.pop_back(); // Go one directory up
                }
            } else {
                stack.push_back(curr); // Valid directory name
            }
        }

        // Construct canonical path
        string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i < stack.size() - 1) {
                result += "/";
            }
        }

        return result;
    }
};
