#include <config.hpp>

int main(int argc, char **argv) {
  if(argc < 2) {
    std::cout << "Usage: cfg.exe <input file>\n";
    std::cout << "Example: cfg.exe configuration.txt\n";
    exit(1);
  }

  auto options = parse_options(argv[1]);

  if(!options.empty()){
    for(auto itm : options){
      std::cout << itm.first << " " << itm.second << std::endl;
    }
  }else{
    std::cout << "Empty options list";
  }
}