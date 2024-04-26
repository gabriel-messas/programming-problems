#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <sys/time.h>

// Work Sample Exercise: Alphabetizer
// Write a program that can read in a series of strings and output the strings with the characters in alphabetical order.
// Capitalization does not matter for a character, but characters should be output in the same form that they were
// input. e.g. P should count the same as p, but be output as P. Non-alphabetic characters should be ignored and not
// included in the output string.
// Examples:
//  “3 Blind Mice” would be output as “BcdeiilMn"

// Time Complexity: n + c => O(n)
// Space Complexity: n + 52 => O(n)

void sortDictionary(char* string, int length) {
	// Create a dictionary to store the count of each letter (both upper and lower case)
	int letterCount[52] = {0};

	// Iterate through the string and increment the count for each letter
	for (int i = 0; i < length; i++) {
		char letter = string[i];
		if (letter >= 'a' && letter <= 'z') {
			letterCount[letter - 'a']++;
		} else if (letter >= 'A' && letter <= 'Z') {
			letterCount[letter - 'A' + 26]++; // Offset the index for upper case letters
		}
	}

	// Output the letters in alphabetical order
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < letterCount[i]; j++) {
			char letter;
			letter = 'a' + i;
			putchar(letter);
		}
		for (int j = 0; j < letterCount[i+26]; j++) {
			char letter;
			letter = 'A' + i; // Offset the index for upper case letters
			putchar(letter);
		}
	}
	putchar('\n');

	return;
}

int main() {
	// Dynamically read in a string from the user
	int length = 0;
	char* string = malloc(1*sizeof(char));
	char c;

	printf("Enter a string: ");

	while ((c = getchar()) != EOF && c != '\n') {
		string[length++] = c;
		string = realloc(string, (length + 1) * sizeof(char));
	}
	string[length] = '\0';

	// Measure the start time
	struct timeval start_time;
	gettimeofday(&start_time, NULL);

	sortDictionary(string, length);

	// Measure the end time
	struct timeval end_time;
	gettimeofday(&end_time, NULL);

	// Calculate the execution time in microseconds
	double execution_time = (end_time.tv_sec - start_time.tv_sec) * 1e6 + (end_time.tv_usec - start_time.tv_usec);
	printf("Execution time: %d microseconds\n", (int)execution_time);

	// Free the memory allocated for the string
	free(string);
	
	return 0;
}
