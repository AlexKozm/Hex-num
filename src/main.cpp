#include "hex_num_d.h"
#include "hex_num_s.h"
#include "menu.h"
#include "operators.h"
#include <iostream>
#include <stdexcept>
using namespace std;
using namespace hex_num_dynamic;

int main() {
  cout << "Start" << endl;

  // static_hex::Hex_num a("FFFFF");
  // hex_num_dynamic::Hex_num b("FFFFFFFF");
  // cout << a;
  // cout << b;
  // cout << b + b;
  // cout << b + a;
  // cout << a + b;
  // cout << a + a;

  bool run = 1;
  while (run) {
    try {
      run = input_menu::menu();
    } catch (hex_num::Container::Wrong_format_exception &err) {
      cout << "ERROR: Wrong_format_exception: " << err.what() << endl;
    } catch (std::overflow_error &err) {
      cout << "ERROR: overflow_error: " << err.what() << endl;
    } catch (input_menu::EOF_exeption &err) {
      cout << "EOF" << endl;
      run = 0;
    }
  }

  cout << "End" << endl;
  return 0;
}
