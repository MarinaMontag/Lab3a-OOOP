#pragma once
#include "sorter.h"


template <class T>
class QuickSorter : public Sorter<T>
{
private:
    static QuickSorter<T>* sorter;
    QuickSorter();
    int partition(vector<T>&, int, int);
    void sort(vector<T>&, int, int);
public:
    static QuickSorter<T>* getSorter();
    void sort(vector<T>) override;
};

template <class T>
QuickSorter<T>* QuickSorter<T>::sorter = nullptr;

template <class T>
QuickSorter<T>::QuickSorter() {}

template <class T>
QuickSorter<T>* QuickSorter<T>::getSorter()
{
    if (sorter == nullptr)
    {
        sorter = new QuickSorter();
    }
    return sorter;
}

template<class T>
void QuickSorter<T>::sort(vector<T> arr)
{
    this->sort(arr, 0, arr.size() - 1);
}

template <class T>
int QuickSorter<T>::partition(vector<T>& arr, int low, int high)
{
    int pivot = arr[high];    // pivot 
    int i = (low - 1);  // Index of smaller element 

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element 
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

template <class T>
void QuickSorter<T>::sort(vector<T>& arr, int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);

        // Separately sort elements before 
        // partition and after partition 
        sort(arr, low, pi - 1);
        sort(arr, pi + 1, high);
    }
}

