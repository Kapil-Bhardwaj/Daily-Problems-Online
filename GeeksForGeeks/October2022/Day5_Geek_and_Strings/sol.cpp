//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class TrieNode {
    public:
     int cnt;
     vector<TrieNode*> child;
     
     TrieNode(){
         cnt = 0;
         child.resize(26,nullptr);
     }
};

class Solution{
public:
    vector<int> prefixCount(int N, int Q, string li[], string query[])
    {
        
        TrieNode* root = new TrieNode();
        
        TrieNode* node;
       for(int i = 0; i < N; i++){
            node = root;
            string s = li[i];
            for(char ch : s){
                if(!node->child[ch-'a'])
                    node->child[ch-'a'] = new TrieNode();
                node = node->child[ch-'a'];
                node->cnt++;
            }
       }
        
        vector<int> res(Q,0);
        
        for(int i = 0; i < Q; i++){
            node = root;
            string q = query[i];
            for(char ch : q){
                if(!node->child[ch-'a'])
                    node->child[ch-'a'] = new TrieNode();
                node = node->child[ch-'a'];
            }
            res[i] = node->cnt;
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int Q, N, i = 0, x;
	    cin>>N;
	    string s;
	    string li[N];
	    for(int i = 0;i < N;i++)
	        cin>>li[i];
	    cin>>Q; 
	    x = Q;
	    string query[Q];
	    while(Q--){
	        cin>>s;
	        query[i++] = s;
	    }
	    
	    Solution ob;
	    vector<int> ans = ob.prefixCount(N, x, li, query);
	    for(auto i: ans) 
	        cout<<i<<"\n";
    }
    return 0;
}
// } Driver Code Ends
