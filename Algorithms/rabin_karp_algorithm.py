
'''

RABIN KARP ALGORITHM :

Rabin Karp algorithm matches the hash value of the pattern with the hash value of current substring of text, and if the hash values match then only it starts matching individual characters

# first test case :
Text = "Hello LGM SOC participant"
Pattern = "LGM"
Output -> pattern found at index 6 in the text

# second test case :
Text = "123 3422 1 3 2 2 12333"
Pattern = "23"
Output -> Pattern found at index 1, and 18 in the text

'''


# Any prime number taken
prime = 1000000007

# number of possible characters in the input alphabet
d = 256

# variable defined to check if pattern is found in text or not
found = 0

# function defined for Rabin Karp Algorithm
def rabin_karp_algorithm(pattern, text):
	global found

	# arbitrary variable j and h taken
	j = 0
	h = 1
	pattern_hash_value = 0 # variable taken to store pattern hash value
	text_hash_value = 0 # variable taken to store text hash value

	# variable h is defined as (d^(M-1))%prime
	for i in range(len(pattern)-1):
		h = (h*d)%prime

	# Calculating the hash value of pattern and text and storing in pattern_hash_value and text_hash_value respectively
	for i in range(len(pattern)):
		pattern_hash_value = (d*pattern_hash_value + ord(pattern[i]))%prime
		text_hash_value = (d*text_hash_value + ord(text[i]))%prime

	# Searching the pattern over text one by one, and if found, then we check pattern character one by one
	for i in range(len(text)-len(pattern)+1):
		if pattern_hash_value==text_hash_value:
			# Check for characters one by one as here hash_value matched
			for j in range(len(pattern)):
				if text[i+j] != pattern[j]:
					break
				else:
					j+=1 # updating the j accordingly

			# j becomes len(pattern), then we print that pattern found at i index
			if j==len(pattern):
				found = 1
				print("Pattern found at index " + str(i))

		# Calculating the  hash value for next window of text bu removing leading digit, add trailing digit
		if i < len(text)-len(pattern):
			text_hash_value = (d*(text_hash_value-ord(text[i])*h) + ord(text[i+len(pattern)]))%prime

			# if we get negative hashvalue, then we convert it to positive by adding prime to it
			if text_hash_value < 0:
				text_hash_value = text_hash_value+prime

	# if pattern is not found then we print this message
	if(found == 0):
		print("Pattern is not present in Text.")



# input
text = "Hello LGM SOC participant"
pattern = "Z"

print("\n# INPUT : ")
print("Text : ", text)
print("Pattern : ", pattern)
print("\n# OUTPUT : ")
# main function called
rabin_karp_algorithm(pattern,text)
