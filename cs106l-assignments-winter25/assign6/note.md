对 std::optional 的简单应用。注意这里的 README 有点问题，`.transfrom`需要使用 C++23 标准编译，仅仅 C++20 是不够的。

```cpp
// task1
std::optional<Course> find_course(std::string course_title)
  {
    /* STUDENT_TODO: Implement this method! You will need to change the return
     * type. */
    for (auto course: courses) {
      if (course.title == course_title) {
        return course;
      }
    }
    return std::nullopt;
  }

// task2
    auto trans = [](Course course) {
      std::string res = "Found course: "+ course.title + "," + course.number_of_units +"," + course.quarter;
      return res;
    };

    std::string output = course.transform(trans).value_or((std::string)"Course not found.");
```

