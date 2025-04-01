class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int size = nums.size();
        int dp[100000] = {0};

        if (size == 1)
        {
            return 0;
        }

        dp[size - 1] = 0;

        for (int i = size - 2; i >= 0; i--)
        {
            if (i + nums[i] >= size - 1)
            {
                dp[i] = 1;
                continue;
            }
            else
            {
                int maxi = 9999999;
                for (int j = 1; j <= nums[i]; j++)
                {
                    if (maxi > dp[i + j] + 1 && dp[i + j] != -1)
                    {
                        maxi = dp[i + j] + 1;
                    }
                }
                if (maxi != 9999999)
                {
                    dp[i] = maxi;
                }
                else
                {
                    dp[i] = -1;
                }
            }
        }

        return dp[0];
    }
};
