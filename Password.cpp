#include "Password.h"
#include <array>
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.empty()) {
    return 0;
  }

  int repetition = 1;
  size_t index = 0;
  while (index + 1 < phrase.length() && phrase[index] == phrase[index + 1]) {
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(string pass){
  bool has_upper = false;
  bool has_lower = false;

  for (unsigned char ch : pass) {
    if (ch >= 'A' && ch <= 'Z') {
      has_upper = true;
    } else if (ch >= 'a' && ch <= 'z') {
      has_lower = true;
    }

    if (has_upper && has_lower) {
      return true;
    }
  }

  return false;
}

unsigned int Password::unique_characters(string phrase) {
  std::array<bool, 256> seen{};
  unsigned int count = 0;

  for (unsigned char ch : phrase) {
    if (!seen[ch]) {
      seen[ch] = true;
      count++;
    }
  }

  return count;
}