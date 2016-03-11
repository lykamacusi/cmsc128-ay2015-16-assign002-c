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
	int strlen1, strlen2, hammingDistance = 0, i;
	
	strlen1 = strlen(str1);
	strlen2 = strlen(str2);
	
	if(strlen1 == strlen2){	//if the strings have equal length
		for(i=0; i<strlen1; i++){	//traverses every character in the string
			//if the characters in the same position are not the same
			if(str1[i] != str2[i]){
				hammingDistance++;
			}
		}
		return hammingDistance;
		
	}else{	//if the strings have unequal length
		return 0;
	}
}
