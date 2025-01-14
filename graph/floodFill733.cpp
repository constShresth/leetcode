#include <iostream>
using namespace std;

class Solution {
public:
  vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    int m = image.size();
    int n = image[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    queue<pair<int, int>> q;
    q.push({ sr,sc });
    vis[sr][sc] = 1;
    int initialColor = image[sr][sc];
    image[sr][sc] = color;
    while (!q.empty()) {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();
      vector<int> drow = { -1,0,+1,0 };
      vector<int> dcol = { 0,-1,0,+1 };
      for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = col + dcol[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && image[nrow][ncol] == initialColor && !vis[nrow][ncol]) {
          q.push({ nrow,ncol });
          vis[nrow][ncol] = 1;
          image[nrow][ncol] = color;
        }
      }
    }
    return image;
    // o(n*m), o(n*m)
  }
};

int main() {



  return 0;
}