/**
 * @file: main.cpp
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include "CppUTest/CommandLineTestRunner.h"
#include "CppUTest/TestHarness.h"

// ── Defines ──────────────────────────────────────────────

// ── Functions ────────────────────────────────────────────

/**
 * @brief Main entry point for the test suite
 * @param argc Command line argument count
 * @param argv Command line arguments
 * @return Exit code from CppUTest framework (0 on success, non-zero on failure)
 * @details Initializes and runs all registered CppUTest test cases discovered
 *          during compilation and returns the overall test result status.
 */
int main(int argc, const char** argv) {
    return CommandLineTestRunner::RunAllTests(argc, argv);
}

// End of file
