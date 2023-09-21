#include <iostream>
#include <unordered_map>
#include <fstream>
#include <cstring>
#include <string>

inline std::unordered_map<std::string, std::string> parse_options(char *szInFile)
{

  std::unordered_map<std::string, std::string> options;
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
      std::cerr << "Error : delimeter not found in line '" << line << "'" << std::endl;
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
      options[line.substr(0, delimeterPos)] = line.substr(delimeterPos + 1, endPos);
    }
    else
    {
      std::cerr << "No '=' character found in the line '" << line << "'" << std::endl;
    }
  }

  file.close();

  return options;
}