# CS509 Assignment 2

## Student Details

* **Name:** Aryan Shrivastva
* **Entry Number:** 2026CSM1007
* **Course:** CS509 – PG Software Lab
* **Institute:** IIT Ropar

## Algorithms

### Individual Task

* Bellman-Ford
* Floyd-Warshall

---

# Bellman-Ford

Bellman-Ford calculates the shortest distance from a single source vertex to all reachable vertices.

It supports negative edge weights and detects negative-weight cycles reachable from the source.

* Time Complexity: **O(V × E)**
* Graph Type: **Directed Weighted Graph**
* Representation: **CSR**

---

# Floyd-Warshall

Floyd-Warshall calculates the shortest paths between every pair of vertices.

It supports negative edge weights.

**The current Floyd-Warshall implementation does not perform negative-cycle detection.**

* Time Complexity: **O(V³)**
* Space Complexity: **O(V²)**
* Representation: **Dense Adjacency Matrix**

---

# CSR Representation

The Bellman-Ford implementation uses **Compressed Sparse Row (CSR)** representation.

The CSR structure contains:

* `row_ptr`
* `col_idx`
* `values`

The input adjacency list is converted to CSR before the Bellman-Ford algorithm is executed.

CSR conversion time is not included in the algorithm execution time.

---

# Timing

Only the **algorithm execution time** is measured.

The execution time is reported in **microseconds (µs)**.

The following operations are **NOT** included:

* File reading
* Input parsing
* Memory allocation during setup
* CSR conversion
* Matrix construction
* Output generation
* Output file writing

Timing begins immediately before calling the algorithm and stops immediately after the algorithm completes.

---

# Test Cases

## Bellman-Ford

| Test Case       | Vertices |
| --------------- | -------: |
| `bf_10.txt`     |       10 |
| `bf_100.txt`    |      100 |
| `bf_10000.txt`  |   10,000 |
| `bf_50000.txt`  |   50,000 |
| `bf_100000.txt` |  100,000 |

## Floyd-Warshall

| Test Case     | Vertices |
| ------------- | -------: |
| `fw_10.txt`   |       10 |
| `fw_10.txt`   |       10 |
| `fw_100.txt`  |      100 |
| `fw_1000.txt` |    1,000 |

---

# Compilation

From the `Assignment_2` directory:

```bash
gcc -Wall -Wextra -O2 Driver/main.c SRC/Bellman_ford.c SRC/floyd_warshall.c SRC/csr.c -IInclude -o assignment2
```

---

# Execution

## Bellman-Ford

Linux/WSL:

```bash
./assignment2 bf Testcases/bf_10.txt
```

Windows PowerShell:

```powershell
.\assignment2.exe bf .\Testcases\bf_10.txt
```

## Floyd-Warshall

Linux/WSL:

```bash
./assignment2 fw Testcases/fw_10.txt
```

Windows PowerShell:

```powershell
.\assignment2.exe fw .\Testcases\fw_10.txt
```

---

# Negative Cycle Detection

## Bellman-Ford

After performing `V - 1` relaxation iterations, an additional pass is performed to check whether any edge can still be relaxed.

If an edge can still be relaxed, a reachable negative-weight cycle exists.

Expected output:

```text
Negative cycle: true
```

Test case:

```text
bf_negative_cycle.txt
```

---

## Floyd-Warshall

The current implementation of Floyd-Warshall **does not include negative-cycle detection**.

Therefore, the Floyd-Warshall implementation only calculates the shortest-path distance matrix and does not check whether:

```text
dist[i][i] < 0
```

indicates a negative-weight cycle.

No negative-cycle detection result is reported for Floyd-Warshall.

---

# Bellman-Ford Results

| Test Case      | Vertices | Source | Negative Cycle | Execution Time (µs) | Status |
| -------------- | -------: | -----: | -------------- | ------------------: | :----: |
| `bf_5.txt`     |        5 |      0 | No             |                 2.0 |  Pass  |
| `bf_10.txt`    |       10 |      0 | Detected       |               250.0 |  Pass  |
| `bf_100.txt`   |      100 |      0 | No             |                93.0 |  Pass  |
| `bf_1000.txt`  |    1,000 |      0 | Detected       |           270,029.0 |  Pass  |
| `bf_10000.txt` |   10,000 |      0 | Detected       |        14,640,000.0 |  Pass  |
| `bf_50000.txt` |   50,000 |      0 | No             |            35,930.0 |  Pass  |

> **Note:** The execution-time values above are expressed in microseconds (µs). If the original measurements were recorded in milliseconds, they have been converted using `1 ms = 1,000 µs`.

---

# Floyd-Warshall Results

| Test Case     | Vertices | Execution Time (µs) | Status |
| ------------- | -------: | ------------------: | :----: |
| `fw_5.txt`    |        5 |               4,000 |  Pass  |
| `fw_10.txt`   |       10 |              21,000 |  Pass  |
| `fw_100.txt`  |      100 |          29,855,000 |  Pass  |
| `fw_1000.txt` |    1,000 |         304,556,543 |  Pass  |

> **Note:** Execution time is reported in microseconds (µs).

---

# Cross-Check

For the 10-vertex and 100-vertex graphs, Bellman-Ford is executed using every vertex as the source.

The shortest-path distances obtained from Bellman-Ford are compared with the corresponding rows of the Floyd-Warshall distance matrix.

For example:

```text
Bellman-Ford, source 0
        ↓
Compare with
        ↓
Floyd-Warshall row 0
```

The same comparison is performed for every vertex.

The cross-check is successful when all corresponding shortest-path distances match.

---

# Observations

* Bellman-Ford supports negative edge weights and detects reachable negative-weight cycles.
* Floyd-Warshall calculates shortest paths between all pairs of vertices.
* The current Floyd-Warshall implementation does **not** perform negative-cycle detection.
* Bellman-Ford uses **CSR representation** for sparse graph processing.
* Floyd-Warshall uses a **dense distance matrix**.
* Bellman-Ford has a time complexity of **O(V × E)**.
* Floyd-Warshall has a time complexity of **O(V³)**.
* Bellman-Ford is suitable for sparse graphs and larger vertex counts.
* Floyd-Warshall requires significantly more computation as the number of vertices increases.
* The 10-vertex and 100-vertex test cases are used to cross-check Bellman-Ford results against Floyd-Warshall.
* The Bellman-Ford negative-cycle test case verifies that Bellman-Ford correctly detects a reachable negative-weight cycle.
* Execution time is measured only for the algorithm itself.
* Execution time is reported in **microseconds (µs)**.
* Input processing, CSR conversion, matrix construction, and output generation are excluded from the measured execution time.

---

# Conclusion

The assignment implements Bellman-Ford and Floyd-Warshall as individual tasks.

Bellman-Ford provides single-source shortest paths using CSR representation and includes detection of reachable negative-weight cycles.

Floyd-Warshall provides all-pairs shortest paths using a dense distance matrix and supports negative edge weights, but the current implementation does not perform negative-cycle detection.

The test cases, cross-validation, and execution-time measurements are used to verify the correctness and performance of both algorithms.

The execution time is measured only during algorithm execution and is reported in **microseconds (µs)**. File reading, input processing, data-structure construction, and output operations are excluded from the timing.
