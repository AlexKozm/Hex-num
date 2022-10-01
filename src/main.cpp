#include <iostream>
#include "hex_num.h"
using namespace std;
using namespace static_hex;

int main() {
  cout << "Start" << endl;
  Hex_num h(-0x12);
  h.print_container(cout);
  return 0;
}
