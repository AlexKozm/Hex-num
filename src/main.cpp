#include "Hex_num/base/hex_num_abstract.h"
#include "overl_dyn_hex_num.h"
#include <iostream>
#include <string>
#include <string_view>
#include "menu.h"
using namespace std;
using namespace overl_dyn_hex_num;

int main() {
  cout << "Start" << endl;
  bool run = 1;
  while (run) {
    try {
      run = input_menu::menu();
    } 
    catch (hex_num::Hex_num::Wrong_format_exception &err) {

    }
  }

  cout << "End" << endl;
  return 0;
}
