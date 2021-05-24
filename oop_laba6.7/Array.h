#pragma once
#include <iostream>

using namespace std;

class Array
{
public:
private:
	static const size_t minsize = 10; // min size
	size_t Size; // memory for array
	size_t Count; // number of elements
	size_t First; // the value of the index of the first element in the array
	double* elems; // array
public:
	// constructors and destructors
	Array(const size_t& n = minsize)	throw(bad_alloc, invalid_argument);
	Array(const Array&) throw(bad_alloc);
	Array(const double* first, const double* last) throw(bad_alloc, invalid_argument);
	Array(const size_t first, const size_t last) throw(bad_alloc, invalid_argument);
	~Array();
	Array& operator=(const Array&);

	// iterators
	double* begin() { return elems; }       //pointer on the first element
	double* end() { return elems + Count; } //pointer on the last element
	// sizes
	size_t size() const; // curent size
	bool empty() const; // (isEmpty)
	size_t capacity() const; // size
	void resize(size_t newsize) // change size
		throw(bad_alloc);

	// access to elements
	double& operator[](size_t) throw(out_of_range);
	const double& operator[](size_t) const throw(out_of_range);
	double& front() { return elems[0]; }
	const double& front() const { return elems[0]; }
	double& back() { return elems[size() - 1]; }
	const double& back() const { return elems[size() - 1]; }

	// other methods
	void push_back(const double& v); // add element from the back
	void pop_back(); // delete the last element
	void clear() { Count = 0; } // clear the array
	void swap(Array& other); // swap with other

	// friendly functions
	friend ostream& operator <<(ostream& out, const Array& a);
	friend istream& operator >>(istream& in, Array& a);

	void Print();
};