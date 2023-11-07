#include "pch.h"
#include "CppUnitTest.h"
#include "../Project7.2(it)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72IT
{
	TEST_CLASS(UnitTest72IT)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            const int n = 3; 
            int** a = new int* [n];
            for (int i = 0; i < n; i++)
                a[i] = new int[n];
            a[0][0] = 5;
            a[0][1] = 10;
            a[0][2] = 15;
            a[1][0] = 20;
            a[1][1] = 25;
            a[1][2] = 30;
            a[2][0] = 35;
            a[2][1] = 40;
            a[2][2] = 45;
            int result = SumMax(a, n, n);
            Assert::AreEqual(90, result); 
            for (int i = 0; i < n; i++)
                delete[] a[i];
            delete[] a;
		}
	};
}
