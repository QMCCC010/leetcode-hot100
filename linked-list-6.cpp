struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *currl1 = list1;
        ListNode *currl2 = list2;
        ListNode *head = new ListNode();
        ListNode *curr = new ListNode();

        // 如果其中一个为空，直接返回
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        // 初始化头节点
        if (currl1->val <= currl2->val) {
            head = currl1;
            currl1 = currl1->next;
        } else {
            head = currl2;
            currl2 = currl2->next;
        }
        curr = head;

        while (currl1 != nullptr || currl2 != nullptr) {
            if (currl1 == nullptr) {
                curr->next = currl2;
                currl2 = currl2->next;
                curr = curr->next;
            }
            else if (currl2 == nullptr) {
                curr->next = currl1;
                currl1 = currl1->next;
                curr = curr->next;
            }
            else {
                if (currl1->val <= currl2->val) {
                    curr->next = currl1;
                    currl1 = currl1->next;
                    curr = curr->next;
                }
                else {
                    curr->next = currl2;
                    currl2 = currl2->next;
                    curr = curr->next;
                }
            }
        }
        return head;
    }
};


// 递归法
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // 如果其中一个为空，直接返回
        if (list1 == nullptr) return list2;
        else if (list2 == nullptr) return list1;

        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};