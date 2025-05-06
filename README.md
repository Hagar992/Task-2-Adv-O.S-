Disk Scheduling Simulator
This is a C program that simulates disk scheduling algorithms, including FCFS (First-Come, First-Serve), SCAN, and C-SCAN. The program calculates the total seek time and displays the order of disk requests based on the selected algorithm.
Features

Supports three disk scheduling algorithms: FCFS, SCAN, and C-SCAN.
Accepts user input for:
Number of disk requests.
Disk request queue.
Initial head position.
Total number of cylinders.
Choice of algorithm.


Outputs the order of disk requests and the total seek time.

Requirements

A C compiler (e.g., GCC).
Standard C libraries (stdio.h, stdlib.h, string.h).

Compilation and Execution

Clone or download the repository.
Navigate to the project directory.
Compile the program:gcc disk_scheduling.c -o disk_scheduling


Run the program:./disk_scheduling



Usage

Run the program.
Enter the number of disk requests.
Input the disk request queue (space-separated integers).
Specify the initial head position.
Provide the total number of cylinders.
Choose the algorithm (fcfs, scan, or cscan).
The program will display the order of disk requests and the total seek time.

Example Input/Output
Input:
Enter number of disk requests: 8
Enter the disk request queue: 98 183 37 122 14 124 65 67
Enter initial head position: 53
Enter total number of cylinders: 200
Enter algorithm (fcfs / scan / cscan): scan

Output:
SCAN Order: 53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 37 -> 14
Total Seek Time = 332

Algorithms Explained

FCFS: Processes requests in the order they arrive.
SCAN: Moves the head in one direction (toward higher cylinders), services requests, then reverses direction after reaching the end.
C-SCAN: Similar to SCAN but resets the head to the opposite end (cylinder 0) after reaching the maximum cylinder, then services requests in the reverse direction.

Limitations

Maximum of 100 disk requests (defined by MAX).
Input validation is minimal; ensure valid inputs are provided.
Assumes all requests and head positions are within the cylinder range (0 to max_cyl - 1).

Contributing
Feel free to fork the repository, make improvements, and submit pull requests. Suggestions for additional algorithms or features are welcome!
License
This project is licensed under the MIT License.
