#include "menu.h"
#include "overl_dyn_hex_num.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;
using namespace input_menu;
using namespace overl_dyn_hex_num;

int input_menu::get_uint(int max) {
  cout << "Enter num: ";
  int inp;
  while (1) {
    cin >> inp;
    if (!cin.good()) {
      if (cin.eof()) {
        throw input_menu::EOF_exeption();
      }
      cout << "Try again: " << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } else if ((0 <= inp && inp < max) || (max == -1 && 0 <= inp)) {
      return inp;
    } else {
      cout << "Int should be in [0; " << max << ") range" << endl;
      cout << "Try again: " << endl;
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

int input_menu::big_if(int num) {
  Hex_num a, b, c;
  int inp;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  switch (num) {
  case 0:
    return 0;
  case 1:
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    c = a + b;
    cout << "+------\\__" << endl;
    cout << "|Answer: " << c;
    break;
  case 2:
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    c = a - b;
    cout << "+------\\__" << endl;
    cout << "|Answer: "<< c;
    break;
  case 3:
    cout << "Enter hex: ";
    cin >> a;
    if (a.evenness()) {
      cout << "Even" << endl;
    } else {
      cout << "Not even" << endl;
    }
    break;
  case 4:
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    if (a == b) {
      cout << "a == b" << endl;
    } else {
      cout << "a != b" << endl;
    }
    break;
  case 5:
    cout << "Enter hex: ";
    cin >> a;
    cout << "Lengh of movement. ";
    inp = get_uint(-1);
    c = (a << inp);
    cout << "+------\\__" << endl;
    cout << "|Answer: "<< c;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    break;
  case 6:
    cout << "Enter hex: ";
    cin >> a;
    cout << "Lengh of movement. ";
    inp = get_uint(-1);
    c = a >> inp;
    cout << "+------\\__" << endl;
    cout << "|Answer: "<< c;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    break;
  }
  return 1;
}

int input_menu::menu() {
  int inp = 1;
  while (inp) {
    // cout << endl;
    system("clear -x");
    cout << "+--------------+" << endl;
    cout << "|0. Exit       |" << endl;
    cout << "|1. Sum        |" << endl;
    cout << "|2. Dif        |" << endl;
    cout << "|3. Evenness   |" << endl;
    cout << "|4. Equaliy    |" << endl;
    cout << "|5. Move left  |" << endl;
    cout << "|6. Move right |" << endl;
    cout << "+--------------+" << endl;
    inp = get_uint(7);
    inp = big_if(inp);
    if (inp == 0) return 0;
    cout << "+----------------------------+" << endl;
    cout << "|Enter any key to continue...|" << endl;
    cout << "+----------------------------+" << endl;
    getchar();
  }

  return 0;
}
