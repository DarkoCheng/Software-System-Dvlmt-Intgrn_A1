/*
Name: Darko
Student ID: 81192
Date: 1949/10/01
Assignment 1 for cis 2750.
*/
#include "listio.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

struct dataHeader *buildHeader()
{
	struct dataHeader * temp;
	temp = malloc(sizeof(struct dataHeader));
	assert(temp!=NULL);

	memset(temp, 0, sizeof(struct dataHeader));

	return temp;
}

void setName(struct dataHeader *header, char *name)
{
	header->name = malloc(strlen(name)+1);
	assert(header->name!=NULL);

	memset(header->name, 0, strlen(name)+1);
    strcpy(header->name, name);

    return;
}

char * getName(struct dataHeader *header)
{
    char * temp;
    temp = header->name;

    return temp;

}

int getLength(struct dataHeader *header)
{
	int a;
	a = header->length;

	return a;
}

void addString(struct dataHeader *header, char *str)
{
	struct dataString * newString, *temp;
	newString = malloc(sizeof(struct dataString));
    assert(newString!=NULL);
	newString->string = malloc((strlen(str)+1));
	assert(newString->string!=NULL);
	memset(newString->string, 0, strlen(str)+1);
	newString->next = NULL;
    strcpy(newString->string, str);
   
	if (header->next == NULL)
	{
        header->next = newString;
        header->length = header->length + strlen(str);
	}
	else
	{
		temp = header->next;
		while(temp->next != NULL)
		{
            temp = temp->next;
		}
		temp->next = newString;
		header->length = header->length + strlen(str);
	}

	return;
}

void printString(struct dataHeader *header)
{
	struct dataString * temp;
	temp = header->next;

	while(temp != NULL)
	{
        printf("%s\n", temp->string);
        temp = temp->next; 
	}

	return;
}

void processString(struct dataHeader *header)
{
	header->length = 0;
	struct dataString * tempList;
	tempList = header->next;
	char * buffer;
	/*
    I did hard code for all malloc cuz I was just lazy!! it was not a good way, but passing 2750? EZ!(as long as you free all)
	*/
    char* outSpace = malloc(sizeof(char)*10240000);
    char * outTab = malloc(sizeof(char)*10240000);
    char * outP = malloc(sizeof(char)*10240000);
    char * outR = malloc(sizeof(char)*10240000);
    char * outNewLine = malloc(sizeof(char)*10240000);
	/*
    A good way to initial space for pointer. You do not have to, but it is good.
	*/
    memset(outR, 0, 10240000);
    memset(outP, 0, 10240000);
    memset(outNewLine, 0, 10240000);
    memset(outTab, 0, 10240000);
    memset(outSpace, 0, 10240000);
    int a = 0;
    int b = 0;
    int c = 0;

    
    while (tempList != NULL)
    {
    	buffer = tempList->string;
	    while (1)  // deal mutil spaces.
	    {
	    	if (buffer[a] == '\0')
	    	{
	    		outSpace[c] = '\0';
	    		break;
	    	}
	        else if (buffer[a] == ' ')
	        {
	        	/*
    				check if there are mutil spaces/
    				Same in rest of loops.
	        	*/
	            if (buffer[a+1] == ' ') 
	            {
	            	b = a+1;
	            	while (1)
	            	{
	            		if (buffer[b] != ' ')
	            		{
	            			a = b;
	            			outSpace[c] = ' ';
	            			c++;
	            			break;
	            		}
	            		b++;
	            	}
	            }
	            else
	            {
	            	outSpace[c] = buffer[a];
	            	a++;
	            	c++;
	            }
	        }
	        else
	        {
	        	outSpace[c] = buffer[a];
	        	c++;
	        	a++;
	        }
	    }
	    /*
        Everytime finish a loop need to reset the a,b,c var in order to do the next loop.
        Same in rest of loops.
         */
	    a = 0;
	    b = 0;
	    c = 0;
	    while(1)  // deal mutil <tab>
	    {
	    	if (outSpace[a] == '\0')
	    	{
	    		outTab[c] = '\0';
	    		break;
	    	}
	    	else if (outSpace[a] == '\t')
	    	{
	    		if (outSpace[a+1] == '\t')
	    		{
	    			b = a + 1;
	    			while (1)
	    			{
	    				if (outSpace[b] != '\t')
	    				{
    						a = b;
    						outTab[c] = '\t';
    						c++;
    						break; 
	    				}
	    				b++;
	    			}
	    		}
	    		else
	    		{
	    			outTab[c] = outSpace[a];
	    			c++;
	    			a++;
	    		}
	    	}
	    	else
	    	{
	    		outTab[c] = outSpace[a];
	        	c++;
	        	a++;
	    	}
	    }
	    a = 0;
	    b = 0;
	    c = 0;
	    while (1)   // deal mutil \n
	    {
	    	if (outTab[a] == '\0')
	    	{
	    		outP[c] = '\0';
	    		break;
	    	}
	    	else if (outTab[a] == '\n' || outTab[a] == '\r')
	    	{
	    		if (outTab[a+1] == '\n' || outTab[a+1] == '\r')
	    		{
	    			b = a + 1;
	    			while (1)
	    			{
	    				if (outTab[b] != '\n' && outTab[b] != '\r')
	    				{
	    					a = b;
	    					outP[c] = '<';
	    					outP[c+1] = 'p';
	    					outP[c+2] = '>';
	    					c = c + 3;
	    					break;
	    				}
	    				b++;
	    			}
	    		}
	    		else
	    		{
	    			outP[c] = outTab[a];
	    			c++;
	    			a++;
	    		}
	    	}
	    	else
	    	{
	    		outP[c] = outTab[a];
	    		a++;
	    		c++;
	    	}
	    }
	    a = 0;
	    b = 0;
	    c = 0;
	    while (1)  // deal mutil \r
	    {
	    	if (outP[a] == '\0')
	    	{
	    		outP[c] = '\0';
	    		break;
	    	}
	    	else if (outP[a] == '\r')
	    	{
	    		if (outP[a+1] == '\r')
	    		{
	    			b = a + 1;
	    			while (1)
	    			{
	    				if (outP[b] != '\r')
	    				{
	    					a = b;
	    					outR[c] = '<';
	    					outR[c+1] = 'p';
	    					outR[c+2] = '>';
	    					c = c + 3;
	    					break;
	    				}
	    				b++;
	    			}
	    		}
	    		else
	    		{
	    			outR[c] = outP[a];
	    			c++;
	    			a++;
	    		}
	    	}
	    	else
	    	{
	    		outR[c] = outP[a];
	    		a++;
	    		c++;
	    	}
	    }
	    a = 0;
	    b = 0;
	    c = 0;
	    while(1)   // deal single \r ot \n
	    {
	    	if (outR[a] == '\0')
	    	{
	    		outR[c] = '\0';
	    		break;
	    	}
	    	else if (outR[a] == '\n' || outR[a] == '\r')
	    	{
                outNewLine[c] = '<';
                outNewLine[c+1] = 'B';
                outNewLine[c+2] = 'R';
                outNewLine[c+3] = '>';
                c = c + 4;
                a++;
	    	}
	    	else
	    	{
	    		outNewLine[c] = outR[a];
	    		c++;
	    		a++;
	    	}
	    }
	    a = 0;
	    b = 0;
	    c = 0;
	    free(tempList->string);
	    tempList->string = malloc(sizeof(char)*10240000);
	    memset(tempList->string, 0, sizeof(char)*10240000);
	    strcpy(tempList->string, outNewLine);
	    header->length = header->length + strlen(outNewLine);
	    // below is to reset all strings.
	    memset(outNewLine, 0, sizeof(char)*10240000);
	    memset(outR, 0, sizeof(char)*10240000);
	    memset(outSpace, 0, sizeof(char)*10240000);
	    memset(outTab, 0, sizeof(char)*10240000);
	    memset(outP, 0, sizeof(char)*10240000);
	    tempList = tempList->next;
	}
	free(outNewLine);
	free(outR);
	free(outSpace);
	free(outTab);
	free(outP);
    return;
}

