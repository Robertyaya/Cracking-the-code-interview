#include <bits/stdc++.h>
bool BruteForce(std::string str)
{
  for (int i = 0; i < str.size(); i++)
  {
    for (int j = 0; j < str.size(); j++)
    {
      // Skip itself
      if (i == j)
        continue;
      // Represent this char is not unique
      if (str[i] == str[j])
      {
        return false;
      }
    }
  }
  return true;
}

bool isUniqueChars(std::string &str)
{
  if (str.size() > 128)
    return false;

  std::vector<bool> char_set(128);
  for (int i = 0; i < str.size(); i++)
  {
    // Get the ASCII of the char
    int val = (int)str[i];
    if (char_set[val])
      return false;
    char_set[val] = true;
  }
  return true;
}

bool isUniqueChars_bitvector(std::string &str)
{
  // Reduce space
  // Each bool occupies a size of 8 bits
  std::bitset<128> bits(0);
  for (int i = 0; i < str.size(); i++)
  {
    int val = (int)str[i];
    if (bits.test(val) > 0)
      return false;
    bits.set(val);
  }
  return true;
}

int main()
{
  // Output the postion which is unique char in string
  std::string str = "abcdefbdsjdkfslsjfsl";

  // O(n^2)
  if (BruteForce(str))
    std::cout << "Every Char in this string is unique" << std::endl;

  // O(n)
  if (isUniqueChars(str))
    std::cout << "Every Char in this string is unique" << std::endl;

  if (isUniqueChars_bitvector(str))
    std::cout << "Every Char in this string is unique" << std::endl;

  return 0;
}
