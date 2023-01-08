// 큐 구현

#include <iostream>

using namespace std;

#define SIZE 1000

class Queue
{
	int* arr;		// Queue 요소를 저장할 어레이
	int capacity;	// Queue의 최대 용량
	int peek;		// 앞은 Queue의 앞 요소를 가리킵니다(있는 경우).
	int rear;		// 후면은 Queue의 마지막 요소를 가리킵니다.
	int count;		// Queue의 현재 크기

public:
	Queue(int size = SIZE);		// 생성자
	~Queue();					// 소멸자

	int pop();
	void push(int x);
	int front();
	int size();
	bool isEmpty();
	bool isFull();
};

// Queue를 초기화하는 생성자
Queue::Queue(int size)
{
	arr = new int[size];
	capacity = size;
	peek = 0;
	rear = -1;
	count = 0;
}

// Queue에 할당된 메모리를 해제하는 소멸자
Queue::~Queue()
{
	delete[] arr;
}

// 앞 요소를 큐에서 빼는 유틸리티 함수
int Queue::pop()
{
	// Queue 언더플로 확인
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

// Queue에 항목을 추가하는 유틸리티 함수
void Queue::push(int item)
{
	// Queue 오버플로 확인
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

// Queue의 앞 요소를 반환하는 유틸리티 함수
int Queue::front()
{
	if (isEmpty())
	{
		cout << "Underflow\nProgram Terminated\n";
		exit(EXIT_FAILURE);
	}
	return arr[peek];
}

// Queue의 크기를 반환하는 유틸리티 함수
int Queue::size()
{
	return count;
}

// Queue가 비어 있는지 확인하는 유틸리티 함수
bool Queue::isEmpty()
{
	return (size() == 0);
}

// Queue가 가득 찼는지 확인하는 유틸리티 함수
bool Queue::isFull()
{
	return (size() == capacity);
}

int main()
{
	// 용량이 5인 Queue 생성
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
