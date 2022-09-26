//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {

  public:
  bool cycle(int i, vector<int> adj[],vector<bool>&vis,vector<bool>&rec)
  {
      //cout<<i<<endl;
      vis[i]=true;
      rec[i]=true;
      for(int j=0;j<adj[i].size();j++)
      {
          if(vis[adj[i][j]]==false)
          {
              if(cycle(adj[i][j],adj,vis,rec)==true)
              return true;
          }
          else
          {
              if(rec[adj[i][j]]==true)
              return true;
          }
          rec[adj[i][j]]=false;
      }
      rec[i]=false;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>vis(V,0);
        vector<bool>rec(V,0);
        for(int i =0;i<V;i++)
        {
            if(!vis[i])
            {
                if(cycle(i,adj,vis,rec)==true)
                return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
