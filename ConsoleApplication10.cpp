#include <iostream>
#include <vector>
#include <sstream>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

// 插入排序
ListNode* solve(ListNode* head) {
    ListNode dummy(0);  
    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* node = cur;       // 目前要插入的
        ListNode* nxt = cur->next; // 先記住下一個

        // 找插入位置
        ListNode* pre = &dummy;
        while (pre->next != nullptr && pre->next->val < node->val) {
            pre = pre->next;
        }

        // 接上去
        node->next = pre->next;
        pre->next = node;
        cur = nxt; // 移到下一個
    }

    return dummy.next;
}

int main() {

    string line;
    getline(cin, line);

    vector<int> arr;
    int n;
    istringstream iss(line);
    while (iss >> n) {
        arr.push_back(n);
    }

    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int i = 0; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }

    // 排序並印出
    ListNode* res = solve(dummy.next);
    while (res != nullptr) {
        cout << res->val;
        if (res->next != nullptr) cout << ",";
        res = res->next;
    }
    cout << "\n";

    return 0;
}