void freeStructure(struct dataHeader *header)
{
	struct dataString * temp, * tempFree;
	temp = header->next;
	while (temp != NULL)
	{
        tempFree = temp;
		temp = temp -> next;
		free(tempFree->string);
		free(tempFree);
    }
    free(header->name);
    free(header);
    return;
}

void writeStrings(char *filename, struct dataHeader * header)
{
	FILE * fp;
	fp = fopen(filename, "wb");
    struct dataString * temp;
    temp = header->next;
    int nameLength = strlen(header->name);
    int stringLength;
    int headerLength;
    char * name;
    name = getName(header);
    headerLength = getLength(header);
    fwrite(&nameLength, sizeof(int), 1, fp);
    fwrite(name, sizeof(char), strlen(name)+1, fp);
    fwrite(&headerLength, sizeof(int), 1, fp);
    while(temp != NULL)
    {
    	stringLength = strlen(temp->string)+1;
    	fwrite(&stringLength, sizeof(int), 1, fp);
    	fwrite(temp->string, sizeof(char),  strlen(temp->string)+1,fp);
        temp = temp->next;
    }
    
    fclose(fp);
    return;
}

struct dataHeader *readStrings(char *filename)
{
    struct dataHeader * tempData;
    tempData = buildHeader();
    FILE * fp;
    fp = fopen(filename, "rb");
    int a;
    char * buffer;
    buffer = malloc(sizeof(char)*10240);
    fread(&a, 1, 4, fp);
    fread(buffer, sizeof(char), a+1, fp);
    setName(tempData, buffer);
    fread(&a, 1, 4, fp);
    memset(buffer, 0, sizeof(char)*10240);
    int c;
    while(!feof(fp))
    {
        c = fread(&a, 1, 4, fp); 
        if (c != 4)
        {
        	break;
        }
        fread(buffer, sizeof(char), a, fp);
        addString(tempData, buffer);
        memset(buffer, 0, sizeof(char)*10240); 
    }
    free(buffer);
    fclose(fp);
    return tempData;
}
