#include <bits/stdc++.h>

bool OneAway(std::string &str1, std::string &str2)
{
  if (std::fabs(str1.size() - str2.size()) > 1)
    return false;

  int table[128] = {0};
  int count = 0;
  for (int i = 0; i < str2.size(); i++)
  {
    int value = (int)str2[i];
    table[value]++;
  }
  for (int i = 0; i < str1.size(); i++)
  {
    int value = (int)str1[i];
    table[value]--;
    if (table[value] < 0)
      count++;
    if (count > 1)
      return false;
  }
  return true;
}
int main()
{
  std::string str1 = "pale";
  std::string str2 = "bake";
  std::string answer = OneAway(str1, str2) ? "true" : "false";
  std::cout << answer << std::endl;

  return 0;
}
