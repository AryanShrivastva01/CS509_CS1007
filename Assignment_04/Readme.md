# CS509 - PG Software Lab

## Assignment 04 - Individual Assignment

### Student Information

**Name:** Aryan Shrivastva  
**Roll No:** 2026CSM1007  

---

## Assignment Overview

This assignment is completed as an **Individual Assignment**.

The assignment implements two graph algorithms:

1. **PageRank**
2. **Welsh-Powell Vertex Coloring**

Both algorithms use the common CSR (Compressed Sparse Row) implementation from the previous assignment.

The programs calculate:

- PageRank values
- Number of colors used
- Execution time
- Number of iterations and convergence status for PageRank

---

## Algorithms Implemented

### 1. PageRank

PageRank is used to assign an importance score to each vertex in a directed graph.

The algorithm starts by assigning an equal rank to every vertex.

The PageRank of each vertex is then repeatedly updated using the ranks of its incoming neighbours.

A damping factor is used during the calculation.

The algorithm continues until:

- The difference between two consecutive PageRank vectors is smaller than the specified tolerance, or
- The maximum number of iterations is reached.

The implementation also handles vertices having no outgoing edges.

---

### 2. Welsh-Powell Vertex Coloring

Welsh-Powell is a greedy graph coloring algorithm for an undirected graph.

The algorithm:

1. Calculates the degree of every vertex.
2. Sorts the vertices in decreasing order of degree.
3. Processes vertices in the sorted order.
4. Assigns the smallest available color.
5. Ensures that adjacent already-colored vertices do not have the same color.

The program reports the total number of colors used and the execution time.

---

## Common CSR

A common CSR (Compressed Sparse Row) implementation is used for storing the graph.

The common CSR component is located outside the Assignment 04 folder:

```text
common_csr/
├── csr.hpp
└── csr.cpp
```

The CSR structure contains:

```cpp
vector<int> row_ptr;
vector<int> col_idx;
vector<int> values;
```

The graph is initially read as an adjacency list and then converted into CSR using:

```cpp
convertToCSR()
```

The CSR conversion is performed before the algorithm timing starts.

The CSR conversion code is reused from the previous assignment and is not copied into Assignment 04.

---

## Language and Environment

- **Programming Language:** C++
- **Compiler:** GNU g++
- **C++ Standard:** C++17
- **Operating System:** Windows 11 / Linux compatible

---

## Repository Structure

```text
Assignment_04/
│
├── driver/
│   ├── driver_pagerank.cpp
│   └── driver_vertex_coloring.cpp
│
├── src/
│   ├── pagerank.hpp
│   ├── pagerank.cpp
│   ├── vertex_coloring.hpp
│   └── vertex_coloring.cpp
│
├── tests/
│   ├── PageRank_tests/
│   │   ├── pagerank_10.txt
│   │   ├── pagerank_100.txt
│   │   ├── pagerank_1000.txt
│   │   ├── pagerank_10000.txt
│   │   └── pagerank_50000.txt
│   │
│   └── VertexColoring_tests/
│       ├── color_10.txt
│       ├── color_100.txt
│       ├── color_10000.txt
│       ├── color_50000.txt
│       └── color_100000.txt
│
├── outputs/
│   ├── pagerank/
│   └── vertex_coloring/
│
├── bin/
│   ├── pagerank.exe
│   └── vertex_coloring.exe
│
└── README.md

common_csr/
├── csr.hpp
└── csr.cpp
```

---

## File Responsibilities

| File/Directory | Responsibility |
|---|---|
| `driver/driver_pagerank.cpp` | Reads PageRank input, creates the adjacency list, converts it to CSR, runs PageRank, measures execution time, and writes output. |
| `driver/driver_vertex_coloring.cpp` | Reads Vertex Coloring input, creates the adjacency list, converts it to CSR, runs Vertex Coloring, measures execution time, and writes output. |
| `src/pagerank.hpp` | Declaration of the PageRank class. |
| `src/pagerank.cpp` | Implementation of the PageRank algorithm. |
| `src/vertex_coloring.hpp` | Declaration of the Vertex Coloring class. |
| `src/vertex_coloring.cpp` | Implementation of Greedy and Welsh-Powell coloring. |
| `tests/` | Contains input graph test cases. |
| `outputs/` | Contains generated output files. |
| `bin/` | Contains compiled executables. |
| `common_csr/` | Shared CSR implementation from the previous assignment. |
| `README.md` | Documentation for Assignment 04. |

---

## Input Format

