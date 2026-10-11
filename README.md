# push_swap

A highly optimized sorting algorithm project developed as part of the 42 curriculum.

---

## Overview

**push_swap** is a C programming project whose objective is to sort a given stack of integers using a secondary stack and a restricted set of stack manipulation instructions. The primary challenge is not merely sorting the numbers, but doing so using the **minimum possible number of operations**.

The project involves two primary programs:
1. **`push_swap`**: Calculates and displays the shortest sequence of instructions to sort the integer stack in ascending order.
2. **`checker`** *(Bonus)*: Takes the integer list and reads instructions from standard input, executing them to verify whether the stack is correctly sorted.

---

## The Rules & Operations

You are provided with two stacks: **Stack A** and **Stack B**.

- At the beginning:
  - **Stack A** contains a random set of unique positive and/or negative integers.
  - **Stack B** is empty.
- The goal is to sort the numbers into ascending order in **Stack A**.

### Allowed Operations

| Operation | Description |
| :--- | :--- |
| **`sa`** / **`sb`** | **Swap**: Swap the first two elements at the top of stack A or B. |
| **`ss`** | `sa` and `sb` simultaneously. |
| **`pa`** / **`pb`** | **Push**: Take the top element of one stack and put it onto the other. |
| **`ra`** / **`rb`** | **Rotate**: Shift all elements of a stack up by 1. The top becomes the bottom. |
| **`rr`** | `ra` and `rb` simultaneously. |
| **`rra`** / **`rrb`** | **Reverse Rotate**: Shift all elements of a stack down by 1. The bottom becomes the top. |
| **`rrr`** | `rra` and `rrb` simultaneously. |

---

## Getting Started

### Compilation

Compile the program using `make`:

```bash
# Build the push_swap executable
make

# Build the checker program (bonus)
make bonus
```

### Usage

Run `push_swap` by passing an unsorted list of integers as arguments:

```bash
./push_swap 2 1 3 6 5 8
```

You can also pass arguments as a quoted string:

```bash
./push_swap "2 1 3 6 5 8"
```

### Testing with the Checker

Verify the output of `push_swap` with the `checker` program:

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG
```

If correctly sorted, the checker outputs:
```text
OK
```

---

## Benchmark Targets (42 Standard)

- **3 numbers**: $\le 3$ operations
- **5 numbers**: $\le 12$ operations
- **100 numbers**: 
  - $< 700$ operations (5/5 points)
  - $< 900$ operations (4/5 points)
- **500 numbers**: 
  - $< 5500$ operations (5/5 points)
  - $< 7000$ operations (4/5 points)

## My project's average operations per set of numbers:

- **3 numbers**: ✔
- **5 numbers**: ✔
- **100 numbers**: ~600
- **500 numbers**: ~4700
