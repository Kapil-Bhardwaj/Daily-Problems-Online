class Solution {
public:
  
// recursion apporach
// int solve(string s,int index)
// {
//     // base case
//     if(index >= s.length())
//     {
//         return 1;
//     }
//     if(s[index] == '0')
//         return 0 ;
//     int ans = 0 ;    
//     ans = solve(s,index+1) ;
//     if(index+1 < s.length() && (s[index] == '1' || (s[index] == '2' && (s[index+1] - 48) <=6 )))
//         ans += solve(s,index+2) ;
//     return ans;        
// }
  
// Memoization (TLE)
// int solve(string s,int index,vector<int>dp)
// {
//     // base case
//     if(index >= s.length())
//         return 1;
//     if(s[index] == '0')
//         return 0 ;
//     if(dp[index] != -1)    
//         return dp[index] ;
//     int ans = 0 ;    
//     ans = solve(s,index+1,dp) ;
//     if(index+1 < s.length() && (s[index] == '1' || (s[index] == '2' && (s[index+1] - 48) <=6 )))
//         ans += solve(s,index+2,dp) ;
//     return dp[index] = ans;        
// }
 
//  Tabulation (Bottom Up apporach )   
    int numDecodings(string s) {
       vector<int> dp(s.length()+2,1) ;
       for(int i = s.length()-1;i>=0;i--)
       {
           if(s[i] == '0')
                dp[i] = 0 ;
            else
                dp[i] = dp[i+1] ;
            if(i+1 < s.length() && (s[i] == '1' || (s[i] == '2' && (s[i+1] - 48) <=6 )))
                dp[i] += dp[i+2]    ;
       }
       return dp[0];
    }
};
