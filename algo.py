import random
from datetime import datetime

from typing import List, Dict


class QuickSort:

    def __init__(self):
        self.number_of_comparisons = 0
        self.number_of_swaps = 0
        self.starting_time = datetime.now()
        self.ending_time = 0

    def __partition(self, array: List[int], low: int, high: int, sorting_type: str) -> int:

        compare_elements = None

        if sorting_type == 'ASC':
            compare_elements = lambda x, y: x <= y
        elif sorting_type == 'DESC':
            compare_elements = lambda x, y: x >= y

        pivot = array[high]
        pointer = low - 1

        for element in range(low, high):
            self.number_of_comparisons += 1
            if compare_elements(array[element], pivot):
                self.number_of_comparisons += 1
                pointer += 1

                array[pointer], array[element] = array[element], array[pointer]

                if array[pointer] != array[element]:
                    self.number_of_swaps += 1

        array[pointer + 1], array[high] = array[high], array[pointer + 1]
        if array[pointer + 1] != array[high]:
            self.number_of_swaps += 1

        return pointer + 1

    def sort(self, array: List[int], low: int, high: int, sorting_type: str) -> Dict:
        if low < high:
            pivot = self.__partition(array, low, high, sorting_type)

            self.sort(array, low, pivot - 1, sorting_type)
            self.sort(array, pivot + 1, high, sorting_type)

        self.ending_time = datetime.now()

        timedelta = self.ending_time - self.starting_time

        output_values = {
            'name_of_algorithm': 'QuickSort',
            'execution_time': f'{timedelta.seconds}s {timedelta.microseconds}ms',
            'comparisons': self.number_of_comparisons,
            'swaps': self.number_of_swaps,
            'sorted_array': array
        }

        return output_values


# unsorted_array = [2, 1, 7, 3, 5, 4, 6]
# sorted_array_asc = sorted(unsorted_array)
# sorted_array_desc = sorted(unsorted_array, reverse=True)
#
# q = QuickSort()
#
# result = q.sort(sorted_array_desc, 0, len(sorted_array_desc)-1, 'ASC')['sorted_array']
#
# # print(sorted_array_desc)
# print(result == sorted_array_asc)
