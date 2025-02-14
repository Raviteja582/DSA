## Algorithms:

1. Bit Manipulation
2. Sorting
3. Searching 
4. Two Pointers
5. Greedy
6. Recursion
7. Backtracking
8. Dynamic Programming


## Data Structures

1. Stacks & Queues - Different type of queues: Deque, Circular queue
2. Heaps - Priority_Queue ( Min, Max )
3. Graphs


## Miscellaneous
1. Combinatorics
2. Number theory & Math
3. Fibonacci and Primes


## Settings
Add below configurations to settings.json for code runner extension  to delete binaries after execution.

  - Linux:
  ```json
      "code-runner.executorMap": {
        // -lm flag for linking c file with libm (will enable use of math.h in VsCode)
        "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt -lm && $dir$fileNameWithoutExt && rm $dir$fileNameWithoutExt",
        "cpp": "cd $dir && g++ $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt && rm $dir$fileNameWithoutExt"

        // "cpp":"cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt.exe && $dir$fileNameWithoutExt && del $dir$fileNameWithoutExt.exe"
      }
  ```
  - Windows:
  ```json
    "code-runner.executorMap": {
        // -lm flag for linking c file with libm (will enable use of math.h in VsCode)
      "c": "cd $dir && gcc $fileName -o $fileNameWithoutExt.exe -lm && .\\$dir$fileNameWithoutExt.exe && del $dir$fileNameWithoutExt.exe",
      "cpp":"cd $dir && g++ -std=c++17 $fileName -o $fileNameWithoutExt.exe && .\\$dir$fileNameWithoutExt.exe && del $dir$fileNameWithoutExt.exe"
    }
  ```