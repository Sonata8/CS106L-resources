#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Student {
    std::string name;
    int score;
};

void sort_students() {
    std::vector<Student> students = {
        {"Alice", 85},
        {"Bob",   92},
        {"Charlie", 78},
        {"David", 92}
    };

    // 🏆 Lambda 函数作为 std::sort 的比较器
    std::sort(students.begin(), students.end(), 
        // 捕获列表为空 []，因为不需要捕获外部状态
        // 参数是两个 Student 元素：a 和 b
        [](const Student& a, const Student& b) {
            // 📌 排序规则：如果 a 的 score 大于 b 的 score，返回 true（降序）
            return a.score > b.score; 
        } 
    ); 

    std::cout << "--- Students Sorted by Score (Descending) ---" << std::endl;
    for (const auto& s : students) {
        std::cout << s.name << ": " << s.score << std::endl;
    }
}