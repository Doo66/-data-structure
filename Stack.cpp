/*1.两个队列实现一个栈*/

#include <iostream>
#include <queue>

using namespace std;

template <class T>

class Stack
{
public:
	void Push(const T& d)
	{
		/*把辅助的队列置空*/
		while(!assist_queue.empty())
		{
			assist_queue.pop();
		}
		/*把主要的队列中元素放到辅助队列中*/
		while(!major_queue.empty())
		{
			assist_queue.push(major_queue.front());
			major_queue.pop();
		}
		/*往主要的队列中压入新元素d*/
		major_queue.push(d);
		/*把辅助的队列中元素压入主要队列中*/
		while(!assist_queue.empty())
		{
			major_queue.push(assist_queue.front());
			assist_queue.pop();
		}
	}
	void Pop()
	{
		if(!major_queue.empty())
		{
			cout<<major_queue.front()<<" ";
			major_queue.pop();
		}
		else
		{
			cout<<endl<<"队列已空!!";
		}
		cout<<endl;
	}
	T& Top()
	{
		return major_queue.front();
	}
	int Size()
	{
		return major_queue.size();
	}
	bool Empty()
	{
		return major_queue.empty();
	}
private:
	queue<T> major_queue;
	queue<T> assist_queue;
};

void Test()
{
	Stack<int> st;
	st.Push(1);
	st.Push(2);
	st.Push(3);
	st.Push(4);
	cout<<st.Top()<<endl;
	cout<<st.Size()<<endl;
	cout<<st.Empty()<<endl;
}

int main()
{
	Test();
	return 0;
}
