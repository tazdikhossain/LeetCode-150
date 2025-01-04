class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        bool inserted = false;
        
        for (const auto& interval : intervals) {
            // No overlap, current interval ends before newInterval starts
            if (interval[1] < newInterval[0]) {
                result.push_back(interval);
            }
            // No overlap, current interval starts after newInterval ends
            else if (interval[0] > newInterval[1]) {
                // If newInterval hasn't been inserted yet, insert it now
                if (!inserted) {
                    result.push_back(newInterval);
                    inserted = true;
                }
                result.push_back(interval);
            }
            // Overlap, merge intervals
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }
        
        // If newInterval hasn't been inserted, insert it at the end
        if (!inserted) {
            result.push_back(newInterval);
        }
        
        return result;
    }
};
