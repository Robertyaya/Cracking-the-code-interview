#include <bits/stdc++.h>

bool isSubString(std::string &str1, std::string &str2)
{
  if (str1 == str2)
    return true;

  for (int i = 1; i < str1.size(); i++)
  {
    std::string sub1 = str1.substr(0, i);
    std::string sub2 = str1.substr(i, str1.size() - 1);
    std::string new_string = sub2 + sub1;
    if (new_string == str2)
      return true;
  }
  return false;
}
int main()
{
  std::string str1, str2;
  std::cin >> str1 >> str2;
  if (isSubString(str1, str2))
    std::cout << "Yes" << std::endl;
  else
    std::cout << "No" << std::endl;
  return 0;
}
