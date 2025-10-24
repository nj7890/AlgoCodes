# # Pangrams Problem (HackerRank)

# Description:
# A pangram is a sentence that contains every letter of the English alphabet at least once.
# Given a sentence, determine whether it is a pangram. Ignore letter case.

# Input:
# A single line containing the sentence to check.

# Output:
# Return "pangram" if the sentence contains every letter of the alphabet,
# otherwise return "not pangram".

# Approach:
# 1. Convert the sentence to lowercase to ignore case differences.
# 2. Use a set to collect all alphabetic characters.
# 3. If the set contains all 26 letters, it's a pangram; otherwise, it is not.

def pangrams(s: str) -> str:
    s = s.lower()
    letters = set()
    
    for char in s:
        if char.isalpha():   # Only consider alphabet letters
            letters.add(char)
    
    if len(letters) == 26:
        return "pangram"
    else:
        return "not pangram"

if __name__ == "__main__":
    
    s = input().strip()
    result = pangrams(s)
    print(result)
