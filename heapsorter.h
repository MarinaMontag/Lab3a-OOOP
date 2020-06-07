#pragma once
#include "sorter.h"

template <class T>
class HeapSorter : public Sorter<T>
{
private:
	static HeapSorter<T>* sorter;
    void heapify(vector<T>&, int, int);
    void sort(vector<T>&, int);
	HeapSorter();
public:
	static HeapSorter<T>* getSorter();
	void sort(vector<T>) override;
};

template <class T>
HeapSorter<T>* HeapSorter<T>::sorter = nullptr;

template <class T>
HeapSorter<T>::HeapSorter() {}

template <class T>
HeapSorter<T>* HeapSorter<T>::getSorter()
{
	if (sorter == nullptr)
	{
		sorter = new HeapSorter();
	}
	return sorter;
}

template <class T>
void HeapSorter<T>::sort(vector<T> arr)
{
    this->sort(arr, arr.size());
}

template <class T>
void HeapSorter<T>::heapify(vector<T>& arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

template <class T>
void HeapSorter<T>::sort(vector<T>& arr, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}