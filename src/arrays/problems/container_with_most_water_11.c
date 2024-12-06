/*
You are given an integer array height of length n. There are n vertical lines
drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the
container contains the most water. Return the maximum amount of water a
container can store. Notice that you may not slant the container.

Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array
[1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the
container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/

#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>
#include <stdio.h>
#include <stdlib.h>

int max(int v1, int v2) {
  if (v1 < v2)
    return v2;

  return v1;
}

int min(int v1, int v2) {
  if (v1 > v2)
    return v2;

  return v1;
}

int maxArea(int *height, int heightSize) {
  int start = 0;
  int end = heightSize - 1;
  int max_area = 0;

  while (start < end) {
    int width = end - start;

    int area = width * min(height[start], height[end]);
    max_area = max(area, max_area);

    if (height[start] < height[end])
      start += 1;
    else
      end -= 1;
  }

  return max_area;
}

void test_example_1() {
  int input[9] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  int expected = 49;

  CU_ASSERT_EQUAL(maxArea(input, 9), expected)
}

void test_example_2() {
  int input[2] = {1, 1};
  int expected = 1;

  CU_ASSERT_EQUAL(maxArea(input, 2), expected)
}

int max_area_test_suite() {

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

  // Run the tests
  CU_basic_run_tests();
  CU_cleanup_registry();
  return 0;
}
