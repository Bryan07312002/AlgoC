/*
You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most
significant to least significant in left-to-right order. The large integer does
not contain any leading 0's. Increment the large integer by one and return the
resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].
*/

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>

// Note: The returned array must be malloced, assume caller calls free().
int *plusOne(int *digits, int digitsSize, int *returnSize) {
  *returnSize = digitsSize;

  int *newDigits = malloc(digitsSize * sizeof(int));
  memcpy(newDigits, digits, digitsSize * sizeof(int));

  for (int i = digitsSize - 1; i >= 0; i--) {
    if (digits[i] != 9) {
      newDigits[i] = digits[i] + 1;
      return newDigits;
    }
    newDigits[i] = 0;
  }

  *returnSize = *returnSize + 1;
  newDigits[0] = 1;

  return newDigits;
}

int compare_arrays(const int *arr1, const int *arr2, int size) {
  for (int i = 0; i < size; ++i) {
    if (arr1[i] != arr2[i]) {
      return 0;
    }
  }
  return 1;
}

void test_example_1() {
  int returnSize = 0;
  int input[3] = {1, 2, 3};
  int *out = plusOne(input, 3, &returnSize);

  int expect[3] = {1, 2, 4};

  CU_ASSERT_EQUAL(returnSize, 3);
  CU_ASSERT_TRUE(compare_arrays(expect, out, 3));

  // free(&out);
}

void test_example_2() {
  int returnSize = 0;
  int input[4] = {4, 3, 2, 1};
  int *out = plusOne(input, 4, &returnSize);

  int expect[4] = {4, 3, 2, 2};

  CU_ASSERT_EQUAL(returnSize, 4);
  CU_ASSERT_TRUE(compare_arrays(expect, out, 4));

  // free(out);
}

void test_example_3() {
  int returnSize = 0;
  int input[1] = {9};
  int *out = plusOne(input, 1, &returnSize);

  int expect[2] = {1, 0};

  CU_ASSERT_EQUAL(returnSize, 2);
  CU_ASSERT_TRUE(compare_arrays(expect, out, 2));

  printf("%d\n", returnSize);
  // free(out);
}

int main() {
  // Initialize the CUnit test registry
  if (CUE_SUCCESS != CU_initialize_registry()) {
    return CU_get_error();
  }

  // Add a test suite
  CU_pSuite pSuite = CU_add_suite("Array_Test_Suite", 0, 0);

  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Add the test to the suite
  if (NULL == CU_add_test(pSuite, "example 1", test_example_1)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "example 2", test_example_2)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  if (NULL == CU_add_test(pSuite, "example 3", test_example_3)) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  // Run the tests
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
