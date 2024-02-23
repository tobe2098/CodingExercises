#pragma once
#include <concepts>

template <typename T>
concept c = requires(T x) {
	{ x + 1 } -> std::same_as<int>;
};
/*
This code defines a concept `c` using C++20 concepts. Concepts are a feature introduced in C++20 to constrain template parameters, allowing you to specify requirements on template arguments.

Let's break down the code:

```cpp
template <typename T>
concept c = requires(T x) {
  { x + 1 } -> std::same_as<int>;
};
```

- `template <typename T>`: This declares a template with a single template parameter `T`. This template parameter can represent any type.

- `concept c`: This introduces the concept named `c`. Concepts are used to specify requirements on template arguments. In this case, `c` is the name of the concept we're defining.

- `requires(T x) { ... }`: This is the requirement set for the concept `c`. It specifies what operations or properties are required for a type `T` to satisfy the concept `c`. Inside the curly braces `{ ... }`, we specify the requirements.

- `{ x + 1 } -> std::same_as<int>;`: This is the requirement itself. It uses the `requires` expression to specify that for any object `x` of type `T`, the expression `x + 1` must be well-formed and its type must be the same as `int` (indicated by `std::same_as<int>`). The `->` syntax is used to specify the expected return type of the expression.

In summary, the concept `c` requires that for a given type `T`, the expression `x + 1` must be valid and its type must be the same as `int`. This concept can then be used to constrain templates, ensuring that only types satisfying this requirement can be used as template arguments.*/