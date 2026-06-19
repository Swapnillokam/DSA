//87_1_ FlatteningLinkedList
//https://www.geeksforgeeks.org/dsa/flatten-a-multi-level-linked-list-set-2-depth-wise/	
ListNode* mergeTwoSortedLists(ListNode* head1, ListNode* head1) {
        ListNode* head = new ListNode(0);
        ListNode* tail = head;
        while (head1 && head2) {
            if (head1->data <= head2->data) {
                tail->bottom = head1;
                head1 = head1->bottom;
            } else {
                tail->bottom = head2;
                head2 = head2->bottom;
            }
            tail = tail->bottom;
            tail->bottom = nullptr;
        }

        if (head1) {
            tail->bottom = head1;
        } else {
            tail->bottom = head2;
        }
        ListNode* newHead = head->bottom;
        delete head;
        return newHead->bottom;
    }
    ListNode* flattenList(ListNode* root) {
        ListNode *head1, *head2, *head3;
        while (root->next) {
            head1 = root;
            head2 = root->next;
            head3 = root->next->next;
            head1->next = nullptr;
            head2->next = nullptr;
            root = mergeTwoSortedLists(head1, head2);
            root->next = head3;
        }
        return root;
    }