The Assignment 04 graph inputs use an adjacency-list representation.

The general graph information begins with:

```text
V E
```

where:

- `V` = number of vertices
- `E` = number of edges

The graph uses vertex numbering from `0` to `V-1`.

### Vertex Coloring

Vertex Coloring uses an **undirected, unweighted graph**.

Each undirected edge is stored in the adjacency lists of both endpoints.

The number of undirected edges is counted once in `E`.

The graph contains no self-loops.

### PageRank

PageRank uses a **directed graph**.

Only outgoing edges of each vertex are stored in the adjacency list.

The graph is unweighted.

---

## Required Test Cases

According to the assignment guideline, the required graph sizes are:

### Vertex Coloring

```text
10
100
10,000
50,000
100,000
```

Large graphs should remain sparse, approximately:

```text
E = 2V to 4V
```

where practical.

### PageRank

```text
10
100
1,000
10,000
50,000
```

The 50,000-vertex graph is the largest required PageRank test.

A 100,000-vertex PageRank test is optional.

---

## Test Files

### PageRank

```text
pagerank_10.txt
pagerank_100.txt
pagerank_1000.txt
pagerank_10000.txt
pagerank_50000.txt
```

### Vertex Coloring

```text
color_10.txt
color_100.txt
color_10000.txt
color_50000.txt
color_100000.txt
```

The driver processes the input file supplied to it.

The wrapper automatically processes all `.txt` files present in the corresponding test directory.

---

## Input Processing

For each graph test case:

1. The input file is opened.
2. The number of vertices and edges is read.
3. The adjacency list is created.
4. The graph is converted into CSR using `convertToCSR()`.
5. The CSR conversion is completed before timing.
6. The selected algorithm is executed.
7. Execution time is measured.
8. The result is written to an output file.

The CSR conversion time is not included in the reported algorithm runtime.

---

## Output Format

### PageRank

The PageRank output contains:

- Number of vertices
- Number of edges
- PageRank value of each vertex
- Number of iterations
- Convergence status
- Execution time

Example:

```text
Number of vertices: 10
Number of edges: ...

----- PageRank -----

Vertex 0: ...
Vertex 1: ...
Vertex 2: ...

Iterations: ...
Converged: Yes

Time: ... microseconds
```

### Vertex Coloring

The Vertex Coloring output contains:

- Number of vertices
- Number of edges
- Number of colors used
- Execution time

Example:

```text
Number of vertices: 10
Number of edges: ...

----- Greedy Coloring -----

Number of colors: ...
Time: ... microseconds

----- Welsh-Powell Coloring -----

Number of colors: ...
Time: ... microseconds
```

---

## Output Directories

PageRank output files are stored in:

```text
Assignment_04/outputs/pagerank/
```

Vertex Coloring output files are stored in:

```text
Assignment_04/outputs/vertex_coloring/
```

For example:

```text
pagerank_10.txt
```

produces:

```text
pagerank_10_output.txt
```

and:

```text
color_10.txt
```

produces:

```text
color_10_output.txt
```

---

## Compilation

### PageRank

From the project root:

```bash
g++ -std=c++17 -I common_csr common_csr/csr.cpp Assignment_04/src/pagerank.cpp Assignment_04/driver/driver_pagerank.cpp -o Assignment_04/bin/pagerank
```

### Vertex Coloring

```bash
g++ -std=c++17 -I common_csr common_csr/csr.cpp Assignment_04/src/vertex_coloring.cpp Assignment_04/driver/driver_vertex_coloring.cpp -o Assignment_04/bin/vertex_coloring
```

On Windows, the executable names may use `.exe`.

---

## Running the Programs

### PageRank

Linux:

```bash
./Assignment_04/bin/pagerank Assignment_04/tests/PageRank_tests/pagerank_10.txt
```

Windows:

```powershell
.\Assignment_04\bin\pagerank.exe Assignment_04\tests\PageRank_tests\pagerank_10.txt
```

### Vertex Coloring

Linux:

```bash
./Assignment_04/bin/vertex_coloring Assignment_04/tests/VertexColoring_tests/color_10.txt
```

Windows:

```powershell
.\Assignment_04\bin\vertex_coloring.exe Assignment_04\tests\VertexColoring_tests\color_10.txt
```

---

## Running Through Wrapper

The assignment can also be executed using the common wrapper.

Run the wrapper and select:

```text
4. Assignment 04
```

The Assignment 04 menu provides:

```text
1. PageRank
2. Vertex Coloring
3. Run Both
4. Back to Main Menu
```

