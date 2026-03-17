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
	{
		a = tmp;
	}
	else
	{
		Node* p = a;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = tmp;
	}
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->data << "->";
		a = a->next;
	}
	if (a == nullptr)
		cout << "Null";
}
Node* copy(Node* a)
{
	Node* tmphead = makeNode(a->data);
	Node* tmptail = tmphead;
	a = a->next;
	while (a != nullptr)
	{
		tmptail->next = makeNode(a->data);
		tmptail = tmptail->next;
		a = a->next;
	}
	return tmphead;
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
Node* divideNode(Node* a,int k)
{
	Node* p = a;
	int n = size(a);
	while (n > 1)
	{
		int num;
		if (n % k != 0)
			num = (n / k) + 1;
		else
			num = n / k;
		Node* head = new Node();
		Node* tail = head;
		for (int i = 1; i < num; i++)
		{
			tail->next = new Node();
			tail = tail->next;
		}
		Node* cur = head;
		while (p != nullptr)
		{
			int max = -1000000;
			for (int i = 0; i < k; i++)
			{
				if (p->data > max)
				{
					max = p->data;
				}
				p = p->next;
				if (p == nullptr)
					break;
			}
			cur->data = max;
			cur = cur->next;
		}
		p = head;
		n = num;
	}
	return p;
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
		cout << "3.Merging every group of K consecutive nodes." << endl;
		int n;
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
		{
			int x;
			cout << "Nhap gia tri can them: ";
				cin >> x;
				addNode(a, x);
		}
		else if (n == 2)
		{
			printLList(a);
		}
		else if (n == 3)
		{
			int k;
			cout << "Nhap so o can chia: ";
			cin >> k;
			Node* acopy = copy(a);
			Node* dNode = divideNode(acopy,k);
			printLList(dNode);
		}
	}
}
