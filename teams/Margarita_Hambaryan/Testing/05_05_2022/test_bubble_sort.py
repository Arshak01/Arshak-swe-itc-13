import unittest
from bubble_sort import bubbleSort


class TestBubbleSort(unittest.TestCase):
    def test_repeated_numbers(self):
        my_list = [-2, 4, 0, 1, 2, 17]
        result = my_list.sort()
        self.assertEqual(result, bubbleSort(my_list))

    def test_positive_numbers(self):
        my_list = [5, 3, 17]
        result = my_list.sort()
        self.assertEqual(result, bubbleSort(my_list))

    def test_negative_numbers(self):
        my_list = [-65, -1, -100, -987]
        result = my_list.sort()
        self.assertEqual(result, bubbleSort(my_list))

    def test_empty_list(self):
        my_list = []
        result = my_list.sort()
        self.assertEqual(result, bubbleSort(my_list))
