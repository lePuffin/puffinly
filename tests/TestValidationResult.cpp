/*
 * @file: TestValidationResult.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <stdexcept>

#include "libs/puffinly.hpp"

// ── CppUTest Includes ────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Test Group ───────────────────────────────────────────
// clang-format off
TEST_GROUP(ValidationResult) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// ── Tests ────────────────────────────────────────────────
TEST(ValidationResult, OkResultCarriesValue) {
    const auto result = puffinly::validation_result<int>::ok(42);

    CHECK_TRUE(result.is_ok());
    CHECK_FALSE(result.is_error());
    CHECK_EQUAL(42, result.value());
}

TEST(ValidationResult, ErrorResultCarriesFieldError) {
    const auto result = puffinly::validation_result<int>::fail({"age", "out of range", "RANGE_ERROR"});

    CHECK_FALSE(result.is_ok());
    CHECK_TRUE(result.is_error());
    STRCMP_EQUAL("age", result.error().field_name.c_str());
}

TEST(ValidationResult, AccessingMissingValueThrows) {
    const auto result = puffinly::validation_result<int>::fail({"field", "error", "GENERIC"});

    CHECK_THROWS(std::logic_error, result.value());
}

TEST(ValidationResult, AccessingMissingErrorThrows) {
    const auto result = puffinly::validation_result<int>::ok(1);

    CHECK_THROWS(std::logic_error, result.error());
}

// End of file
