#include <iostream>
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
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;
    ListNode* curr = head;
    ListNode* prevNode = curr;
    curr = curr->next;
    while (curr != nullptr) {
      if (curr->val == prevNode->val) {
        prevNode->next = curr->next;
      }
      else {
        prevNode = curr;
      }
      curr = curr->next;
    }
    return head;
  }
};

int main() {



  return 0;
}