#include <iostream>

#define MAX 10

using namespace std;

typedef struct Node
{
    int data;
    struct Node* Next;

}    Node;

Node* Insert(Node* node, int data) // 데이터 추가
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

Node* Search(Node* node, int data) // 데이터 탐색
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

Node* Delete(Node* node, int data) // 데이터 삭제
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

    // 데이터 추가
    for (int i = 0; i < MAX; i++)
    {
        head = Insert(head, i);
    }
    cout << "결과 : ";
    Print(head);

    cout << '\n';

    cout << "결과 : ";
    Node* someNode = Search(head, 5);
    if (someNode != NULL)
    {
        cout << someNode->data << '\n';
    }
    
    cout << "결과 : ";
    head = Delete(head, 4);
    Print(head);

    return 0;
}