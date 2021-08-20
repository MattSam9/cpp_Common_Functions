#include "sortFunction.h"

void swap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

int SelectionSort(int array[], int length)
{
    int i{0}, j{0}, temp{0}, counter{0};
    for (i = 0; i < length - 1; i++)
    {
        temp = i;
        for (j = i + 1; j < length; j++)
        {
            counter++;
            if (array[j] < array[temp])
            {
                temp = j;
            }
        }
        swap(array[i], array[temp]);
    }
    return counter;
}

int bubbleSort(int array[], int length)
{
    bool isNotSwapped{true};
    int counter{0};
    for (int i = 0; i < length - 1; i++)
    {
        isNotSwapped = true;
        for (int j = 0; j < length - i - 1; j++)
        {
            counter++;
            if (array[j] > array[j + 1])
            {
                isNotSwapped = false;
                swap(array[j], array[j + 1]);
            }
        }
        if (isNotSwapped)
            break;
    }
    return counter;
}

int insertionSort(int array[], int length)
{
    int counter{0};
    for (int i = 1; i < length; i++)
    {
        int tempValue = array[i];
        int j{i - 1};
        while (j >= 0 && tempValue < array[j])
        {
            counter++;
            array[j + 1] = array[j];
            j -= 1;
        }
        array[j + 1] = tempValue;
    }
    return counter;
}

void merge(int array[], int left, int mid, int right)
{
    int leftArraySize{mid - left + 1};
    int rightArraySize{right - mid};
    int *leftArray = new int[leftArraySize];
    int *rightArray = new int[rightArraySize];

    for (int u = 0; u < leftArraySize; u++)
    {
        leftArray[u] = array[u + left];
    }
    for (int v = 0; v < rightArraySize; v++)
    {
        rightArray[v] = array[v + mid + 1];
    }
    int i{0}, j{0}, k{left};
    while (i < leftArraySize && j < rightArraySize)
    {
        if (leftArray[i] < rightArray[j])
        {
            array[k++] = leftArray[i++];
        }
        else
        {
            array[k++] = rightArray[j++];
        }
    }
    while (i < leftArraySize)
    {
        array[k++] = leftArray[i++];
    }
    while (j < rightArraySize)
    {
        array[k++] = rightArray[j++];
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int mid{(left + right) / 2};
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);
        merge(array, left, mid, right);
    }
}

void quickSort(int array[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int pivotIndex = partition(array, left, right);
    quickSort(array, left, pivotIndex - 1);
    quickSort(array, pivotIndex + 1, right);
}

int partition(int array[], int left, int right)
{
    int i{left - 1};
    for (int j = left; j < right; j++)
    {
        if (array[j] <= array[right])
        {
            i++;
            if (i != j)
            {
                swap(array[i], array[j]);
            }
        }
    }
    swap(array[i + 1], array[right]);
    return i + 1;
}

void showDoubleBinary(double num)
{
    unsigned long long result = *(unsigned long long *)&num;
    std::cout << "Sign = ";
    for (int i = 63; i >= 0; i--)
    {
        std::cout << (result >> i & 1);
        if (i == 63)
        {
            std::cout << "  Exponent = ";
        }
        else if (i == 52)
        {
            std::cout << "  Mantiss = ";
        }
    }
    std::cout << '\n';
}

void showFloatBinary(float num)
{
    unsigned long result = *(unsigned long *)&num;
    std::cout << "Sign = ";
    for (int i = 31; i >= 0; i--)
    {
        std::cout << (result >> i & 1);
        if (i == 31)
        {
            std::cout << "  Exponent = ";
        }
        else if (i == 23)
        {
            std::cout << "  Mantiss = ";
        }
    }
    std::cout << '\n';
}