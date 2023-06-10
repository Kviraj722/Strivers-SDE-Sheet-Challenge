#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};

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
node *intersectionPresent(node *head1, node *head2)
{
    node *a = head1;
    node *b = head2;

    while (a != b)
    {
        if (a == nullptr)
            a = head1;
        else
            a = a->next;

        if (b == nullptr)
            b = head2;
        else
            b = b->next;
    }
    return a;
}
void printList(node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
}
int main()
{
    // creation of both lists
    node *head = NULL;
    insertNode(head, 1);
    insertNode(head, 3);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 4);
    node *head1 = head;
    head = head->next->next->next;
    node *headSec = NULL;
    insertNode(headSec, 3);
    node *head2 = headSec;
    headSec->next = head;
    cout << "List1: ";
    printList(head1);
    cout << "List2: ";
    printList(head2);

    node *answerNode = intersectionPresent(head1, head2);

    if (answerNode == NULL)
        cout
            << "No intersection\n";
    else
        cout << "The intersection point is " << answerNode->num << endl;
    return 0;
}