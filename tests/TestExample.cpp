/**
 * @file: TestExample.cpp
 * @date: 2026-06-26
 * @copyright: Copyright (c) ${CURRENT_YEAR} TheCPuffin
 */

// ── Includes ─────────────────────────────────────────────
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Functions ────────────────────────────────────────────
// Test group

// clang-format off
TEST_GROUP(FirstTestGroup) {
    void setup() {
       // Code here will be called immediately before each test
    }
    void teardown() {
       // Code here will be called immediately after each test
    }
};
// clang-format on

// Tests
TEST(FirstTestGroup, FirstTest) {
    CHECK_TRUE(true);
}

// End of file
