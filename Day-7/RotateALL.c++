#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int a)
    {
        num = a;
        next = NULL;
    }
};
// utility function to insert node at the end of the list
void insertNode(node *&head, int val)
{
    node *newNode = new node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
// utility function to rotate list by k times
node *rotateRight(node *head, int k)
{
    Node *curr = head;

    if (head == NULL || head->next == NULL || k == 0)
        return head;
    int len = 1;

    while (curr->next != NULL)
    {
        len++;
        curr = curr->next;
    }

    curr->next = head;
    k = k % len;
    k = len - k;
    while (k--)
        curr = curr->next;

    head = curr->next;
    curr->next = NULL;

    return head;
}

int main()
{
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    int k = 2;
    node *newHead = rotateRight(head, k);

        return 0;
}
