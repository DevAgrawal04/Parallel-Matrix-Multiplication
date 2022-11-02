# Matrix Multiplication 

## Requirements
- GNU Compiler Collection (GCC)
- OpenMP 

For an installation guide, kindly refer the [References](#references)

---
## Compiling the File

To compile the file, run the following command:
>  gcc -fopenmp matrix_mul.c 

- ##### Add an  _-lm_ at the end if you're using math.h and the math library isn't linked with your binary by default.

Here, matrix_mul.c is the name of the file we're trying to compile.

A file titled **a.out** (assembler output) will get created.


Run the file using the following command:
> time ./a.out

We prefix the run command with the keyword [**time**](https://www.geeksforgeeks.org/time-command-in-linux-with-examples/#:~:text=time%20command%20in%20Linux%20is,a%20command%20when%20it%20terminates. "GeeksForGeeks") to print the runtime of the file onto the terminal.
- <ins>‘real‘ time</ins> is the time elapsed wall clock time taken by a command to get executed, while <ins>‘user‘</ins> and <ins>‘sys‘ time</ins> are the number of CPU seconds that command uses in user and kernel mode respectively. 

---
## Achieving Synchronization 

- This solution deals with Data Parallelism (_distributes subsets of the same data 
across multiple cores, same operation on each_). 
- Since there are no shared variables there are no race conditions and hence synchronization is achieved.

---
## Thread Performance Analysis
The variation of turnaround time of the solution with degree of parallelisation for different implementations has been plotted as follows:

![Time vs Degree of Parallelisation for rand()](./Thread%20Performance%20Analysis%20Matrix%20Multiplication.jpeg) 

rand() function isn't thread safe in linux, thus rand_r() function is used for generating random numbers.

For further information on rand_r(), kindly refer the [References](https://github.com/DevAgrawal04/OperatingSystems_Assignment_CS252/tree/main/Q_4.25#references)

##### (Kindly note that this graph is for representation purposes only, and the values are subject to change as the performance mainly depends on how the tasks are divided among the threads, which is handled internally by OpenMP.) 

---
## Additional Hardware Information

### Kernel Version
Kernel version can be found using the following command in linux based terminals:
> uname -r 

> 5.10.16.3-microsoft-standard-WSL2

### Processor Details
- Name: [AMD Ryzen™ 7 5800H](https://www.amd.com/en/products/apu/amd-ryzen-7-5800h "Official Specs by AMD")
- Number of CPU Cores: 8
- Number of Threads: 16
- Base Clock: 3.2GHz
- Max Boost Clock: Upto 4.4 Ghz
- L2 Cache: 4 MB
- L3 Cache: 16 MB   
- Default TDP: 45W

---
## References
1. [Open MP Documentation](https://github.com/ResearchComputing/Documentation/blob/main/docs/programming/OpenMP-C.md "GitHub")
2. [OpenMP and GCC Installation Guide](https://www.geeksforgeeks.org/openmp-introduction-with-installation-guide/ "GeeksForGeeks")
3. [Time command in Linux with examples](https://www.geeksforgeeks.org/time-command-in-linux-with-examples/#:~:text=time%20command%20in%20Linux%20is,a%20command%20when%20it%20terminates. "GeeksForGeeks")
4. [Documentation for rand_r()](https://linux.die.net/man/3/rand_r "linux.die.net")
5. [Documentation for calloc()](https://pubs.opengroup.org/onlinepubs/009696799/functions/calloc.html "pubs.opengroup.org")
6. Operating Systems Lecture Slides by Dr. Mohit P Tahiliani
7. Operating Systems Concepts 10th Ed by Abraham Silberschatz, Peter Baer Galvin and Greg Gagne

---
## Author
[@DevAgrawal04](https://github.com/DevAgrawal04 "GitHub")

- [LinkedIn](https://www.linkedin.com/in/dev-agrawal-04/ "dev-agrawal-04")
  
For any queries or feedback, please feel free to reach out.