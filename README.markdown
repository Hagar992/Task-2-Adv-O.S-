# Disk Scheduling Simulator

A C program to simulate disk scheduling algorithms: **FCFS**, **SCAN**, and **C-SCAN**. It calculates total seek time and displays the order of disk requests based on the chosen algorithm.

## ✨ Features
- Implements **FCFS**, **SCAN**, and **C-SCAN** disk scheduling algorithms.
- User inputs:
  - Number of disk requests.
  - Disk request queue (cylinder numbers).
  - Initial head position.
  - Total number of cylinders.
  - Algorithm choice (`fcfs`, `scan`, or `cscan`).
- Outputs the request order and total seek time.

## 🛠️ Requirements
- C compiler (e.g., GCC).
- Standard C libraries: `stdio.h`, `stdlib.h`, `string.h`.

## 🚀 Getting Started

### Compilation
1. Clone or download the repository.
2. Open a terminal in the project directory.
3. Compile the code:
   ```bash
   gcc disk_scheduling.c -o disk_scheduling
   ```

### Execution
4. Run the program:
   ```bash
   ./disk_scheduling
   ```

## 📋 Usage
1. Launch the program.
2. Enter the number of disk requests (e.g., `8`).
3. Input the disk request queue (e.g., `98 183 37 122 14 124 65 67`).
4. Specify the initial head position (e.g., `53`).
5. Provide the total number of cylinders (e.g., `200`).
6. Select an algorithm (`fcfs`, `scan`, or `cscan`).
7. View the request order and total seek time.

### Example
**Input:**
```
Enter number of disk requests: 8
Enter the disk request queue: 98 183 37 122 14 124 65 67
Enter initial head position: 53
Enter total number of cylinders: 200
Enter algorithm (fcfs / scan / cscan): scan
```

**Output:**
```
SCAN Order: 53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 37 -> 14
Total Seek Time = 332
```

## 🧠 Algorithms
- **FCFS (First-Come, First-Serve)**: Services requests in the order they arrive.
- **SCAN**: Moves the head in one direction (toward higher cylinders), services requests, then reverses after hitting the disk end.
- **C-SCAN**: Like SCAN, but jumps to cylinder 0 after reaching the maximum cylinder, then services requests in the reverse direction.

## ⚠️ Limitations
- Supports up to 100 requests (set by `MAX`).
- Limited input validation; ensure inputs are valid.
- Assumes requests and head position are within 0 to `max_cyl - 1`.

## 🌟 Contributing
1. Fork the repository.
2. Add improvements or new features (e.g., more algorithms).
3. Submit a pull request with clear descriptions.

## 📜 License
Licensed under the [MIT License](LICENSE).