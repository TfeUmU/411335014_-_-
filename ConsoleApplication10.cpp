#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* insertionSortList(ListNode* head) {
    ListNode dummy(0);
    ListNode* unsorted = head;

    while (unsorted) {
        ListNode* key = unsorted;
        ListNode* nextUnsorted = unsorted->next;

        ListNode* sorted = &dummy;
        while (sorted->next && sorted->next->val < key->val)
            sorted = sorted->next;

        key->next = sorted->next;
        sorted->next = key;
        unsorted = nextUnsorted;
    }

    return dummy.next;
}

ListNode* buildList(vector<int>& vals) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vals) cur = cur->next = new ListNode(v);
    return dummy.next;
}

void printList(ListNode* head) {
    for (; head; head = head->next)
        cout << head->val << (head->next ? " -> " : "\n");
}

int main() {
    vector<int> vals;
    string line;
    int num;

    cout << "請輸入數字（以空格分隔，按 Enter 結束）：";
    getline(cin, line);

    istringstream iss(line);
    while (iss >> num)
        vals.push_back(num);

    if (vals.empty()) {
        cout << "沒有輸入任何數字\n";
        return 0;
    }

    ListNode* head = buildList(vals);
    ListNode* result = insertionSortList(head);

    cout << "排序結果：";
    printList(result);

    return 0;
}
