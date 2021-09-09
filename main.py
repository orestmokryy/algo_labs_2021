from algo import QuickSort

import argparse

parser = argparse.ArgumentParser(description='Sort an array of integers using quick sort')
parser.add_argument('array', type=str, help='Comma separated integers in arbitrary order without spaces')
parser.add_argument('sorting_type', type=str, help='ASC or DESC')
args = parser.parse_args()

array = [int(x) for x in args.array.split(',')]
sorting_type = args.sorting_type

q = QuickSort()

print(q.sort(array, 0, len(array) - 1, sorting_type))



