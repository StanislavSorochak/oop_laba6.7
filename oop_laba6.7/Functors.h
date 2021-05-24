#pragma once
#include "Array.h"
//functor - an object of class that has the properties of a function
template<class T> //interface describing functors - unary predicates
class Predicate
{
public:
	virtual bool operator () (T x) = 0;  //function call overload operator
};

template <class T>                  //implement the interface with a functor -                               
class Zero : public Predicate<T>    //check whether the value is zero
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};

template<class T>						// implement the interface with a functor -
class Positive : public Predicate<T>    //check whether the value is possitive
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>						// implement the interface with a functor -
class Negative : public Predicate<T>	//check whether the value is negative
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>					// implement the interface with a functor -
class Even : public Predicate<T>    //check whether the value is even
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 == 0;
	}
};

template<class T>					// implement the interface with a functor -
class Odd : public Predicate<T>    //check whether the value is odd
{
public:
	virtual bool operator () (T x)
	{
		return (int)x % 2 != 0;
	}
};

// myTask

template<class T>
T duplicate(T& arr)
{
	T duplicatedArray = T(2 * arr.size());
	int iterator = 0;

	for (int i = 0; i < duplicatedArray.size(); i++)
	{
		duplicatedArray[i] = arr[iterator];
		duplicatedArray[++i] = arr[iterator];

		iterator++;
	}

	return duplicatedArray;
}
template<class T>
T duplicate_if(double* begin, double* end, T& arr, Predicate<double>& predicate)
{
	T duplicateArray = Array(1);
	duplicateArray[0] = arr[0];
	if (predicate(*begin))
		duplicateArray.push_back(arr[0]);

	begin++;

	for (begin; begin < end; begin++)
	{
		duplicateArray.push_back(*begin);

		if (predicate(*begin))
			duplicateArray.push_back(*begin);
	}

	return duplicateArray;
}