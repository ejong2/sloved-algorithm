#include <iostream>

#define MAX 10

using namespace std;

typedef struct Node
{
    int data;
    struct Node* Next;

}    Node;

Node* Insert(Node* node, int data) // ������ �߰�
{
    if (node == NULL)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->Next = NULL;

        return newNode;
    }
    node->Next = Insert(node->Next, data);
    return node;
}

Node* Search(Node* node, int data) // ������ Ž��
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == data)
    {
        return node;
    }
    return Search(node->Next, data);
}

Node* Delete(Node* node, int data) // ������ ����
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == data)
    {
        Node* nextNode = node->Next;
        free(node);

        return nextNode;
    }
    node->Next = Delete(node->Next, data);
    return node;
}

void Print(Node* node)
{
    if (node == NULL)
    {
        return;
    }

    cout << node->data;
    Print(node->Next);
}

int main()
{
    Node* head = NULL;

    // ������ �߰�
    for (int i = 0; i < MAX; i++)
    {
        head = Insert(head, i);
    }
    cout << "��� : ";
    Print(head);

    cout << '\n';

    cout << "��� : ";
    Node* someNode = Search(head, 5);
    if (someNode != NULL)
    {
        cout << someNode->data << '\n';
    }
    
    cout << "��� : ";
    head = Delete(head, 4);
    Print(head);

    return 0;
}