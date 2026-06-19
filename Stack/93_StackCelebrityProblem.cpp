//93_StackCelebrityProblem
//https://www.geeksforgeeks.org/problems/the-celebrity-problem/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution {
  public:
    int celebrity(vector<vector<int>>& m) {
        stack<int> s;
        int k = m.size();

        for(int i = 0; i < k; i++) s.push(i);

        while(s.size() > 1) {
            int first = s.top(); s.pop();
            int second = s.top(); s.pop();

            // correct elimination
            if(m[first][second] == 1) s.push(second);
            else s.push(first);
        }

        if(s.empty()) return -1;

        int num = s.top();

        int row = 0, col = 0;
        for(int i = 0; i < k; i++) {
            if(i != num) row += m[num][i];  // num knows others?
            col += m[i][num];               // others know num?
        }

        // since m[num][num] == 1, col should be k and row should be 0
        return (row == 0 && col == k) ? num : -1;
    }
};