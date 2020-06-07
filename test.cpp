#include "pch.h"
#include "CppUnitTest.h"
#include <vector>
using namespace std;

#include "../threads_1/insertionsorter.h"
#include "../threads_1/heapsorter.h"
#include "../threads_1/quicksorter.h"

vector<int> generate_array(const int& sz)
{
	vector<int> v;
	for (int i = sz; i > -1; i--)
		v.push_back(i);
	return v;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:
		
		TEST_METHOD(CheckInsertionSortAlgorithm)
		{
			// тест перевіряє чи правильно сортує InsertionSort (у порядку зростання)
			int sz = 100;
			vector<int> v = generate_array(sz);
			InsertionSorter<int>* is = InsertionSorter<int>::getSorter();
			is->sort(v);
			for (int i = 0; i < sz - 1; i++)
				if (v[i] < v[i + 1]) Assert::Fail();
		}
		TEST_METHOD(CheckQuickSortAlgorithm)
		{
			// тест перевіряє чи правильно сортує QuickSort (у порядку зростання)
			int sz = 100;
			vector<int> v = generate_array(sz);
			QuickSorter<int>* is = QuickSorter<int>::getSorter();
			is->sort(v);
			for (int i = 0; i < sz - 1; i++)
				if (v[i] < v[i + 1]) Assert::Fail();
		}
		TEST_METHOD(CheckHeapSortAlgorithm)
		{
			// тест перевіряє чи правильно сортує HeapSort (у порядку зростання)
			int sz = 100;
			vector<int> v = generate_array(sz);
			HeapSorter<int>* is = HeapSorter<int>::getSorter();
			is->sort(v);
			for (int i = 0; i < sz - 1; i++)
				if (v[i] < v[i + 1]) Assert::Fail();
		}
	};
}