### PageRank

Selecting:

```text
1. PageRank
```

automatically runs all PageRank `.txt` test files.

### Vertex Coloring

Selecting:

```text
2. Vertex Coloring
```

automatically runs all Vertex Coloring `.txt` test files.

### Both

Selecting:

```text
3. Run Both
```

runs all required PageRank and Vertex Coloring test cases.

The wrapper does not require test filenames to be entered manually.

---

## Execution Time Measurement

Execution time is measured using C++ `chrono`.

The timing starts after the graph has already been converted into CSR.

Therefore, CSR preprocessing time is not included in the reported algorithm execution time.

The reported time represents the measured execution of the algorithm itself.

---

## Complexity

### PageRank

For each iteration, the algorithm processes the vertices and their outgoing edges.

The approximate complexity is:

```text
O(I(V + E))
```

where:

- `V` = number of vertices
- `E` = number of edges
- `I` = number of iterations

### Greedy Vertex Coloring

The implementation examines the neighbours of each vertex.

The running time depends on the number of vertices and edges.

### Welsh-Powell

The implementation first sorts the vertices by degree.

The sorting step takes approximately:

```text
O(V log V)
```

followed by the coloring process over the graph edges.

---

## Assignment Requirements Followed

The implementation follows the important graph requirements from the guideline:

- Graph input is stored as an adjacency list.
- Vertex Coloring uses an undirected, unweighted graph.
- PageRank uses a directed, unweighted graph.
- Vertex numbering follows the `0` to `V-1` convention.
- The adjacency list is converted to CSR before the algorithm.
- The common CSR conversion from the previous assignment is reused.
- CSR conversion time is excluded from algorithm timing.
- Required graph sizes are tested.
- Output is generated separately for each test case.
- The number of edges and graph properties can be recorded for each test case.

---

## Individual Work

This is an **individual assignment**.

The implementation and testing of:

- PageRank
- Greedy Vertex Coloring
- Welsh-Powell Vertex Coloring

are completed individually.

---

---

---

# Observation Tables

## 1. PageRank Observation Table

| Test Case | Vertices (V) | Damping | Sum of Ranks | Iterations | Converged | Execution Time |
|---|---:|---:|---:|---:|---|---:|
| `pagerank_10.txt` | 4* | 1 | 1 | 0 | false | 1 microseconds |
| `pagerank_100.txt` | 100 | 0 | 1 | 0 | false | 1 microseconds |
| `pagerank_1000.txt` | 1,000 | 0 | 1 | 0 | false | 6 microseconds |
| `pagerank_10000.txt` | 10,000 | 0 | 1 | 0 | false | 53 microseconds |
| `pagerank_50000.txt` | 50,000 | 0 | 1 | 0 | false | 420 microseconds |

### PageRank Observation

The sum of PageRank values is `1` in all recorded outputs. The recorded iteration count is `0` and the convergence flag is `false` in the supplied output records. The measured execution time increases from `1` microsecond for the smaller tests to `420` microseconds for the 50,000-vertex test.

\* The supplied `pagerank_10_output.txt` contains ranks for vertices `0` to `3`, so the output itself records 4 vertices.

**Note:** Edge counts are not included in this observation table.

---

## 2. Vertex Coloring Observation Table

| Test Case | Vertices (V) | Colors Used | Execution Time |
|---|---:|---:|---:|
| `color_10.txt` | 10 | 4 | 7 microseconds |
| `color_100.txt` | 100 | 6 | 55 microseconds |
| `color_10000.txt` | 10,000 | 7 | 22,165 microseconds |
| `color_50000.txt` | 50,000 | 5 | 42,347 microseconds |
| `color_100000.txt` | 100,000 | 5 | 115,603 microseconds |

### Vertex Coloring Observation

The submitted output records show that the algorithm produced color assignments using 4, 6, 7, 5, and 5 colors respectively for the five test cases.

The execution time increases for the larger test cases, reaching `115,603` microseconds for the 100,000-vertex test.

**Note:** Edge counts are not included in this observation table.

---

## Conclusion

The two algorithms were tested separately on graphs of increasing size.

For **PageRank**, the recorded execution time increased from `1` microsecond for the smaller inputs to `420` microseconds for the largest supplied test.

For **Vertex Coloring**, the recorded execution time increased from `7` microseconds for the 10-vertex test to `115,603` microseconds for the 100,000-vertex test.

The actual measured execution times are machine-dependent and are taken directly from the supplied output records.
