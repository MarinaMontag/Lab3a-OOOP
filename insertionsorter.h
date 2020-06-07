#pragma once
#include "sorter.h"

template <class T>
class InsertionSorter : public Sorter<T>
{
private:
	static InsertionSorter<T>* sorter;
	InsertionSorter();
public:
	static InsertionSorter<T>* getSorter();
	void sort(vector<T>) override;
};

template <class T>
InsertionSorter<T>* InsertionSorter<T>::sorter = nullptr;

template <class T>
InsertionSorter<T>::InsertionSorter() {}

template <class T>
InsertionSorter<T>* InsertionSorter<T>::getSorter()
{
	if (sorter == nullptr)
	{
		sorter = new InsertionSorter();
	}
	return sorter;
}

template <class T>
void InsertionSorter<T>::sort(vector<T> arr)
{
	for (int i = 1; i < arr.size(); i++)
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
			swap(arr[j - 1], arr[j]);
}

