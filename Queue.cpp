#include<iostream>
using namespace std;

template<class Type>
class Queue
{
public:
	Queue()
	{
		front = -1;
		rear = -1;
		maxSize = 100;
		arr = new Type[maxSize];
	}
	void enqueue(Type data)
	{
		if (full())
			cout << "Queue is full!\n";
		else
		{
			if (front == -1)
				front = 0;
			rear++;
			arr[rear] = data;
		}
	}
	void dequeue()
	{
		if (empty()==true)
			cout << "Queue is empty!\n";
		else
		{
			front++;
			if (front > rear)
				front = rear = -1;
			
		}
	}
	bool full()
	{
		if (front == 0 && rear == maxSize - 1)
			return true;
		else
			return false;
	}
	bool empty()
	{
		if (front == -1)
			return true;
		else 
			return false;
	}
	Type peek()
	{
		return arr[front];
	}
	~Queue()
	{
		delete[] arr;
	}
private:
	Type* arr;
	int front;
	int rear;
	int maxSize;
};

template <class Type>
void showQueue(Queue <Type> &obj)
{
	while (obj.empty()!=true)
	{
		cout << obj.peek() << " ";
		obj.dequeue();
	}
	cout << endl;
}

int main()
{
	Queue<int>obj;
	obj.enqueue(1);
	obj.enqueue(2);
	obj.enqueue(3);
	obj.enqueue(4);
	showQueue(obj);

	system("pause");
	return 0;
}