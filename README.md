# Puffinly

[![Tests CI](https://github.com/lePuffin/puffinly/actions/workflows/tests-ci.yml/badge.svg?branch=main)](https://github.com/lePuffin/puffinly/actions/workflows/tests-ci.yml)
[![License: MIT](https://img.shields.io/badge/License-MIT-green.svg)](LICENCE)

Puffinly is a C++17 validation library focused on small, explicit, dependency-free core APIs for consumer code.

Phase 1 is implemented as a header-only public surface through a single include, with CppUTest used only for test targets.

## Current Status

Implemented in Phase 1:

- Namespace lock: puffinly
- C++ standard lock: C++17
- Single-header public API entrypoint
- Core validation dispatcher with fail-fast policy chaining
- Policy set:
  - Range
  - NonEmpty
  - MaxLength
  - RegexMatch
  - CustomPolicy
- Validated types:
  - ranged_int<Min, Max>
  - non_empty_string
  - bounded_float<Min, Max>
  - optional<T>
- CppUTest suite coverage for policies, types, custom policy, and integration validate flows

## Project Layout

```text
.
|-- CMakeLists.txt
|-- docs/
|-- libs/
|   `-- puffinly.hpp
|-- src/
|   |-- core/
|   |-- policies/
|   `-- types/
`-- tests/
```

## Requirements

- CMake 3.28+
- C++17-capable compiler (GCC, Clang, or MSVC)
- CppUTest (required only for tests)

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build
```

Optional test toggle at configure time:

```bash
cmake -S . -B build -DPUFFINLY_BUILD_TESTS=OFF
```

## Test

```bash
cmake --build build --target UnitTests
./build/tests/UnitTests
```

Note: in test translation units, include project/STL headers before CppUTest headers to avoid macro collisions in some standard library implementations.

## Usage

Consumer code should include only the single public header:

```cpp
#include "libs/puffinly.hpp"

int main() {
    puffinly::ranged_int<0, 150> age(29);
    puffinly::non_empty_string name("Puffin");
    puffinly::bounded_float<0, 100> confidence(98.5);
    puffinly::optional<int> lucky(7);

    const auto even = puffinly::make_custom_policy([](int v) { return v % 2 == 0; });
    const bool ok = puffinly::validate(8, puffinly::range_policy<int>(0, 10), even);

    return ok ? 0 : 1;
}
```

## Constraints

- Core and consumer paths must remain dependency-free (standard library only)
- CppUTest is allowed only under tests
- Snippet source file is immutable by process policy

## Roadmap

Phase 2 - Model system:

- Struct composition support
- Model-level validation orchestration
- Structured validation errors (v1)

Phase 3 - Serialization layer:

- JSON adapters for to/from model conversion
- Explicit mapping without reflection dependency

Phase 4 - Optional reflection extension:

- Reflection backend integration
- Optional schema generation support

Phase 5 - Hardening:

- Benchmarks
- Fuzzing validation inputs
- Documentation expansion and examples
- ABI/API stability review

## Contributing

1. Create a branch from main.
2. Keep changes scoped and test-backed.
3. Run UnitTests locally before opening a pull request.
4. Open a pull request with a clear summary of behavior and tests.

## License

This project is licensed under the MIT License. See LICENCE for details.
