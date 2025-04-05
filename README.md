# Push Swap Project

## Overview
The Push Swap project involves sorting a stack of integers using a limited set of operations. The goal is to sort the stack in ascending order using a minimum number of operations. The project uses two stacks, `stack_a` and `stack_b`, to perform the sorting operations.

## Operations Available
The following operations can be performed on the stacks:

- `sa`: Swap the top two elements of stack_a.
- `sb`: Swap the top two elements of stack_b.
- `ss`: Perform sa and sb simultaneously.
- `pa`: Push the top element from stack_b to stack_a.
- `pb`: Push the top element from stack_a to stack_b.
- `ra`: Rotate stack_a (move the top element to the bottom).
- `rb`: Rotate stack_b (move the top element to the bottom).
- `rr`: Perform ra and rb simultaneously.
- `rra`: Reverse rotate stack_a (move the bottom element to the top).
- `rrb`: Reverse rotate stack_b (move the bottom element to the top).
- `rrr`: Perform rra and rrb simultaneously.

## Sorting Algorithm

### Step 1: Bubble Sort
The sorting algorithm starts with a Bubble Sort. It creates a sorted array (`sort_tab`) by copying the contents of stack_a and sorting it. This sorted array will help guide the push and rotate operations used in the next steps of the algorithm.

```c
int *bubble_sort(t_stack *list) {
    int i;
    int *arr;

    arr = malloc(sizeof(int) * list->length_a);
    ft_memcpy(arr, list->stack_a, list->length_a * sizeof(int));
    i = 0;
    while (i < (list->length_a - 1)) {
        if (arr[i] > arr[i + 1]) {
            ft_swap(&arr[i], &arr[i + 1]);
            i = 0;
        } else {
            i++;
        }
    }
    list->len_tab = list->length_a;
    list->sort_tab = arr;
    return arr;
}
```

In the Bubble Sort function:
- The elements of stack_a are copied into a temporary array `arr`.
- A traditional Bubble Sort is applied to the array `arr`, which will be used to guide the operations like push and rotate in the subsequent steps.

### Step 2: Chunking
Once the array is sorted into `sort_tab`, the next step is to divide stack_a into chunks. This chunking approach allows the algorithm to focus on smaller sections of the stack, making the sorting process more efficient.

The chunk size is determined by the size of stack_a:
- For 6 to 16 elements in stack_a, the chunk size is 3.
- For 17 to 100 elements in stack_a, the chunk size is 18.
- For stacks larger than 100 elements, the chunk size is 35.

This chunking helps by organizing the stack into smaller, more manageable parts.

```c
void sort_bigg(t_stack *list, int chunk) {
    int i = 0;
    while (list->length_a) {
        if (list->stack_a[0] <= list->sort_tab[i]) {
            push_b(list);       // Move element from stack_a to stack_b
            rotate_b(list);     // Rotate stack_b to maintain order
            i++;                // Move to the next chunk
        } else if (list->stack_a[0] > list->sort_tab[i] && list->stack_a[0] <= list->sort_tab[chunk + i]) {
            push_b(list);       // Push element to stack_b
            i++;                // Continue with the next chunk
        } else {
            rotate_a(list);     // Rotate stack_a to bring the next element to the top
        }
    }
}
```

In this function:
- The top element of stack_a is compared with the elements in `sort_tab`.
- If the element is within the current chunk's range, it is pushed to stack_b.
- The algorithm then rotates stack_b to maintain order.
- If the element doesn't belong to the current chunk, stack_a is rotated to bring the correct element to the top.

### Step 3: Push and Rotate Back
Once the chunks are processed and elements are pushed to stack_b, the algorithm then rotates the elements back into stack_a in sorted order.

```c
void sort(t_stack *list) {
    int range;
    int size;

    range = 0;
    size = list->length_a;
    if (size >= 6 && size <= 16) range = 3;
    else if (size <= 100) range = 18;
    else range = 35;

    sort_bigg(list, range);

    while (list->length_b) {
        check_max(list);       // Identify and place the largest element from stack_b
        push_a(list);          // Push element back to stack_a
    }
}
```

In the sort function:
- Based on the size of stack_a, the appropriate chunk size is calculated.
- The `sort_bigg` function is called to push elements into stack_b in chunks.
- Once all elements are moved to stack_b, the elements are moved back to stack_a in the correct order using the `push_a` operation.

### Step 4: Helper Functions
There are several helper functions used throughout the program to handle the following tasks:
- `check_max`: Identifies and processes the maximum element in stack_b.
- `check_min`: Identifies and processes the minimum element in stack_a.
- `sorted`: Checks if stack_a is already sorted, to prevent unnecessary operations.

## Final Algorithm
In the final steps, the algorithm performs the necessary rotations, pushes, and swaps to ensure that stack_a is sorted in ascending order. The sequence of operations aims to minimize the number of operations and efficiently sort the stack.

```c
int get_max_value(t_stack *list) {
    int max;
    int i;

    i = 0;
    max = list->stack_a[0];
    while (i < list->length_a) {
        if (max < list->stack_a[i]) max = list->stack_a[i];
        i++;
    }
    return max;
}

void check_max(t_stack *list) {
    int pos;

    while (1) {
        pos = max_pos(list);   // Find the position of the max value in stack_b
        if (pos == 0) break;    // If max is at the top, stop
        else if (pos <= list->length_b / 2) rotate_b(list);  // Rotate stack_b if necessary
        else reverse_rotate_b(list);  // Reverse rotate stack_b if necessary
    }
}
```

## Conclusion
The Push Swap project is a challenge that involves efficiently sorting a stack of integers using a limited set of operations. By implementing a Bubble Sort and Chunking strategy, the algorithm breaks down the sorting process into smaller steps, making it more manageable and efficient. The sorting process is completed by pushing and rotating elements between two stacks, ensuring the stack is sorted in the minimum number of operations.
