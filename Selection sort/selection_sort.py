arr = []


def selection_sort(arr):
    for i in range(len(arr) - 1):
        for j in range(i, len(arr), 1):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]


def accept_user_input():
    global arr
    print("Enter the elements: ", end="\n")
    arr = list(input().split())
    arr = [int(i) for i in arr]


def print_sorted_list():
    print("Elements after sorting by Selection sort:", end="\n")
    for item in arr:
        print(item, end=" ")
    print("\n")


accept_user_input()

selection_sort(arr)

print_sorted_list()

     
