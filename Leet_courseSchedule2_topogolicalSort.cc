class Solution {
public:
    bool dfs(vector<vector<int>>&v,vector<bool>&vis,vector<bool>&recursionStack, stack<int>&stk,int i)
    {   
        //mind checking if there is loop, if loop return false and say not possible topology return []
        vis[i]=true;
        recursionStack[i]=true;
        for(auto j:v[i])
        {
            if(!vis[j])
            {
                if(dfs(v,vis,recursionStack,stk,j))
                    return true;
            }
            else
            {
                //if visited check if present in recursion stack
                if(recursionStack[j]==true)
                {
                    return true;
                }
            }
        }
        //cout<<i<<endl;
        stk.push(i);
        recursionStack[i]=false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& preq) {
        //Need topological sorting.
        if(preq.size()==0)
        {
            vector<int>v(numCourses);
            for(int i=0;i<numCourses;i++)
            {
                v[i]=i;
            }
            return v;
        }
        vector<vector<int>>v(numCourses);
        //do dfs, use stack, put when loop ends, pop at end and print.
        vector<bool>vis(numCourses,false);
        vector<bool>recursionStack(numCourses,false);
        for(auto e:preq)
        {
            v[e[1]].push_back(e[0]);
        }
        stack<int>stk;
        for(int i=0;i<numCourses;i++)
        {
            if(!vis[i])
            {
                if(dfs(v,vis,recursionStack,stk,i))
                    return vector<int>();
            }
        }
        vector<int>vRes;
        while(!stk.empty())
        {
            vRes.push_back(stk.top());
            stk.pop();
        }
        return vRes;
    }
};
