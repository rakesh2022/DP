/*
    link: https://practice.geeksforgeeks.org/problems/longest-alternating-subsequence5951/1

    sol: from above link's sol only
*/

// ----------------------------------------------------------------------------------------------------------------------- //
// O(N^2)
int AlternatingaMaxLength(vector<int> &nums)
{
    int n = nums.size();
    int ans = 1;
    int t[n][2];
    t[0][0] = 1;
    t[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        t[i][0] = 1;
        t[i][1] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && t[i][0] < t[j][1] + 1)
                t[i][0] = t[j][1] + 1;
            else if (nums[i] < nums[j] && t[i][1] < t[j][0] + 1)
                t[i][1] = t[j][0] + 1;
        }
        ans = max({ans, t[i][0], t[i][1]});
    }
    return ans;
}

// ----------------------------------------------------------------------------------------------------------------------- //

// most optimized sol.
// TC: O(N);
int AlternatingaMaxLength(vector<int> &nums)
{
    if (nums.size() < 2)
        return nums.size();
    int up = 1, down = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > nums[i - 1])
            // before this element what was the highest down + 1;
            up = down + 1;
        else if (nums[i] < nums[i - 1])
            // before this element what was the highest up + 1;
            down = up + 1;
    }
    return max(up, down);
}

// ----------------------------------------------------------------------------------------------------------------------- //