/*
This is the main.c to test the assignment, should work perfectly.
This file made by Professor David Calvert.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listio.h"

int main() {
struct dataHeader *hdr;
char *fname = "TESTING";
char *str1, *str2, *bigString;
int i;

	// test #1 - small strings
   hdr = buildHeader();
   setName(hdr, fname);
   printf("*** File name test - output should be TESTING: ");
   printf("%s\n", getName(hdr));

   str1 = malloc(sizeof(char)*1024);
   str2 = malloc(sizeof(char)*1024);
   bigString = malloc(sizeof(char)*4096);

   strcpy(str1, "abc\ndef\n\nghi");
   for (i=0; i<1023; i++)
      str2[i] = 'a';
   str2[1023] = '\0';

   addString(hdr, str1);
   addString(hdr, str2);

   printf("*** printString() test\n");
   printf("*** Print out contents of list, should be abc,def,ghi on three lines\n");
   printf("*** followed by 1024 a's\n");
   printString(hdr);

   printf("*** printString() test 2, after processString() has been run\n");
   printf("*** Print out contents of list, should be abc<BR>def<P>ghi on one line\n");
   printf("*** followed by 1024 a's\n");
   processStrings(hdr);
   printString(hdr);

   printf("*** running freeStructure()\n\n");
   freeStructure(hdr);

	// test #2 - small strings
   printf("*** building a second structure\n");
   hdr = buildHeader();
   setName(hdr, fname);

   printf("*** test processString() with combinations of space, tab, newline, carriage return\n");
   printf("*** removing multiple spaces\n");
   strcpy(str1, "abc def     ghi         j");
   addString(hdr, str1);
   processStrings(hdr);
   printf("*** should print out \"abc def ghi j\" with a single space between each word\n");
   printString(hdr);

   printf("*** removing multiple tabs\n");
   strcpy(str2, "123\t\t\t\t456\t\t\t7\t8");
   addString(hdr, str2);
   processStrings(hdr);
   printf("*** should print out \"123<tab>456<tab>7<tab>8\" with a single tab between each word (after repeating the line from above)\n");
   printString(hdr);

   printf("*** running freeStructure()\n\n");
   freeStructure(hdr);

	// test #3 - big strings read/written to disk
   printf("*** building a third structure - testing file operations on big strings\n");
   hdr = buildHeader();
   setName(hdr, fname);

   for (i=0; i<4096; i++)
      bigString[i] = 'b';
   printf("*** add 10 big string to the list\n");
   for (i=0; i<10; i++)
      addString(hdr, bigString);

   printf("*** call processString\n");
   processStrings(hdr);

   printf("*** call writeStrings\n");
   writeStrings(fname, hdr);

   printf("*** running freeStructure()\n\n");
   freeStructure(hdr);

   printf("*** call readStrings()\n");
   hdr = NULL;
   hdr = readStrings(fname);
   printf("*** test content on first few strings is correct\n");
   for(i=0; i<4096; i++) {
      if ((hdr->next->string)[0] != 'b') 
         printf("   error in strings read with readstring()\n");
      if ((hdr->next->next->string)[0] != 'b') 
         printf("   error in strings read with readstring()\n");
      if ((hdr->next->next->next->string)[0] != 'b') 
         printf("   error in strings read with readstring()\n");
   }

}

