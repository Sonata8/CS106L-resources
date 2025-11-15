# CS106L-Lecture-Code

**Write a function:
  `std::optional<int> divide(int a, int b);`**

that returns:
1. the result if `b != 0`
2. `std::nullopt` if `b == 0`

In main(), call it twice:
1. once with `(10, 2)`
2. once with `(10, 0)`

For each call, check whether the optional contains a value. If so, print the result. Otherwise print an error message

Hints!!!
1. Use if `(opt)` to check if the optional contains a value.
2. Use `.value()` to get the underlying int.
