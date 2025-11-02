# Project-1 Report
1. Which program is fastest? Is it always the fastest? <br>
The program that seemed to be the fastest was the alloca.cpp program, which showed fast results for most of the tests, except when it came to optimizer tests, where malloc.cpp outperformed alloca.cpp. There were also instances where the two tests tied.
2. Which program is slowest? Is it always the slowest? <br>
list.cpp seemed to be the slowest program with new.cpp occassionally tying it like in the data per node trials where at 8 nodes, new.cpp was slower, and at 256 they were tied.
3. Was there a trend in program execution time based on the size of data in each Node? If so, what, and why? <br>
There is a clear pattern with the increase of time execution in the data per node. Although the rankings of the programs still stayed the same, fastest:alloc, malloc. slowest: list, new. This is due to the increase in workload that each program is dealing with, however the increase in time was fairly minor in each case.
4. Was there a trend in program execution time based on the length of the block chain? <br>
There is a clear pattern with the increase of time execution increaseing based on the length of the chains. This time the increase in time is linear of about 4x for tests 200k -> 1M.
5. Consider heap breaks, what's noticeable? Does increasing the stack size affect the heap? Speculate on any similarities and differences in programs? <br>
Throughout the heap break tests, the first thing I noticed was that alloca stayed the same throughout every test. List and New grew at the same rates, which also turned out to have the fastest growing number of breaks. Increasing the stack size does not affect the number of heap breaks needed, as they will still expand as needed. <br>
6.Considering either the malloc.cpp or alloca.cpp versions of the program, generate a diagram showing two Nodes. Include in the diagram <br>
the relationship of the head, tail, and Node next pointers. <br>
show the size (in bytes) and structure of a Node that allocated six bytes of data <br>
include the bytes pointer, and indicate using an arrow which byte in the allocated memory it points to. <br>
head -> node (->bytes) -next-> null (tail) <br>
node *next; //8 bytes <br>
uint size; //6 bytes <br>
uint size = 6 //4 bytes <br>
allocated data region: <br>
[b0][b1][b2][b3][b4][b5] <br> 
  ^bytes points here <br>
7. There's an overhead to allocating memory, initializing it, and eventually processing (in our case, hashing it). For each program, were any of these tasks the same? Which one(s) were different? <br>
The initializing of data is generally the same across the same for all programs, along with the hashing of lists due to the algorithms being similar across all programs. Where they did differ was in the way they allocated memory. List does so through the simple iterative declarations of nodes utilizing std::list. Malloc utilized malloc(). alloc used alloca(). And new used new when declaring a new node. <br>
8. As the size of data in a Node increases, does the significance of allocating the node increase or decrease? <br>
Decreases, the impact to performance starts to become more apparent with the initializing and hashing of bytes rather than allocation. 
