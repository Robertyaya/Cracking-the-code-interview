#include <bits/stdc++.h>
#include <unordered_map>

bool isPermutationOfPalindrome(std::string &str)
{
  int count[128] = {0};

  // Calculate the every char frequency
  for (int i = 0; i < str.size(); i++)
  {
    int value = (int)str[i];
    count[value] = count[value] + 1;
  }

  int cont = 0;
  for (int i = 0; i < str.size(); i++)
  {
    int value = (int)str[i];
    if (count[value] % 2 == 1)
      cont++;
  }
  return cont == 0 || (str.size() % 2 == 1 && cont == 1);
}

bool isPermutationOfPalindrome2(std::string &pali)
{
  // We check the odd during the process
  int count[128] = {0};
  int count_odd = 0;
  for (int i = 0; i < pali.size(); i++)
  {
    int value = (int)pali[i];
    count[value]++;
    if (count[value] % 2 == 1)
      count_odd++;
    else
      count_odd--;
  }
  // If count_odd == 0, represent every char is even
  // If count_odd == 1, represent only one char is odd
  return count_odd <= 1;
}
int main()
{
  std::string pali = "carerac";
  std::string isPermutation = isPermutationOfPalindrome(pali) ? "yes" : "no";
  std::string isPermutation2 = isPermutationOfPalindrome2(pali) ? "yes" : "no";
  std::cout << isPermutation << std::endl;
  std::cout << isPermutation2 << std::endl;

  return 0;
}
