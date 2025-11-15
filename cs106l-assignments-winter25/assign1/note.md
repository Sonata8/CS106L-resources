# CS106L assignment1

## Part0

在这一部分，我们需要完成结构体`Course`的定义并且修改关键函数的定义，使之能够达成我们希望的效果。

观察`utils.cpp`，我们发现他是使用`stringstream`处理表格的每一行数据的。因此，结构体中的三个变量全部使用`std::string`类型声明。

阅读函数`parse_csv`和`write_courses_offered`的功能注释，发现他们需要能够达成修改**实际变量**的目标。因此应当将参数声明改为引用传参`&`。

## Part1

在这一部分，我们需要录入`courses.csv`中的数据到`courses`中，这是一个`vector`，每个元素都是一个`Course`结构体。根据提示，阅读`utils.cpp`中的`split`函数，发现录入的逻辑是按行录入，并且用特定的分隔符去把每一行分割成三个部分。观察 csv 文件发现分隔符就是逗号。但是，在 csv 文件中发现第一行的内容是“标题”，这个是我们不需要的。所以首先用`getline()`吃掉这一行。然后，用 while 循环不断录入，直到录完为止。

```cpp
void parse_csv(std::string filename, std::vector<Course>& courses) {
  std::ifstream ifs(filename);
  std::string line;
  std::getline(ifs, line);
  while (std::getline(ifs, line)) {
    Course L;
    std::vector<std::string> res = split(line, ',');
    L.title = res[0]; L.number_of_units = res[1]; L.quarter = res[2];
    courses.push_back(L);
  }
}
```

## Part2

在这一部分，我们需要完成`write_courses_offered`函数。具体来说，我们要完成两个功能：

1. 导出所有存在的课程（课程存在意味着`quarter`不为`null`）；
2. 删除存在的课程。

在提示中，设计课程的教师告诉我们在遍历 vector 的时候去删除元素是很危险的。因此我们需要用另一个 vector 记录下所有需要删除的课程，最后再统一删除他们。

在课程的学习中，我们知道使用 ofstream 打开文件的时候需要修改写入模式为`std::ios::app`，这样就不会覆盖之前写入的内容。然而，**什么时候进入这个模式是值得思考的**。如果在打开文件的时候就进入，那么会发生什么情况呢？比如，我们由于测试需要，要多次运行程序；那么，由于每次在打开文件之后立刻进入不覆盖模式，那每次运行程序都会写入一模一样的重复内容。但我们实际上只需要写入一次就可以了。所以，我们打开文件之后**先不改变默认的覆盖模式**，直接写入标题行，同时清理掉了上次运行程序写入的东西。然后在进入不覆盖模式。这样就不会重复了。

```cpp
void write_courses_offered(std::vector<Course>& all_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream ofs("student_output/courses_offered.csv");  // 不能在这里就以 append 方式打开！否则运行几次就会重复添加几次
  ofs << "Title,Number of Units,Quarter" << '\n';
  ofs.close();
  ofs.open("student_output/courses_offered.csv", std::ios::app);
  std::vector<Course> toDelete;
  for (auto course: all_courses) {
    if (course.quarter == "null") {
      continue;
    }
    toDelete.push_back(course);
    ofs << course.title + "," + course.number_of_units + "," + course.quarter << "\n";
  }
  for (auto del: toDelete) {
    delete_elem_from_vector(all_courses, del);
  }
}
```

## Part3

逻辑同上，不再赘述。

```cpp
void write_courses_not_offered(std::vector<Course> unlisted_courses) {
  /* (STUDENT TODO) Your code goes here... */
  std::ofstream ofs("student_output/courses_not_offered.csv");
  ofs << "Title,Number of Units,Quarter" << '\n';
  ofs.close();
  ofs.open("student_output/courses_not_offered.csv", std::ios::app);
  for (auto course: unlisted_courses) {
    ofs << course.title + "," + course.number_of_units + "," + course.quarter << "\n";
  }
}
```

