struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


// 直接法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;

        ListNode *dummy = new ListNode();
        dummy->next = head->next;
        ListNode *done = dummy;
        ListNode *prev = head;
        ListNode *curr = head->next;
        ListNode *next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            prev->next = next;
            curr->next = prev;
            done->next = curr;

            done = prev;
            if (next == nullptr) break;
            curr = next->next;
            prev = next;
        }
        ListNode *newNode = dummy->next;
        delete dummy;
        return newNode;
    }
};


// 递归法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        
        ListNode *newHead = head->next;
        head->next = swapPairs(newHead->next);
        newHead->next = head;

        return newHead;
    }
};