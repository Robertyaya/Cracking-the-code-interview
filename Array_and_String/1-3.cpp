#include <bits/stdc++.h>

void replaceSapces(std::string &str, int length)
{
  std::string answer;
  for (int i = 0; i < length; i++)
  {
    if (str[i] == ' ')
      answer += "%20";
    else
      answer += str[i];
  }
  std::cout << answer << std::endl;
}

int main()
{
  std::string str = "Mr John Smith";
  int length = 13;
  // O(length)
  replaceSapces(str, length);
  return 0;
}
