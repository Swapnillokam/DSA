//64_PermutationWithoutRepeatition
//https://leetcode.com/problems/permutations/submissions/2007404392/

/*

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]
*/

//TC - O(n*n!) SC- O(n)
void permute(vector<int> &v,vector<vector<int>> &ans,vector<int> &temp,vector<bool> &visited)
{
    if(visited.size() == temp.size())
    {
        ans.push_back(temp);
        return;
    }
    for(int i = 0;i<visited.size();i++)
    {
        if(visited[i]==0)
        {
            visited[i] = 1;
            temp.push_back(v[i]);
            permute(v,ans,temp,visited);
            temp.pop_back();
            visited[i] = 0;
        }
    }
}

void permute2(vector<int> &v,vector<vector<int>> &ans,int index)
{
    if(index == v.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i=index;i<v.size();i++)
    {
        swap(v[i],v[index]);
        permute2(v,ans,index+1);
        swap(v[i],v[index]);
    }
}

int main() {    
    vector<int> v3 = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(v3.size(),0);
    permute(v3,ans,temp,visited);
    for(vector<int> x : ans)
    {
        for(int y : x)
        {
            cout<<y;
        }
        cout<<endl;
    }
    
    
    return 0;
}