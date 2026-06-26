/*
 * @file: TestNonEmptyString.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>
#include <string>

#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(NonEmptyString) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(NonEmptyString, AcceptsNonEmptyValue) {
    const puffinly::non_empty_string value("puffinly");
    STRCMP_EQUAL("puffinly", value.value().c_str());
}

TEST(NonEmptyString, ThrowsOnEmptyValue) {
    CHECK_THROWS(std::invalid_argument, puffinly::non_empty_string(std::string()));
}

// End of file
