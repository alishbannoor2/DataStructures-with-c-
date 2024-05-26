#include<iostream>
#include<string>
using namespace std;

template<class Type>
class Node{
public:
	Node(Type d){ data = d; next = prev = nullptr; }
	Type data;
	Node<Type>* prev;
	Node<Type>* next;
};

template<class Type>
class DoublyLinkedList{
public:
	DoublyLinkedList(){}
	//front  insertion
	void insertAtFront(Type d)
	{
		Node<Type>* new_node = new Node<Type>(d);
		new_node->prev = nullptr;
		if (head==nullptr)
			new_node->next = nullptr;
		else
			new_node->next = head;
		head = new_node;
	}
	//display function
	void display()
	{
		Node<Type>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data<< " ";
			temp = temp->next;
		}
		cout << "\nFinish display?";
		string q;
		cin>>q;
	}
	// end insertion
	void insertAtEnd(Type d)
	{
		Node<Type>* new_node = new Node<Type>(d);
		new_node->next = nullptr;
		if (head == nullptr)
		{
			new_node->prev = nullptr;
			head = new_node;
		}
		else
		{
			Node<Type>* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			new_node->prev = temp;
			temp->next = new_node;
		}
	}
	//front remove
	Type removeFromFront()
	{
		Node<Type>* temp = head;
		if (head == nullptr)
		{
			cout << "List is empty\n";
			//exit();
		}
		else
		{
			head = temp->next;
			temp->next->prev = nullptr;
			temp->next = nullptr;
			temp->prev = nullptr;
			return temp->data;
		}
	}
	//end remove
	Type removeFromEnd()
	{
		Node<Type>* temp = head;
		if (head == nullptr)
		{
			cout << "List is empty\n";
			//exit;
		}
		else
		{
			Node<Type>* temp = head;
			while (temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->prev->next = nullptr;
			temp->prev=nullptr;
			return temp->data;
		}
	}
	//insertATIndex
	void insertAt(int index, Type d)
	{
		Node<Type>* new_node = new Node<Type>(d);
		Node<Type>* temp = head;
		for (int i = 0; i < index-1; i++)
		{
			temp = temp->next;
		}
		new_node->next = temp->next;
		new_node->prev = temp;
		if (temp->next != nullptr)
		{
			temp->next->prev = new_node;
		}
		temp->next = new_node;
	}
	//search
	bool search(Type d)
	{
		Node<Type>* temp = head;
		while (temp->data != d)
		{
			temp = temp->next;
		}
		if (temp->data == d)
			return true;
		else
			return false;
	}
private:
	Node <Type> *head=nullptr;
};

void displayMenu()
{
	cout << "Select operations you want to do:\n"
		"1. Insert at Front\n"
		"2. Insert at End\n"
		"3. Remove from Front\n"
		"4. Remove from End\n"
		"5. Insert at Index\n"
		"6. Search value\n"
		"7. Display linked list\n"
		"8. Quit\n";
}

int main()
{
	int choice;
	DoublyLinkedList<int> list;
	int val;
	do{
	displayMenu();
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "Enter value to insert:";
		cin >> val;
		list.insertAtFront(val);
		break;
	case 2:
		cout << "Enter value to insert:";
		cin >> val;
		list.insertAtEnd(val);
		break;
	case 3:
		cout << "\nElement removed from front: " << list.removeFromFront() << endl;
		break;
	case 4:
		cout << "\nElement removed from end: " << list.removeFromEnd() << endl;
		break;
	case 5:
		cout << "Enter index to insert at: ";
		int index;
		cin >> index;
		cout << "Enter value to insert:";
		cin >> val;
		list.insertAt(index, val);
		cout << "Inserted!\n";
		break;
	case 6:
		cout << "Enter value to search:";
		cin >> val;
		cout << "Is it in list? ";
		cout << ((list.search(val) == 1) ? "Yes\n" : "No\n");
		break;
	case 7:
		list.display();
		break;
	case 8:
		break;
	}
	system("cls");
	} while (choice != 8);
	cout << endl;

	system("pause");
	return 0;
}