#include <bits/stdc++.h>

bool arePermutation(std::string &str1, std::string &str2)
{
  int n1 = str1.size();
  int n2 = str2.size();

  if (n1 != n2)
    return false;

  // Sorting O(nlogn)
  std::sort(str1.begin(), str2.end());
  std::sort(str2.begin(), str2.end());

  // O(n)
  for (int i = 0; i < n1; i++)
  {
    if (str1[i] != str2[i])
      return false;
  }
  return true;
}

bool arePermutation2(std::string &str1, std::string &str2)
{
  if (str1.size() != str2.size())
    return false;

  int count[128] = {0};
  for (int i = 0; i < str1.size(); i++)
  {
    // Get the char's ASCII code
    int value = (int)str1[i];
    count[value]++;
  }
  for (int i = 0; i < str2.size(); i++)
  {
    int value = (int)str2[i];
    count[value]--;
    if (count[value] < 0)
      return false;
  }
  return true;
}
int main()
{
  // Method 1: Using sorting O(nlogn)
  std::string str1 = "testest";
  std::string str2 = "estxest";
  if (arePermutation(str1, str2))
    std::cout << str1 << " and " << str2 << " are permutation of each other" << std::endl;

  // Method 2: O(n)
  if (arePermutation2(str1, str2))
    std::cout << str1 << " and " << str2 << " are permutation of each other" << std::endl;

  return 0;
}
