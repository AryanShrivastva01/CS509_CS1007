# CS509 - PG Software Lab

## Assignment 3 - Individual Assignment

**Student:** Aryan Shrivastva  
**Roll Number:** 2026CSM1007  
**Course:** CS509 - PG Software Lab

---

## 1. Assignment Overview

This individual assignment implements two Minimum Spanning Tree (MST) algorithms:

1. **Kruskal's Algorithm**
2. **Prim's Algorithm**

The graph is represented using the common **Compressed Sparse Row (CSR)** component. Both algorithms are executed on the given test cases and their results are stored in separate output files.

The implementation is written in **C++** using the GNU g++ compiler.

---

## 2. Algorithms Implemented

### 2.1 Kruskal's Algorithm

Kruskal's algorithm constructs a Minimum Spanning Tree by:

- Collecting the edges of the graph.
- Sorting the edges in increasing order of weight.
- Using the Disjoint Set Union (DSU) data structure for cycle detection.
- Adding an edge when it does not create a cycle.
- Continuing until the MST contains `V - 1` edges.

The implementation uses path compression and union by rank for efficient DSU operations.

### 2.2 Prim's Algorithm

Prim's algorithm constructs a Minimum Spanning Tree by:

- Starting from a source vertex.
- Maintaining the vertices already included in the MST.
- Using a minimum-priority queue to select the minimum-weight edge.
- Adding the selected edge and vertex to the MST.
- Continuing until all reachable vertices are processed.

---

## 3. Common CSR Representation

The graph is stored using the common CSR component.

The CSR representation contains:

- `row_ptr` - stores the starting position of each vertex's adjacency list.
- `col_idx` - stores destination vertices.
- `values` - stores edge weights.

The MST algorithms use this representation to access the graph efficiently.

---

## 4. Repository Structure

```text
Assignment_03/
│
├── driver/
│   └── driver.cpp
│
├── src/
│   ├── edge.hpp
│   ├── kruskal.hpp
│   ├── kruskal.cpp
│   ├── prim.hpp
│   └── prim.cpp
│
├── tests/
│   ├── mst_5.txt
│   ├── mst_100.txt
│   ├── mst_1000.txt
│   ├── mst_5000.txt
│   ├── mst_10000.txt
│   ├── mst_50000.txt
│   └── mst_100000.txt
│
├── output/
│   ├── mst_5_output.txt
│   ├── mst_100_output.txt
│   ├── mst_1000_output.txt
│   ├── mst_5000_output.txt
│   ├── mst_10000_output.txt
│   ├── mst_50000_output.txt
│   └── mst_100000_output.txt
│
├── Executables/
│   └── assignment3.exe
│
└── README.md
```

---

## 5. File Responsibilities

| File/Directory | Responsibility |
|---|---|
| `driver/driver.cpp` | Reads test files, constructs the graph, converts it to CSR, runs both MST algorithms, measures execution time, and writes results. |
| `src/edge.hpp` | Defines the graph edge structure. |
| `src/kruskal.hpp` | Declaration of Kruskal's algorithm. |
| `src/kruskal.cpp` | Implementation of Kruskal's algorithm and DSU operations. |
| `src/prim.hpp` | Declaration of Prim's algorithm. |
| `src/prim.cpp` | Implementation of Prim's algorithm. |
| `tests/` | Contains input graph test cases. |
| `output/` | Contains generated results. |
| `Executables/` | Contains the compiled executable. |
| `README.md` | Documentation for the assignment. |

---

## 6. Input Processing

The driver processes the test files present in the `tests` directory.

For each test case:

1. The graph input is read.
2. The graph is constructed.
3. The graph is converted to CSR representation.
4. Kruskal's algorithm is executed.
5. Prim's algorithm is executed.
6. Execution time is measured.
7. The results are written to the corresponding output file.

---

## 7. Output

The output contains information about both algorithms, including:

- Algorithm name
- MST edges
- Total MST weight
- Execution time

A typical output is of the form:

```text
Algorithm: Kruskal's MST

MST edges:
...

Total MST weight: ...

Execution time: ... ms


Algorithm: Prim's MST

MST edges:
...

Total MST weight: ...

Execution time: ... ms
```

---

## 8. Test Cases

The assignment contains test cases with different graph sizes:

| Test File | Number of Vertices |
|---|---:|
| `mst_5.txt` | 5 |
| `mst_100.txt` | 100 |
| `mst_1000.txt` | 1,000 |
| `mst_5000.txt` | 5,000 |
| `mst_10000.txt` | 10,000 |
| `mst_50000.txt` | 50,000 |
| `mst_100000.txt` | 100,000 |

---

## 9. Results

The measured results from the assignment are:

| Test Case | Kruskal Weight | Kruskal Time (ms) | Prim Weight | Prim Time (ms) |
|---|---:|---:|---:|---:|
| `mst_5.txt` | 16 | 0.0041 | 16 | 0.0069 |
| `mst_100.txt` | 2512 | 0.0657 | 2512 | 0.2032 |
| `mst_1000.txt` | 0 | 0.0073 | 0 | 0.0023 |
| `mst_5000.txt` | 101899 | 2.7236 | 101899 | 13.8162 |
| `mst_10000.txt` | 200867 | 5.4889 | 200867 | 29.038 |
| `mst_50000.txt` | 1023200 | 29.5573 | 1023200 | 179.992 |
| `mst_100000.txt` | 2015368 | 58.9275 | 2015368 | 380.409 |

The recorded results show that both algorithms produce the same total MST weight for the listed test cases.

---

## 10. Complexity

### Kruskal's Algorithm

The main computational operations are edge sorting and DSU operations.

```text
Time Complexity: O(E log E)
```

where `E` is the number of edges.

### Prim's Algorithm

The implementation uses a priority queue.

```text
Time Complexity: O((V + E) log V)
```

where:

- `V` = number of vertices
- `E` = number of edges

---

## 11. Compilation

Using GNU g++ and C++17:

```bash
g++ -std=c++17 -I common_csr common_csr/csr.cpp Assignment_03/src/kruskal.cpp Assignment_03/src/prim.cpp Assignment_03/driver/driver.cpp -o Assignment_03/Executables/assignment3.exe
```

---

## 12. Execution

From the repository root:

```bash
.\Assignment_03\Executablesssignment3.exe
```

The program processes the available test cases and generates the corresponding output files.

---

## 13. Correctness

For every listed test case, the total MST weight obtained using Kruskal's algorithm matches the total MST weight obtained using Prim's algorithm.

For example:

- `mst_5.txt` → MST weight = **16**
- `mst_100.txt` → MST weight = **2512**
- `mst_5000.txt` → MST weight = **101899**
- `mst_100000.txt` → MST weight = **2015368**

This provides a consistency check between the two independent MST implementations.

---

## 14. Execution Time Measurement

Execution time is measured separately for Kruskal's and Prim's algorithms using C++ `chrono`.

The reported time represents the measured execution of the respective algorithm.

---

## 15. Conclusion

This individual assignment implements two standard Minimum Spanning Tree algorithms:

- **Kruskal's Algorithm**
- **Prim's Algorithm**

The graph is represented using the common CSR component. The implementation is tested on graph sizes ranging from **5 vertices to 100,000 vertices**.

Both algorithms produce matching MST weights for the listed test cases, while the execution-time results allow their performance to be compared across different graph sizes.
