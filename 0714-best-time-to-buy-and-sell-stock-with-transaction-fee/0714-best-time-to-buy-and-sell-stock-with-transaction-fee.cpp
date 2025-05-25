class Solution {
public:
    int solve(int ind, vector<int>& prices, bool haveit, int fee, vector<vector<int>>& dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][haveit]!=INT_MIN) return dp[ind][haveit];

        int ans = INT_MIN;
        if(haveit){
            int sell = solve(ind+1, prices, false, fee, dp)+prices[ind]-fee;
            int keep = solve(ind+1, prices, true, fee, dp);
            ans = max(ans, max(sell, keep));
        }
        else{
            int buy = solve(ind+1, prices, true, fee, dp)-prices[ind];
            int notbuy = solve(ind+1, prices, false, fee, dp);
            ans = max(ans, max(buy, notbuy));
        }
        return  dp[ind][haveit] = ans;
    }
    int maxProfit(vector<int>& prices, int fee){
        int n=prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, INT_MIN));
        return solve(0, prices, false, fee, dp);
    }
};