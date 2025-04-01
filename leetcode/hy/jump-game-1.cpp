class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int size = nums.size();
        int dp[10001] = {0};
        dp[size - 1] = 0;
        if (size == 1)
        {
            return true;
        }
        for (int i = size - 2; i >= 0; i--)
        {
            dp[i] = false;
            if (nums[i] + i >= size - 1)
            {
                dp[i] = 1;
                continue;
            }
            for (int j = 1; j <= nums[i]; j++)
            {
                if (dp[i + j] == true)
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
