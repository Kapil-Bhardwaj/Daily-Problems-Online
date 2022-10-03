class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        for(int i=0;i<colors.length();){
            int j = i ;
            int max_index = i ;
            int max = neededTime[i] ;
            while(j<=colors.length() && colors[i] == colors[j]){
                if(neededTime[j] > max){
                    max_index = j ;
                    max = neededTime[j] ;
                }
                j++;
            }
            int sum = 0;
            for(int k=i;k<j;k++){
                if(k!=max_index){
                    sum += neededTime[k] ;
                }
            }
            ans += sum ;
            i = j ;
        }
        return ans ;
    }
};
