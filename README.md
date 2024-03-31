# LBYARCH
Lbyarch x86-to-C interface programming project

The program is done under the requirement of LBYARCH’s MP2 with the following specs:

![lbyarch specs](PNGs/lbyarch%20specs.PNG)


## The C Program

The C program allows the calling of both C and assembly kernels. The C program also tracks both the average time and number of execution of each kernel. We tested it using 3 vectors. 2^20, 2^24, and 2^29 as 2^30 was too much to handle for my computer. The sanity check done to see the correctness of both the C and assembly programs is if both programs have the same answer. The average time is calculated by executing each kernel 30 times.

## Kernel Comparison and Analysis




## Results 

### 2^20 DEBUG
![2^20 Debug](PNGs/2^20%20debug.PNG)
### 2^20 RELEASE
![2^20 Release](PNGs/2^20%20release.PNG)

### 2^24 DEBUG
![2^24 Debug](PNGs/2^24%20debug.PNG)
### 2^24 RELEASE
![2^24 Release](PNGs/2^24%20release.PNG)

### 2^29 DEBUG
![2^20 Debug](PNGs/2^29%20debug.PNG)
### 2^29 RELEASE
![2^29 Release](PNGs/2^29%20release.PNG)
