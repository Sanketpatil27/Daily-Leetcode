class Solution {
public:
    bool check(vector<int>& nums) {
        // we have to count the number of times we got decreasing changes
        // if decrement is 1 means its rotated & last cell should lesser than 0th cell (coz rotated)

        int dec = 0;
        int n = nums.size();
        for(int i = 1; i < n; i++)
            if(nums[i] < nums[i-1])
                dec++;

        // if its rotated then have to check with last position, to ensure its sorted 
        if(dec == 1 && nums[n-1] <= nums[0])
            return true;

        return dec == 0;
    }
};