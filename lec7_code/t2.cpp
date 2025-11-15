#include <iostream>
#include <cstdio> // For printf and scanf

// 使用命名空间是好的做法
using namespace std;

// --- Point 类的定义 (4021d9d33abc4bfa4bb2969a0030a6b7.jpg) ---
class Point {
private:
    int x, y;
public:
    // 构造函数：使用初始化列表和默认参数
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 设置坐标
    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }

    // 显示坐标 (const 成员函数)
    void show() const {
        printf("(%d,%d)", x, y);
    }

    // 获取 x 坐标 (const 成员函数)
    int getX() const { return x; }
    
    // 获取 y 坐标 (const 成员函数)
    int getY() const { return y; }
    
    // 没有显式析构函数，但对于这个简单的类是没问题的
};
// -------------------------------------------------------------------


// --- Circle 类的定义 (5ad306bbb3b5c8c6b3190cac240afed9.jpg & 7508e5923f6c93f7f07e71bcc4e4600e.jpg) ---
class Circle {
private:
    double radius;
    Point position;
    // 静态成员变量，用于记录当前 Circle 对象的数量
    static int n; 

public:
    // 构造函数：使用初始化列表初始化成员，并增加计数
    Circle(double r, const Point& p) : radius(r), position(p) {
        n++;
    }

    // 设置半径和圆心位置
    void set(double r, int x, int y) {
        radius = r;
        position.set(x, y);
    }

    // 显示圆的信息 (const 成员函数)
    void showC() const {
        // 打印半径
        printf("%.2f", radius); 
        // 打印圆心坐标，注意：position.show() 没有换行符
        position.show(); 
    }

    // 计算面积 (const 成员函数)
    double s() const {
        // PI 变量在这个函数内部定义，更好做法是定义为类静态成员
        const double PI = 3.14; 
        return PI * radius * radius;
    }

    // 静态函数：显示对象计数
    static void showCount() {
        printf("%d\n", n);
    }

    // 析构函数：对象销毁时减少计数
    ~Circle() {
        n--;
    }
};
// -------------------------------------------------------------------


// --- 静态成员变量的初始化 (6c4777672b37692b7dc39085632c27ab.jpg) ---
// 必须在类外对静态成员 n 进行初始化
int Circle::n = 0;

// 全局常量 PI (注意：Circle::s() 中也定义了 PI)
const double PI = 3.14; 
// -------------------------------------------------------------------


// --- main 函数 (6c4777672b37692b7dc39085632c27ab.jpg) ---
int main() {
    double r;
    int x, y;

    // 从标准输入读取数据
    // 注意：这里的格式化字符串 "%1f%d%d" 有问题，应该是 "%lf%d%d" 或 "%f%d%d"
    // C++ 中 double 应该用 %lf，但 scanf 通常 %f 也行，这里我保留你的写法，但提醒最好用 %lf
    printf("请输入半径 r, x 坐标, y 坐标: ");
    scanf("%f%d%d", &r, &x, &y); 
    printf("%f\n", r);

    // 1. 创建 Point 对象 p (n=0)
    Point p(x, y); 
    // 2. 创建 Circle 对象 c (n=1)
    Circle c(r, p); 

    // 局部作用域开始
    { 
        Point p1; // p1 默认构造 (0,0)
        // 3. 创建 Circle 对象 c1 (n=2)
        Circle c1(r, p1); 
        
        // 调用静态函数：显示计数
        // 预期输出：2
        printf("局部作用域内调用 showCount(): ");
        Circle::showCount(); 
    } // 局部作用域结束，c1 和 p1 销毁
      // c1 销毁时 ~Circle() 被调用，n-- (n=1)

    // 显示 Circle c 的信息
    printf("Circle c 的信息 (r, (x,y)): ");
    c.showC(); 
    printf("\n"); // c.showC() 内部没有换行，这里手动添加

    // 显示 Circle c 的面积
    printf("Circle c 的面积: ");
    printf("%.2f\n", c.s());

    // 再次显示对象计数
    // 预期输出：1
    printf("main 函数末尾调用 showCount(): ");
    Circle::showCount(); 

    return 0;
}