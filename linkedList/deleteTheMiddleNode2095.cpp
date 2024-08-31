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
  ListNode* deleteMiddle(ListNode* head) {
    if (!head->next) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prevNode = slow;
    while (fast != nullptr) {
      if (!fast->next) break;
      fast = fast->next->next;
      prevNode = slow;
      slow = slow->next;
    }
    prevNode->next = slow->next;
    return head;

  }
};

int main() {



  return 0;
}