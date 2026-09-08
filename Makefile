# =========================================================
# Makefile for CS509_CS1007
#
# Compatible with:
#   - Linux
#   - Windows + MinGW/MSYS2
#
# Usage:
#   make          -> Build everything
#   make wrapper  -> Build wrapper
#   make a1       -> Build Assignment 01
#   make a2       -> Build Assignment 02
#   make a3       -> Build Assignment 03
#   make a4       -> Build Assignment 04
#   make run      -> Build everything and run wrapper
#   make clean    -> Remove compiled files
# =========================================================


# =========================================================
# COMPILER
# =========================================================

CXX = g++
CXXFLAGS = -std=c++17 -O2


# =========================================================
# OPERATING SYSTEM DETECTION
# =========================================================

ifeq ($(OS),Windows_NT)

    # -------------------------
    # Windows
    # -------------------------

    EXE = .exe
    RM = del /Q
    RMDIR = rmdir /S /Q
    MKDIR = if not exist

else

    # -------------------------
    # Linux / Unix
    # -------------------------

    EXE =
    RM = rm -f
    RMDIR = rm -rf
    MKDIR = mkdir -p

endif


# =========================================================
# DEFAULT TARGET
# =========================================================

all: wrapper a1 a2 a3 a4


# =========================================================
# COMMON WRAPPER
# =========================================================

wrapper: Common_wrapper/wrapper$(EXE)


Common_wrapper/wrapper$(EXE): Common_wrapper/wrapper.cpp
	$(CXX) $(CXXFLAGS) Common_wrapper/wrapper.cpp -o Common_wrapper/wrapper$(EXE)


# =========================================================
# ASSIGNMENT 01
# CSR + GEMM + BLOCKED GEMM
# =========================================================

a1: Assignment_01/csr$(EXE) Assignment_01/matrix$(EXE)


Assignment_01/csr$(EXE): \
	Assignment_01/driver/driver_csr.cpp \
	Assignment_01/src/csr.cpp
	$(CXX) $(CXXFLAGS) \
		-IAssignment_01/src \
		Assignment_01/driver/driver_csr.cpp \
		Assignment_01/src/csr.cpp \
		-o Assignment_01/csr$(EXE)


Assignment_01/matrix$(EXE): \
	Assignment_01/driver/driver_gemm.cpp \
	Assignment_01/src/GEMM.cpp \
	Assignment_01/src/B_GEMM.cpp
	$(CXX) $(CXXFLAGS) \
		-IAssignment_01/src \
		Assignment_01/driver/driver_gemm.cpp \
		Assignment_01/src/GEMM.cpp \
		Assignment_01/src/B_GEMM.cpp \
		-o Assignment_01/matrix$(EXE)


# =========================================================
# ASSIGNMENT 02
# BELLMAN-FORD + FLOYD-WARSHALL
# =========================================================

a2: Assignment_02/bellman$(EXE) Assignment_02/floyd$(EXE)


Assignment_02/bellman$(EXE): \
	Assignment_02/driver/Bellmanford_driver.cpp \
	Assignment_02/src/csr.cpp \
	Assignment_02/src/Bellmanford.cpp
	$(CXX) $(CXXFLAGS) \
		-IAssignment_02/src \
		Assignment_02/driver/Bellmanford_driver.cpp \
		Assignment_02/src/csr.cpp \
		Assignment_02/src/Bellmanford.cpp \
		-o Assignment_02/bellman$(EXE)


Assignment_02/floyd$(EXE): \
	Assignment_02/driver/Floyd_driver.cpp \
	Assignment_02/src/csr.cpp \
	Assignment_02/src/FloydWarshall.cpp
	$(CXX) $(CXXFLAGS) \
		-IAssignment_02/src \
		Assignment_02/driver/Floyd_driver.cpp \
		Assignment_02/src/csr.cpp \
		Assignment_02/src/FloydWarshall.cpp \
		-o Assignment_02/floyd$(EXE)


# =========================================================
# ASSIGNMENT 03
# KRUSKAL + PRIM
# =========================================================

a3: Assignment_03/assignment3$(EXE)


Assignment_03/assignment3$(EXE): \
	Assignment_03/driver/driver.cpp \
	Assignment_03/src/kruskal.cpp \
	Assignment_03/src/prim.cpp \
	common_csr/csr.cpp
	$(CXX) $(CXXFLAGS) \
		-Icommon_csr \
		common_csr/csr.cpp \
		Assignment_03/src/kruskal.cpp \
		Assignment_03/src/prim.cpp \
		Assignment_03/driver/driver.cpp \
		-o Assignment_03/assignment3$(EXE)


# =========================================================
# ASSIGNMENT 04
# VERTEX COLORING + PAGERANK
# =========================================================

a4: Assignment_04/vertex_coloring$(EXE) \
	Assignment_04/pagerank$(EXE)


Assignment_04/vertex_coloring$(EXE): \
	Assignment_04/driver/driver_vertex_coloring.cpp \
	Assignment_04/src/vertex_coloring.cpp \
	common_csr/csr.cpp
	$(CXX) $(CXXFLAGS) \
		-Icommon_csr \
		common_csr/csr.cpp \
		Assignment_04/src/vertex_coloring.cpp \
		Assignment_04/driver/driver_vertex_coloring.cpp \
		-o Assignment_04/vertex_coloring$(EXE)


Assignment_04/pagerank$(EXE): \
	Assignment_04/driver/driver_pagerank.cpp \
	Assignment_04/src/pagerank.cpp \
	common_csr/csr.cpp
	$(CXX) $(CXXFLAGS) \
		-Icommon_csr \
		common_csr/csr.cpp \
		Assignment_04/src/pagerank.cpp \
		Assignment_04/driver/driver_pagerank.cpp \
		-o Assignment_04/pagerank$(EXE)


# =========================================================
# RUN
# =========================================================

run: all
ifeq ($(OS),Windows_NT)
	Common_wrapper\wrapper.exe
else
	./Common_wrapper/wrapper
endif


# =========================================================
# CLEAN
# =========================================================

clean:
ifeq ($(OS),Windows_NT)
	@if exist Common_wrapper\wrapper.exe del /Q Common_wrapper\wrapper.exe
	@if exist Assignment_01\csr.exe del /Q Assignment_01\csr.exe
	@if exist Assignment_01\matrix.exe del /Q Assignment_01\matrix.exe
	@if exist Assignment_02\bellman.exe del /Q Assignment_02\bellman.exe
	@if exist Assignment_02\floyd.exe del /Q Assignment_02\floyd.exe
	@if exist Assignment_03\assignment3.exe del /Q Assignment_03\assignment3.exe
	@if exist Assignment_04\vertex_coloring.exe del /Q Assignment_04\vertex_coloring.exe
	@if exist Assignment_04\pagerank.exe del /Q Assignment_04\pagerank.exe
else
	$(RM) Common_wrapper/wrapper
	$(RM) Assignment_01/csr
	$(RM) Assignment_01/matrix
	$(RM) Assignment_02/bellman
	$(RM) Assignment_02/floyd
	$(RM) Assignment_03/assignment3
	$(RM) Assignment_04/vertex_coloring
	$(RM) Assignment_04/pagerank
endif


# =========================================================
# PHONY TARGETS
# =========================================================

.PHONY: all wrapper a1 a2 a3 a4 run clean