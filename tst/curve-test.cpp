#include "hex_num_abstract.h"
#include "stat_hex_num.h"
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

TEST_CASE("To reverse code") {
  std::stringstream str;
  SECTION("7FFFFFF") {
    Hex_num("7FFFFFF").to_reverse_code()->print_container(str);
    CHECK(str.str() == "7FFFFFF\n");
  }
  SECTION("A10") {
    Hex_num("A10").to_reverse_code()->print_container(str);
    CHECK(str.str() == "0000A10\n");
  }
  SECTION("1") {
    Hex_num("1").to_reverse_code()->print_container(str);
    CHECK(str.str() == "0000001\n");
  }
  SECTION("0") {
    Hex_num("0").to_reverse_code()->print_container(str);
    CHECK(str.str() == "0000000\n");
  }
  SECTION("-1") {
    Hex_num("-1").to_reverse_code()->print_container(str);
    CHECK(str.str() == "FFFFFFE\n");
  }
  SECTION("-A10") {
    Hex_num("-A10").to_reverse_code()->print_container(str);
    CHECK(str.str() == "FFFF5EF\n");
  }
  SECTION("-7FFFFFF") {
    Hex_num("-7FFFFFF").to_reverse_code()->print_container(str);
    CHECK(str.str() == "8000000\n");
  }
}

TEST_CASE("To additional code") {
  std::stringstream str;
  SECTION("7FFFFFF") {
    Hex_num("7FFFFFF").to_reverse_code()->to_additional_code()->print_container(
        str);
    CHECK(str.str() == "7FFFFFF\n");
  }
  SECTION("A10") {
    Hex_num("A10").to_reverse_code()->to_additional_code()->print_container(
        str);
    CHECK(str.str() == "0000A10\n");
  }
  SECTION("1") {
    Hex_num("1").to_reverse_code()->to_additional_code()->print_container(str);
    CHECK(str.str() == "0000001\n");
  }
  SECTION("0") {
    Hex_num("0").to_reverse_code()->to_additional_code()->print_container(str);
    CHECK(str.str() == "0000000\n");
  }
  SECTION("-1") {
    Hex_num("-1").to_reverse_code()->to_additional_code()->print_container(str);
    CHECK(str.str() == "FFFFFFF\n");
  }
  SECTION("-A10") {
    Hex_num("-A10").to_reverse_code()->to_additional_code()->print_container(
        str);
    CHECK(str.str() == "FFFF5F0\n");
  }
  SECTION("-7FFFFFF") {
    Hex_num("-7FFFFFF")
        .to_reverse_code()
        ->to_additional_code()
        ->print_container(str);
    CHECK(str.str() == "8000001\n");
  }
}

TEST_CASE("From additional code to reverse") {
  std::stringstream str;
  SECTION("7FFFFFF") {
    Hex_num("7FFFFFF")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "7FFFFFF\n");
  }
  SECTION("A10") {
    Hex_num("A10")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "0000A10\n");
  }
  SECTION("1") {
    Hex_num("1")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "0000001\n");
  }
  SECTION("0") {
    Hex_num("0")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "0000000\n");
  }
  SECTION("-1") {
    Hex_num("-1")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "FFFFFFE\n");
  }
  SECTION("-A10") {
    Hex_num("-A10")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "FFFF5EF\n");
  }
  SECTION("-7FFFFFF") {
    Hex_num("-7FFFFFF")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->print_container(str);
    CHECK(str.str() == "8000000\n");
  }
}

TEST_CASE("From additional to additional throw all") {
  std::stringstream str;
  SECTION("7FFFFFF") {
    Hex_num("7FFFFFF")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "7FFFFFF\n");
  }
  SECTION("A10") {
    Hex_num("A10")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "0000A10\n");
  }
  SECTION("1") {
    Hex_num("1")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "0000001\n");
  }
  SECTION("0") {
    Hex_num("0")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "0000000\n");
  }
  SECTION("-1") {
    Hex_num("-1")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "8000001\n");
  }
  SECTION("-A10") {
    Hex_num("-A10")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "8000A10\n");
  }
  SECTION("-7FFFFFF") {
    Hex_num("-7FFFFFF")
        .to_reverse_code()
        ->to_additional_code()
        ->from_add_to_rev_code()
        ->to_reverse_code()
        ->print_container(str);
    CHECK(str.str() == "FFFFFFF\n");
  }
}
