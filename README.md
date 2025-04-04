# Shared-Memory-Communication-Program
This C program demonstrates basic shared memory communication between processes. It creates a shared memory segment, writes data to it, and then reads from it. The program serves as a simple example of inter-process communication (IPC) using System V shared memory.

Features
Creates a shared memory segment

Writes user input to shared memory

Reads from shared memory

Basic error handling for shared memory operations

Input validation

Dependencies
Standard C libraries: stdio.h, stdlib.h, string.h

System V IPC headers: sys/types.h, sys/ipc.h, sys/shm.h

Compilation and Usage
Compile the program:

bash
Copy
gcc main.c -o shared_memory_demo
Run the program:

bash
Copy
./shared_memory_demo
Enter input when prompted (program will store first input line in shared memory)

Input Handling
The program reads up to 3 lines of input (MAX_CHAR = 128 characters per line)

Input lines are truncated at newline characters

Displays "ERR" if input exceeds maximum length

Terminates on "END" command (currently commented out)

Shared Memory Operations
Creates a shared memory segment with key generated from "/tmp" path

Allocates 2048 bytes (MAX_SIZE) of shared memory

Attaches to the shared memory segment

Copies first input line to shared memory

Prints the shared memory content

Detaches from shared memory before exiting

Error Handling
The program checks for and reports errors in:

Shared memory key generation (ftok)

Shared memory segment creation (shmget)

Shared memory attachment (shmat)

Example Session
Copy
Hello, shared memory!
this is the shared memory value Hello, shared memory!
Additional input line
Another line
Notes
The shared memory segment persists after program termination (use ipcs to view and ipcrm to remove)

Currently only the first input line is stored in shared memory

Error cases for input length are detected but don't terminate the program

Shared memory permissions are set to 0600 (read/write for owner only)

Limitations
No cleanup of shared memory segment in the code

Limited to single-process demonstration (no actual inter-process communication shown)

Basic error handling with immediate exit on some failures

Security Considerations
Uses fixed path ("/tmp") for key generation

Shared memory permissions are restrictive (owner-only) by default
