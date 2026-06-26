/*
 * @file: custom_policy.hpp
 * @brief: User-provided callable wrapper policy.
 * @copyright: Copyright (c) 2026 TheCPuffin
 * @date: 2026-06-26
 */

#ifndef SRC_POLICIES_CUSTOM_POLICY_HPP_
#define SRC_POLICIES_CUSTOM_POLICY_HPP_

// ── Includes ─────────────────────────────────────────────

// ── Namespace ────────────────────────────────────────────
namespace puffinly {

// ── Defines ──────────────────────────────────────────────

// ── Classes ──────────────────────────────────────────────

template <typename Callable>
class custom_policy {
 private:
    Callable callable_;

 public:
    explicit custom_policy(Callable callable) : callable_(callable) {}
    ~custom_policy() = default;

    template <typename T>
    constexpr bool operator()(const T& value) const {
        return static_cast<bool>(callable_(value));
    }
};

template <typename Callable>
custom_policy<Callable> make_custom_policy(Callable callable) {
    return custom_policy<Callable>(callable);
}

}  // namespace puffinly

#endif  // SRC_POLICIES_CUSTOM_POLICY_HPP_

// End of file
