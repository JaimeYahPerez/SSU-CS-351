# Project-1 Report
1. The program that seemed to be the fastest was the alloca.cpp program, which showed fast results for most of the tests, except when it came to optimizer tests, where malloc.cpp outperformed alloca.cpp. There were also instances where the two tests tied.
2. list.cpp seemed to be the slowest program with new.cpp occassionally tying it like in the data per node trials where at 8 nodes, new.cpp was slower, and at 256 they were tied.
3. There is a clear pattern with the increase of time execution in the data per node. Although the rankings of the programs still stayed the same, fastest:alloc, malloc. slowest: list, new. This is due to the increase in workload that each program is dealing with, however the increase in time was fairly minor in each case.
4. There is a clear pattern with the increase of time execution increaseing based on the length of the chains. This time the increase in time is linear of about 4x for tests 200k -> 1M.
5. Throughout the heap break tests, the first thing I noticed was that alloca stayed the same throughout every test. List and New grew at the same rates, which also turned out to have the fastest growing number of breaks. Increasing the stack size does not affect the number of heap breaks needed, as they will still expand as needed.
6. <br>
head -> node (->bytes) -next-> null (tail) <br>
node *next; //8 bytes <br>
uint size; //6 bytes <br>
uint size = 6 //4 bytes <br>
allocated data region: <br>
[b0][b1][b2][b3][b4][b5] <br> 
  ^bytes points here <br>
7. The initializing of data is generally the same across the same for all programs, along with the hashing of lists due to the algorithms being similar across all programs. Where they did differ was in the way they allocated memory. List does so through the 
