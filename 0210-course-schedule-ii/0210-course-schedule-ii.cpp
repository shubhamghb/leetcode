class Solution {
private:
    bool topoSort(vector<vector<int>> &adj, int n, vector<int> & indegree, vector<int> & ans){
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            for(auto it:adj[curr]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
            ans.push_back(curr);
            count++;
        }

        if(count!=n) return false;
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses); 
        vector<int> indegree(numCourses, 0); 

        for (int i = 0; i < n; i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]] ++;
        }
        vector<int> ans;

        if(topoSort(adj,numCourses,indegree,ans)) return ans;

        return{};
    }
};