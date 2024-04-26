#include "pch.h"
#include "CppUnitTest.h"
#include "../lab5.1B/Rational.h"
#include "../lab5.1B/Rational.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51В
{
	TEST_CLASS(UnitTest51В)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Rational r1;
			std::stringstream input("2 3");
			std::stringstream output;

			// Act
			input >> r1;
			output << r1;

			// Assert
			Assert::AreEqual(std::string("2\\3"), output.str());
		}
	};
}
