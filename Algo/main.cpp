#include <iostream>

using namespace std;

// 노드 클래스
class Node
{
public:
    int data;       // 현재 노드의 값
    Node* next;     // 다음 노드를 가리키는 포인터 변수

    Node(int data)
    {   // 생성자
        this->data = data;
        this->next = nullptr;
    }
};

// 연결 리스트 클래스
class LinkedList
{
private:
    Node* head;     // 첫 번째 노드를 가리키는 포인터 변수
public:
    LinkedList()
    {
        head = nullptr;     // 생성자에서 head를 null로 초기화
    }

    // 연결 리스트에 새 노드 추가
    void insert(int value)
    {
        Node* newNode = new Node(value);   // 새로운 노드 생성

        if (head == nullptr)
        {      // 연결 리스트가 비어있는 경우
            head = newNode;         // head가 새 노드를 가리키도록 함
        }
        else
        {                      // 연결 리스트가 비어있지 않은 경우
            Node* temp = head;      // 연결 리스트를 순회하기 위한 포인터 변수
            while (temp->next != nullptr)
            { // 마지막 노드까지 이동
                temp = temp->next;
            }
            temp->next = newNode;   // 마지막 노드의 다음 노드로 새 노드를 연결
        }
    }

    // 연결 리스트에서 특정 노드 삭제
    void remove(int value)
    {
        if (head == nullptr)
        {      // 연결 리스트가 비어있는 경우
            return;
        }

        if (head->data == value)
        {  // 삭제할 값이 첫 번째 노드에 있는 경우
            Node* temp = head;      // 삭제할 노드의 메모리를 해제하기 위한 임시 포인터 변수
            head = head->next;      // head가 두 번째 노드를 가리키도록 함
            delete temp;            // 첫 번째 노드의 메모리를 해제
            return;
        }

        Node* prev = head;          // 삭제할 노드의 이전 노드를 가리키는 포인터 변수
        Node* current = head->next; // 삭제할 노드를 가리키는 포인터 변수
        while (current != nullptr)
        { // 연결 리스트를 순회하며 삭제할 노드를 찾음
            if (current->data == value)
            {
                prev->next = current->next; // 이전 노드가 다음 노드를 가리키도록 함
                delete current;             // 삭제할 노드의 메모리를 해제
                return;
            }
            prev = current;             // 다음 노드로 이동
            current = current->next;
        }
    }
    void print()
    {
        Node* temp = head;      // 첫 번째 노드부터 시작
        while (temp != nullptr)
        {   // 연결 리스트를 순회하며 노드 값을 출력
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

// 테스트 코드
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