/*
Lower case converter

Prompts the user to enter a single word, and displays it in lower case.

Implementation notes:
 - Ensure the user enters a single word.
 - String conversion doesn't need to be done 'in place'.
 - Non-alpha characters should be preserved.
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
      output = toLowerCase(input);
    } else {
      cout << input << " is not a single word." << endl;
    }
  }

  cout << "\n" << input << " converted to lower case is: " << output << endl;
}
