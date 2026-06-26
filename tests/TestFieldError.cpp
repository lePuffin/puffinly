/*
 * @file: TestFieldError.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(FieldError) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(FieldError, ConstructsWithAllFields) {
    const puffinly::field_error error{"age", "invalid range", "RANGE_ERROR"};

    STRCMP_EQUAL("age", error.field_name.c_str());
    STRCMP_EQUAL("invalid range", error.message.c_str());
    STRCMP_EQUAL("RANGE_ERROR", error.error_code.c_str());
}

TEST(FieldError, SupportsEqualityComparison) {
    const puffinly::field_error first{"name", "empty value", "EMPTY_ERROR"};
    const puffinly::field_error second{"name", "empty value", "EMPTY_ERROR"};

    CHECK_TRUE(first == second);
    CHECK_FALSE(first != second);
}

// End of file
