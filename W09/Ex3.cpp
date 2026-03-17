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
Node* copy(Node* source)
{
	Node* tmphead = makeNode(source->data);
	Node* tmptail = tmphead;
	source = source->next;
	while (source != nullptr)
	{
		tmptail->next = makeNode(source->data);
		tmptail = tmptail->next;
		source = source->next;
	}
	return tmphead;
}
void addNode(Node*& a,int x)
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
Node* concatenateNode(Node* a, Node* b)
{
	Node* phead = a;
	Node* ptail = a;
	ptail = ptail->next;
	while (ptail->next != nullptr)
		ptail = ptail->next;
	ptail->next = b;
	return phead;
}
Node* mergeAlternate(Node* a, Node* b)
{
	Node* tmphead = a;
	Node* tmptail = a;
	a = a->next;
	while (a != nullptr || b != nullptr)
	{
		if (b != nullptr)
		{
			tmptail->next = b;
			tmptail = tmptail->next;
			b = b->next;
		}
		if (a != nullptr)
		{
			tmptail->next = a;
			tmptail = tmptail->next;
			a = a->next;
		}
	}
	return tmphead;

}
Node* mergeOddEven(Node* a, Node* b)
{
	Node* oddhead = nullptr;
	Node* oddtail = nullptr;
	Node* evenhead = nullptr;
	Node* eventail = nullptr;
	while (a != nullptr)
	{
		Node* nxt = a->next;
		a->next = nullptr;
		if (a->data % 2 == 0)
		{
			if (evenhead == nullptr)
			{
				evenhead = a;
				eventail = a;
			}
			else
			{
				eventail->next = a;
				eventail = eventail->next;
			}
		}
		else
		{
			if (oddhead == nullptr)
			{
				oddhead = a;
				oddtail = a;
			}
			else
			{
				oddtail->next = a;
				oddtail = oddtail->next;
			}
		}
		a = nxt;
	}
	while (b != nullptr)
	{
		Node* nxt = b->next;
		b->next = nullptr;
		if (b->data % 2 == 0)
		{
			if (evenhead == nullptr)
			{
				evenhead = b;
				eventail = b;
			}
			else
			{
				eventail->next = b;
				eventail = eventail->next;
			}
		}
		else
		{
			if (oddhead == nullptr)
			{
				oddhead = b;
				oddtail = b;
			}
			else
			{
				oddtail->next = b;
				oddtail = oddtail->next;
			}
		}
		b = nxt;
	}
	oddtail->next = evenhead;
	return oddhead;
	
}
Node* mergeSort(Node* a, Node* b)
{
	Node* tmphead = nullptr;
	Node* tmptail = nullptr;
	while (a != nullptr && b != nullptr)
	{
		if (a->data < b->data)
		{
			if (tmphead == nullptr)
			{
				tmphead = a;
				tmptail = a;
				a = a->next;
			}
			else
			{
				tmptail->next = a;
				tmptail = tmptail->next;
				a = a->next;
			}
		}
		else
		{
			if (tmphead == nullptr)
			{
				tmphead = b;
				tmptail = b;
				b = b->next;
			}
			else
			{
				tmptail->next = b;
				tmptail = tmptail->next;
				b = b->next;
			}
		}
	}
	if (a == nullptr&&b!=nullptr)
	{
		for (Node* q=b; q->next != nullptr; q = q->next)
		{
			for (Node* p = q->next; p != nullptr; p = p->next)
			{
				if (q->data > p->data)
				{
					int tmp = q->data;
					q->data = p->data;
					p->data = tmp;
				}
			}
		}
		while (b != nullptr)
		{
			tmptail->next = b;
			tmptail = tmptail->next;
			b = b->next;
		}
	}
	if (b == nullptr&&a!=nullptr)
	{
		for (Node* q = a; q->next != nullptr; q = q->next)
		{
			for (Node* p = q->next; p != nullptr; p = p->next)
			{
				if (q->data > p->data)
				{
					int tmp = q->data;
					q->data = p->data;
					p->data = tmp;
				}
			}
		}
		while (a != nullptr)
		{
			tmptail->next = a;
			tmptail = tmptail->next;
			a = a->next;
		}

	}
	return tmphead;
}
void printLList(Node* a)
{
	while (a != nullptr)
	{
		cout << a->data << " ";
		a = a->next;
	}
}
int main()
{
	Node* a = nullptr;
	Node* b = nullptr;
	while (1)
	{
		cout << endl;
		cout << "0. Exit" << endl;
		cout << "1.Create singly linked list a from given integer values." << endl;
		cout << "2.Create singly linked list b from given integer values. " << endl;
		cout << "3. Print list 1" << endl;
		cout << "4. Print list 2" << endl;
		cout << "5.Concatenate the two singly linked lists." << endl;
		cout << "6.Merge the two singly linked lists so that elements in list 1 and list 2 alternate." << endl;
		cout << "7.Merge the two singly linked lists so that the final list has odd elements first and even elements last." << endl;
		cout << "8.Merge the two singly linked lists so that the resulting list is sorted in ascending order." << endl;
		int n;
		cout << "Nhap lua chon: ";
		cin >> n;
		if (n == 0)
			break;
		else if (n == 1)
		{
			int x;
			cout << "Nhap gia tri can them vao list a: ";
			cin >> x;
			addNode(a, x);
		}
		else if (n == 2)
		{
			int x;
			cout << "Nhap gia tri can them vao list b: ";
			cin >> x;
			addNode(b, x);
		}
		else if (n == 3)
		{
			cout << "List a: ";
			printLList(a);
		}
		else if (n == 4)
		{
			cout << "List b: ";
			printLList(b);
		}
		else if (n == 5)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* clist = concatenateNode(acopy, bcopy);
			cout << "List a: ";
			printLList(a);
			cout << endl;
			cout << "List b: ";
			printLList(b);
			cout << endl;
			cout << "Sau khi gop: " << endl;
			printLList(clist);
		}
		else if (n == 6)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* alist = mergeAlternate(acopy, bcopy);
			cout << "List a: ";
			printLList(a);
			cout << endl;
			cout << "List b: ";
			printLList(b);
			cout << endl;
			cout << "Sau khi gop: " << endl;
			printLList(alist);
		}
		else if (n == 7)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* oelist = mergeOddEven(acopy, bcopy);
			cout << "List a: ";
			printLList(a);
			cout << endl;
			cout << "List b: ";
			printLList(b);
			cout << endl;
			cout << "Sau khi gop: " << endl;
			printLList(oelist);
		}
		else if (n == 8)
		{
			Node* acopy = copy(a);
			Node* bcopy = copy(b);
			Node* slist = mergeSort(acopy, bcopy);
			cout << "List a: ";
			printLList(a);
			cout << endl;
			cout << "List b: ";
			printLList(b);
			cout << endl;
			cout << "Sau khi gop: " << endl;
			printLList(slist);
		}
	}
	return 0;
}
