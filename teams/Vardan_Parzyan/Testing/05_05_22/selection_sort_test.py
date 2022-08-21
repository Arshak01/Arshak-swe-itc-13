import unittest


def selection_sort(array):

    size = len(array)

    for step in range(size):
        min_idx = step

        for i in range(step + 1, size):
            if array[i] < array[min_idx]:
                min_idx = i

        (array[step], array[min_idx]) = (array[min_idx], array[step])


class selection_sort_tests(unittest.TestCase):
    def sort(self, lst):
        copy = lst[:]
        selection_sort(copy)
        return copy

    def test_empty_list(self):
        lst = []
        sorted_lst = self.sort(lst)
        self.assertEqual(lst, sorted_lst)

    def test_single(self):
        lst = [1]
        sorted_lst = self.sort(lst)
        self.assertEqual(lst, sorted_lst)

    def test_two(self):
        lst = [2, 1]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [1, 2])

    def test_zero(self):
        lst = [10, 0]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [0, 10])

    def test_odd(self):
        lst = [13, 7, 5]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [5, 7, 13])

    def test_even(self):
        lst = [23, 7, 13, 5]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [5, 7, 13, 23])

    def test_duplicate(self):
        lst = [1, 2, 2, 1, 0, 0, 15, 15]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [0, 0, 1, 1, 2, 2, 15, 15])

    def test_larger_int(self):
        lst = [135604, 1000000, 45, 78435, 456219832, 2, 546]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst,
                [2, 45, 546, 78435, 135604, 1000000, 456219832])

    def test_minus(self):
        lst = [-41, -456, -89741, 0, -123, -3]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst,
                [-89741, -456, -123, -41, -3, 0])

    def test_(self):
        lst = [1, 2, -5, -6, 13]
        sorted_lst = self.sort(lst)
        self.assertEqual(sorted_lst, [-6, -5, 1, 2, 13])


if __name__ == '__main__':
    unittest.main()