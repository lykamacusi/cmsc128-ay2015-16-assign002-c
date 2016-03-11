/*
	Macusi, Daniellika G.
	2013-61871
	CMSC 128 AB-6L
	Programming Assignment 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(){
	int choice = 7, result;
	char *str1, *str2;
	
	while(choice != 0){
		printMenu(&choice);
		
		str1 = (char *)malloc(sizeof(char));
		str2 = (char *)malloc(sizeof(char));
		
		switch(choice){
			case 1:
				printf("\nGet Hamming Distance\n");
				printf("\nEnter string 1: ");
				scanf("%s", str1);
				printf("Enter string 2: ");
				scanf("%s", str2);
				result = getHammingDistance(str1, str2);
				
				if(result == 0){
					printf("\nError! Strings have unequal length!\n");
					
				}else{
					printf("\nHamming Distance: %d\n", result);
				}
				
				break;
				
			case 2:
				printf("\nCount Substring Pattern\n");
				break;
				
			case 3:
				printf("\nIs String Valid\n");
				break;
				
			case 4:
				printf("\nGet Skew\n");
				break;
				
			case 5:
				printf("\nGet Maximum Skew of N\n");
				break;
				
			case 6:
				printf("\nGet Minimum Skew of N\n");
				break;
				
			case 0:
				free(str1);
				free(str2);
				printf("\nProgram Terminated...\n");
				break;
				
			default:
				printf("\nInvalid input!\n");
				break;
		}
		
	}
}
