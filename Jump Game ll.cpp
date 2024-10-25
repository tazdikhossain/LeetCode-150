class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;

        int jump = 0;
        int start = 0;
        int end = 0;

        for(int i = 0; i<n-1; i++)
        {
            end = max(end, i+nums[i]);

            if(i == start)
            {
                jump++;
                start = end;
            }
        }

        return jump;

    }

};
