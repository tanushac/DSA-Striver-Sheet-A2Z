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
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}
ListNode *deleteHead(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    { // empty LL
        return NULL;
    }
    ListNode *prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    free(prev);
    return head;
}
ListNode *deleteTail(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    { // empty LL
        return NULL;
    }
    ListNode *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    ListNode *newTail = tail->back;
    newTail->next = NULL;
    tail->back = NULL;
    free(tail);
    return head;
}

int main()
{
    vector<int> arr = {12, 5, 8, 7};
    ListNode *head = convertToDLL(arr);
    head = deleteHead(head);
    PrintList(head);

    return 0;
}