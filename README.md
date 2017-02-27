# CIS2750
Assignment 1 - Develop a String Storage and Processing Library

Build a system which stores strings in a linked structure. Write the function(s) necessary to process the string to remove redundant whitespace characters and format it using HTML tags. The strings can be stored and retrieved from binary files. 

what are the assumptions and limitations of your solution:
1.There might be a problem with larger input file(due to long string).

how  can  a  user  build  and  test  your  program (also  called  the  user  guide):
1. Simply type make, then it will build a library file .a and you can use the library.
2. put your own main.c function (here a1.c).
3. type make.
4. then type this command: gcc -o list a1.c liblistio.a
5. then ./list will run the program.
