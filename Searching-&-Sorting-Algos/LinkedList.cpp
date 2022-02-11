#include <iostream>
class LinkedList
{
    struct Node
    {
        int num;
        Node *next = NULL;
    };

private:
    Node *first;
    Node *last;

public:
    LinkedList()
    {
    }

    void create()
    {
        first = NULL;
        last = NULL;

        std::cout << "How many Nodes you Need ? ";
        int numberOfNodes;
        std::cin >> numberOfNodes;
        for (int i = 0; i < numberOfNodes; i++)
        {
            std::cout << "Enter value in node <" << i + 1 << "> :";

            Node *current = new Node();
            std::cin >> current->num;

            if (first == NULL)
            {
                first = last = current;
            }
            else
            {
                last->next = current;
                last = last->next;
            }
        }
    }

    void insertionSortIteratively()
    {
        Node *p = first->next;
        while (p)
        {
            Node *q = first;
            while (q->next != p)
                q = q->next;
            if (q->next == p && q->num < p->num)
            {
                p = p->next;
                continue;
            }
            Node *track_q = NULL;
            while (q->num > p->num && q != first)
            {
                track_q = q;
                q = first;
                while (q->next != track_q)
                    q = q->next;
            }
            Node *extra = first;
            while (extra->next != p)
                extra = extra->next;
            if (p == last)
                last = extra;
            extra->next = p->next;
            extra = p;
            p = p->next;
            if (q == first && q->num > extra->num)
            {
                extra->next = q;
                first = extra;
            }
            else
            {
                extra->next = q->next;
                q->next = extra;
            }
        }
    }

    void selectionSortIteratively()
    {
        Node *i = first;
        Node *j, *k;
        while (i->next != last)
        {
            j = k = i;
            while (j)
            {
                if (j->num < k->num)
                    k = j;
                j = j->next;
            }
            if (i == k)
            {
                i = i->next;
            }
            else if (i->next == k && i == first)
            {
                i->next = k->next;
                k->next = i;
                first = k;
            }
            else if (i == first)
            {
                Node *tracer = first;
                while (tracer->next != k)
                    tracer = tracer->next;
                Node *k_next = k->next;

                tracer->next = i;
                k->next = i->next;
                i->next = k_next;

                if (last == k)
                    last = i;
                i = k->next;
                first = k;
            }
            else if (i->next == k)
            {
                i->next = k->next;
                k->next = i;
                Node *tracer = first;
                while (tracer->next != i)
                    tracer = tracer->next;
                tracer->next = k;
                if (last == k)
                    last = i;
            }
            else
            {
                Node *k_next = k->next;
                Node *tracer = first;
                while (tracer->next != k)
                    tracer = tracer->next;
                tracer->next = i;
                k->next = i->next;
                i->next = k_next;

                tracer = first;
                while (tracer->next != i)
                    tracer = tracer->next;
                tracer->next = k;
                if (last == k)
                    last = i;
                i = k->next;
            }
        }
    }

    void bubbleSortIteratively()
    {
        for (Node *p = first; p != last; p = p->next)
        {
            int flag = 0;
            for (Node *q = first; q != last;)
            {
                if (q->num > q->next->num)
                {
                    Node *q_next = q->next;
                    q->next = q_next->next;
                    q_next->next = q;
                    if (q != first)
                    {
                        Node *tracer = first;
                        while (tracer->next != q)
                            tracer = tracer->next;
                        tracer->next = q_next;
                    }
                    if (p == q)
                        p = q_next;
                    if (first == q)
                        first = q_next;
                    if (last == q_next)
                        last = q;
                    flag++;
                }
                else
                    q = q->next;
            }
            if (flag == 0)
                break;
        }
    }

    void append(int a)
    {
        Node *current = new Node();
        current->num = a;

        if (first == NULL)
        {
            first = last = current;
        }
        else
        {
            last->next = current;
            last = last->next;
        }
    }

    void display()
    {
        Node *p = first;
        while (p)
        {
            std::cout << p->num << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }

    void linearRecursiveSearch(int element)
    {
        static Node *pointer = first;
        if (pointer->num == element)
            std::cout << "< FOUND >" << std::endl;

        else if (pointer->next == NULL)
            std::cout << "< NOT FOUND >" << std::endl;

        else
        {
            pointer = pointer->next;
            linearRecursiveSearch(element);
        }
    }
};
