#include "Hex_num/base/hex_num.h"
#include "Hex_num/static/hex_num_s.h"
#include <catch2/catch_test_macros.hpp>
#include <sstream>

using namespace Catch;
using namespace static_hex;

// for static arr with len = 7
TEST_CASE("Constructors") {
  SECTION("Empty") { REQUIRE_NOTHROW(Hex_num()); }

  SECTION("String") {
    REQUIRE_THROWS_AS(Hex_num("8FFFFFF"), std::overflow_error);
    REQUIRE_NOTHROW(Hex_num("7FFFFFF"));
    REQUIRE_NOTHROW(Hex_num("A10"));
    REQUIRE_NOTHROW(Hex_num("1"));
    REQUIRE_NOTHROW(Hex_num("0"));
    REQUIRE_NOTHROW(Hex_num("-0"));
    REQUIRE_NOTHROW(Hex_num("-1"));
    REQUIRE_NOTHROW(Hex_num("-A10"));
    REQUIRE_NOTHROW(Hex_num("-7FFFFFF"));
    REQUIRE_THROWS_AS(Hex_num("-8FFFFFF"), std::overflow_error);
  }
  SECTION("Int") {
    REQUIRE_THROWS_AS(Hex_num(0x8FFFFFF), std::overflow_error);
    REQUIRE_NOTHROW(Hex_num(0x7FFFFFF));
    REQUIRE_NOTHROW(Hex_num(0xA10));
    REQUIRE_NOTHROW(Hex_num(0x1));
    REQUIRE_NOTHROW(Hex_num(0x0));
    REQUIRE_NOTHROW(Hex_num(-0x0));
    REQUIRE_NOTHROW(Hex_num(-0x1));
    REQUIRE_NOTHROW(Hex_num(-0xA10));
    REQUIRE_NOTHROW(Hex_num(-0x7FFFFFF));
    REQUIRE_THROWS_AS(Hex_num(-0x8FFFFFF), std::overflow_error);
  }
}

TEST_CASE("Output after init by constructors") {
  SECTION("by strings") {
    std::stringstream str;
    SECTION("7FFFFFF") {
      Hex_num("7FFFFFF").output(str);
      CHECK(str.str() == "7FFFFFF\n");
    }
    SECTION("A10") {
      Hex_num("A10").output(str);
      CHECK(str.str() == "A10\n");
    }
    SECTION("1") {
      Hex_num("1").output(str);
      CHECK(str.str() == "1\n");
    }
    SECTION("0") {
      Hex_num("0").output(str);
      CHECK(str.str() == "0\n");
    }
    SECTION("-0") {
      Hex_num("-0").output(str);
      CHECK(str.str() == "0\n");
    }
    SECTION("-1") {
      Hex_num("-1").output(str);
      CHECK(str.str() == "-1\n");
    }
    SECTION("-A10") {
      Hex_num("-A10").output(str);
      CHECK(str.str() == "-A10\n");
    }
    SECTION("-7FFFFFF") {
      Hex_num("-7FFFFFF").output(str);
      CHECK(str.str() == "-7FFFFFF\n");
    }
  }

  SECTION("by int") {
    std::stringstream str;

    SECTION("7FFFFFF") {
      Hex_num(0x7FFFFFF).output(str);
      CHECK(str.str() == "7FFFFFF\n");
    }
    SECTION("A10") {
      Hex_num(0xA10).output(str);
      CHECK(str.str() == "A10\n");
    }
    SECTION("1") {
      Hex_num(0x1).output(str);
      CHECK(str.str() == "1\n");
    }
    SECTION("0") {
      Hex_num(0x0).output(str);
      CHECK(str.str() == "0\n");
    }
    SECTION("-0") {
      Hex_num(-0x0).output(str);
      CHECK(str.str() == "0\n");
    }
    SECTION("-1") {
      Hex_num(-0x1).output(str);
      CHECK(str.str() == "-1\n");
    }
    SECTION("-A10") {
      Hex_num(-0xA10).output(str);
      CHECK(str.str() == "-A10\n");
    }
    SECTION("-7FFFFFF") {
      Hex_num(-0x7FFFFFF).output(str);
      CHECK(str.str() == "-7FFFFFF\n");
    }
  }
}

