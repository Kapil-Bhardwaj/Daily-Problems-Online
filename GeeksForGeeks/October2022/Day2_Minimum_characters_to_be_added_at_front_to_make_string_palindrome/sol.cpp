class Solution {
public:
    int minChar(string str){
        //Write your code here
        int i=0;
        int n = str.length() ;
        int j = n-1,trim = n-1 ;
        while(i<=j)
        {
            if(str[i] == str[j] )
            {
                i++ ;
                j--;
            }
            else
            {
                i = 0 ;
                trim-- ;
                j = trim ;
            }
        }
        return n-1 - trim ;
    }
};
