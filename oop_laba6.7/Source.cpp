#include <iostream>
#include "Array.h"
#include "Functors.h"
#include <time.h>

template<typename T>
Array returnDynamicArray(T arr[], const int size);

int main()
{
    srand((unsigned)time(NULL));
    const int size = 5;
    double arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = -10 + rand() % int(10 - (-10) + 1);  //filled the array( -10 до 10)

    Array dynamicArray = returnDynamicArray(arr, size);

    dynamicArray.Print();

    Predicate<double>* zero = new Zero<double>(); //functor: "zero elements"
    Predicate<double>* positive = new Positive<double>(); //functor: "positive elements" 
    Predicate<double>* negative = new Negative<double>(); //functor: "negative elements" 
    Predicate<double>* even = new Even<double>(); //functor: "even elements" 
    Predicate<double>* odd = new Odd<double>(); //functor: "odd elements" 


    cout << "Duplicated(general): "; duplicate<Array>(dynamicArray).Print();
    cout << "Duplicated(zero): "; duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *zero).Print();
    cout << "Duplicated(positive): "; duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *positive).Print();
    cout << "Duplicated(negative): "; duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *negative).Print();
    cout << "Duplicated(even): "; duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *even).Print();
    cout << "Duplicated(odd): "; duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *odd).Print();
    return 0;
}
template<typename T>
Array returnDynamicArray(T arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}