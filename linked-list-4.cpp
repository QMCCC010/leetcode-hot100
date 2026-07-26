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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false;

        unordered_set<ListNode*> set;
        ListNode *curr = head;

        while(curr != NULL) {
            if (set.count(curr)) return true;
            set.insert(curr);
            curr = curr -> next;
        }

        return false;
    }
};


// 快慢指针法
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head -> next == NULL) return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != NULL && fast -> next != NULL) {
            slow = slow -> next;
            fast = fast -> next -> next;
            if (slow == fast) return true;
        }
        return false;
    }
};