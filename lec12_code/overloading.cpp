#include <iostream>
#include <fstream>

class Student {
private:
    std::string name;
    int id;
public:
    Student(std::string name, int id) : name{name}, id{id} {};
    Student() : name{"unknown"}, id{0} {};
    friend std::ofstream& operator << (std::ofstream& out, const Student& stu);
};

std::ofstream& operator << (std::ofstream& out, const Student& stu) {
    out << stu.name << " " << stu.id << "\n";
    return out;
}

int main() {
    std::ofstream ofs("out.txt", std::ios::app);
    Student sysu[2];
    sysu[0] = {"wwh", 25329114};
    sysu[1] = {"who", 11451419};
    ofs << sysu[0] << sysu[1] << "\n";
    return 0;
}