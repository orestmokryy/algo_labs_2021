import unittest

from algo import QuickSort


class AlgoTest(unittest.TestCase):
    unsorted_array = [2, 1, 7, 3, 5, 4, 6]
    sorted_array_asc = sorted(unsorted_array)
    sorted_array_desc = sorted(unsorted_array, reverse=True)

    def test_sorting_asc(self):
        algo = QuickSort()
        algo_output = algo.sort(AlgoTest.unsorted_array, 0, len(AlgoTest.unsorted_array) - 1, 'ASC')['sorted_array']
        self.assertEqual(AlgoTest.sorted_array_asc, algo_output)

    def test_sorting_desc(self):
        algo = QuickSort()
        algo_output = algo.sort(AlgoTest.unsorted_array, 0, len(AlgoTest.unsorted_array) - 1, 'DESC')['sorted_array']
        self.assertEqual(AlgoTest.sorted_array_desc, algo_output)

    def test_sorting_already_sorted_array_asc(self):
        algo = QuickSort()
        self.assertEqual(AlgoTest.sorted_array_asc,
                         algo.sort(AlgoTest.sorted_array_asc, 0, len(AlgoTest.sorted_array_asc) - 1, 'ASC')[
                             'sorted_array'])

    def test_sorting_already_sorted_array_desc(self):
        algo = QuickSort()
        self.assertEqual(AlgoTest.sorted_array_desc,
                         algo.sort(AlgoTest.sorted_array_desc, 0, len(AlgoTest.sorted_array_desc) - 1, 'DESC')[
                             'sorted_array'])

    def test_sorting_reverse_sorted_array_1(self):
        algo = QuickSort()

        sorted_array_desc = [1, 2, 3, 4, 5, 6, 7]

        algo_output = algo.sort(sorted_array_desc, 0, len(AlgoTest.sorted_array_desc) - 1, 'ASC')['sorted_array']
        self.assertEqual(AlgoTest.sorted_array_asc, algo_output)

    def test_sorting_reverse_sorted_array_2(self):
        algo = QuickSort()
        algo_output = algo.sort(AlgoTest.sorted_array_asc, 0, len(AlgoTest.sorted_array_asc) - 1, 'DESC')['sorted_array']
        self.assertEqual(AlgoTest.sorted_array_desc, algo_output)
