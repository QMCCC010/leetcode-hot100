struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 直接遍历删除法
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        if (head->next == nullptr && n == 1) return nullptr;
        
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        curr->next = head;
        int len = 0;

        while (curr != nullptr) {
            len++;
            curr = curr->next;
        }

        int left = len - n;
        curr = dummy;
        for (int i = 0; i < left - 1; i++) curr = curr->next;
        curr->next = curr->next->next;

        ListNode *newNode = dummy->next;
        delete dummy;
        return newNode;
    }
};


// 双指针法（让距离差固定为 n - 1，就可以定位到删除节点的前一个节点）
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        if (head->next == nullptr && n == 1) return nullptr;
        
        ListNode *dummy = new ListNode();
        dummy->next = head;
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        // fast 先走n + 1步
        for (int i = 0; i <= n; i++) fast = fast->next;

        // 一起走，停止时slow刚好指向删除节点的前一个节点
        while (fast !=nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        ListNode *newNode = dummy->next;
        delete dummy;
        return newNode;
    }
};