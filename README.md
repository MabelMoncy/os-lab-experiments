# OS Lab Exam Preparation

This repository collects the OS lab experiment code provided by the instructor to help with study and exam preparation. It contains example programs and small simulations illustrating core operating systems concepts used in lab assignments and exams.

Contents
- Example C programs for scheduling, synchronization, paging, IPC, and related topics.

Repository layout
- `All_Programs/` — main set of exercises and example programs.
- `Day_1_Batch/` — Day 1 practice exercises.
- `Day_2_Batch/` — Day 2 practice exercises.

Quick start

1. Clone the repository:

```
git clone https://github.com/MabelMoncy/os-lab-experiments
```

2. Change into the repository folder:

```
cd os-lab-experiments
```

3. Install a C compiler if needed (Debian/Ubuntu):

```
sudo apt update
sudo apt install build-essential
```

4. Compile a program .

```
# compile
gcc program_name.c -o program_name
```

5. Run the compiled program:

```
./program_name
```

Notes & tips
- Many programs use POSIX APIs (threads, message queues, shared memory). Run them on a Linux/Unix system.
- Read comments inside source files for input format and usage notes.
- If a program requires additional arguments or input files, the source file usually documents that at the top.

**Good luck with your exam — test the programs locally and read the code to understand behaviour.**

