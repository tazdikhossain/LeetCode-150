class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        // Sort the balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 0; // Number of arrows needed
        long arrowPosition = LONG_MIN; // Position of the last arrow
        
        for (const auto& balloon : points) {
            // If the current balloon's start is greater than the last arrow position
            if (balloon[0] > arrowPosition) {
                arrows++; // Need a new arrow
                arrowPosition = balloon[1]; // Place it at the end of the current balloon
            }
        }
        
        return arrows;
    }
};
