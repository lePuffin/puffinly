/*
 * @file: range_policy.hpp
 * @brief: Inclusive range validation policy.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_POLICIES_RANGE_POLICY_HPP_
#define SRC_POLICIES_RANGE_POLICY_HPP_

// ── Includes ─────────────────────────────────────────────

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename T>
class range_policy {
 private:
    T min_;
    T max_;

 public:
    range_policy(T min_value, T max_value) : min_(min_value), max_(max_value) {}
    ~range_policy() = default;

    constexpr bool operator()(const T& value) const { return (value >= min_) && (value <= max_); }
};

}  // namespace puffinly

#endif  // SRC_POLICIES_RANGE_POLICY_HPP_

// End of file
