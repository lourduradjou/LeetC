class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        //lets first create the pq with diff and row, col
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1e9)); // distance matrix
        dist[0][0] = 0;
        pq.push({0, {0,0}});

        int rowMovements[] = {-1, 0, 1, 0};
        int colMovements[] = {0, 1, 0, -1};

        while(!pq.empty()) {
            auto it = pq.top();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            pq.pop();
            
            if(row == n - 1 && col == m - 1)
                return diff;
            
            for(int i = 0; i < 4; i++) {
                int newRow = row + rowMovements[i];
                int newCol = col + colMovements[i];
              
                //condition check
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                      int newEffort = max(abs(heights[row][col] - heights[newRow][newCol]), diff);
                      //update the distance and put in the queue
                      if(newEffort < dist[newRow][newCol]) {
                          dist[newRow][newCol] = newEffort;
                          pq.push({newEffort, {newRow, newCol}});
                      }
                }
            }
          
        }
          return 0;
        }
};