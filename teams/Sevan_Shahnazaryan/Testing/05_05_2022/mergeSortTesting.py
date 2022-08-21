import unittest

import mergeSort

class mergeSortTest(unittest.TestCase):

    def testSingle(self):
        array = [5]
        expectedResult = [5]
        self.assertAlmostEqual(mergeSort.merge_sort(array), expectedResult)
    
    def testTwo(self):
        array = [9, 4]
        expectedResult = [4, 9]
        self.assertAlmostEqual(mergeSort.merge_sort(array), expectedResult)

    def testMore(self):
        array = [7, 3, 6, 1, 9]
        expectedResult = [1, 3, 6, 7, 9]
        self.assertAlmostEqual(mergeSort.merge_sort(array), expectedResult)

    def testNegative(self):
        array = [-5, -6, 0, 6]
        expectedResult = [-6, -5, 0, 6]
        self.assertAlmostEqual(mergeSort.merge_sort(array), expectedResult)

    def testType(self):
        self.assertIs(type(mergeSort.merge_sort([5, 6, 2])), list)

if __name__ == "__main__":
    unittest.main()