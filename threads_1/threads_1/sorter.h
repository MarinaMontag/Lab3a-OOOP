#pragma once
#include <vector>
using namespace std;

template <class T>
class Sorter
{
public:
	virtual void sort(vector<T>) = 0;
};

