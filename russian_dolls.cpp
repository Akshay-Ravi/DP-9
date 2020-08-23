//Time complexity - O(n^2)
//Space complexity - O(n)
//Ran sucessfully on leetcode

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(),envelopes.end());
        int n=envelopes.size();
        int ans=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]>envelopes[j][0]&&envelopes[i][1]>envelopes[j][1])
                    dp[i]=max(dp[i],1+dp[j]);
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};