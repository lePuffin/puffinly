/*
 * @file: non_empty_policy.hpp
 * @brief: Non-empty container/string validation policy.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_POLICIES_NON_EMPTY_POLICY_HPP_
#define SRC_POLICIES_NON_EMPTY_POLICY_HPP_

// ── Includes ─────────────────────────────────────────────

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

class non_empty_policy {
 private:
 public:
    non_empty_policy()  = default;
    ~non_empty_policy() = default;

    template <typename T>
    constexpr bool operator()(const T& value) const {
        return !value.empty();
    }
};

}  // namespace puffinly

#endif  // SRC_POLICIES_NON_EMPTY_POLICY_HPP_

// End of file
