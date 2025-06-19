# 🚀 Parallel Programming with OpenMP & MPI

Welcome to the **Parallel Programming Practice Repository**. This repo contains hands-on programs, concepts, and documentation related to parallel programming using **OpenMP**, **MPI**, and **fundamentals of GPU computing**.

## 📚 Topics Covered

This repository is structured to help beginners and intermediate users understand and implement parallel programming techniques. The content is organized by topics and day-wise practice.

### ✅ Parallel Programming Fundamentals
- What is Parallel Programming?
- Shared vs Distributed Memory Models
- CPU vs GPU Processing
- Speedup, Scalability, Amdahl’s Law

### 💡 OpenMP (Open Multi-Processing)
- Introduction to OpenMP and how it enables multithreading
- Basic OpenMP structure with `#pragma omp`
- `parallel`, `for`, `sections`, `critical`, `barrier`, `single` constructs
- Understanding race conditions and how to handle them
- Clauses: `private`, `shared`, `firstprivate`, `lastprivate`, `reduction`, `copyin`, `copyprivate`
- Scheduling strategies: `static`, `dynamic`, `guided`
- Nested parallelism and synchronization mechanisms

### 🔄 MPI (Message Passing Interface)
- Basics of MPI programming
- Process vs Thread model
- `MPI_Init`, `MPI_Comm_rank`, `MPI_Comm_size`, `MPI_Send`, `MPI_Recv`, `MPI_Bcast`, `MPI_Reduce`, etc.
- Point-to-point vs Collective communication
- MPI programs for sum, max, broadcasting arrays
- Performance considerations in MPI

### 🧠 CUDA (Conceptual References)
- What is CUDA and how it differs from OpenMP/MPI
- Role of GPU in high-performance computing
- Concepts like grid, block, thread hierarchy

## 🗂️ Repository Structure

