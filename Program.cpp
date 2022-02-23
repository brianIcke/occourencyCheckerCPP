#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/case_conv.hpp>
#include <boost/format.hpp>
#include <boost/format/free_funcs.hpp>
#include <exception>
#include <iostream>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

struct Occourencies {
  char character;
  int occour;

public:
  Occourencies(char character, int occour) {
    this->character = character;
    this->occour = occour;
  }
};

std::vector<Occourencies> occChecker(std::string myString, std::string chars) {
  int occFound{0};
  std::vector<Occourencies> occ;
  boost::to_lower(myString);

  for (int y = 0; y < chars.length(); y++) {
    for (int z = 0; z < myString.length(); z++) {
      if (myString[z] == chars[y]) {
        occFound += 1;
      }
    }
    occ.push_back(Occourencies(chars[y], occFound));
    occFound = 0;
  }
  return occ;
};

int main() {
  std::string myString{"abbccdeefffggghiijjkklllmnoppqrrstuvvvvvvwwwwwwwxxyyzz !"};
  std::string chars{"abcdefghijklmnopqrstuvwxyz1234567890!/?.,=+-_%"};
  std::vector<Occourencies> occ{occChecker(myString, chars)};
  std::string toString {std::to_string(32)};

  std::cout << boost::format("%-50s %-20s\n") % "Zeichen" % "Vorkommen";

  for(auto i = 0; i < sizeof(occ); i++) {
    std::cout << boost::format("%-50s %-20s\n") % occ[i].character % occ[i].occour;
  }
};