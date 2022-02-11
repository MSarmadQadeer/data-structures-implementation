#include <iostream>
using namespace std;

void insert_end();
void display();

struct stu
{
	int id;
	stu *next = NULL;
};
stu *first = NULL;
stu *last = NULL;

int main()
{
	int opt;
	do
	{
		cout << "\n\n Enter 1 for insertion  ";
		cout << "\n Enter 2 to display ";
		cout << "\n Enter 0 to exit";
		cout << "\n Enter your option: ";
		cin >> opt;
		switch (opt)
		{
		case 0:
			break;
		case 1:
			insert_end();
			break;
		case 2:
			display();
			break;
		default:
			cout << "\n Wrong option";
		}
	} while (opt != 0);

	return 0;
}

void insert_end()
{
	cout << "\n Insert at end method: ";

	stu *curr;
	curr = new stu;
	curr->next = NULL;

	cout << "\n Enter id:   ";
	cin >> curr->id;

	if (first == NULL)
	{
		cout << "\n Before this insertion the list is empty";
		first = last = curr;
		cout << "\n After insertion first points: " << first->id;
		cout << "\n After insertion last points: " << last->id;
	}
	else
	{
		cout << "\n First pointer points to:  " << first->id;
		cout << "\n Last pointer points to:  " << last->id;
		last->next = curr;
		last = curr;
		cout << "\n After insertion:";
		cout << "\n First pointer points to:  " << first->id;
		cout << "\n Last pointer points to:  " << last->id;
	}
}
void display()
{
	cout << "\n Display method: ";
	stu *p;
	p = first;
	while (p != NULL)
	{
		cout << "\n ID is:  " << p->id;
		p = p->next;
	}
}
