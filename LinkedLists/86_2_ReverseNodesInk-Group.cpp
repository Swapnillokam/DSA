//leetcode 25 - 86_2_ReverseNodesIn_vk-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* first = new ListNode(0);
        first->next = head;
        head = first;
ListNode *prev,*sec,*curr,*front;
        while (first->next) {
            
// ✅ check if k nodes exist
            curr = first;
            int cnt = 0;
            while (cnt < k && curr->next) {
                curr = curr->next;
                cnt++;
            }
            if (cnt < k) break;   // 🚫 do NOT reverse partial group

            prev = first;
            sec = first->next;
            curr = first->next;
            int x = k;
            while (x > 0 && curr) {
                front = curr->next;
                curr->next = prev;
                prev = curr;
                curr = front;
                x--;
            }
            first->next = prev;
            sec->next = curr;
            first = sec;
        }
        first = head;
        head = head->next;
        delete first;
        return head;
    }
};