#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class heuristic {
public:
  std::string language;
  std::string directive;
  std::string data;
  void print();
  bool apply(std::string filename);
  std::string to_string();
};

bool search_file(std::string filename, std::string data) {
  std::ifstream file(filename);
  std::string line;
  while (std::getline(file, line)) {
    if (line.find(data) != std::string::npos) {
      return true;
    }
  }

  return false;
}

void heuristic::print() {
  std::cout << language << " " << directive << " " << data << std::endl;
}

std::string heuristic::to_string() {
  return language + " " + directive + " " + data;
}

bool heuristic::apply(std::string filename) {
  // for "contains" directive
  if (directive == "contains") {
    if (search_file(filename, data)) {
      return true;
    }
  }

  return false;
}

void parse_tsv(std::string filename, std::vector<heuristic> &heuristics) {
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cout << "Unable to open file: " << filename << std::endl;
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    std::string language;
    std::string directive;
    std::string data;
    std::getline(iss, language, '\t');
    std::getline(iss, directive, '\t');
    std::getline(iss, data, '\t');
    heuristic h;
    h.language = language;
    h.directive = directive;
    h.data = data;
    heuristics.push_back(h);
  }
}

int main() {
  // Collect heuristics
  std::vector<heuristic> heuristics;
  parse_tsv("heuristics", heuristics);
}
