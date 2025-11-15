#include <iostream>
#include <fstream>

int main() {
    std::ofstream ofs("hello.txt");
    if (ofs.is_open()) {
        ofs << "Hello Wu!" << '\n';
    }
    ofs.close();
    ofs << "this will not get written";

    ofs.open("hello.txt", std::ios::app);
    ofs << "this will though! It's open again";
    return 0;
}