arr = []

def partition(arr, start, end):

    pivot = arr[start]
    pos = start + 1

    lt = start  # to mark the position of the last element less than pivot
    gt = start  # to mark the position of the first element greater than pivot

    while pos <= end:

        if arr[pos] < pivot:
            if gt != start:

                arr[gt], arr[pos] = arr[pos], arr[gt]
                gt = gt + 1

            lt = lt + 1

        if arr[pos] >= pivot:
            if gt == start:
                gt = pos
        pos = pos + 1
    arr[start], arr[lt] = arr[lt], pivot

    return lt


def quicksort(arr, start, end):

    if (end - start) < 1:
        return None

    pivot_pos = partition(arr, start, end)

    quicksort(arr, start, pivot_pos)
    quicksort(arr, pivot_pos + 1, end)


def accept_user_input():
    global arr
    print("Enter the elements: ", end="\n")

    arr = list(input().split())
    arr = [int(i) for i in arr]


def print_sorted_list():
    print("\nElements after sorting by Quicksort:", end="\n")
    for item in arr:
        print(item, end=" ")
    print("\n")


accept_user_input()

quicksort(arr, 0, len(arr) - 1)

print_sorted_list()

