# Work Sample Exercise: Alphabetizer
# Write a program that can read in a series of strings and output the strings with the characters in alphabetical order.
# Capitalization does not matter for a character, but characters should be output in the same form that they were
# input. e.g. P should count the same as p, but be output as P. Non-alphabetic characters should be ignored and not
# included in the output string.
# Examples:
#  “3 Blind Mice” would be output as “BcdeiilMn"

# Time Complexity: n + c => O(n)
# Space Complexity: n + 52 => O(n)

import timeit

def sortDictionary(string):
	# Create a dictionary to store the count of each letter (both upper and lower case)
	letterCount = [0] * 52

	# Iterate through the string and increment the count for each letter
	for letter in string:
		if letter.isalpha():
			if letter.islower():
				letterCount[ord(letter) - ord('a')] += 1
			else:
				letterCount[ord(letter) - ord('A') + 26] += 1  # Offset the index for upper case letters

	# Output the letters in alphabetical order
	sorted_string = ''
	for i in range(26):
		for j in range(letterCount[i]):
			letter = chr(ord('a') + i)
			sorted_string += letter
		for j in range(letterCount[i + 26]):
			letter = chr(ord('A') + i)  # Offset the index for upper case letters
			sorted_string += letter

	# print(sorted_string)
	# print()
	return sorted_string

def sortNestedLoop(string):
	# Convert the string to a list of characters
	letters = list(string)

	# Iterate through the list and compare each pair of adjacent letters
	for i in range(len(letters)):
		for j in range(i + 1, len(letters)):
			# Compare the letters and swap if necessary
			if letters[i].lower() > letters[j].lower():
				letters[i], letters[j] = letters[j], letters[i]

	# Output the sorted letters
	sorted_string = ''
	for letter in letters:
		if letter.isalpha():
			sorted_string += letter

	# print(sorted_string)
	# print()
	return sorted_string

string = ''

def main():
	# Dynamically read in a string from the user
	global string
	string = input("Enter the string: ")

	print(sortDictionary(string))
	print(sortNestedLoop(string))

	print("Execution time for sortDictionary:", timeit.timeit("sortDictionary(string)", "from __main__ import sortDictionary", number=1000, globals=globals()))
	print("Execution time for sortNestedLoop:", timeit.timeit("sortNestedLoop(string)", "from __main__ import sortNestedLoop", number=1000, globals=globals()))

if __name__ == '__main__':
	main()
