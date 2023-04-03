#include <iostream>
#define MAX_SIZE 100

using namespace std;

class Stack
{
private:
    int top;        // 스택의 가장 위에 있는 원소를 가리키는 변수
    int arr[MAX_SIZE];  // 스택을 저장할 배열

public:
    Stack()
    {
        top = -1;   // 스택이 비어있는 경우를 나타내기 위해 top을 -1로 초기화
    }

    void push(int num)
    {
        if (top >= MAX_SIZE - 1)
        {  // 스택이 꽉 차 있는 경우
            cout << "Stack overflow!" << endl;  // 스택 오버플로우 메시지 출력
            return; // 함수 종료
        }
        arr[++top] = num;  // 스택에 원소 추가
    }

    void pop()
    {
        if (top < 0)
        {  // 스택이 비어있는 경우
            cout << "Stack underflow!" << endl;  // 스택 언더플로우 메시지 출력
            return; // 함수 종료
        }
        top--;  // 스택에서 원소 제거
    }

    int peek()
    {
        if (top < 0)
        {  // 스택이 비어있는 경우
            cout << "Stack is empty!" << endl;  // 스택이 비어있다는 메시지 출력
            return -1;  // 임의의 값 반환
        }
        return arr[top];  // 스택의 가장 위에 있는 원소 반환
    }

    bool isEmpty()
    {
        return top < 0;  // 스택이 비어있는지 여부를 반환
    }

    void printStack()
    {
        if (isEmpty())
        {  // 스택이 비어있는 경우
            cout << "Stack is empty!" << endl;  // 스택이 비어있다는 메시지 출력
            return;  // 함수 종료
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {  // 스택의 모든 원소를 출력
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;  // 스택 객체 생성
    s.push(10);  // 스택에 10 추가
    s.push(20);  // 스택에 20 추가
    s.push(30);  // 스택에 30 추가
    s.printStack(); // 스택의 모든 원소 출력: 30 20 10
    s.pop();  // 스택에서 원소 제거
    cout << s.peek() << endl; // 스택의 가장 위에 있는 원소 반환 후 출력: 20
    s.printStack(); // 스택의 모든 원소 출력: 20 10
    return 0;
}