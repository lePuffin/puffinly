/**
 * @file: main.cpp
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

// ── Includes ─────────────────────────────────────────────
#include <iostream>

#include "app_config.hpp"
#include "libs/puffinly.hpp"

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Functions ────────────────────────────────────────────
// Public

void run_demo() {
    const ranged_value<int, 0, 150>    age(29);
    const non_empty_string             name("Puffin");
    const ranged_value<double, 0, 100> confidence(99.5);
    const optional<int>                lucky_number(7);

    std::cout << "Validated user: " << name.value() << ", age=" << age.value() << ", confidence=" << confidence.value()
              << ", lucky=" << lucky_number.value_or(-1) << '\n';
}

// Private

}  // namespace puffinly

int main() {
    try {
        std::cout << "Initializing application: " << APP_NAME << " v" << APP_VERSION << " by " << PRODUCT_MAINTAINER
                  << '\n';
        puffinly::run_demo();
    } catch (const std::exception& e) {
        std::cerr << "[Main] Error: " << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// End of file
