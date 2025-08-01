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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use same min heap approach as used in Flatten list OR sort lists

        if(lists.size() == 0)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode *, ListNode *)>> pq([](ListNode *a, ListNode *b){
            return a->val > b->val;
        });

        for(int i = 0; i < lists.size(); i++)
            if(lists[i])
                pq.push(lists[i]);      // push the head of list (lists are already sorted in themself so only head is needed)
        
            
        ListNode *head = new ListNode(-1);
        ListNode *curr = head;

        while(!pq.empty()) {
            ListNode *min = pq.top();
            pq.pop();
            curr->next = min;

            // avoid null in heap
            if(min->next) pq.push(min->next);

            curr = curr->next;
        }

        // // end the list
        // curr->next = NULL;

        return head->next;
    }
};

