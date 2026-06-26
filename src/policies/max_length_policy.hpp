/*
 * @file: max_length_policy.hpp
 * @brief: Maximum length validation policy.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_POLICIES_MAX_LENGTH_POLICY_HPP_
#define SRC_POLICIES_MAX_LENGTH_POLICY_HPP_

// ── Includes ─────────────────────────────────────────────
#include <cstddef>

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

class max_length_policy {
 private:
    std::size_t max_length_;

 public:
    explicit max_length_policy(std::size_t max_length) : max_length_(max_length) {}
    ~max_length_policy() = default;

    template <typename T>
    constexpr bool operator()(const T& value) const {
        return value.size() <= max_length_;
    }
};

}  // namespace puffinly

#endif  // SRC_POLICIES_MAX_LENGTH_POLICY_HPP_

// End of file
