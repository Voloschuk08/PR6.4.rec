#include "pch.h"
#include "CppUnitTest.h"

#include "../PR6.4/PR6.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest64
{
	TEST_CLASS(UnitTest64)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double* a = 0;
			int i = 0;
			int n = 0;
			int sum = sumNegative( 0, n, i);
			Assert::AreEqual(sum, 0);
		}
	};
}