// TEST_CASE("To reverse code") {
//   std::stringstream str;
//   SECTION("7FFFFFF") {
//     Hex_num("7FFFFFF").reverse_code()->print_container(str);
//     CHECK(str.str() == "7FFFFFF\n");
//   }
//   SECTION("A10") {
//     Hex_num("A10").reverse_code()->print_container(str);
//     CHECK(str.str() == "0000A10\n");
//   }
//   SECTION("1") {
//     Hex_num("1").reverse_code()->print_container(str);
//     CHECK(str.str() == "0000001\n");
//   }
//   SECTION("0") {
//     Hex_num("0").reverse_code()->print_container(str);
//     CHECK(str.str() == "0000000\n");
//   }
//   SECTION("-1") {
//     Hex_num("-1").reverse_code()->print_container(str);
//     CHECK(str.str() == "FFFFFFE\n");
//   }
//   SECTION("-A10") {
//     Hex_num("-A10").reverse_code()->print_container(str);
//     CHECK(str.str() == "FFFF5EF\n");
//   }
//   SECTION("-7FFFFFF") {
//     Hex_num("-7FFFFFF").reverse_code()->print_container(str);
//     CHECK(str.str() == "8000000\n");
//   }
// }
//
// TEST_CASE("To additional code") {
//   std::stringstream str;
//   SECTION("7FFFFFF") {
//     Hex_num("7FFFFFF").reverse_code()->to_additional_code()->print_container(
//         str);
//     CHECK(str.str() == "7FFFFFF\n");
//   }
//   SECTION("A10") {
//     Hex_num("A10").reverse_code()->to_additional_code()->print_container(str);
//     CHECK(str.str() == "0000A10\n");
//   }
//   SECTION("1") {
//     Hex_num("1").reverse_code()->to_additional_code()->print_container(str);
//     CHECK(str.str() == "0000001\n");
//   }
//   SECTION("0") {
//     Hex_num("0").reverse_code()->to_additional_code()->print_container(str);
//     CHECK(str.str() == "0000000\n");
//   }
//   SECTION("-1") {
//     Hex_num("-1").reverse_code()->to_additional_code()->print_container(str);
//     CHECK(str.str() == "FFFFFFF\n");
//   }
//   SECTION("-A10") {
//     Hex_num("-A10").reverse_code()->to_additional_code()->print_container(str);
//     CHECK(str.str() == "FFFF5F0\n");
//   }
//   SECTION("-7FFFFFF") {
//     Hex_num("-7FFFFFF")
//         .reverse_code()
//         ->to_additional_code()
//         ->print_container(str);
//     CHECK(str.str() == "8000001\n");
//   }
//   // not sure that this test is right
//   // SECTION("-0100001") {
//   //   Hex_num("-1FFFFFF")
//   //       .reverse_code()
//   //       ->to_additional_code()
//   //       ->print_container(str);
//   //   CHECK(str.str() == "8000001\n");
//   // }
// }
//
// TEST_CASE("From additional code to reverse") {
//   std::stringstream str;
//   SECTION("7FFFFFF") {
//     Hex_num("7FFFFFF")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "7FFFFFF\n");
//   }
//   SECTION("A10") {
//     Hex_num("A10")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000A10\n");
//   }
//   SECTION("1") {
//     Hex_num("1")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000001\n");
//   }
//   SECTION("0") {
//     Hex_num("0")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000000\n");
//   }
//   SECTION("-1") {
//     Hex_num("-1")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "FFFFFFE\n");
//   }
//   SECTION("-A10") {
//     Hex_num("-A10")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "FFFF5EF\n");
//   }
//   SECTION("-7FFFFFF") {
//     Hex_num("-7FFFFFF")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->print_container(str);
//     CHECK(str.str() == "8000000\n");
//   }
// }
//
// TEST_CASE("From additional to additional throw all") {
//   std::stringstream str;
//   SECTION("7FFFFFF") {
//     Hex_num("7FFFFFF")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "7FFFFFF\n");
//   }
//   SECTION("A10") {
//     Hex_num("A10")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000A10\n");
//   }
//   SECTION("1") {
//     Hex_num("1")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000001\n");
//   }
//   SECTION("0") {
//     Hex_num("0")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "0000000\n");
//   }
//   SECTION("-1") {
//     Hex_num("-1")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "8000001\n");
//   }
//   SECTION("-A10") {
//     Hex_num("-A10")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "8000A10\n");
//   }
//   SECTION("-7FFFFFF") {
//     Hex_num("-7FFFFFF")
//         .reverse_code()
//         ->to_additional_code()
//         ->from_add_to_rev_code()
//         ->reverse_code()
//         ->print_container(str);
//     CHECK(str.str() == "FFFFFFF\n");
//   }
// }

