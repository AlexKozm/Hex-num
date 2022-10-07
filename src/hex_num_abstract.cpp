#include "hex_num_abstract.h"
#include "string"
#include <functional>
#include <iostream>
#include <math.h>
#include <stdexcept>
#include <string>

using namespace hex_num;
using namespace std;
typedef Container C;

//-----------------Container-----------------------------------
size_t C::get_len() const { return len; }
void C::set_len(size_t len) { this->len = len; }

char C::int_to_char(int hex) {
  hex %= 16;
  if (hex < 10) {
    return '0' + hex;
  } else {
    return 'A' + hex - 10;
  }
}

int C::char_to_int(char hex) {
  // cout << "Befor throw: " << (char)hex << endl;
  if ('0' <= hex && hex <= '9') {
    return hex - '0';
  } else if ('A' <= hex && hex <= 'F') {
    return hex - 'A' + 10;
  } else {
    throw Hex_num::Wrong_format_exception(
        "Wrong format in converting char to int");
  }
}

C::~Container() {}
//-------------------------------------------------------------

//-----------------Hex_num constructors------------------------
Hex_num::Hex_num(C *arr) : arr(arr) {}

Hex_num::Hex_num(C *arr, int hex) : arr(arr) {
  if (hex < 0) {
    arr->set_minus();
    hex = -hex;
  }
  int i = 0;
  while (hex > 0) {
    arr->set(i++, C::int_to_char(hex));
    hex /= 16;
  }
}

Hex_num::Hex_num(C *arr, string hex) : arr(arr) { str_to_arr(hex); }

Hex_num::Wrong_format_exception::Wrong_format_exception(string msg)
    : runtime_error(msg){};

Hex_num::Hex_num(const Hex_num &that) { arr = that.arr->get_copy(); }
Hex_num::~Hex_num() {
  delete arr;
  arr = nullptr;
  // cout << "Abstact container destructor" << endl;
}
//-------------------------------------------------------------

//-----------------Protected methods---------------------------

// as an example -1A3F, len = 5
void Hex_num::str_to_arr(string str) {
  size_t len = str.length();
  if (len == 0) {
    throw Wrong_format_exception("Empty string");
  }
  if (str.length() > 1 && str[0] == '-') {
    arr->set_minus();
    --len;
  }
  for (size_t i = 0; i < len; ++i) {
    if (string("0123456789ABCDEF").find(str[str.length() - 1 - i]) !=
        str.npos) {
      arr->set(i, str[str.length() - 1 - i]);
    } else {
      throw Hex_num::Wrong_format_exception(
          "Wrong format in converting str to arr");
    }
  }
}

// void Hex_num::unset_minus(){};
//-------------------------------------------------------------
void Hex_num::move_left(int n) {}
void Hex_num::move_right(int n) {}

