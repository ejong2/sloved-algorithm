#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int top;        // ������ ���� ���� �ִ� ���Ҹ� ����Ű�� ����
    int arr[MAX_SIZE];  // ������ ������ �迭

public:
    Stack()
    {
        top = -1;   // ������ ����ִ� ��츦 ��Ÿ���� ���� top�� -1�� �ʱ�ȭ
    }

    void push(int num)
    {
        if (top >= MAX_SIZE - 1)
        {  // ������ �� �� �ִ� ���
            cout << "Stack overflow!" << endl;  // ���� �����÷ο� �޽��� ���
            return; // �Լ� ����
        }
        arr[++top] = num;  // ���ÿ� ���� �߰�
    }

    void pop()
    {
        if (top < 0)
        {  // ������ ����ִ� ���
            cout << "Stack underflow!" << endl;  // ���� ����÷ο� �޽��� ���
            return; // �Լ� ����
        }
        top--;  // ���ÿ��� ���� ����
    }

    int peek()
    {
        if (top < 0)
        {  // ������ ����ִ� ���
            cout << "Stack is empty!" << endl;  // ������ ����ִٴ� �޽��� ���
            return -1;  // ������ �� ��ȯ
        }
        return arr[top];  // ������ ���� ���� �ִ� ���� ��ȯ
    }

    bool isEmpty()
    {
        return top < 0;  // ������ ����ִ��� ���θ� ��ȯ
    }

    void printStack()
    {
        if (isEmpty())
        {  // ������ ����ִ� ���
            cout << "Stack is empty!" << endl;  // ������ ����ִٴ� �޽��� ���
            return;  // �Լ� ����
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {  // ������ ��� ���Ҹ� ���
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;  // ���� ��ü ����
    s.push(10);  // ���ÿ� 10 �߰�
    s.push(20);  // ���ÿ� 20 �߰�
    s.push(30);  // ���ÿ� 30 �߰�
    s.printStack(); // ������ ��� ���� ���: 30 20 10
    s.pop();  // ���ÿ��� ���� ����
    cout << s.peek() << endl; // ������ ���� ���� �ִ� ���� ��ȯ �� ���: 20
    s.printStack(); // ������ ��� ���� ���: 20 10
    return 0;
}