/*
 * @file: field_error.hpp
 * @brief: Structured field-level validation error.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_ERRORS_FIELD_ERROR_HPP_
#define SRC_ERRORS_FIELD_ERROR_HPP_

// ── Includes ─────────────────────────────────────────────
#include <string>

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

struct field_error {
    std::string field_name;
    std::string message;
    std::string error_code;

    bool operator==(const field_error& other) const {
        return field_name == other.field_name && message == other.message && error_code == other.error_code;
    }

    bool operator!=(const field_error& other) const { return !(*this == other); }
};

}  // namespace puffinly

#endif  // SRC_ERRORS_FIELD_ERROR_HPP_

// End of file
