
#### 2487. Remove Nodes From Linked List
Link : https://leetcode.com/problems/remove-nodes-from-linked-list/

```cpp
class Solution {
public:
    ListNode* removeNodes(ListNode* head)
  {
        // vector<int> a = { 5 , 2 , 13 , 3 , 8 };
        // vector<ListNode*> LL;
        // ListNode* temp = head;
        // while( temp )
        // {
        //     LL.push_back(temp);
        //     temp = temp -> next;
        // }

        if( head == NULL ) return NULL;
        head -> next = removeNodes( head -> next );\
        // x0 = F(x0)

        if( head -> next )
        {
            if( head -> next -> val > head -> val ) 
                return head -> next;
            else return head;
        }

        else return head;

    }
};
```
