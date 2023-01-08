// ť ����

#include <iostream>

using namespace std;

#define SIZE 1000

class Queue
{
	int* arr;		// Queue ��Ҹ� ������ ���
	int capacity;	// Queue�� �ִ� �뷮
	int peek;		// ���� Queue�� �� ��Ҹ� ����ŵ�ϴ�(�ִ� ���).
	int rear;		// �ĸ��� Queue�� ������ ��Ҹ� ����ŵ�ϴ�.
	int count;		// Queue�� ���� ũ��

public:
	Queue(int size = SIZE);		// ������
	~Queue();					// �Ҹ���

	int pop();
	void push(int x);
	int front();
	int size();
	bool isEmpty();
	bool isFull();
};

// Queue�� �ʱ�ȭ�ϴ� ������
Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	peek = 0;
	rear = -1;
	count = 0;
}

// Queue�� �Ҵ�� �޸𸮸� �����ϴ� �Ҹ���
Queue::~Queue()
{
	delete[] arr;
}

// �� ��Ҹ� ť���� ���� ��ƿ��Ƽ �Լ�
int Queue::pop()
{
	// Queue ����÷� Ȯ��
	if (isEmpty())
	{
		cout << "Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	int x = arr[peek];
	cout << "Removing " << x << endl;

	peek = (peek + 1) % capacity;
	count--;

	return x;
}

// Queue�� �׸��� �߰��ϴ� ��ƿ��Ƽ �Լ�
void Queue::push(int item)
{
	// Queue �����÷� Ȯ��
	if (isFull())
	{
		cout << "Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}

	cout << "Inserting " << item << '\n';

	rear = (rear + 1) % capacity;
	arr[rear] = item;
	count++;
}

// Queue�� �� ��Ҹ� ��ȯ�ϴ� ��ƿ��Ƽ �Լ�
int Queue::front()
{
	if (isEmpty())
	{
		cout << "Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[peek];
}

// Queue�� ũ�⸦ ��ȯ�ϴ� ��ƿ��Ƽ �Լ�
int Queue::size()
{
	return count;
}

// Queue�� ��� �ִ��� Ȯ���ϴ� ��ƿ��Ƽ �Լ�
bool Queue::isEmpty()
{
	return (size() == 0);
}

// Queue�� ���� á���� Ȯ���ϴ� ��ƿ��Ƽ �Լ�
bool Queue::isFull()
{
	return (size() == capacity);
}

int main()
{
	// �뷮�� 5�� Queue ����
	Queue q(5);

	q.push(1);
	q.push(2);
	q.push(3);

	cout << "The front element is " << q.front() << endl;
	q.pop();

	q.push(4);

	cout << "The queue size is " << q.size() << endl;

	q.pop();
	q.pop();
	q.pop();

	if (q.isEmpty())
	{
		cout << "The queue is empty\n";
	}
	else
	{
		cout << "The queue is not empty\n";
	}

	return 0;
}
