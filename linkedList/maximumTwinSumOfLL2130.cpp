#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
  int pairSum(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    stack<int> st;
    while (slow) {
      st.push(slow->val);
      slow = slow->next;
    }
    int sum = 0;
    while (!st.empty()) {
      int val = st.top();
      st.pop();
      sum = max(sum, val + head->val);
      head = head->next;
    }
    return sum;


    // unordered_map<int, int> umap;
    // ListNode* curr = head;
    // int i = 0;
    // int n = 0;
    // int sum = 0;
    // while (curr) {
    //   n++;
    //   curr = curr->next;
    // }
    // curr = head;
    // while (curr) {
    //   int index = n - 1 - i;
    //   if (umap.find(index) != umap.end()) {
    //     sum = max(sum, curr->val + umap[index]);
    //   }
    //   umap[i] = curr->val;
    //   i++;
    //   curr = curr->next;
    // }
    // return sum;
  }
};

int main() {



  return 0;
}