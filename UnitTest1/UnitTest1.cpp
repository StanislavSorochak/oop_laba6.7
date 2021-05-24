#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_laba6.7/Array.cpp"
#include "../oop_laba6.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int arr[] = { 0, 1, 2, 3, -4 };
			Array result = Array(1);
			Array dynamicArray = returnDynamicArray(arr, 5);

			int zeroDuplicated[] = { 0, 0, 1, 2, 3, -4 };

			Predicate<double>* zero = new Zero<double>(); //functor: "zero elements"


			result = duplicate_if<Array>(dynamicArray.begin(), dynamicArray.end(), dynamicArray, *zero);
			for (int i = 0; i < result.size(); i++)
				Assert::AreEqual((int)result[i], zeroDuplicated[i]);
		}
	};
}
