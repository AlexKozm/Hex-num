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
int C::get_len() const { return len; }
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

Hex_num &Hex_num::operator=(const Hex_num &a) {
  arr = a.arr->get_copy();
  return *this;
}
//-------------------------------------------------------------

//-----------------Protected methods---------------------------

// as an example -1A3F, len = 5
void Hex_num::str_to_arr(string str) {
  size_t len = str.length();
  len = str[0] == '-' ? len - 1 : len;
  // cout<<"Start of str_to_arr"<<endl;
  if (len == 0) {
    throw Wrong_format_exception("Empty string");
  }
  for (size_t i = 0; i < len; ++i) {
    if (string("0123456789ABCDEF").find(str[str.length() - 1 - i]) !=
        str.npos) {
      // cout<< i << ": "<< str[str.length() - 1 - i] <<endl;
      arr->set(i, str[str.length() - 1 - i]);
    } else {
      throw Hex_num::Wrong_format_exception(
          "Wrong format in converting str to arr");
    }
  }
  if (str[0] == '-') {
    arr->set_minus();
  }
}

//-------------------------------------------------------------
Hex_num Hex_num::move_left(unsigned n) {
  if (n == 0) {
    return *this;
  }
  bool sign = arr->get_sign();
  for (int i = arr->get_len(); i >= 0; --i) {
    arr->force_set(i + n - 1, arr->weak_get(i - 1, '0'));
  }
  for (int i = 0; i < n; ++i) {
    arr->force_set(i, '0');
  }
  if (!sign) {
    arr->unset_minus();
  } else {
    arr->set_minus();
  }
  return *this;
}

Hex_num Hex_num::move_right(unsigned n) {
  if (n == 0) {
    return *this;
  }
  bool sign = arr->get_sign();
  cout << "Sign: " << sign << endl;
  for (int i = 1; i < arr->get_len(); ++i) {
    arr->set(i - 1, arr->weak_get(i + n - 1, '0'));
  }
  for (int i = arr->get_len() - 1; i > arr->get_len() - 1 - n; --i) {
    arr->set(i, '0');
  }
  if (!sign) {
    arr->unset_minus();
  } else {
    arr->set_minus();
  }
  return *this;
}

bool Hex_num::evenness() {
  if (C::char_to_int(arr->get(0)) % 2 == 0) {
    return 1;
  } else {
    return 0;
  }
}

istream &Hex_num::input(istream &is) {
  string inp;
  getline(is, inp);
  arr->set_zeros();
  str_to_arr(inp);
  return is;
}

ostream &Hex_num::output(ostream &os) const {

  bool started = 0;
  int i = arr->get_len() - 1;
  if (arr->get_sign()) {
    os << '-';
  }
  for (; i >= 0; --i) {
    int a = C::char_to_int(arr->weak_get(i, '0'));
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

  // bool started = 0;
  // int i = arr->get_len() - 1;
  // int a = C::char_to_int(arr->get(i));
  // if (arr->get_sign()) {
  //   os << '-';
  //   if (a > 8) {
  //     os << C::int_to_char(a - 8);
  //   }
  //   --i;
  // }
  // for (; i >= 0; --i) {
  //   a = C::char_to_int(arr->get(i));
  //   if (a != 0) {
  //     os << C::int_to_char(a);
  //     started = 1;
  //   } else if (started) {
  //     os << C::int_to_char(a);
  //   }
  // }
  // if (started == 0) {
  //   os << '0';
  // }
  // os << endl;
  return os;
}

void Hex_num::print_container(ostream &out) {
  for (int i = arr->get_len() - 1; i >= 0; --i) {
    out << arr->get(i);
  }
  out << endl;
}

Hex_num *Hex_num::reverse_code() {
  int val = C::char_to_int(arr->get(arr->get_len() - 1));
  if (arr->get_sign()) {
    arr->unset_minus();
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
      // cout << "val: " << val << endl;
    }
    // cout << "val s = " << val << endl;
    arr->set(arr->get_len() - 1, C::int_to_char(val));
    // cout << "Cont: ";
    // print_container(cout);

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
    arr->set_minus();
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
  cout << "rev code: "; this->print_container(cout);
  return this;
}

bool Hex_num::equal(Hex_num const &a, Hex_num const &b) {
  if (a.arr->get_sign() != a.arr->get_sign()) {
    return 0;
  }
  for (int i = 0; i < max(a.arr->get_len(), b.arr->get_len()); ++i) {
    if (a.arr->weak_get(i, '0') != b.arr->weak_get(i, '0')) {
      return 0;
    }
  }
  return 1;
}

Hex_num Hex_num::sum_of_additonals(const Hex_num &a, const Hex_num &b) {
  Hex_num ans(a.arr->get_new());
  int i = 0;
  int from_prev = 0;
  while (i < a.arr->get_len() || i < b.arr->get_len()) {
    int s1 = C::char_to_int(a.arr->get(i, a.arr->get_sign() ? 'F' : '0'));
    int s2 = C::char_to_int(b.arr->get(i, b.arr->get_sign() ? 'F' : '0'));
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
  cout << "additional in sum func: "; ans.print_container(cout);
  if (a.arr->get_sign() == 1 && b.arr->get_sign() == 1 &&
      C::char_to_int(ans.arr->get(ans.arr->get_len() - 1)) / 8 % 2 == 0) {
    throw overflow_error("<0 + <0 = >0");
  } else if (a.arr->get_sign() == 0 && b.arr->get_sign() == 0 &&
             C::char_to_int(ans.arr->get(ans.arr->get_len() - 1)) / 8 % 2 ==
                 1) {
    throw overflow_error(">0 + >0 = <0");
  } else if (a.arr->get_sign() == 1 ||
             b.arr->get_sign() == 1) {
  }
  cout << "final additional in sum func: "; ans.print_container(cout);
  return ans;
}

Hex_num Hex_num::sum(const Hex_num &a, const Hex_num &b) {
  Hex_num a_add(a);
  a_add.reverse_code()->to_additional_code();
  cout<<"additional a: "; a_add.print_container(cout);
  Hex_num b_add(b);
  b_add.reverse_code()->to_additional_code();
  cout<<"additional b: "; b_add.print_container(cout);
  Hex_num ans = sum_of_additonals(a_add, b_add);
  ans.from_add_to_rev_code()->reverse_code();
  cout<<"ans: "; ans.print_container(cout);
  return ans;
}

Hex_num Hex_num::dif(Hex_num const &a, Hex_num const &b) {
  Hex_num minus_b(b);
  if (!minus_b.arr->get_sign()) {
    minus_b.arr->set_minus();
  } else {
    minus_b.arr->unset_minus();
  }
  return sum(a, minus_b);
}
