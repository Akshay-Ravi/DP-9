//Time complexity - O(n^2) and O(nlogn)
//Space complexity - O(n)
//Ran sucessfully on leetcode

class Solution {
public:
    int lengthOfLIS(vector<int>& nums){
        if(nums.empty())
            return 0;
			
		//DP solution with O(n^2) time complexity
        /*int n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                    dp[i]=max(dp[i],dp[j]+1);
            }
        int m=INT_MIN;
        for(int i=0;i<n;i++)
            m=max(m,dp[i]);
        return m;*/
		
		//Binary search solution with O(nlogn) time complexity		
        vector<int>result;
        result.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>result[result.size()-1])
                result.push_back(nums[i]);
            else
            {
                //Find the next larger element after nums[i] and replace it with that 
                int pos=binarysearch(result,nums[i],0,result.size()-1);
                result[pos]=nums[i];
            }
        }
        return result.size();
    }
    int binarysearch(vector<int>result,int target,int l,int r)
    {
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(result[mid]==target)
                return mid;
            else if(result[mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return l;
    }
};