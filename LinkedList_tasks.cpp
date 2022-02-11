#include <iostream>
using namespace std;

struct Record
{
	int id;
	struct Record *next = NULL;
};

struct Record *first = NULL;
struct Record *last = NULL;

void create()
{
	int n;
	cout << "how many Nodes you wanna insert ?";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		struct Record *r = new Record;
		cout << "Enter : ";
		cin >> r->id;
		if (first == NULL)
			first = last = r;
		else
		{
			last->next = r;
			last = r;
		}
	}
}

void display()
{
	struct Record *p = first;
	while (p)
	{
		cout << p->id << " ";
		p = p->next;
	}
}

void josephusProblem()
{
	last->next = first;
	struct Record *head = first;
	struct Record *p;
	while (head->next != head)
	{
		p = head->next;
		head->next = head->next->next;
		head = head->next;
		delete p;
	}
	cout << "Id of Winner Node is : " << head->id;
	first = last = head;
}

void palindrome()
{
	struct Record *p = first;
	struct Record *q = last;
	bool palindrome = true;
	while (p->id == q->id)
	{
		struct Record *n = p;
		if (p == q || p->next == q)
			break;
		while (n->next != q)
			n = n->next;
		p = p->next;
		q = n;
	}
	if (p->id != q->id)
		palindrome = false;
	if (palindrome)
		cout << "IT IS A PALINDROME";
	else
		cout << "IT IS NOT A PALINDROME";
}

void reverse()
{
	struct Record *p = first;
	struct Record *q = last;
	while (first != last)
	{
		p = first;

		while (p->next != last)
			p = p->next;

		last->next = p;
		p->next = NULL;
		last = p;
	}
	first = q;
}

void swapNodes()
{
	int node1, node2;
	cout << "Enter 2 Nodes that you wanna Swap : ";
	cin >> node1;
	cin >> node2;
	struct Record *a, *b, *c, *p = first;
	int counter = 1;
	while (p)
	{
		if (counter + 1 == node1 && node1 != 1)
			a = p;
		if (counter == node1)
			b = p;
		if (counter == node2)
			c = p;
		counter++;
		p = p->next;
	}
	if (node1 != 1 && node2 != 1)
	{
		p = b->next;
		b->next = c->next;
		c->next = p;
		a->next = c;
		while (p->next != c)
			p = p->next;
		p->next = b;
	}
	else
	{
		p = b->next;
		b->next = c->next;
		c->next = p;
		while (p->next != c)
			p = p->next;
		p->next = b;
		first = c;
	}
}

void swapValues()
{
	int node1, node2, value;
	cout << "Enter 2 Nodes whom values you wanna Swap : ";
	cin >> node1;
	cin >> node2;
	int counter = 1;
	struct Record *p = first, *a, *b;
	while (p)
	{
		if (counter == node1)
			a = p;
		if (counter == node2)
			b = p;
		counter++;
		p = p->next;
	}
	value = a->id;
	a->id = b->id;
	b->id = value;
}

int main()
{
	create();
	int opt;
	do
	{
		cout << "\n Enter 1 for Josephus Problem  ";
		cout << "\n Enter 2 to Reverse ";
		cout << "\n Enter 3 to check Palindrome ";
		cout << "\n Enter 4 to Swap values ";
		cout << "\n Enter 5 to Swap Nodes";
		cout << "\n Enter 6 to Display";
		cout << "\n Enter 7 to Insert Nodes";
		cout << "\n Enter 0 to Exit";
		cout << "\n Enter your option: ";
		cin >> opt;

		switch (opt)
		{
		case 0:
			break;
		case 1:
			josephusProblem();
			break;
		case 2:
			reverse();
			break;
		case 3:
			palindrome();
			break;
		case 4:
			swapValues();
			break;
		case 5:
			swapNodes();
			break;
		case 6:
			display();
			break;
		case 7:
			create();
			break;
		default:
			cout << "\n Wrong option";
		}
	} while (opt != 0);

	return 0;
}
