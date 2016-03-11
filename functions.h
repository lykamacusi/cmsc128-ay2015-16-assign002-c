void printMenu(int *choice){
	printf("\nMENU\n");
	printf("[1] Get Hamming Distance\n");
	printf("[2] Count Substring Pattern\n");
	printf("[3] Is String Valid\n");
	printf("[4] Get Skew\n");
	printf("[5] Get Maximum Skew of N\n");
	printf("[6] Get Minimum Skew of N\n");
	printf("[0] Exit\n");
	
	printf("\nEnter Choice: ");
	scanf("%d", choice);
}

/*-----------------------------------------------------------------------------	
	Given two strings str1 and str2 of same length (length must never be 0 or
	negative!), the Hamming Distance of those two strings are the number of
	inversions per character needed to transform str1 to str2 or vise-versa.
	Simply put, the Hamming Distance of two strings is the number of characters
	that differ in ith position from position 1 to strlen(str1).
-----------------------------------------------------------------------------*/
int getHammingDistance(char *str1, char *str2){
	int strlen1, strlen2, inversion = 0, i;
	
	strlen1 = strlen(str1);
	strlen2 = strlen(str2);
	
	if(strlen1 == strlen2){	//if the strings have equal length
		for(i=0; i<strlen1; i++){	//traverses every character in the string
			//if the characters in the same position are not the same
			if(str1[i] != str2[i]){
				inversion++;
			}
		}
		return inversion;
		
	}else{	//if the strings have unequal length
		return 0;
	}
}

/*-----------------------------------------------------------------------------
	Given an original string and a pattern, we will count the number of
	occurrence of pattern in original.
-----------------------------------------------------------------------------*/
int countSubstrPattern(char *str1, char *str2){
	int strlen1, strlen2, occurence = 0, i, j = 0, k, check = 0;
	
	strlen1 = strlen(str1);
	strlen2 = strlen(str2);
	
	for(i=0; i<strlen1; i++){	//traverses every character in the original string
		k = i;	//k is a temporary variable for storing the index of i
		while(j < strlen2){	//loops through the pattern
			//if the ith character of the original string is equal to the ith
			//character of the pattern
			if(str1[k] == str2[j]){
				k++;
				check++;
			}
			j++;
		}
		
		if(check == strlen2){	//if check is equal to the length of the pattern
			occurence++;	//a substring is found
		}
		
		//reinitialize to zero for next character in original string
		check = 0;
		j = 0;
	}
	return occurence;
}
