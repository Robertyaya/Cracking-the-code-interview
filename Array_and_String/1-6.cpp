#include <bits/stdc++.h>

// O(n)
std::string CompressString(std::string &str)
{
  int count = 1;
  std::string answer = "";

  char previous_char = str[0];
  for (int i = 1; i < str.size(); i++)
  {
    if (str[i] != previous_char || i == str.size() - 1)
    {
      // Handle the last element
      if (str[i] == previous_char)
        count++;

      answer = answer + (previous_char + std::to_string(count));

      if (str[i] != previous_char && i == str.size() - 1)
        answer = answer + str[i] + "1";
      count = 1;
    }
    else // str[i] == previous_char
      count++;

    previous_char = str[i];
  }
  return answer.size() < str.size() ? answer : str;
}

int main()
{
  std::string str = "aabcccccaaa";
  std::cout << CompressString(str) << std::endl;
  return 0;
}
