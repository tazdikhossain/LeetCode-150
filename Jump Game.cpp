class Solution {
public:
    bool canJump(vector<int>& nums) {
        int highest = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(i>highest)
            {
                return false;
            }

            highest = max(highest, i+ nums[i]);

            if(highest >= nums.size()-1)
            {
                return true;
            }

        }
    return false;

    }
};
