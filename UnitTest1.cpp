#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestCalcMethod)
		{
			const int rows = 3, cols = 3;
			int** testMatrix = new int* [rows];
			for (int i = 0; i < rows; i++)
				testMatrix[i] = new int[cols];

			int data[3][3] = {
				{18, 21, 40},
				{14, 49, 30},  
				{17, 19, 28}  
			};

			for (int i = 0; i < rows; i++)
				for (int j = 0; j < cols; j++)
					testMatrix[i][j] = data[i][j];

			int S = 0, k = 0;
			Calc(testMatrix, rows, cols, S, k);

			Assert::AreEqual(3, k);    
			Assert::AreEqual(88, S);  

			for (int i = 0; i < rows; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
