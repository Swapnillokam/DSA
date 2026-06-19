//leetcode 23 - 87_2_ Merge k Sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head2) {
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                head->next = head1;
                head1 = head1->next;
            } else {
                head->next = head2;
                head2 = head2->next;
            }
            head = head->next;
            head->next = nullptr;
        }
        if (head1) {
            head->next = head1;
        } else {
            head->next = head2;
        }
        ListNode* newHead = curr->next;
        delete curr;
        return newHead;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if (size == 0)
            return nullptr;
        ListNode* mergedList = lists[0];
        for (int i = 1; i < size; i++) {
            mergedList = mergeTwoSortedLists(mergedList, lists[i]);
        }
        return mergedList;
    }
};