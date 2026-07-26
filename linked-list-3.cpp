struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 暴力遍历找中点 + 反转链表前半部分
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if (head == nullptr || head -> next == nullptr) return true;

//         int len = 0;
//         bool isEven = true;
//         int midpoint = 0;
//         ListNode *curr = head;
//         while(curr != nullptr) {
//             len++;
//             curr = curr -> next;
//         }

//         // 记录链表长度是否为偶数，记录中点
//         if (len % 2 != 0) isEven = false;
//         midpoint = len / 2;

//         // 反转链表的前半部分
//         ListNode *prev = nullptr;
//         curr = head;
//         ListNode *next = nullptr;
//         for (int i = 0; i < midpoint; i++) {
//             next = curr -> next;
//             curr -> next = prev;
//             prev = curr;
//             curr = next;
//         }

//         if (!isEven) curr = curr -> next;
//         // 判断是否为回文链表
//         while (curr != nullptr) {
//             if (curr -> val != prev -> val) return false;
//             curr = curr -> next;
//             prev = prev -> next;
//         }
//         return true;
//     }
// };

// 快慢指针找中点 + 反转链表后半部分
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;

        // 快慢指针找中点
        ListNode *slow = head, *fast = head;
        while (fast != nullptr && fast -> next != nullptr) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        // 反转后半部分
        ListNode *prev = nullptr;
        ListNode *next = nullptr;
        while(slow != nullptr) {
            next = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = next;
        }

        // 判断是否为回文串
        ListNode *left = head, *right = prev;
        while (right != nullptr) {
            if (left ->val != right ->val) return false;
            left = left -> next;
            right = right -> next;
        }
        return true;
    }
};