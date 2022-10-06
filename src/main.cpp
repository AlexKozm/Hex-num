#include "stat_hex_num.h"
#include <iostream>
using namespace std;
using namespace static_hex;

int main() {
  cout << "Start" << endl;
  Hex_num h("-A10");
  h.to_reverse_code()
      ->to_additional_code()
      ->print_container(cout);
  h.from_add_to_rev_code()->print_container(cout);
  // Hex_num h("-7FFFFFF");
  // Hex_num h("-B123");
  // h.print_container(cout);
  // h.input(cin);
  // h.output(cout);
  // h.to_reverse_code();
  // h.print_container(cout);
  // h.to_additional_code();
  // h.print_container(cout);
  return 0;
}
