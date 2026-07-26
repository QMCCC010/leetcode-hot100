struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr) return head;
        
        ListNode *curr = head -> next;
        ListNode *next = curr -> next;
        head -> next = nullptr;
        
        while (curr != nullptr) {
            curr -> next = head;
            head = curr;
            curr = next;
            if (curr != nullptr) next = curr -> next;
        }
        return head;
    }
};