#include "gtest/gtest.h"
#include "array.h"

class ArrayTest : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	ArrayTest() {
		// You can do set-up work for each test here.
	}

	virtual ~ArrayTest() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
	Array<int> p;
};

TEST_F(ArrayTest, test) {
	for(int i = 0; i < 10; i++) {
		p.push(i);
	}
	ASSERT_EQ(p.capacity(), 20);
	ASSERT_EQ(p.size(), 10);
	for(int i = 0; i < 20; i++) {
		p.push(i);
	}
	ASSERT_EQ(p.capacity(), 40);

	//ASSERT_THROW(p.at(0), std::out_of_range);
}