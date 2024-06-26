# LBYARCH
Lbyarch x86-to-C interface programming project

The program is done under the requirement of LBYARCH’s MP2 with the following specs:

![lbyarch specs](PNGs/lbyarch%20specs.PNG)


## The C Program

The C program allows the calling of both C and assembly kernels. The C program also tracks both the average time and number of execution of each kernel. 

We tested it using 3 vectors. 2^20, 2^24, and 2^29 as 2^30 were too much to handle for my computer.

The sanity check done to see the correctness of both the C and assembly programs is if both programs have the same answer. The average time is calculated by executing each kernel 30 times.

## Kernel Comparison and Analysis

DEBUG AVERAGE TIME COMPARISON OF C AND ASM
|  TEST  |  C AVERAGE TIME  |  ASSEMBLY AVERAGE TIME  | 
| ------------- | ------------- | ------------- |
|  2^20  |  0.002633 seconds  |  0.000833 seconds  |
|  2^24  |  0.043700 seconds  |  0.012100 seconds  |
|  2^29  |  1.422933 seconds  |  0.392833 seconds  |

The average time for the assembly kernel is generally faster than its C counterpart. As the test variables grow arbitrarily large, the time it takes to complete the program also rises. Still, there is a significant period between the time it takes for the C kernel to finish and its assembly counterpart. The comparison shows that the performance of the assembly kernel outperforms its C counterpart. However, taking into consideration the readability and complexity of the written codes, the assembly kernel is more prone to errors than its C counterpart.

RELEASE AVERAGE TIME COMPARISON OF C AND ASM
|  TEST  |  C AVERAGE TIME  |  ASSEMBLY AVERAGE TIME  | 
| ------------- | ------------- | ------------- |
|  2^20  |  0.000733 seconds  |  0.000767 seconds  |
|  2^24  |  0.012167 seconds  |  0.012133 seconds  |
|  2^29  |  0.388567 seconds  |  0.392333 seconds  |

For release, the C kernel runs closely faster in comparison with the assembly kernel. For larger values, the C kernel runs faster for the release mode than its counterpart. This would infer that the release mode made the C kernel run faster due to the optimization process that is not present during the debugging mode where the program checks for bugs. However, looking closely at the values of the average time for assembly for debug and release, it shows a similar scaling. The C kernel runtime improved at release mode.

## Results C & x86-64 

### SAMPLE ERROR MESSAGE 
By changing a value right before the checker.
![SAMPLE ERROR](PNGs/sample%20error.PNG)
### 2^20 DEBUG C & x86-64
![2^20 Debug](PNGs/2^20%20debug.PNG)
### 2^20 RELEASE C & x86-64
![2^20 Release](PNGs/2^20%20release.PNG)

### 2^24 DEBUG C & x86-64
![2^24 Debug](PNGs/2^24%20debug.PNG)
### 2^24 RELEASE C & x86-64
![2^24 Release](PNGs/2^24%20release.PNG)

### 2^29 DEBUG C & x86-64
![2^20 Debug](PNGs/2^29%20debug.PNG)
### 2^29 RELEASE C & x86-64
![2^29 Release](PNGs/2^29%20release.PNG)
