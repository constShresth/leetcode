#include <iostream>
using namespace std;

class Solution {
private:
  void dfs(int room, vector<int>& vis, vector<vector<int>>& rooms) {
    vis[room] = 1;
    for (auto it : rooms[room]) {
      if (!vis[it]) {
        dfs(it, vis, rooms);
      }
    }
  }
public:
  bool canVisitAllRooms(vector<vector<int>>& rooms) {
    int n = rooms.size();
    vector<int> vis(n, 0);
    dfs(0, vis, rooms);
    for (auto it : vis) {
      if (it == 0) return false;
    }
    return true;
  }
};

int main() {



  return 0;
}