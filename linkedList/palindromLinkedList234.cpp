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
  bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr) {
      if (!fast->next) break;
      fast = fast->next->next;
      slow = slow->next;
    }
    ListNode* prevNode = nullptr;
    while (slow != nullptr) {
      ListNode* temp = slow->next;
      slow->next = prevNode;
      prevNode = slow;
      slow = temp;
    }
    while (head != nullptr && prevNode != nullptr) {
      if (head->val != prevNode->val) return false;
      head = head->next;
      prevNode = prevNode->next;
    }
    return true;
    // stack<int> st;
    // ListNode* curr = head;
    // while(curr!=nullptr){
    //     st.push(curr->val);
    //     curr = curr->next;
    // }
    // curr = head;
    // while(curr!=nullptr){
    //     int val = st.top();
    //     st.pop();
    //     if(curr->val!=val) return false;
    //     curr = curr->next;
    // }
    // return true;
  }
};

int main() {



  return 0;
}