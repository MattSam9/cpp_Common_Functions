#include "time.h"
#include <iostream>

#ifndef SORTFUNCTION_H
#define SORTFUNCTION_H

int partition(int[], int, int);
void swap(int &, int &);
int SelectionSort(int[], int);
int bubbleSort(int[], int);
int insertionSort(int[], int);
void merge(int[], int, int, int);
void mergeSort(int[], int, int);
void quickSort(int[], int, int);

template <class T>
void printArray(T &x)
{
    for (const auto &item : x)
    {
        std::cout << item << " ";
    }
    std::cout << '\n';
}

void showDoubleBinary(double num);
void showFloatBinary(float num);

#endif