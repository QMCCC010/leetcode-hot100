struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        
        ListNode *curr1 = l1;
        ListNode *curr2 = l2;

        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;

        bool carry = false;
        while (curr1 != nullptr && curr2 != nullptr) {
            if (carry) curr1->val = curr1->val + curr2->val + 1;
            else curr1->val = curr1->val + curr2->val;
            carry = false;

            if (curr1->val >= 10) {
                curr1->val = curr1->val - 10;
                carry = true;
            }
            curr->next = curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
            curr = curr->next;
        }

        while (curr1 != nullptr) {
            if (carry) curr1->val = curr1->val + 1;
            carry = false;

            if (curr1->val >= 10) {
                curr1->val = curr1->val - 10;
                carry = true;
            }
            curr->next = curr1;
            curr1 = curr1->next;
            curr = curr->next;
        }
        while (curr2 != nullptr) {
            if (carry) curr2->val = curr2->val + 1;
            carry = false;

            if (curr2->val >= 10) {
                curr2->val = curr2->val - 10;
                carry = true;
            }
            curr->next = curr2;
            curr2 = curr2->next;
            curr = curr->next;
        }

        if (carry) {
            ListNode *node = new ListNode(1);
            curr->next = node;
        }
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};


// 标准解法
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *curr = dummy;
        int carry = 0;
        
        while (l1 != nullptr || l2 != nullptr || carry > 0) {
            int sum = carry;
            
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }
        
        ListNode *head = dummy->next;
        delete dummy;
        return head;
    }
};