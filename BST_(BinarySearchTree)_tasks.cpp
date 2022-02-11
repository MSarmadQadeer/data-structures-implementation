#include <Limits.h>
#include <iostream>

struct Node
{
    int num;
    Node *l_child = NULL;
    Node *r_child = NULL;
};

Node *root = NULL;

void insert(Node *Root, int num)
{
    Node *current = new Node;
    current->num = num;
    if (root == NULL)
    {
        root = current;
    }
    else
    {
        Node *p = Root;
        Node *o;
        //*o is created to Follow *p
        while (p)
        {
            o = p;
            if (current->num > p->num)
                p = p->r_child;
            else if (current->num < p->num)
                p = p->l_child;
            else if (current->num == p->num)
                return;
        }
        if (o->num > current->num)
            o->l_child = current;
        else
            o->r_child = current;
    }
}

int min(Node *Root)
{
    if (Root == NULL)
        return -1;
    Node *p = Root;
    Node *o;
    //*o is created to Follow *p
    while (p)
    {
        o = p;
        p = p->l_child;
    }
    return o->num;
    //*o has the address of left-most Node
}

int max(Node *Root)
{
    if (Root == NULL)
        return -1;
    Node *p = Root;
    Node *o;
    //*o is created to Follow *p
    while (p)
    {
        o = p;
        p = p->r_child;
    }
    return o->num;
    //*o has the address of right-most Node
}

Node *search(Node *Root, int num)
{
    Node *p = Root;
    while (p)
    {
        if (p->num == num)
            return p;
        else if (p->num > num)
            p = p->l_child;
        else
            p = p->r_child;
    }
    return NULL;
}

void preOrder(Node *Root)
{
    if (Root)
    {
        std::cout << Root->num << "  ";
        preOrder(Root->l_child);
        preOrder(Root->r_child);
    }
}

void postOrder(Node *Root)
{
    if (Root)
    {
        postOrder(Root->l_child);
        postOrder(Root->r_child);
        std::cout << Root->num << "  ";
    }
}

void inOrder(Node *Root)
{
    if (Root)
    {
        inOrder(Root->l_child);
        std::cout << Root->num << "  ";
        inOrder(Root->r_child);
    }
}

Node *inOrderPredecessor(Node *p)
{
    while (p && p->r_child != NULL)
        p = p->r_child;

    return p;
}
Node *inOrderSuccessor(Node *p)
{
    while (p && p->l_child != NULL)
        p = p->l_child;

    return p;
}
Node *Delete(Node *p, int key)
{

    struct Node *successor;

    if (p == NULL)
        return NULL;
    if (p->l_child == NULL && p->r_child == NULL && p->num == key)
    {
        if (p == root)
            root = NULL;
        delete (p);
        return NULL;
    }

    if (key < p->num)
        p->l_child = Delete(p->l_child, key);
    else if (key > p->num)
        p->r_child = Delete(p->r_child, key);
    else
    {
        if (p->r_child)
        {
            successor = inOrderPredecessor(p->l_child);
            p->num = successor->num;
            p->l_child = Delete(p->l_child, successor->num);
        }
        else
        {
            successor = inOrderSuccessor(p->r_child);
            p->num = successor->num;
            p->r_child = Delete(p->r_child, successor->num);
        }
    }
    return p;
}

int main()
{
    int opt;
    int x;
    Node *a;
    do
    {
        std::cout << std::endl;
        std::cout << "1 To Insert Value" << std::endl;
        std::cout << "2 To Find Min Value" << std::endl;
        std::cout << "3 To Find Max Value" << std::endl;
        std::cout << "4 To Search Value" << std::endl;
        std::cout << "5 To Display in Pre Order" << std::endl;
        std::cout << "6 To Display in In Order" << std::endl;
        std::cout << "7 To Display in Post Order" << std::endl;
        std::cout << "8 To Delete Value" << std::endl;
        std::cout << "0 To Exit" << std::endl;
        std::cout << "Enter Your Option: ";
        std::cin >> opt;

        switch (opt)
        {
        case 1:
            std::cout << "Enter Value : ";
            std::cin >> x;
            insert(root, x);
            break;
        case 2:
            x = min(root);
            std::cout << "Minimum Value is " << x << std::endl;
            break;
        case 3:
            x = max(root);
            std::cout << "Maximum Value is " << x << std::endl;
            break;
        case 4:
            std::cout << "Enter Value : ";
            std::cin >> x;
            a = search(root, x);
            if (a)
                std::cout << "FOUND" << std::endl;
            else
                std::cout << "NOT FOUND" << std::endl;
            break;
        case 5:
            preOrder(root);
            break;
        case 6:
            inOrder(root);
            break;
        case 7:
            postOrder(root);
            break;
        case 8:
            std::cout << "Enter Value : ";
            std::cin >> x;
            Delete(root, x);
            break;
        default:
            std::cout << "Wrong option" << std::endl;
        }
    } while (opt != 0);

    return 0;
}