bool Hex_num::evenness() {
  if (C::char_to_int(arr->get(0)) % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

void Hex_num::input(istream &is) {
  string inp;
  getline(is, inp);
  arr->set_zeros();
  str_to_arr(inp);
}

void Hex_num::output(ostream &os) {
  bool started = 0;
  int i = arr->get_len() - 1;
  int a = C::char_to_int(arr->get(i));
  if (a >= 8) {
    os << '-';
    if (a > 8) {
      os << C::int_to_char(a - 8);
    }
    --i;
  }
  for (; i >= 0; --i) {
    a = C::char_to_int(arr->get(i));
    if (a != 0) {
      os << C::int_to_char(a);
      started = 1;
    } else if (started) {
      os << C::int_to_char(a);
    }
  }
  if (started == 0) {
    os << '0';
  }
  os << endl;
}

void Hex_num::print_container(ostream &out) {
  for (int i = arr->get_len() - 1; i >= 0; --i) {
    out << arr->get(i);
  }
  out << endl;
}

Hex_num *Hex_num::reverse_code() {
  int val = C::char_to_int(arr->get(arr->get_len() - 1));
  if (val >= 8) {
    val -= 8;
    for (int i = 0; i < 3; ++i) {
      int bit = static_cast<int>(pow(2, i));
      // cout << "  bit = " << bit << endl;
      // cout << "  last bit = " << (arr->get(i) / bit) % 2 << endl;
      if ((val / bit) % 2 == 0) {
        val += bit;
      } else {
        val -= bit;
      }
    }
    // cout << "val s = " << val << endl;
    arr->set(arr->get_len() - 1, C::int_to_char(val));

    for (int j = arr->get_len() - 2; j >= 0; --j) {
      int val = C::char_to_int(arr->get(j));
      for (int i = 0; i < 4; ++i) {
        int bit = static_cast<int>(pow(2, i));
        if ((C::char_to_int(arr->get(j)) / bit) % 2 == 0) {
          val += bit;
        } else {
          val -= bit;
        }
      }
      arr->set(j, C::int_to_char(val));
    }
  }
  return this;
}

Hex_num *Hex_num::to_additional_code() {
  int val = C::char_to_int(arr->get(arr->get_len() - 1));
  if (val >= 8) {
    for (int i = 0; i < arr->get_len() - 2; ++i) {
      val = C::char_to_int(arr->get(i));
      val += 1;
      if (val == 16) {
        arr->set(i, C::int_to_char(0));
      } else {
        arr->set(i, C::int_to_char(val));
        break;
      }
    }
  }
  return this;
}

Hex_num *Hex_num::from_add_to_rev_code() {
  if (C::char_to_int(arr->get(arr->get_len() - 1)) >= 8) {
    int i = 0;
    int val = C::char_to_int(arr->get(i));
    while (val == 0 && i < arr->get_len()) {
      ++i;
      val = C::char_to_int(arr->get(i));
    }
    if (i == arr->get_len() - 1 && val == 8) {
      throw overflow_error(
          "Such additional code can't be represented as a reversed code");
    } else {
      for (int j = 0; j < 4; ++j) {
        int bit = static_cast<int>(pow(2, j));
        if ((C::char_to_int(arr->get(i)) / bit) % 2 == 1) {
          val -= bit;
          for (--j; j >= 0; --j) {
            bit = static_cast<int>(pow(2, i));
            val += bit;
          }
          break;
        }
      }
      arr->set(i, C::int_to_char(val));
      --i;
    }
    for (; i >= 0; --i) {
      arr->set(i, 'F');
    }
  }
  return this;
}

bool Hex_num::equal(Hex_num const &a, Hex_num const &b) {}

Hex_num Hex_num::sum_of_additonals(const Hex_num &a, const Hex_num &b) {
  Hex_num ans(a.arr->get_new());
  int i = 0;
  int from_prev = 0;
  while (i < a.arr->get_len() && i < b.arr->get_len()) {
    int s1 = C::char_to_int(a.arr->get(i));
    int s2 = C::char_to_int(b.arr->get(i));
    int res = s1 + s2 + from_prev;
    from_prev = 0;
    if (res >= 16) {
      from_prev = 1;
      ans.arr->force_set(i, C::int_to_char(res % 16));
      ++i;
    } else {
      ans.arr->force_set(i, C::int_to_char(res));
      ++i;
    }
  }
  if (C::char_to_int(a.arr->get(a.arr->get_len() - 1)) >= 8 &&
      C::char_to_int(b.arr->get(b.arr->get_len() - 1)) >= 8 &&
      C::char_to_int(ans.arr->get(ans.arr->get_len() - 1)) / 8 % 2 == 0) {
    throw overflow_error("<0 + <0 = >0");
  } else if (C::char_to_int(a.arr->get(a.arr->get_len() - 1)) < 8 &&
             C::char_to_int(b.arr->get(b.arr->get_len() - 1)) < 8 &&
             C::char_to_int(ans.arr->get(ans.arr->get_len() - 1)) / 8 % 2 ==
                 1) {
    throw overflow_error(">0 + >0 = <0");
  } else if (C::char_to_int(a.arr->get(a.arr->get_len() - 1)) >= 8 ||
             C::char_to_int(b.arr->get(b.arr->get_len() - 1)) >= 8) {
  }
  return ans;
}

Hex_num Hex_num::sum(const Hex_num &a, const Hex_num &b) {
  Hex_num a_add(a);
  a_add.reverse_code()->to_additional_code();
  Hex_num b_add(b);
  b_add.reverse_code()->to_additional_code();

  a_add.print_container(cout << "a in additional: ");
  b_add.print_container(cout << "b in additional: ");
  // a_add.print_container(cout);
  // b_add.print_container(cout);

  // cout << "HERE" << endl;
  Hex_num ans = sum_of_additonals(a_add, b_add);
  ans.from_add_to_rev_code()->reverse_code();
  return ans;
}
Hex_num *Hex_num::dif(Hex_num const &a, Hex_num const &b) {}

// Hex_num::~Hex_num() {
//   free()
// }
