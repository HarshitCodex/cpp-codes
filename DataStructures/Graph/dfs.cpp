// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


/* Function to do DFS of graph

g : adjacency list of graph
N : number of vertices

return a list containing the DFS traversal of the given graph
*/

void dfs(vector<int>& res, vector<int> g[], int n, vector<bool>& isVisited, int s) {
    if(isVisited[s])
        return;
    isVisited[s]=true;
    res.push_back(s);
    for(int i=0; i<g[s].size(); i++) 
        dfs(res,g,n,isVisited,g[s][i]);
}

vector <int> dfs(vector<int> g[], int N)
{   
    int n=N;
    vector<int> res;
    vector<bool> isVisited(n+5,false);
    int s=0;
    while(s<n) {
        if(!isVisited[s])
            dfs(res,g,N,isVisited,s);
        s++;
    }
    return res;
}

// ITERATIVE DFS
vector <int> dfs(vector<int> g[], int N)
{   
    int n=N;
    vector<int> res;
    vector<bool> isVisited(n+5,false);
    int s=0;
    stack<int> st;
    
    for(; s<n; s++) {
        if(isVisited[s])
            continue;
        st.push(s);
        while(!st.empty()) {
            int top=st.top();
            res.push_back(top);
            st.pop();
            isVisited[top]=true;
            
            for(int i=0; i<g[top].size(); i++)
                if(!isVisited[g[top][i]]){
                    st.push(g[top][i]);
                    isVisited[g[top][i]]=true;
                }
        }
    }
    
    return res;
}

// { Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {

        int N, E;
        cin>>N>>E;
        
        vector<int> g[N];
        bool vis[N];
        
        memset(vis, false, sizeof(vis));
        
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        vector <int> res = dfs(g, N);
        for (int i = 0; i < res.size (); i++)
            cout << res[i] << " ";
        cout<<endl;

    }
}  // } Driver Code Ends
