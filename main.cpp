#include <iostream>
#include <thread>
#include <chrono>

#include "heapsorter.h"
#include "insertionsorter.h"
#include "quicksorter.h"


using namespace std;

void line_sorting(vector<int> v);
void parralel_sorting(vector<int> v);
void hs(vector<int>);
void is(vector<int>);
void qs(vector<int>);
vector<int> generate_array(const int&);

int main()
{
	auto v = generate_array(1000);
	line_sorting(v);
	parralel_sorting(v);
	return 0;
}

void line_sorting(vector<int> v)
{
	auto start = chrono::steady_clock::now();
	hs(v);
	is(v);
	qs(v);
	auto end = chrono::steady_clock::now();
	cout << "------LINEAR SORTING------" << endl;
	cout << "Elapsed time in nanoseconds : "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " mcs" << endl;

	cout << "Elapsed time in milliseconds : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< "sec" <<endl;
}

void parralel_sorting(vector<int> v)
{
	auto start = chrono::steady_clock::now();
	thread h1(hs, v);
	thread h2(is, v);
	thread h3(qs, v);
	h1.detach();
	h2.detach();
	h3.detach();
	auto end = chrono::steady_clock::now();
	cout << "------PARRALEL SORTING------" << endl;
	cout << "Elapsed time in nanoseconds : "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;

	cout << "Elapsed time in microseconds : "
		<< chrono::duration_cast<chrono::microseconds>(end - start).count()
		<< " mcs" << endl;

	cout << "Elapsed time in milliseconds : "
		<< chrono::duration_cast<chrono::milliseconds>(end - start).count()
		<< " ms" << endl;

	cout << "Elapsed time in seconds : "
		<< chrono::duration_cast<chrono::seconds>(end - start).count()
		<< "sec" <<endl;
}


void hs(vector<int> v)
{
	HeapSorter<int>* hs = HeapSorter<int>::getSorter();
	hs->sort(v);
}

void is(vector<int> v)
{
	InsertionSorter<int>* is = InsertionSorter<int>::getSorter();
	is->sort(v);
}

void qs(vector<int> v)
{
	QuickSorter<int>* qs = QuickSorter<int>::getSorter();
	qs->sort(v);
}

vector<int> generate_array(const int& sz)
{
	vector<int> v;
	for (int i = sz; i > -1; i--)
		v.push_back(i);
	return v;
}