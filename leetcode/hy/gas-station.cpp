class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int totalcount = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            totalcount = totalcount + gas[i] - cost[i];
        }
        if (totalcount < 0)
        {
            return -1;
        }
        int cur = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            cur = cur + gas[i] - cost[i];
            if (cur < 0)
            {
                start = i + 1;
                cur = 0;
            }
        }
        return start;
    }
};
