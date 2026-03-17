#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* makeNode(int x)
{
	Node* tmp = new Node();
	tmp->data = x;
	tmp->next = nullptr;
	return tmp;
}
void addNode(Node*& a, int x)
{
	Node* tmp = makeNode(x);
	if (a == nullptr)
		a = tmp;
	else
	{
		Node* p = a;
		while (p->next != nullptr)
			p = p->next;
		p->next = tmp;
	}
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
}
int size(Node* a)
{
	int count = 0;
	while (a != nullptr)
	{
		count++;
		a = a->next;
	}
	return count;
}
void insertNode(Node*& a, int x, int pos)
{
	Node* tmp = makeNode(x);
	if (pos <= 0 || pos > size(a) + 1)
	{
		cout << "Invalid position";
		return;
	}
	if (pos == 1)
	{
		tmp->next = a;
		a = tmp;
		return;
	}
	if (pos == size(a) + 1)
	{
		addNode(a, x);
		return;
	}
	else
	{
		Node* p = a;
		for (int i = 1; i < pos - 1; i++)
		{
			p = p->next;
		}
		tmp->next = p->next;
		p->next = tmp;
		return;
	}
}
void findNode(Node* a, int value)
{
	for (int i = 1; i <= size(a); i++)
	{
		if (a->data == value)
		{
			cout << "Gia tri can tim o node thu: " << i;
			return;
		}
	}
	cout << "Khong co";
}
void deleteNodeAtPosition(Node*& a, int pos)
{
	if (pos <= 0 || pos > size(a))
	{
		cout << "Invalid position";
		return;
	}
	if (size(a) == 1)
	{
		a = nullptr;
		return;
	}
	if (pos == 1)
	{
		Node* tmp = a;
		a = a->next;
		delete tmp;
		return;
	}
	if (pos == size(a))
	{
		Node* pre = nullptr;
		Node* cur = a;
		while (cur->next != nullptr)
		{
			pre = cur;
			cur = cur->next;
		}
		Node* tmp = cur;
		pre->next = nullptr;
		delete tmp;
		return;
	}
	Node* pre = nullptr;
	Node* cur = a;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	Node* tmp = cur;
	pre->next = cur->next;
	delete tmp;
}
void deleteNodeHaveValue(Node*& a, int x)
{
	Node* pre = nullptr;
	Node* cur = a;
	while (cur != nullptr)
	{
		if (cur->data == x)
		{
			if (pre == nullptr)
			{
				Node* tmp = a;
				a=a->next;
				cur = a;
				delete tmp;
			}
			else
			{
				Node* tmp = cur;
				pre->next = cur->next;
				cur = cur->next;
				delete tmp;
			}
		}
		else
		{
			pre = cur;
			cur = cur->next;
		}
		
	}
}
void updateNode(Node* &a,int x,int pos)
{
	Node* p = a;
	for (int i = 1; i < pos; i++)
		p = p->next;
	p->data = x;
}
void reverseList(Node* &a)
{
	Node* pre = nullptr;
	Node* cur = a;
	while (cur != nullptr)
	{
		Node* next = cur->next;
		cur->next = pre;
		pre = cur;
		cur = next;
	}
	a = pre;
}
void sortList(Node*& a)
{
	for (Node* p = a; p->next != nullptr; p = p->next)
	{
		for (Node* q = p->next; q!= nullptr; q = q->next)
		{
			if (q->data < p->data)
			{
				int min = q->data;
				q->data = p->data;
				p->data = min;
			}

		}
	}
}
void removeDuplicated(Node*& a)
{
	Node* p1 = a;
	while (p1 != nullptr)
	{
		Node* pre = p1;
		Node* p2 = p1->next;
		while (p2 != nullptr)
		{
			if (p2->data == p1->data)
			{
				Node* tmp = p2;
				pre->next = p2->next;
				p2 = p2->next;
				delete tmp;
			}
			else
			{
				pre = p2;
				p2 = p2->next;
			}
		}
		p1 = p1->next;
	}

}
void rotateLeft(Node*& a,int k)
{
	for (int i = 1; i <= k; i++)
	{
		Node* p = a;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		Node* next = a->next;
		p->next = a;
		a->next = nullptr;
		a = next;
	}
}
void rotateRight(Node*& a, int k)
{
	for (int i = 1; i <= k; i++)
	{
		Node* pre = nullptr;
		Node* cur = a;
		while (cur->next != nullptr)
		{
			pre = cur;
			cur = cur->next;
		}
		cur->next = a;
		pre->next = nullptr;
		a = cur;
	}
}
bool isPalindrome(Node* right, Node*& left)
{
	if (right == nullptr)
		return true;
	bool check = isPalindrome(right->next, left);
	if (!check)
		return false;
	if (right->data != left->data)
		return false;
	left = left->next;
	return true;
}
int main()
{
	Node* a = nullptr;
	while (true)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1.Create a singly linked list from given integer values." << endl;
		cout << "2.Print the elements in the list." << endl;
		cout << "3.Count the number of elements in the linked list." << endl;
		cout << "4.Insert a node at an arbitrary position k in the singly linked list." << endl;
		cout << "5.Search for a value in the list." << endl;
		cout << "6.Delete a node at an arbitrary position k in the singly linked list." << endl;
		cout << "7.Delete a node containing a value (entered from the keyboard) in the singly linked list." << endl;
		cout << "8.Update the value of a node at any position in the singly linked list." << endl;
		cout << "9.Reverse the linked list."<< endl;
		cout << "10.Sort the singly linked list." << endl;
		cout << "11.Remove duplicate elements in the singly linked list." << endl;
		cout << "12.Rotate the linked list to the left by k times." << endl;
		cout << "13.Rotate the linked list to the right by k times." << endl;
		cout << "14.Check whether the linked list is a palindrome." << endl;
		int choice;
		cout << "Nhap lua chon: ";
		cin >> choice;
		if (choice == 0)
			break;
		else if (choice == 1)
		{
			int x;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			addNode(a, x);
		}
		else if (choice == 2)
			printLList(a);
		else if (choice == 3)
		{
			int nodesize = size(a);
			cout << "Kich thuoc linked list la: " << nodesize;
		}
		else if (choice == 4)
		{
			int pos;
			cout << "Nhap vi tri can them: ";
			cin >> pos;
			int x;
			cout << "Nhap gia tri can them: ";
			cin >> x;
			insertNode(a, x, pos);
		}
		else if (choice == 5)
		{
			int x;
			cout << "Nhap gia tri can tim: ";
			cin >> x;
			findNode(a, x);
		}
		else if (choice == 6)
		{
			int x;
			cout << "Nhap vi tri can xoa: ";
			cin >> x;
			deleteNodeAtPosition(a, x);
		}
		else if (choice == 7)
		{
			int x;
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			deleteNodeHaveValue(a, x);
		}
		else if (choice == 8)
		{
			int pos;
			cout << "Nhap vi tri can cap nhat: ";
			cin >> pos;
			int x;
			cout << "Nhap gia tri can cap nhat: ";
			cin >> x;
			updateNode(a, x, pos);
		}
		else if (choice == 9)
		{
			reverseList(a);
			printLList(a);
		}
		else if (choice == 10)
		{
			sortList(a);
		}
		else if (choice == 11)
		{
			removeDuplicated(a);
		}
		else if (choice == 12)
		{
			int x;
			cout << "Nhap so lan xoay: ";
			cin >> x;
			rotateLeft(a, x);
		}
		else if (choice == 13)
		{
			int x;
			cout << "Nhap so lan xoay: ";
			cin >> x;
			rotateRight(a, x);
		}
		else if (choice == 14)
		{
			if (isPalindrome(a, a))
				cout << "List is palindrome";
			else
				cout << "List is not palindrome";
		}

	}
	return 0;
}


