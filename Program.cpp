#include <boost/algorithm/string.hpp>
#include <boost/format.hpp>
#include <boost/format/format_fwd.hpp>
#include <iostream>
#include <string>
#include <vector>

struct Occourencies {
  char character;
  std::string visualizer;
  int occour;

public:
  Occourencies(char character, std::string visualizer, int occour) {
    this->character = character;
    this->visualizer = visualizer;
    this->occour = occour;
  }
};

std::vector<Occourencies> occChecker(std::string myString, std::string chars) {
  int occFound{0};
  std::string visualizer;
  std::vector<Occourencies> occ;
  boost::to_lower(myString);

  for (int y = 32; y < 128; y++) {
    for (int z = 0; z < myString.length(); z++) {
      if (myString[z] == char (y)) {
        occFound += 1;
        visualizer.append("*");

      }
    }
    occ.push_back(Occourencies(char(y), visualizer, occFound));
    occFound = 0;
    visualizer.clear();
  }
  return occ;
};

int main() {
  std::string myString{"LKWPETER!!123"};
  std::string chars{"abcdefghijklmnopqrstuvwxyz1234567890!§$%&/()=?"};
  std::vector<Occourencies> occ{occChecker(myString, chars)};

  std::cout << boost::format("String: %1%\n") % myString << std::endl;
  std::cout << boost::format("%-50s %-20s\n") % "Zeichen" % "Vorkommen";

  for(auto i = 0; i < occ.size(); i++) {
    std::cout << boost::format("%-50s %-10s %-20s\n") % occ[i].character % occ[i].occour % occ[i].visualizer;
  }
};