class Solution {
public:
    int bfs(int idx,vector<int>& cost,vector<int>& visited)
    {
        if(idx > cost.size()) return cost[cost.size()-1];
        if(idx == cost.size()) return 0;

        //1 step
        int to_add ;
        if(idx+1 < cost.size() && visited[idx+1] != -1)
        {
          to_add = visited[idx+1];
        }else
        { 
          to_add =  bfs(idx+1,cost,visited);
        }
        int left = cost[idx] + to_add;
 
       //2 step
        int to_add2 ;
        if(idx+2 < cost.size() && visited[idx+2] != -1) //visited me h
        {
          to_add2 = visited[idx+2];
        }else to_add2 =  bfs(idx+2,cost,visited);
        
        int right = cost[idx] + to_add2;

        int ans = min(left,right);
        visited[idx] = ans;
        return ans;
                
    }
    int minCostClimbingStairs(vector<int>& cost) {
     vector<int> visited(cost.size(),-1);
     int ans = bfs(0,cost,visited); // 0th idx
     return min(ans,visited[1]); // 1 can also be start

    }
};