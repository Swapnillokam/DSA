//68_RatInMaze
//https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
/*
Consider a rat placed at position (0, 0) in an n x n square matrix maze[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

The matrix contains only two possible values:

0: A blocked cell through which the rat cannot travel.
1: A free cell that the rat can pass through.
Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
If no path exists, return an empty list.

Note: Return the final result vector in lexicographically smallest order.

Examples:

Input: maze[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
Output: ["DDRDRR", "DRDDRR"]
Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.
Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.
Input: maze[][] = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
Output: ["DDRR", "RRDD"]
Explanation: The rat has two possible paths to reach the destination: DDRR and RRDD.
*/
class Solution {
  public:
  
    bool valid(int i,int j,int n)
    {
        return i>=0 && i<n && j>=0 && j<n;
    }
    
    bool direction(int i,int j,vector<vector<int>> &v)
    {
        if(v[i][j]==1)
            return true;
        return false;
    }
    
    bool check(int i,int j,vector<vector<bool>> &visited)
    {
        if(visited[i][j]==1)
            return true;
        return false;
    }
    
    //TC - O(3^n^2)
    void ways(vector<vector<int>> &v,int i,int j,int n,string &path,vector<vector<bool>> &visited,vector<string> &ans)
{
    if(i==n-1 && j==n-1)
    {
        ans.push_back(path);
        return;
    }
    
    visited[i][j] = 1;
    
    
    //Down
    if(valid(i+1,j,n)&&direction(i+1,j,v)&&!check(i+1,j,visited))
    {
        path.push_back('D');
        ways(v,i+1,j,n,path,visited,ans);
        path.pop_back();
    }
    //left
    if(valid(i,j-1,n)&&direction(i,j-1,v)&&!check(i,j-1,visited))
    {
        path.push_back('L');
        ways(v,i,j-1,n,path,visited,ans);
        path.pop_back();
    }
    //right
    if(valid(i,j+1,n)&&direction(i,j+1,v)&&!check(i,j+1,visited))
    {
        path.push_back('R');
        ways(v,i,j+1,n,path,visited,ans);
        path.pop_back();
    }
    //Up
    if(valid(i-1,j,n)&&direction(i-1,j,v)&&!check(i-1,j,visited))
    {
        path.push_back('U');
        ways(v,i-1,j,n,path,visited,ans);
        path.pop_back();
    }
    
    visited[i][j] = 0;
}
  
    //refactored code
    vector<int> row = {-1,1,0,0};
    vector<int> col = {0,0,-1,1};
    string dir = "UDLR";
    //TC - O(3^n^2)
    void ways2(vector<vector<int>> &v,int i,int j,int n,string &path,vector<vector<bool>> &visited,vector<string> &ans)
    {
        if(i==n-1 && j==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[i][j] = 1;
        
        for(int k = 0;k<4;k++)
        {
            if(valid(i+row[k],j+col[k],n)&&direction(i+row[k],j+col[k],v)&&!check(i+row[k],j+col[k],visited))
            {
                path.push_back(dir[k]);
                ways(v,i+row[k],j+col[k],n,path,visited,ans);
                path.pop_back();
            }
        }
        
        visited[i][j] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        int n = maze[0].size();
        
        if(n==0)
            return ans;
        
        if(maze[0][0]==0)
            return ans;
        
        
        vector<vector<bool>> visited(n,vector<bool>(n,0));
    
        string path = "";
        
        ways2(maze,0,0,n,path,visited,ans);
        
        return ans;
            
    }
};