#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

typedef struct option
{
  std::string configuration;
  std::string value;
} option;

inline std::vector<option> parse_options(char *szInFile)
{

  std::vector<option> options;
  std::fstream file(szInFile, std::ios::in);

  if (!file.is_open())
  {
    std::cerr << "Failed to open the file!" << std::endl;

    if (file.fail())
    {
      std::cerr << "Error code: " << strerror(errno) << std::endl;
    }

    return {};
  }

  std::string line;
  while (std::getline(file, line))
  {
    // Find the position of the first ':' character
    size_t pos = line.find(':');

    if (pos != std::string::npos)
    {
      // Split the line at the first ':' character
      option currentOption;
      currentOption.configuration = line.substr(0, pos);
      currentOption.value = line.substr(pos + 1);

      std::cout << currentOption.configuration << " " << currentOption.value << std::endl;
      options.push_back(currentOption);
    }
    else
    {
      std::cerr << "No ':' character found in the line." << std::endl;
    }
  }

  file.close();

  return options;
}