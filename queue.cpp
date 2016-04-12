/*两个栈实现一个队列*/

#include <iostream>
#include <stack>
using namespace std;

template <class T>
class Queue
{
public:
	void Push(const T& d)
	{
		/*把辅助栈清空*/
		while(!assist_stack.empty())
		{
			assist_stack.pop();
		}
		/*把主栈元素压入辅助栈中*/
		while(!major_stack.empty())
		{
			assist_stack.push(major_stack.top());
			major_stack.pop();
		}
		/*往主栈中压入新元素*/
		major_stack.push(d);
		/*将辅助栈中元素压入主栈中*/
		while (!assist_stack.empty())
		{
			major_stack.push(assist_stack.top());
			assist_stack.pop();
		}
	}
	void Pop()
	{
		if(!major_stack.empty())
		{
			cout<<major_stack.top()<<" ";
			major_stack.pop();
		}
		else
		{
			cout<<endl<<"队列已空";
		}
		cout<<endl;
	}
	const T& Front()
	{
		return major_stack.top();
	}
	const T& Back() 
	{
		/*将辅助栈清空*/
		while (!assist_stack.empty())
		{
			assist_stack.pop();
		}
		/*将主栈中元素压入辅助栈*/
		while(!major_stack.empty())
		{
			assist_stack.push(major_stack.top());
			major_stack.pop();
		}
		/*获得辅助栈栈顶元素，也就是主栈栈尾元素*/
		T& ret = assist_stack.top();
		/*将辅助栈中元素又压回主栈中*/
		while(!assist_stack.empty())
		{
			major_stack.push(assist_stack.top());
			assist_stack.pop();
		}
		return ret;
	}
	int Size()
	{
		return major_stack.size();
	}
	bool Empty()
	{
		return major_stack.empty();
	}
private:
	stack<T> major_stack;
	stack<T> assist_stack;
};

void Test()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout<<q.Front()<<endl<<endl;
	cout<<q.Back()<<endl<<endl;
	cout<<q.Empty()<<endl<<endl;
	cout<<q.Size()<<endl<<endl;
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	q.Pop();
	cout<<endl<<q.Empty()<<endl<<endl;
}
int main()
{
	Test();
	return 0;
}
