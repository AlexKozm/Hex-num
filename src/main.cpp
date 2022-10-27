// #include "Hex_num/base/hex_num.h"
// #include "overl_dyn_hex_num.h"
#include "menu.h"
#include "hex_num_s.h"
#include "hex_num_d.h"
#include "operators.h"
#include <iostream>
// #include <string>
// #include <string_view>
using namespace std;
using namespace hex_num_dynamic;

int main() {
  cout << "Start" << endl;

  // static_hex::Hex_num a(1);
  // hex_num_dynamic::Hex_num b(2);
  // cout << a;
  // cout << b;
  // cout << a + a;
  // cout << b + b;
  // cout << a + b;

  bool run = 1;
  while (run) {
    try {
      run = input_menu::menu();
    } catch (hex_num::Container::Wrong_format_exception &err) {
    }
  }

  cout << "End" << endl;
  return 0;
}
