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
void spilitLList(Node* a)
{
	Node* oddhead = nullptr;
	Node* oddtail = nullptr;
	Node* evenhead = nullptr;
	Node* eventail = nullptr;
	Node* cur = a;
	while (cur != nullptr)
	{
		Node* nxt = cur->next;
		cur->next = nullptr;
		if (cur->data % 2 != 0)
		{
			if (oddhead == nullptr)
			{
				oddhead = cur;
				oddtail = cur;
			}
			else
			{
				oddtail->next = cur;
				oddtail = oddtail->next;
			}
		}
		else
		{
			if (evenhead == nullptr)
			{
				evenhead = cur;
				eventail = cur;
			}
			else
			{
				eventail->next = cur;
				eventail = eventail->next;
			}
		}
		cur = nxt;
	}
	Node* p1 = oddhead;
	Node* p2 = evenhead;
	cout << "Odd list: ";
	while (p1 != nullptr)
	{
		cout << p1->data << " ";
		p1 = p1->next;
	}
	cout << endl;
	cout << "Even list: ";
	while (p2 != nullptr)
	{
		cout << p2->data << " ";
		p2 = p2->next;
	}
}
int main()
{
	Node* a = nullptr;
	while (true)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1.Create a singly linked list from given integer values." << endl;
		cout << "2. Split a linked list into two new lists: one containing nodes with odd values, and one containing nodes with even values" << endl;
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
			spilitLList(a);
	}
	return 0;
}