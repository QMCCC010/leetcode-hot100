#include <cstddef>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 哈希集合法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;

        unordered_set<ListNode*> set;
        ListNode *curr = head;

        while(curr != NULL) {
            if (set.count(curr)) return curr;
            set.insert(curr);
            curr = curr -> next;
        }

        return NULL;
    }
};


// 快慢指针法
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return NULL;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) {
                ListNode *start = head;
                while (start != NULL) {
                    if (start == slow) return start;
                    start = start -> next;
                    slow = slow ->next;
                }
            }
        }
        return NULL;
    }
};