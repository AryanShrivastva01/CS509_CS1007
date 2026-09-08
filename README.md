# CS509 Laboratory Repository

## Repository Overview

This repository contains the laboratory assignments for **CS509 – High Performance Computing**. The implementation focuses on efficient graph representation using **Compressed Sparse Row (CSR)** and matrix multiplication using **General Matrix Multiplication (GEMM)** and **Blocked General Matrix Multiplication (B_GEMM)**. The execution time of GEMM and B_GEMM is compared to analyze performance.

---

## Student Details

- **Name:** Aryan Shrivastva
- **Entry Number:** 2026CSM1007
- **Course:** CS509 – PG Software Lab
- **Institute:** IIT Ropar

---

## Language and Environment

- **Programming Language:** C++
- **Compiler:** g++
- **Operating System:** Windows
- **IDE:** Visual Studio Code
- **Timing Library:** `<chrono>`

---

## Directory Structure

```
Assignment_01/
│
├── driver/
│   ├── driver_csr.cpp
│   ├── driver_gemm.cpp
│  
├── src/
│   ├── csr.cpp
│   ├── csr.hpp
│   ├── GEMM.cpp
│   ├── GEMM.hpp
│   ├── B_GEMM.cpp
│   └── B_GEMM.hpp
│
├── tests/
│   ├── csr_input_01.txt
│   ├── csr_input_02.txt
│   ├── input_50x50.txt
│   ├── input_512x512.txt
│   └── input_1024x1024.txt
│____Common Wrapper
         |__Wrapper.cpp
├── README.md
└── Report.pdf
```

---

# Assignment 01 – CSR Representation, GEMM and Blocked GEMM

## Assignment Mode

- Individual Assignment
- Language: C++

---

## Objective

- Implement **Compressed Sparse Row (CSR)** representation for sparse graphs.
- Implement **General Matrix Multiplication (GEMM)**.
- Implement **Blocked General Matrix Multiplication (B_GEMM)**.
- Compare the execution time of GEMM and B_GEMM.

---

## Algorithm / Approach

### 1. CSR Representation

- Read the graph as a weighted adjacency list.
- Store all destination vertices in **col_idx**.
- Store edge weights in **values**.
- Store the starting index of every vertex in **row_ptr**.
- Print the CSR arrays.

### 2. GEMM

- Read two matrices.
- Verify that matrix multiplication is possible.
- Multiply matrices using the standard three nested loops.
- Store the result in the output matrix.
- Measure execution time using `std::chrono`.

### 3. Blocked GEMM

- Divide matrices into fixed-size blocks.
- Multiply corresponding blocks.
- Store the result matrix.
- Measure execution time.
- Compare execution time with standard GEMM.

---

## Input Format

### CSR

```
Number_of_Vertices

Number_of_Neighbours
Destination Weight
Destination Weight
...
```

Example

```
4
2 1 10 2 20
1 2 15
1 3 5
0
```

---

### GEMM / B_GEMM

```
r1 c1
Matrix A

r2 c2
Matrix B
```

Example

```
2 2
1 2
3 4

2 2
5 6
7 8
```

---

## Helper Functions / CSR Conversion

### CSR

- `convertToCSR()`
- Converts adjacency list into CSR representation.

### GEMM

- `GEMM()`
- Performs classical matrix multiplication.

### B_GEMM

- `B_GEMM()`
- Performs blocked matrix multiplication using block processing.

---

## File Structure

| File | Description |
|------|-------------|
| csr.cpp | CSR implementation |
| csr.hpp | CSR declarations |
| GEMM.cpp | Standard matrix multiplication |
| GEMM.hpp | GEMM declarations |
| B_GEMM.cpp | Blocked GEMM implementation |
| B_GEMM.hpp | B_GEMM declarations |
| driver_csr.cpp | CSR driver program |
| driver_gemm.cpp | GEMM/B_GEMM driver |
| wrapper.cpp | Runs CSR or GEMM programs |
| tests/ | Input test files |

---

## Compilation

### CSR

```bash
g++ driver/driver_csr.cpp src/csr.cpp -o csr
```

### GEMM

```bash
g++ driver/driver_gemm.cpp src/GEMM.cpp src/B_GEMM.cpp -o matrix.exe
```

### Wrapper

```bash
g++ wrapper.cpp -o wrapper.exe
```

---

## Execution

### CSR

```bash
./csr

### GEMM

```bash
./matrix
```

### Wrapper

```bash
./wrapper
```

The wrapper provides the following options:

```
1. Run All Programs
2. Run CSR
3. Run GEMM/B_GEMM
4. Exit
```

---

## Test Cases and Result Table

### CSR

| Vertices | Edges | Result |
|----------|------|--------|
| 10 | 14 | Passed |
| 1000 | 2000 | Passed |

---

### GEMM

| Matrix Size | Execution Time (µs) |
|-------------|--------------------:|
| 50 × 50 | 663 |
| 512 × 512 | 1067 |
| 1024 × 1024 | 22231620 |

---

### Blocked GEMM

| Matrix Size | Block Size | Execution Time (µs) |
|-------------|-----------:|--------------------:|
| 50 × 50 | 2 | 1180 |
| 512 × 512 | 2 | 1939 |
| 1024 × 1024 | 2 | 13131656 |

---

### Performance Comparison

| Matrix Size | GEMM (µs) | B_GEMM (µs) | Faster |
|-------------|----------:|------------:|---------|
| 50 × 50 | 663 | 1180 | GEMM |
| 512 × 512 | 1067 | 1939 | GEMM |
| 1024 × 1024 | 22231620 | 13131656 | B_GEMM |

---


Although both GEMM and B_GEMM have the same theoretical complexity, B_GEMM provides better practical performance for large matrices due to improved cache locality.

