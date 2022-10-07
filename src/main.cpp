#include "stat_hex_num.h"
#include <iostream>
using namespace std;
using namespace static_hex;

int main() {
  cout << "Start" << endl;
  
  Hex_num a;
  a.input(cin);
  a.print_container(cout << "Container: ");
  a.reverse_code()->print_container(cout << "Reversed: ");
  a.reverse_code()->print_container(cout << "Reversed: ");
  a.to_additional_code()->print_container(cout << "Additional: ");

  // Hex_num a("-10"), b("-F");
  // a.print_container(cout);
  // b.print_container(cout);
  // a.print_container(cout << "a direct: ");
  // b.print_container(cout << "b direct: ");
  // Hex_num::sum(a, b).output(cout);

  // Hex_num h("-A10");
  // h.to_reverse_code()
  //     ->to_additional_code()
  //     ->print_container(cout);
  // h.from_add_to_rev_code()->print_container(cout);
  // Hex_num h("-7FFFFFF");
  // Hex_num h("-B123");
  // h.print_container(cout);
  // h.input(cin);
  // h.output(cout);
  // h.to_reverse_code();
  // h.print_container(cout);
  // h.to_additional_code();
  // h.print_container(cout);
  cout << "End" << endl;
  return 0;
}
