#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>

typedef struct option
{
  std::string key;
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
    // Find the position of the first '=' character
    size_t delimeterPos = line.find('=');
    size_t commentStartPos = line.find('#');
    size_t endPos;

    if(commentStartPos < delimeterPos){
      std::cerr << "Error : delimeter not found" << std::endl;
      continue;
    }else{
      if(commentStartPos == std::string::npos){
        endPos = line.size() - delimeterPos;
      }else{
        endPos = commentStartPos - delimeterPos - 1;
      }
    }

    if (delimeterPos != std::string::npos)
    {
      // Split the line at the first '=' character
      option currentOption;
      currentOption.key = line.substr(0, delimeterPos);
      currentOption.value = line.substr(delimeterPos + 1, endPos);

      std::cout << currentOption.key << " " << currentOption.value << std::endl;
      options.push_back(currentOption);
    }
    else
    {
      std::cerr << "No '=' character found in the line." << std::endl;
    }
  }

  file.close();

  return options;
}