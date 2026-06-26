/**
 * @file: main.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Functions ────────────────────────────────────────────
// Test group

// clang-format off
TEST_GROUP(TestRunnerGroup) {
    void setup() {
        // Code here will be called immediately before each test
    }
    void teardown() {
        // Code here will be called immediately after each test
    }
};
// clang-format on

// Tests
TEST(TestRunnerGroup, RunnerIsLinked) {
    CHECK_TRUE(true);
}

int main(int argc, const char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

// End of file
