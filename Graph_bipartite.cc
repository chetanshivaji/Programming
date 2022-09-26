//https://practice.geeksforgeeks.org/problems/bipartite-graph/1
//https://www.geeksforgeeks.org/bipartite-graph/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bp(int v, vector<int>adj[], vector<int>&color)
    {
        color[v]=1;//r=1,blue=0; no color -1;
        queue<int>q;
        q.push(v);
        while(!q.empty())
        {
            int u = q.front();q.pop();
            for(auto x:adj[u])
            {
                if(color[x]==-1)
                {
                    color[x] = 1-color[u];
                    q.push(x);
                }
                else
                {
                    if(color[x]==color[u])
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here

	    vector<int>color(V,-1);
	    for(int i =0;i<V;i++)
	    {
	      if(color[i]==-1)     
	      if(false==bp(i, adj, color))
	      return false;
	    }
	    return true;
	    }

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends
