#include<stdio.h>
#include<string.h>

/*
* Author : Aditya Deshpande (aditya12agd5@gmail.com)
*
* CUDA/Thrust Implementation of String Sort algorithm given in IEEE High Performance 
* Computing 2013 paper:
*
* "Can GPUs Sort Strings Efficiently?",
* By: Aditya Deshpande and P J Narayanan
* 
* Copyright (c) 2013 International Institute of Information Technology - Hyderabad. 
* All rights reserved.
*  
* Permission to use, copy, modify and distribute this software and its documentation for 
* educational purpose is hereby granted without fee, provided that the above copyright 
* notice and this permission notice appear in all copies of this software and that you do 
* not sell the software.
*  
* THE SOFTWARE IS PROVIDED "AS IS" AND WITHOUT WARRANTY OF ANY KIND, EXPRESSED, IMPLIED OR 
* OTHERWISE.
*
*
* File: sortVerifier.c
* 	- Code to verify sorted output written to files suffixed with "_string_sort_output"
* 	- This code also computes avg/max matching prefix length
*	- To Execute: ./verify <output filepath>
*/

int main(int argc, char *argv[]) { 

	char line1[1000];
	char line2[1000];
	char newLine;

	if(argc!=2) { 
		printf("[Usage] ./a.out <filename>\n");
		return 1;
	}
	FILE *fp = fopen(argv[1],"r");
	fscanf(fp, "%[^\n]", line1);
	fscanf(fp, "%c", &newLine);
	int count = 1;
	int flag = 0;
	unsigned int maxSamePrefixLength = 0;
	unsigned int average = 0;
	while(fscanf(fp, "%[^\n]", line2)!=EOF) { 
		fscanf(fp, "%c", &newLine);
		if(strcmp(line1, line2) > 0) { 
			printf("[Unordered] (%d) %s \t [Unordered] (%d) %s\n", count-1, line1, count, line2);
			flag = 1;
		} else { 
			unsigned int i = 0;
			while(line1[i]!='\0' && line2[i]!='\0' && (line1[i] == line2[i])) i++;
			if(i > maxSamePrefixLength) maxSamePrefixLength = i;
			average += i;
		}
		count++;
		strcpy(line1, line2);
	}
	printf("[DEBUG] number of elements is %d\n", count);
	printf("[DEBUG] maximum matching prefix length %d\n", maxSamePrefixLength);
	printf("[DEBUG] average matching prefix length %d\n", average/count);
	if(flag == 0) { 
		printf("test PASSED\n");
	}
	return 0;
}
