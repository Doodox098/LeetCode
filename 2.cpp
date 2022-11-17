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
private:
    void findFirst(ListNode* l1, ListNode* l2, int k) {
        if(l1 != nullptr && l2 != nullptr){
            int p = (l1 -> val + l2 -> val + k) / 10;
            l1 -> val = (l1 -> val + l2 -> val + k) % 10;
            if(l1 -> next == nullptr && l2 -> next == nullptr){
                if(p){
                    l1 -> next = new ListNode;
                    l1 -> next -> val = p;
                }
                return;
            }
            else if(l2 -> next != nullptr && l1 -> next == nullptr){
                ListNode* s = l2 -> next;
                l2 -> next = l1 -> next;
                l1 -> next = s;
            }  
            findFirst(l1 -> next, l2 -> next, p);
        }
        else if(l1 != nullptr && l2 == nullptr){
            if(k){
                int p = (l1 -> val + k) / 10;
                l1 -> val = (l1 -> val + k) % 10;
                if(p){
                    if(l1 -> next != nullptr)
                        findFirst(l1 -> next, l2, p);
                    else{
                        l1 -> next = new ListNode;
                        l1 -> next -> val = p;
                    }
                }
            }
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        findFirst(l1, l2, 0);
        return l1;
    }
};
