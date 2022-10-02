
class Solution {
public:
    long long mod = 1000000007 ;
    // Recursion
    // long long solve(int dice,int faces,int target){
    //     // base case 
    //     if(target < 0)
    //         return 0 ;
    //     if(dice == 0 && target !=0)
    //         return 0;
    //     if(target==0 && dice !=0)
    //         return 0 ;
    //     if(dice ==0 && target ==0)
    //         return 1 ;
    //     long long ans = 0 ;
    //     for(int i=1;i<=faces;i++)
    //         ans = ans + solve(dice-1,faces,target-i) ;
    //     return ans%mod ;                
    // }

    // Memoization
    long long solve(int dice,int faces,int target,vector<vector<long long>>&dp){
        // base case 
        if(target < 0)
            return 0 ;
        if(dice == 0 && target !=0)
            return 0;
        if(target==0 && dice !=0)
            return 0 ;
        if(dice ==0 && target ==0)
            return 1 ;
        if(dp[dice][target] != -1)
            return dp[dice][target] ;    
        long long ans = 0 ;
        for(int i=1;i<=faces;i++)
            ans = ans + solve(dice-1,faces,target-i,dp) ;
        return dp[dice][target] = ans%mod ;                
    }

    // Tabulation
    // long long solveTab(int dice,int faces,int target){
    //     vector<vector<long long>> dp(dice+1,vector<long long>(target+1,0));
    //     // after aalysing base case
    //     dp[0][0] = 1 ;
    //     for(int d=1 ; d<=dice ; d++){
    //         for(int t=1 ; t<=target ; t++){
    //             long long ans = 0 ;
    //             for(int i=1;i<=faces;i++){
    //                 if(t-i >= 0)
    //                     ans = ans + dp[d-1][t-i] ;
    //             }
                    
    //             dp[d][t] = ans%mod ; 
    //         }
    //     }
    //     return dp[dice][target]%mod ;
    // }
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);

        vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1)) ;
        return solve(n,k,target,dp);

        // return solveTab(n,k,target) ;
    }
};
