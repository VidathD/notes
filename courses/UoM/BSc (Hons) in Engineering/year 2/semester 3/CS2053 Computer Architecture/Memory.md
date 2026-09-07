![](assets/documents/Memory%20Hierarchy_QuantitativeCH2_I.pdf)


Caching: Keep copies of frequently used data in faster storage.

Locality in computers. How close instructions/data are. Two types.
- Temporal (Same memory address is accessed repeatedly in a short time.)
- Spatial (Memory addresses that are closer to each other are accessed in sequence.)

Dark silicon. Power wall.

In direct mapping, each block is a set.
In fully associative, there is only one set.

## Cache Organization for Exam

We have to draw a diagram for cache organization. Make sure to name the boxes.


**We never map the entire secondary memory to the virtual memory.**

![](assets/documents/Memory%20Hierarchy_V.pdf)



# Questions

Assume we have an 8 KiB direct-mapped data cache with 16-byte blocks, and it is a write-back cache that does write allocate. The elements of *a* and *b* are 8 bytes long because they are double-precision floating-point arrays. There are 3 rows and 100 columns for *a* and 101 rows and 3 columns for *b*. Let's also assume they are not in the cache at the start of the program. The arrays are stored in row-major order in memory.

1. How many blocks are there?
> $\frac{8\times2^{10}}{16}=512$

2. If $a[i][0]$ causes a cache miss and loads a 16-byte block, what is most likely to happen when $a[i][1]$ is accessed immediately afterward?
> Likely a cache hit.

3. For double $b[101][3]$, what is the byte distance between $b[j][0]$ and $b[j+1][0]$? What can we conclude about access to consecutive elements in a column: $b[j][0]$ and $b[j+1][0]$?
> $3\times8=24$ bytes.
> There is no spacial locality. So access can't take advantage of caching.

4. Consider two iterations of the inner loop. What element is reused?
```c
for (i=1; i<3; i=i+1)
  for (j=0; j<100; j=j+1)
    a[i][j] = b[j][0] * b[j+1][0];
```
```c
j=0: b[0][0] * b[1][0]
j=1: b[1][0] *b [2][0]
```

5. What happens when the process encounters a write miss?
   > Bring the data into cache and write to it.
   
6. How many data accesses performed in the program?
    1. How many data values are read?
       *101*
    2. How many are written to?
       *200*
    3. Data accesses per iteration?
       *2 reads + 1 write =3 accesses*
    4. Number of iterations?
       $(3-1)\times(100-0)=200$

7. If the 8 KiB direct-mapped cache is changed to a 2-way set-associative cache while keeping the block size unchanged, how many sets will the new cache contain?
   > $\frac{8\times{2}^{10}}{16\times_{2}}=256$
   
8. What are the purposes of tag, index bits, valid bit, dirty bit, block offset?
> tag: Identify the unique memory block in cache block
> index bits: Identify the mapping cache block for a given address.
> block offset: Identify the correct byte/word within the cache block.
> 

## Exercise

If we group by 4 addresses, we can use the 2 MSBs to identify the block. So we can use it as the tag.
0000
0001
0010
0011

0100
0101
0110
0111

1000
1001
1010
1011

1100
1101
1110
1111