#include "Hex_num/base/hex_num.h"
// #include "overl_dyn_hex_num.h"
#include <iostream>
#include <string>
#include <string_view>
#include "menu.h"
using namespace std;

int main() {
  cout << "Start" << endl;
  bool run = 1;
  while (run) {
    try {
      run = input_menu::menu();
    } 
    catch (hex_num::Container::Wrong_format_exception &err) {

    }
  }

  cout << "End" << endl;
  return 0;
}
