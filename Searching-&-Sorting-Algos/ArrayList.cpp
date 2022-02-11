#include <iostream>

class ArrayList
{
private:
    int *array;
    int size;

public:
    ArrayList()
    {
    }

    void create()
    {
        std::cout << "Enter Size of Array : ";
        std::cin >> size;
        array = new int[size];
        for (int i = 0; i < size; i++)
        {
            std::cout << "Enter value at index <" << i << "> :";
            std::cin >> array[i];
        }
    }

private:
    void swap(int &a, int &b)
    {
        int extra = a;
        a = b;
        b = extra;
    }

public:
    void bubbleSortIteratively()
    {
        for (int i = 0; i < size - 1; i++)
        {
            int flag = 0;
            for (int j = 0; j < size - 1 - i; j++)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                    flag++;
                }
            }
            if (flag == 0)
                break;
        }
    }

    void merge(int startIndex, int midIndex, int endIndex)
    {
        int i = startIndex;
        int mid = midIndex;
        int j = mid + 1;
        int k = startIndex;
        int *B = new int[endIndex + 1];
        while (i <= mid && j <= endIndex)
        {
            if (array[i] < array[j])
                B[k++] = array[i++];
            else
                B[k++] = array[j++];
        }
        while (i <= mid)
            B[k++] = array[i++];
        while (j <= endIndex)
            B[k++] = array[j++];
        for (i = startIndex; i <= endIndex; i++)
            array[i] = B[i];
    }

    void mergeSortRecursively(int startIndex, int endIndex)
    {
        if (startIndex < endIndex)
        {
            int mid = (startIndex + endIndex) / 2;
            mergeSortRecursively(startIndex, mid);
            mergeSortRecursively(mid + 1, endIndex);
            merge(startIndex, mid, endIndex);
        }
    }

    void mergeSortIteratively()
    {
        int p;
        for (p = 2; p < size; p *= 2)
        {
            for (int i = 0; i + p - 1 < size; i += p)
            {
                merge(i, (i + i + p - 1) / 2, i + p - 1);
            }
        }
        if (p / 2 < size)
            merge(0, p / 2 - 1, size - 1);
    }

    void selectionSortIteratively()
    {
        int j, k;
        for (int i = 0; i < size - 1; i++)
        {
            for (j = k = i; j < size; j++)
            {
                if (array[j] < array[k])
                    k = j;
            }
            swap(array[i], array[k]);
        }
    }

    void selectionSortRecursively()
    {
        static int i = 0;
        static int j = i, k = i;

        if (!(i < size - 1))
        {
            j = k = i = 0;
            return;
        }
        if (j < size)
        {
            if (array[j] < array[k])
                k = j;
            j++;
            selectionSortRecursively();
        }
        else
        {
            swap(array[i], array[k]);
            i++;
            j = k = i;
            selectionSortRecursively();
        }
    }

    void bubbleSortRecursively2()
    {
        static int i = 0;
        static int j = 0;
        static int flag = 0;

        if (!(i < size - 1) && !(j < size - 1 - i))
        {
            i = 0;
            j = 0;
            flag = 0;
            // RESETTING DONE
            return;
        }
        if (j < size - 1 - i)
        {
            if (array[j] > array[j + 1])
            {
                swap(array[j], array[j + 1]);
                flag++;
            }
            j++;
        }
        else
        {
            if (flag == 0)
                return;
            i++;
            j = 0;
            flag = 0;
        }
        bubbleSortRecursively2();
    }

    void bubbleSortRecursively()
    {
        static int i = 0;
        static int j = 0;
        static int flag = 0;
        if (i < size - 1)
        {
            if (j < size - 1 - i)
            {
                if (array[j] > array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                    flag++;
                }
                j++;
            }
            else
            {
                if (flag == 0)
                    return;
                i++;
                j = 0;
                flag = 0;
            }
            bubbleSortRecursively();
        }
        /* if I did not reset the following values to their
           original values than after the first time when I call
           this method, it will operate with the current values.  */
        i = 0;
        j = 0;
        flag = 0;
    }

    void insertionSortRecursively()
    {
        static int i = 1;
        static int j = i - 1;
        static int value = array[i];

        if (!(i < size))
        {
            i = 1;
            j = i - 1;
            value = array[i];
            return;
        }

        if (j > -1 && array[j] > value)
        {
            array[j + 1] = array[j--];
            insertionSortRecursively();
        }
        else
        {
            array[j + 1] = value;
            i++;
            value = array[i];
            j = i - 1;
            insertionSortRecursively();
        }
    }

    void insertionSortIteratively()
    {
        for (int i = 1; i < size; i++)
        {
            int value = array[i];
            int j = i - 1;
            while (j > -1 && array[j] > value)
            {
                array[j + 1] = array[j--];
            }
            array[j + 1] = value;
        }
    }

    void linearRecursiveSearch(int element)
    {
        static int index = 0;

        if (index == size && array[index] != element)
        {
            std::cout << "< NOT FOUND >" << std::endl;
            index = 0; // RESET STATEMENT
        }
        else if (array[index] == element)
        {
            std::cout << "<" << element << ">"
                      << " is at index "
                      << "<" << index << ">" << std::endl;
            index = 0; // RESET STATEMENT
        }
        else
        {
            index++;
            linearRecursiveSearch(element);
        }
    }

    void binaryRecursiveSearch(int element)
    {
        static int firstIndex = 0;
        static int lastIndex = size - 1;

        static int start = 1;
        if (start == 1)
        {
            bubbleSortIteratively();
            start++;
        }

        int mid = (firstIndex + lastIndex) / 2;

        if (array[mid] == element)
        {
            std::cout << "< FOUND >" << std::endl;
            // RESET STATEMENTS
            firstIndex = 0;
            lastIndex = size - 1;
            start = 1;
        }
        else if (firstIndex == lastIndex)
        {
            std::cout << "< NOT FOUND >" << std::endl;
            // RESET STATEMENTS
            firstIndex = 0;
            lastIndex = size - 1;
            start = 1;
        }

        else
        {
            if (element > array[mid])
                firstIndex = mid + 1;
            else if (element < array[mid])
                lastIndex = mid - 1;
            binaryRecursiveSearch(element);
        }
    }

    void binaryIterativeSearch(int element)
    {
        bubbleSortIteratively();

        int firstIndex = 0;
        int lastIndex = size - 1;

        int mid = (firstIndex + lastIndex) / 2;

        while (firstIndex != lastIndex && array[mid] != element)
        {
            if (element > array[mid])
                firstIndex = mid + 1;
            else if (element < array[mid])
                lastIndex = mid - 1;
            mid = (firstIndex + lastIndex) / 2;
        }

        if (array[mid] == element)
            std::cout << "< FOUND >" << std::endl;
        else
            std::cout << "< NOT FOUND >" << std::endl;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    int getSize()
    {
        return size;
    }
};
