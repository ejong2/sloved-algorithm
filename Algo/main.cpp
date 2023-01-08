// Stack 구현

#include <iostream>

using namespace std;

class Stack
{
private:
	int stack_size;		// 스택 사이즈
	int stack_count;	// 스택에 저장된 데이터 개수
	int* p_stack;		// 스택으로 사용할 메모리 주소를 가리킬 포인터

public:

	// 메서드 선언
	Stack();
	~Stack();

	void create_stack(int size);
	void push(int value);
	void pop();
	void show_stack();
};

Stack::Stack() // 생성자
{
	// 클래스 변수 초기화
	stack_size = 0;
	stack_count = 0;
	p_stack = nullptr;
}

Stack::~Stack()
{
	if (p_stack != nullptr)
	{
		delete[] p_stack; // p_stack이 존재하면 소멸
	}
}

// 스택 생성 -> 스택에 사용할 size를 size 변수로 정의
void Stack::create_stack(int size)
{
	if (p_stack != nullptr)
	{
		delete[] p_stack; // 기존에 사용하던 메모리가 있으면 해당 메모리를 제거한다
	}
	stack_size = size; // class 변수에 값을 넣어줌
	p_stack = new int[stack_size]; // 새로 메모리를 할당한다
}

// 스택 push
void Stack::push(int value)
{
	// 스택에 빈 공간이 있을 때 값을 넣는다
	if (stack_count < stack_size)
	{
		*(p_stack + stack_count) = value; // 스택 메모리 공간에 stack_count index 만큼의 주소값에 값을 넣어 준다

		stack_count++; // 저장이 되어 스택 count를 증가시킨다
	}
	else
	{
		cout << "Stack이 가득 찼습니다." << '\n';
	}
}

// 스택 pop
void Stack::pop()
{
	if (stack_count == 0) // 저장된 stack이 없으면
	{
		cout << "stack에 저장된 값이 없습니다." << '\n';
	}
	else
	{
		cout << "popped !" << '\n';
		p_stack[stack_count--] = 0;	// 마지막 값을 0으로 만들고 stack_count를 감소시킨다
	}
}

void Stack::show_stack()
{
	if (stack_count == 0)
	{
		cout << "stack에 저장된 값이 없습니다." << '\n';
	}
	else
	{
		cout << "stack에 저장된 데이터" << '\n';
		for (int i = 0; i < stack_count; i++)
		{
			cout << i << " : " << p_stack[i] << '\n';
		}
		cout << "총 " << stack_count << "개의 value가 저장되어 있습니다." << '\n';
	}
}


int main()
{
	Stack stack;
	int s_size = 0;
	int tmp = 0;
	int button = -1; // 아무 숫자로 초기화
	int value = 0;
	cout << "Stack 사이즈를 입력하세요 : ";

	// 입력된 stack 사이즈가 양수인지 체크
	while (s_size <= 0)
	{
		scanf_s("%d", &tmp);
		if (tmp <= 0)
		{
			cout << "stack_size를 양수로 입력하세요, 현재 입력된 값 ->" << s_size << endl << endl;
			cout << "Stack 사이즈를 입력하세요 : ";
		}
		else s_size = tmp;
	}

	// 스택 생성
	stack.create_stack(s_size);


	cout << endl;
	cout << "1. Stack Push" << endl;
	cout << "2. Stack Pop" << endl;
	cout << "3. Stack Print" << endl;
	cout << "0. Exit program" << endl;
	cout << endl << endl;

	while (button != 0)
	{
		cout << "버튼 선택 : ";
		scanf_s("%d", &button);
		cout << endl << endl;
		switch (button)
		{
			case 1: // 입력한 값 저장
				cout << "저장할 값은 ? : ";
				scanf_s("%d", &value);
				stack.push(value);
				break; // break 필수 안그러면 아래 항목들도 실행

			case 2:
				stack.pop();
				break;

			case 3:
				stack.show_stack();
				break;

		}

	}
	return 0;
}