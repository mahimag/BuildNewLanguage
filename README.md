# Ultron

Introduction
For this homework, we are going to work with pointers and built-in arrays. We are also going to build our own computer, called Ultron. Rather than soldering chips together, we are building a software-based simulation of a computer in C. We can write programs and debug our programs that execute on Ultron using our own programming language called U.


The full writeup is available [here](https://docs.google.com/document/d/1m72nJVCzEKrGQXBH9kfN_tpNsejaczpVfH4HUBGfYj0/edit#heading=h.1wsouwify7av).

**User Input Instructions:**

Build the program with 

	make 

Run it with

	./ultron [-i instructions] [-f filename]

Note that you can run ultron either with the -i flag, or with the -f flag, but not both together. -i should cause ultron to read instructions from the user, while -f causes ultron to read the program from a file.

**For example:**

$ultron -i 7
1010
1011
2010
3011
2112
1112
4300
? 5
? 9
= 14
Result: 0
PC: 6
AC: 14
 0 1010
 1 1011
 2 2010
 3 3011
 4 2112
 5 1112
 6 4300
 7    0
 8    0
 9    0
10    5
11    9
12   14
13    0
14    0
15    0
16    0
17    0
18    0
19    0
20    0
21    0
22    0
23    0
24    0
25    0
26    0
27    0
28    0
29    0
30    0
31    0
