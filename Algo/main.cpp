#include <iostream>

using namespace std;

// ��� Ŭ����
class Node
{
public:
    int data;       // ���� ����� ��
    Node* next;     // ���� ��带 ����Ű�� ������ ����

    Node(int data)
    {   // ������
        this->data = data;
        this->next = nullptr;
    }
};

// ���� ����Ʈ Ŭ����
class LinkedList
{
private:
    Node* head;     // ù ��° ��带 ����Ű�� ������ ����
public:
    LinkedList()
    {
        head = nullptr;     // �����ڿ��� head�� null�� �ʱ�ȭ
    }

    // ���� ����Ʈ�� �� ��� �߰�
    void insert(int value)
    {
        Node* newNode = new Node(value);   // ���ο� ��� ����

        if (head == nullptr)
        {      // ���� ����Ʈ�� ����ִ� ���
            head = newNode;         // head�� �� ��带 ����Ű���� ��
        }
        else
        {                      // ���� ����Ʈ�� ������� ���� ���
            Node* temp = head;      // ���� ����Ʈ�� ��ȸ�ϱ� ���� ������ ����
            while (temp->next != nullptr)
            { // ������ ������ �̵�
                temp = temp->next;
            }
            temp->next = newNode;   // ������ ����� ���� ���� �� ��带 ����
        }
    }

    // ���� ����Ʈ���� Ư�� ��� ����
    void remove(int value)
    {
        if (head == nullptr)
        {      // ���� ����Ʈ�� ����ִ� ���
            return;
        }

        if (head->data == value)
        {  // ������ ���� ù ��° ��忡 �ִ� ���
            Node* temp = head;      // ������ ����� �޸𸮸� �����ϱ� ���� �ӽ� ������ ����
            head = head->next;      // head�� �� ��° ��带 ����Ű���� ��
            delete temp;            // ù ��° ����� �޸𸮸� ����
            return;
        }

        Node* prev = head;          // ������ ����� ���� ��带 ����Ű�� ������ ����
        Node* current = head->next; // ������ ��带 ����Ű�� ������ ����
        while (current != nullptr)
        { // ���� ����Ʈ�� ��ȸ�ϸ� ������ ��带 ã��
            if (current->data == value)
            {
                prev->next = current->next; // ���� ��尡 ���� ��带 ����Ű���� ��
                delete current;             // ������ ����� �޸𸮸� ����
                return;
            }
            prev = current;             // ���� ���� �̵�
            current = current->next;
        }
    }
    void print()
    {
        Node* temp = head;      // ù ��° ������ ����
        while (temp != nullptr)
        {   // ���� ����Ʈ�� ��ȸ�ϸ� ��� ���� ���
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// �׽�Ʈ �ڵ�
int main()
{
    LinkedList myList;
    myList.insert(5);
    myList.insert(10);
    myList.insert(15);
    myList.print();
    myList.remove(10);
    myList.print();
    return 0;
}