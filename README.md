# push_swap

## Overview
push_swap is a sorting program written in C that sorts a stack of integers using a limited set of operations.
The goal is to sort the numbers with the minimum possible number of operations, following the project rules.

This repository may also include small utility functions (e.g., ft_atoi, ft_abs) and printing helpers used for output.

---

## Features
- Uses two stacks:
  - stack A
  - stack B

- Allowed operations:
  - sa, sb, ss – swap
  - pa, pb – push
  - ra, rb, rr – rotate
  - rra, rrb, rrr – reverse rotate

- Input handling:
  - Valid numeric format checking
  - Values outside INT_MIN/INT_MAX (overflow/underflow)
  - Duplicate detection

---

## Data Structures
Each node contains:
- value (original number)
- index
- cost (number of operations required)
- next (pointer to the next node, or NULL)

Each stack contains:
- head (pointer to the first node)
- tail (pointer to the last node)
- name (A or B)
- size (number of elements in the stack)

---

## Algorithm Description

### 1) Input Parsing & Stack Initialization
The program receives numbers as string arguments. Each value is converted from string to int one by one, while checking:
- valid numeric format
- does not exceed INT_MAX
- is not less than INT_MIN
- no duplicates

For each valid value, a new node is created and added to stack A.

### 2) Initial Push to Stack B
All elements are pushed from stack A to stack B except the last three elements.
The remaining three elements in stack A are sorted using the minimum number of operations.

### 3) Cost Calculation (B → A)
For each element in stack B, two costs are calculated:
- Cost in stack B: operations needed to bring the element to the top of stack B (rb or rrb)
- Cost in stack A: operations needed to prepare stack A so the element can be inserted in its correct position (ra or rra)

The total cost combines both costs, with optimization using combined operations (rr / rrr) when both stacks rotate in the same direction.

### 4) Moving the Cheapest Element
The element with the lowest total cost is selected:
- perform required rotations on both stacks
- push it from stack B to stack A using pa
This process repeats until stack B is empty.

### 5) Final Rotation
After all elements are moved back to stack A, stack A is rotated until the smallest value is on top, ensuring the stack is fully sorted.

---

## Build & Run
make
./push_swap 3 2 1 5 4

## Checker
ARG="3 2 1 5 4"
./push_swap $ARG | ./checker_linux $ARG

---

## Error Handling
The program prints "Error" and exits if:
- input contains non-numeric values
- overflow/underflow occurs (outside INT_MIN/INT_MAX)
- duplicate numbers are found
