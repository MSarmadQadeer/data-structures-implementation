#include <iostream>
#include "LinkedList.cpp"
#include "ArrayList.cpp"

int main()
{
    int opt;
    int x;
    ArrayList arrayList;
    LinkedList linkedList;
    do
    {
        std::cout << std::endl;
        std::cout << "---<<< ARRAY >>>---" << std::endl;
        std::cout << "1 To Create Array" << std::endl;
        std::cout << "2 To Display Array" << std::endl;
        std::cout << "--- SEARCHING ARRAY ---" << std::endl;
        std::cout << "3 To Search value by linearRecursiveSearch in Array" << std::endl;
        std::cout << "4 To Search value by binaryRecursiveSearch in Array" << std::endl;
        std::cout << "5 To Search value by binaryIterativeSearch in Array" << std::endl;
        std::cout << "--- SORTING ARRAY ---" << std::endl;
        std::cout << "6 To Sort values by bubbleSortIteratively in Array" << std::endl;
        std::cout << "7 To Sort values by bubbleSortRecursively in Array" << std::endl;
        std::cout << "8 To Sort values by insertionSortIteratively in Array" << std::endl;
        std::cout << "9 To Sort values by insertionSortRecursively in Array" << std::endl;
        std::cout << "10 To Sort values by selectionSortIteratively in Array" << std::endl;
        std::cout << "11 To Sort values by selectionSortRecursively in Array" << std::endl;
        std::cout << "12 To Sort values by mergeSortIteratively in Array" << std::endl;
        std::cout << "13 To Sort values by mergeSortRecursively in Array" << std::endl;
        std::cout << "---<<< LINKED LIST >>>---" << std::endl;
        std::cout << "14 To Create Linked List" << std::endl;
        std::cout << "15 To Display Linked List" << std::endl;
        std::cout << "16 To Append Linked List" << std::endl;
        std::cout << "--- SEARCHING LINKED LIST ---" << std::endl;
        std::cout << "17 To Search value by linearRecursiveSearch in Linked List" << std::endl;
        std::cout << "--- SORTING LINKED LIST ---" << std::endl;
        std::cout << "18 To Sort values by bubbleSortIteratively in Linked List" << std::endl;
        std::cout << "19 To Sort values by insertionSortIteratively in Linked List" << std::endl;
        std::cout << "20 To Sort values by selectionSortIteratively in Linked List" << std::endl;

        std::cout << "0 To Exit" << std::endl;
        std::cout << "Enter Your Option: ";
        std::cin >> opt;

        switch (opt)
        {
        case 0:
            break;
        case 1:
            arrayList.create();
            break;
        case 2:
            arrayList.display();
            break;
        case 3:
            std::cout << "Enter Value : ";
            std::cin >> x;
            arrayList.linearRecursiveSearch(x);
            break;
        case 4:
            std::cout << "Enter Value : ";
            std::cin >> x;
            arrayList.binaryRecursiveSearch(x);
            break;
        case 5:
            std::cout << "Enter Value : ";
            std::cin >> x;
            arrayList.binaryIterativeSearch(x);
            break;
        case 6:
            arrayList.bubbleSortIteratively();
            break;
        case 7:
            arrayList.bubbleSortRecursively2();
            break;
        case 8:
            arrayList.insertionSortIteratively();
            break;
        case 9:
            arrayList.insertionSortRecursively();
            break;
        case 10:
            arrayList.selectionSortIteratively();
            break;
        case 11:
            arrayList.selectionSortRecursively();
            break;
        case 12:
            arrayList.mergeSortIteratively();
            break;
        case 13:
            arrayList.mergeSortRecursively(0, arrayList.getSize() - 1);
            break;
        case 14:
            linkedList.create();
            break;
        case 15:
            linkedList.display();
            break;
        case 16:
            std::cout << "Enter Value : ";
            std::cin >> x;
            linkedList.append(x);
            break;
        case 17:
            std::cout << "Enter Value : ";
            std::cin >> x;
            linkedList.linearRecursiveSearch(x);
            break;
        case 18:
            linkedList.bubbleSortIteratively();
            break;
        case 19:
            linkedList.insertionSortIteratively();
            break;
        case 20:
            linkedList.selectionSortIteratively();
            break;
        default:
            std::cout << "Wrong option" << std::endl;
        }
    } while (opt != 0);

    return 0;
}