难度不大，熟悉 assignment1 里面读入文件的`std:ifstream`的用法之后很快就可以做出来。唯一值得注意的是，`find_matches`函数的类型为`std::queue<const std::string*>`。故而，我们往里头 push 的应该是地址而不是字符串本身。

```cpp
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  std::queue<const std::string*> valid;
  for (auto stu: students) {
    if (helper(name) == helper(stu)) {
      valid.push(&stu);
    }
  }
  return valid;
}
```

