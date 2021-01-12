/*
Reverse word

Prompts the user to enter a single word, and displays it in reverse.

Implementation notes:
 - Ensure the user enters a single word.
 - String reversal doesn't need to be done 'in place'.
 - Case and non-alpha characters should be preserved.
*/

#include <iostream>

using namespace std;

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
  // initialise variables to store the input and output strings
  string input = "";
  string output = "";

  // loop until the output string has been populated
  while (output.length() == 0) {
    cout << "\nPlease enter a word:" << endl;
    getline(cin, input);

    if (isSingleWord(input)) {
      output = reverseString(input);
    } else {
      cout << input << " is not a single word." << endl;
    }
  }

  cout << "\n" << input << " spelt backwards is: " << output << endl;
}
