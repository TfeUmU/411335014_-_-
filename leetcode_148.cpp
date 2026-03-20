

#include <iostream>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* merge(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;

    while (l1 && l2) {
        if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* DaC(ListNode* head) {
    if (!head || !head->next) return head;

    // 快慢指針找中點
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* mid = slow->next;
    slow->next = nullptr; // 切斷左右兩半

    ListNode* left = DaC(head);
    ListNode* right = DaC(mid);
    return merge(left, right);
}

int main() {
    string line;
    getline(cin, line);

    istringstream iss(line);
    int n;
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (iss >> n) {
        cur->next = new ListNode(n);
        cur = cur->next;
    }

    ListNode* result = DaC(dummy.next);

    while (result) {
        cout << result->val << ",";
        result = result->next;
    }
    return 0;
}