int LCS (vector <int>& a, vector <int>& b)
{
    int n = a.size (), m = b.size ();
    vector <vector <int>> dp (n + 1, vector <int> (m + 1));
    for (int i = 0; i < n + 1; i++)
        dp[i][0] = 0;
    for (int j = 0; j < m + 1; j++)
        dp[0][j] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max (dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
