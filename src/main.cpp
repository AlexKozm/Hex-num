#include <iostream>
#include "stat_hex_num.h"
using namespace std;
using namespace static_hex;

int main() {
  cout << "Start" << endl;
  Hex_num h("-123");
  h.print_container(cout);
  h.output(cout);
  return 0;
}
