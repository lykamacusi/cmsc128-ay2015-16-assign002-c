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
	int choice = 7, result, n;
	char *str1, *str2;
	
	while(choice != 0){	//while user has not chosen to exit the program
		printMenu(&choice);	//calls function printMenu
		
		str1 = (char *)malloc(100*sizeof(char));
		str2 = (char *)malloc(100*sizeof(char));
		
		switch(choice){
			case 1:
				printf("\n*****************************************\n");
				printf("*\t   Get Hamming Distance\t\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter string 1: ");
				scanf("%s", str1);
				printf("Enter string 2: ");
				scanf("%s", str2);
				//return value of function getHammingDistance stored in result
				result = getHammingDistance(str1, str2);
				
				if(result == 0){	//if the strings have unequal length
					printf("\nError! Strings have unequal length!\n");
					
				}else{	//if the strings have equal length
					printf("\nHamming Distance: %d\n", result);
				}
				
				break;
				
			case 2:
				printf("\n*****************************************\n");
				printf("*\t Count Substring Pattern\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter original string: ");
				scanf("%s", str1);
				printf("Enter pattern: ");
				scanf("%s", str2);
				//return value of function countSubstrPattern stored in result
				result = countSubstrPattern(str1, str2);
				printf("\nNumber of occurence of pattern in orginal: %d\n", result);
				break;
				
			case 3:
				printf("\n*****************************************\n");
				printf("*\t    Is String Valid\t\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter alphabet: ");
				scanf("%s", str1);
				printf("Enter string: ");
				scanf("%s", str2);
				//return value of function isValidString stored in result
				result = isValidString(str2, str1);
				
				if(result == 1){
					printf("\nString is valid.\n");
				}else{
					printf("\nString is not valid.\n");
				}
				
				break;
				
			case 4:
				printf("\n*****************************************\n");
				printf("*\t\tGet Skew\t\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter genome string: ");
				scanf("%s", str1);
				printf("Enter number: ");
				scanf("%d", &n);
				
				if(n > (strlen(str1)+1) || n <= 0){
					printf("\nError! Number must be within string length!\n");
				}else{
					//return value of function getSkew stored in result
					result = getSkew(str1, n);
					printf("\nNumber of G-C: %d\n", result);
				}
				
				break;
				
			case 5:
				printf("\n*****************************************\n");
				printf("*\t  Get Maximum Skew of N\t\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter genome string: ");
				scanf("%s", str1);
				printf("Enter number: ");
				scanf("%d", &n);
				
				if(n > (strlen(str1)+1) || n <= 0){
					printf("\nError! Number must be within string length!\n");
				}else{
					//return value of function getMaxSkewN stored in result
					result = getMaxSkewN(str1, n);
					printf("\nMaximum Skew: %d\n", result);
				}
				
				break;
				
			case 6:
				printf("\n*****************************************\n");
				printf("*\t  Get Minimum Skew of N\t\t*\n");
				printf("*****************************************\n");
				
				printf("\nEnter genome string: ");
				scanf("%s", str1);
				printf("Enter number: ");
				scanf("%d", &n);
				
				if(n > (strlen(str1)+1) || n <= 0){
					printf("\nError! Number must be within string length!\n");
				}else{
					//return value of function getMinSkewN stored in result
					result = getMinSkewN(str1, n);
					printf("\nMinimum Skew: %d\n", result);
				}
				
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
