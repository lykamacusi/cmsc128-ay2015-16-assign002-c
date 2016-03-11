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
int countSubstrPattern(char *original, char *pattern){
	int originalLen, patternLen, occurence = 0, i, j, k, check = 0;
	
	originalLen = strlen(original);
	patternLen = strlen(pattern);
	
	for(i=0; i<originalLen; i++){ //traverses every character in the original string
		k = i;	//k is a temporary variable for storing the index of i
		for(j=0; j<patternLen;j++){	//loops through the pattern
			//if the ith character of the original string is equal to the ith
			//character of the pattern
			if(original[k] == pattern[j]){
				k++;
				check++;
			}
		}
		
		if(check == patternLen){	//if check is equal to the length of the pattern
			occurence++;	//a substring is found
		}
		
		check = 0; //reinitialize to zero for next character in original string
	}
	return occurence;
}

/*-----------------------------------------------------------------------------
	Given an alphabet string where all letters are assumed to be unique, this
	function returns true if the string str is a valid string based on the
	letters of alphabet.
-----------------------------------------------------------------------------*/
int isValidString(char *str, char *alphabet){
	int strLen, valid = 0, i;
	
	strLen = strlen(str);
	
	for(i=0; i<strLen; i++){	//loops through every character of string
		if(strchr(alphabet, str[i]) != NULL){ //if character found in alphabet
			valid++;
		}
	}
	
	if(valid == strLen){	//if valid is equal to the length of string
		return 1;
	}else{
		return 0;
	}
}

/*-----------------------------------------------------------------------------
	Given a genome str of some length q (where q>0), it returns the number of
	Gs minus the number of Cs in the first n nucleotides (q>=n). The value can
	be zero, negative or positive. The first position is one (1) not zero(0) as
	we typically associate with string implementations.
-----------------------------------------------------------------------------*/
int getSkew(char *str, int n){
	int tempLen, i, G = 0, C = 0, value;
	char *temp;
	
	temp = (char *)malloc(100*sizeof(char));	//temporary storage of string
	strcpy(temp, "X");	//add dummy character to temp
	strcat(temp, str);	//concatenate genome string
	
	tempLen = strlen(temp);
	
	//if the input number is less than or equal to the length of the temporary
	//string
	if(n <= tempLen){
		//traverses characters with index less than or equal to n
		for(i=1; i<=n; i++){
			if(temp[i] == 'G'){
				G++;
			}
			if(temp[i] == 'C'){
				C++;
			}
		}
	}
	
	value = G - C;
	return value;
}

/*-----------------------------------------------------------------------------
	Given a genome str of some length q (where q>0), it returns the maximum
	value of the number of Gs or Cs in the first n nucleotides (q>=n). The
	value can be zero, negative or positive. The first position is one (1) not
	zero(0) as we typically associate with string implementations.
-----------------------------------------------------------------------------*/
int getMaxSkewN(char *str, int n){
	int tempLen, i, G = 0, C = 0;
	char *temp;
	
	temp = (char *)malloc(100*sizeof(char));	//temporary storage of string
	strcpy(temp, "X");	//add dummy character to temp
	strcat(temp, str);	//concatenate genome string
	
	tempLen = strlen(temp);
	
	//if the input number is less than or equal to the length of the temporary
	//string
	if(n <= tempLen){
		//traverses characters with index less than or equal to n
		for(i=1; i<=n; i++){
			if(temp[i] == 'G'){
				G++;
			}
			if(temp[i] == 'C'){
				C++;
			}
		}
	}
	
	if(G > C){
		return G;
	}else{
		return C;
	}
}
