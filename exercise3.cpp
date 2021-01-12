/*
Palindrome checker

Prompts the user to enter a word, and displays whether or not it is a palindrome.

Implementation notes:
 - Ensure the user enters a single word.
 - Converting to lower case and reversing is one method.
 - A two pointer approach is a more efficient method.
 - Case should be ignored in the comparison but preserved in the output.
*/

#include <iostream>

using namespace std;

/** Returns a copy of the input string in which the characters appear in lower case. */
string toLowerCase(string s) {
  // initialise variable to store the result
  string lowerCase;

  // iterate over the input string, appending a lower case version of each charater
  // to the output string.
  for (int i = 0; i < s.length(); i++) {
    lowerCase += tolower(s[i]);
  }

  return lowerCase;
}

/** Returns a copy of the input string in which the characters appear in reverse order. */
string reverseString(string s) {
  // initialise variable to store the result
  string reversed;

  // starting with the last character, iterate back over the input string,
  // updating the output string accordingly
  for (int i = s.length() - 1; i >= 0; i--) {
    reversed += s[i];
  }

  return reversed;
}

/** Returns whether or not the input string is a palindrome (case-insensitive). */
bool isPalindrome(string s) {
  // convert the string to lower case
  string lowercase = toLowerCase(s);
  
  // reverse it
  string reversed = reverseString(lowercase);

  // compare the two strings characterwise;
  // if any characters don't match, return false
  for (int i = 0; i < s.length(); i++) {
    if (reversed[i] != lowercase[i]) {
      return false;
    }
  }

  return true;
}

/** Optimised version of isPalindrome, using a two pointer approach. */
bool isPalindromeOptimised(string s) {
  // initialise the pointers to indices at the start and end of the string
  int p1 = 0;
  int p2 = s.length() - 1;

  // loop until p1 is no longer before p2, comparing the characters at the two indices;
  // if they don't match, return false, otherwise, increment p1 and decrement p2.
  while (p1 < p2) {
    if (tolower(s[p1]) != tolower(s[p2])) {
      return false;
    }
    p1++;
    p2--;
  }
  return true;
}

/*
* Returns whether or not the input string is a single word.
* 
* Returns false if the input string contains at least one space character.
*/
bool isSingleWord(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ') {
      return false;
    }
  }
  return true;
}

int main() {
  // initialise a variable to store the input string
  string input = "";
  bool isValid = false;

  // loop until the input string is a single word
  while (!isValid) {
    cout << "\nPlease enter a word:" << endl;
    getline(cin, input);

    if (isSingleWord(input)) {
      isValid = true;
    } else {
      cout << input << " is not a single word." << endl;
    }
  }

  if (isPalindromeOptimised(input)) {
    cout << "\nYes, " << input << " is a palindrome." << endl;
  } else {
    cout << "\nSorry, " << input << " is not a palindrome." << endl;
  }
}
