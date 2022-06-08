class Solution {
public:
    // int fun(int i,int prevInd,vector<int>& nums){
    //     if(i==nums.size()) return 0;

    //     if(prevInd==-1||nums[i]>nums[prevInd]){
    //         return max(1+fun(i+1,i,nums),fun(i+1,prevInd,nums));
    //     }
    //     return fun(i+1,prevInd,nums);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // return fun(0,-1,nums);
        int n=nums.size();
        // dp
        // vector<vector<int>> dp(n+1,vector<int> (n+1,0));
        //   for(int i=n-1;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         if(j-1==-1||nums[i]>nums[j-1]){
        //             dp[i][j]=max(1+dp[i+1][i+1],dp[i+1][j]);
        //         }else{
        //             dp[i][j]=dp[i+1][j];
        //         }
        //     }
        // }
        // return dp[0][0];

        // tabulation
        // vector<int> dp(n,1);
        // for(int i=0;i<n;i++){
        //     for(int prev=0;prev<i;prev++){
        //         if(nums[i]>nums[prev]){
        //             dp[i]=max(dp[i],1+dp[prev]);
        //         }
        //     }
        // }
        // int maxiLen=1;
        // for(auto i:dp) maxiLen=max(maxiLen,i);
        // int len=maxiLen;
        
        //printing
        // int ind=n-1;
        // vector<int> ans;
        // while(ind>=0){
        //     if(dp[ind]==len){
        //         ans.push_back(nums[ind]);
        //         len--;
        //     }
        //     ind--;
        // }
        // for(auto p:ans) cout<<p<<" ";
        
        // return maxiLen;

        //bin search
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }else{
                int low=0,high=temp.size()-1;
                while(low<=high){
                    int mid=(low+high)/2;
                    if(temp[mid]==nums[i]){
                        break;
                    }else if(temp[mid]<nums[i]){
                        low=mid+1;
                    }else{
                        high=mid-1;
                    }
                }
                if(low>high){
                    temp[low]=nums[i];
                }
            }
        }
        return temp.size();
    }
};