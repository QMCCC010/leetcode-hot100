#include <cstddef>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

// 暴力解法
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *currA = headA;
//         while(currA != NULL) {
//             ListNode *currB = headB;
//             while(currB != NULL) {
//                 if (currB == currA) return currB;
//                 currB = currB -> next;
//             }
//             currA = currA -> next;
//         }
//         return NULL;
//     }
// };

// 让长的链表先走，对齐后再一起走
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *currA = headA, *currB = headB;

        // 计算链表长度
        while(currA != NULL) {
            lenA++;
            currA = currA -> next;
        }
        while (currB != NULL)
        {
            lenB++;
            currB = currB -> next;
        }

        // 长的先走
        currA = headA;
        currB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) currA = currA -> next;
        }
        if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++) currB = currB -> next;
        }
        
        // 对齐后同步走
        while (currA != NULL) {
            if (currA == currB) return currA;
            currA = currA -> next;
            currB = currB -> next;
        }
        return NULL;
    }
};