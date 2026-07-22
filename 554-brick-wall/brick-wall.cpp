class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
     long long sum = 0;
     if(wall.size() == 1 && wall[0].size() != 1) return 0;
     vector<vector<int>> arr(wall.size());

    for(int r = 0 ; r < wall.size(); r++)
    {
        sum = 0;
        for(int c = 0; c < wall[r].size() ; c++)
        {
          sum += wall[r][c];
          arr[r].push_back(sum);
        }
    }
    int ans = INT_MAX;

    //unique values in arr
    set<int> unique;
    for(int r = 0 ; r < arr.size(); r++)
    {
        for(int c = 0; c < arr[r].size() ; c++)
        {
          unique.insert(arr[r][c]);
        }
    }
    
    unique.erase(arr[0][arr[0].size()-1]);
    for(auto itr : unique)
    {
        int curr = itr;
        int count = 0;
        for(int r = 0 ; r < arr.size() ; r++ )
        {
            for(int c = 0 ; c < arr[r].size() ; c++)
            {
                if(arr[r][c] > curr)
                {
                    count++;
                    break; //next row
                }else if(arr[r][c] == curr) break;
            }
        }
        ans = min(count,ans);
    }
    if(ans == INT_MAX) return arr.size();
    return ans;
}
};