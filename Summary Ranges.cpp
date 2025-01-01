#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) {
            return result;
        }

        int start = nums[0]; // Initialize the start of the current range

        for (int i = 1; i <= nums.size(); ++i) {
            // Check if we've reached the end of a range
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (start == nums[i - 1]) {
                    result.push_back(to_string(start)); // Single number range
                } else {
                    result.push_back(to_string(start) + "->" + to_string(nums[i - 1])); // Range with multiple numbers
                }
                // Start a new range
                if (i < nums.size()) {
                    start = nums[i];
                }
            }
        }

        return result;
    }
};
