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
        prev = temp;
    }
    return head;
}
ListNode *insertBeforeHead(ListNode *head, int val)
{
    ListNode *newHead = new ListNode(val, head, nullptr);
    head->back = newHead;
    return newHead;
}
ListNode *insertBeforeTail(ListNode *head, int val)
{
    if (head->next == NULL)
    {
        return insertBeforeHead(head, val);
    }
    ListNode *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    ListNode *prev = tail->back;
    ListNode *newNode = new ListNode(val, tail, prev);
    prev->next = newNode;
    tail->back = newNode;
    return head;
}

ListNode *insertBeforeKth(ListNode *head, int k, int val)
{
    if (k == 1)
    {
        return insertBeforeHead(head, val);
    }
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    ListNode *prev = temp->back;
    ListNode *newNode = new ListNode(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}
int main()
{
    vector<int> arr = {12, 5, 8, 7};
    ListNode *head = convertToDLL(arr);
    PrintList(head);
    return 0;
}