// #include "stat_hex_num.h"
#include "overl_stat_hex_num.h"
#include <iostream>
// using namespace std;
// using namespace static_hex;
using namespace overl_stat_hex_num;

int main() {
  cout << "Start" << endl;
  Hex_num a, b;
  cout << "Enter a: ";
  cin >> a;
  cout << "Enter b: ";
  cin >> b;
  cout << "a: " << a;
  cout << "b: " << b;
  // cout << b + a; // - ?
  cout << "a + b = " << static_cast<Hex_num>(a + b);
  cout << "a - b = " << static_cast<Hex_num>(a - b);
  cout << "a == b: " << (a == b) << endl;
  cout << "Is a even: " << a.evenness() << endl;
  cout << "Is a even: " << b.evenness() << endl;

  int n, m;
  cout << "Move left on: ";
  cin >> n;
  cout << "Move right on: ";
  cin >> m;
  a << n;
  b >> m;
  cout << "Moved left on: ";
  cout << a;
  cout << "Moved right on: ";
  cout << b;

  // Hex_num a("123FADE");
  // a.move_right(2);
  // cout <<  "HERE" << endl;
  // a.print_container(cout);
  // a.output(cout);

  // Hex_num a;
  // a.input(cin);
  // a.print_container(cout << "Container: ");
  // a.reverse_code()->print_container(cout << "Reversed: ");
  // a.reverse_code()->print_container(cout << "Reversed: ");
  // a.to_additional_code()->print_container(cout << "Additional: ");

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
