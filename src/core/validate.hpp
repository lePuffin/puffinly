/*
 * @file: validate.hpp
 * @brief: Fail-fast validation composition helpers.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_CORE_VALIDATE_HPP_
#define SRC_CORE_VALIDATE_HPP_

// ── Includes ─────────────────────────────────────────────

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename Value, typename... Policies>
constexpr bool validate(const Value& value, const Policies&... policies) {
    return (policies(value) && ...);
}

}  // namespace puffinly

#endif  // SRC_CORE_VALIDATE_HPP_

// End of file
