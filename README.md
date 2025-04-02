# ParallelMergeSort

## Overview
ParallelMergeSort is an implementation of the Merge Sort algorithm using multiple threads to improve performance.

![image](https://github.com/user-attachments/assets/cbd0f912-b542-451d-9d6d-80c366408174)


## Compilation and Execution
Follow these steps to compile and run the program:

### Step 1: Compile the source files
```sh
g++ -c MergeSort.cpp ParallelMergeSort.cpp
```

### Step 2: Link the object files and compile the main program
```sh
g++ -o main main.cpp MergeSort.o ParallelMergeSort.o
```

### Step 3: Run the executable
```sh
./main
```

## File Structure
- **main.cpp**: Entry point of the program.
- **MergeSort.cpp**: Implements the standard Merge Sort algorithm.
- **ParallelMergeSort.cpp**: Implements parallelized Merge Sort.
- **MergeSort.h**: Header file for MergeSort.cpp.
- **ParallelMergeSort.h**: Header file for ParallelMergeSort.cpp.

## Requirements
- **C++ Compiler**: Ensure you have `g++` installed.
- **Multi-threading Support**: The implementation may require OpenMP or pthreads if used for parallel execution.

## Contributing
Feel free to fork the repository, create a branch, make improvements, and submit a pull request.

## License
This project is licensed under the MIT License.
