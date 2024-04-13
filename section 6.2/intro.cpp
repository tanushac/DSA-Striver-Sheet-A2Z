#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *back;
    ListNode(int x)
    {
        val = x;
        next = NULL;
        back = NULL;
    }
    ListNode(int x, ListNode *next1, ListNode *back1)
    {
        val = x;
        next = next1;
        back = back1;
    }
};
void PrintList(ListNode *head) // Function to print the LinkedList
{
    ListNode *curr = head;
    for (; curr != NULL; curr = curr->next)
        cout << curr->val << "-->";
    cout << "null" << endl;
}

ListNode *convertToDLL(vector<int> &arr)
{
    ListNode *head = new ListNode(arr[0]);
    ListNode *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        ListNode *temp = new ListNode(arr[i]);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
int main()
{
    vector<int>arr={12,5,8,7};
    ListNode* head=convertToDLL(arr);
    PrintList(head);
    return 0;
}