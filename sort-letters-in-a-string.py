# Work Sample Exercise: Alphabetizer
# Write a program that can read in a series of strings and output the strings with the characters in alphabetical order.
# Capitalization does not matter for a character, but characters should be output in the same form that they were
# input. e.g. P should count the same as p, but be output as P. Non-alphabetic characters should be ignored and not
# included in the output string.
# Examples:
#  “3 Blind Mice” would be output as “BcdeiilMn"

# Time Complexity: n + c => O(n)
# Space Complexity: n + 52 => O(n)

# Dynamically read in a string from the user
string = input()

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
for i in range(26):
	for j in range(letterCount[i]):
		letter = chr(ord('a') + i)
		print(letter, end='')
	for j in range(letterCount[i + 26]):
		letter = chr(ord('A') + i)  # Offset the index for upper case letters
		print(letter, end='')

print()
# print(string)