TEST_CASE("Equality") {
  SECTION("1 == 1") {
    Hex_num a("1"), b("1");
    CHECK(Hex_num::equal(a, b) == 1);
  }
  SECTION("1 != 2") {
    Hex_num a("1"), b("2");
    CHECK(Hex_num::equal(a, b) == 0);
  }
  SECTION("-1 != 1") {
    Hex_num a("-1"), b("2");
    CHECK(Hex_num::equal(a, b) == 0);
  }
  SECTION("0 == 0") {
    Hex_num a("0"), b("0");
    CHECK(Hex_num::equal(a, b) == 1);
  }
}

TEST_CASE("Sum") {
  std::stringstream str;
  SECTION("1 + 1") {
    Hex_num a("1"), b("1");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "2\n");
  }
  SECTION("12 + F9") {
    Hex_num a("12"), b("F9");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "10B\n");
  }
  SECTION("-1 + -1") {
    Hex_num a("-1"), b("-1");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "-2\n");
  }
  SECTION("-12 + -F9") {
    Hex_num a("-12"), b("-F9");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "-10B\n");
  }
  SECTION("1 + -1") {
    Hex_num a("1"), b("-1");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "0\n");
  }
  SECTION("12 + -F9") {
    Hex_num a("12"), b("-F9");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "-E7\n");
  }
  SECTION("7FFFFFE + 1") {
    Hex_num a("7FFFFFE"), b("1");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "7FFFFFF\n");
  }
  SECTION("7FFFFFE + 2 |overflow_error") {
    Hex_num a("7FFFFFE"), b("2");
    REQUIRE_THROWS(Hex_num::sum(a, b));
  }
  SECTION("7FFFFFE + 3 |overflow_error") {
    Hex_num a("7FFFFFE"), b("3");
    REQUIRE_THROWS(Hex_num::sum(a, b));
  }
  SECTION("-7FFFFFE + -1") {
    Hex_num a("-7FFFFFE"), b("-1");
    Hex_num::sum(a, b).output(str);
    CHECK(str.str() == "-7FFFFFF\n");
  }
  SECTION("-7FFFFFE + -2 |overflow_error") {
    Hex_num a("-7FFFFFE"), b("-2");
    REQUIRE_THROWS(Hex_num::sum(a, b));
  }
  SECTION("-7FFFFFE + -3 |overflow_error") {
    Hex_num a("-7FFFFFE"), b("-3");
    REQUIRE_THROWS(Hex_num::sum(a, b));
  }
}

TEST_CASE("dif") {
  std::stringstream str;
  SECTION("1 - 1") {
    Hex_num a("1"), b("1");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "0\n");
  }
  SECTION("12 - F9") {
    Hex_num a("12"), b("F9");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "-E7\n");
  }
  SECTION("-1 - -1") {
    Hex_num a("-1"), b("-1");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "0\n");
  }
  SECTION("-12 - -F9") {
    Hex_num a("-12"), b("-F9");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "E7\n");
  }
  SECTION("1 - -1") {
    Hex_num a("1"), b("-1");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "2\n");
  }
  SECTION("12 - -F9") {
    Hex_num a("12"), b("-F9");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "10B\n");
  }
  SECTION("7FFFFFE - 1") {
    Hex_num a("7FFFFFE"), b("1");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "7FFFFFD\n");
  }
  SECTION("-7FFFFFE - -1") {
    Hex_num a("-7FFFFFE"), b("-1");
    Hex_num::dif(a, b).output(str);
    CHECK(str.str() == "-7FFFFFD\n");
  }
}

TEST_CASE("Moves") {
  std::stringstream str;
  SECTION("left") {
    SECTION("pos") {
      Hex_num a("123FADE");
      a.move_left(2).output(str);
      CHECK(str.str() == "3FADE00\n");
    }
    SECTION("neg") {
      Hex_num a("-123FADE");
      a.move_left(2).output(str);
      CHECK(str.str() == "-3FADE00\n");
    }
  }
  SECTION("right") {
    SECTION("pos") {
      Hex_num a("123FADE");
      a.move_right(2).output(str);
      CHECK(str.str() == "123FA\n");
    }
    SECTION("neg") {
      Hex_num a("-123FADE");
      a.move_right(2).output(str);
      CHECK(str.str() == "-123FA\n");
    }
    SECTION("-123 -> 3") {
      Hex_num a("-123");
      a.move_right(3).output(str);
      CHECK(str.str() == "0\n");
    }
  }
}
