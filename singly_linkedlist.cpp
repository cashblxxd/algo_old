#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node
{
    T elem;
    Node * next;
    Node()
    {
        this->elem = 0;
    }
    Node(T data)
    {
        this->elem = data;
    }
    Node<T> * insert_after(T data)
    {
        Node * curr = new Node(data);
        curr->next = this->next;
        this->next = curr;
        return curr;
    }
    Node<T> * insert_before(T data)
    {
        Node * curr = new Node;
        *curr = *this;
        this->elem = data;
        this->next = curr;
        return curr;
    }
};

template<typename T>
struct Node<T> * divide(Node<T> * head, Node<T> * end, Node<T> ** newHead, Node<T> ** newEnd)
{
    Node<T> * prev = NULL, * cur = head, * tail = end;

    while (cur != end)
    {
        if (cur->elem < end->elem)
        {
            if ((*newHead) == NULL) (*newHead) = cur;
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev != NULL) prev->next = cur->next;
            Node<T> * tmp = cur->next;
            cur->nex
            t = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    if ((*newHead) == NULL)
        (*newHead) = end;

    (*newEnd) = tail;
    return end;
}

template<typename T>
Node<T> * qsort_recursive(Node<T> * head, Node<T> * end)
{
    if (head == NULL || head == end) return head;
    Node<T> * newHead = NULL, * newEnd = NULL;
    Node<T> * pivot = divide(head, end, &newHead, &newEnd);
    Node<T> * tmp = newHead;
    if (newHead != pivot)
    {
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = NULL;
        newHead = qsort_recursive(newHead, tmp);
        tmp = newHead;
        while(tmp != NULL && tmp->next != NULL) tmp = tmp->next;
        tmp->next = pivot;
    }
    pivot->next = qsort_recursive(pivot->next, newEnd);
    return newHead;
}

template<typename T>
void quickSort(Node<T> ** head)
{
    Node<T> * end = * head;
    while(end != NULL && end->next != NULL) end = end->next;
    (*head) = qsort_recursive(* head, end);
    return;
}

signed main()
{
    Node<int> * start = new Node(-1);
    Node<int> * head = start;
    int k; cin >> k;
    while(k != 0)
    {
        start = start->insert_after(k);
        cin >> k;
    }
    head = head->next;
    start = head;
    while(head != NULL)
    {
        cout << head->elem << " ";
        head = head->next;
    }
    cout << "\n";
    quickSort(&start);
    while(start != NULL)
    {
        cout << start->elem << " ";
        start = start->next;
    }
    cout << "\n";
    return 0;
}
