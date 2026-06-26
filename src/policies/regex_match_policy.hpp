/*
 * @file: regex_match_policy.hpp
 * @brief: Regular expression matching policy.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_POLICIES_REGEX_MATCH_POLICY_HPP_
#define SRC_POLICIES_REGEX_MATCH_POLICY_HPP_

// ── Includes ─────────────────────────────────────────────
#include <regex>
#include <string>

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

class regex_match_policy {
 private:
    std::regex expression_;

 public:
    explicit regex_match_policy(const std::string& expression) : expression_(expression) {}
    ~regex_match_policy() = default;

    bool operator()(const std::string& value) const { return std::regex_match(value, expression_); }
};

}  // namespace puffinly

#endif  // SRC_POLICIES_REGEX_MATCH_POLICY_HPP_

// End of file
