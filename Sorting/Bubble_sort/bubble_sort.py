arr = []


def bubble_sort(arr):

    for i in range(0, len(arr) - 1):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]


def accept_user_input():
    global arr
    print("Enter the elements: ", end="\n")
    arr = list(input().split())
    arr = [int(i) for i in arr]


def print_sorted_list():
    print("Elements after sorting by Bubble sort:", end="\n")
    for item in arr:
        print(item, end=" ")
    print("\n")


accept_user_input()

bubble_sort(arr)

print_sorted_list()
     

