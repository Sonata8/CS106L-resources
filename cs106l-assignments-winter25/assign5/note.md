 比起 assignment4 有些恼人的语法坑，这个 assignment 还是很娱乐的。在此列出最值得注意的几个要点：

- 在 lecture 里我们学的是 ofstream 的使用，而这题要求 ostream。实际上就是换个名字，但是要读清楚要求。笔者已经多次因为没读清楚`README`而吃亏了。警钟长鸣！（）

- 在重载`=`运算符的时候，我们要记得**先 delete 原来的`_friends`**然后再按照需要赋值的空间重新 new 出来；
- 在重载`+=`运算符的时候，需要注意到这个操作是**双向**的。因此，参数**必须**是`User&`而不能是`const User& user`；
- 重载`<`运算符需要加上 const 修饰。这是因为在实际的使用场景中用到小于号重载的接口往往要求提供不修改类成员的证明。

```cpp
// 需要在.h文件User的public里增添的声明
  ~User();
  User(const User& user);
  User& operator=(const User& user);
  User(User&& user)=delete;
  User& operator=(User&& user)=delete;

  friend std::ostream& operator << (std::ostream& os, const User& user);
  User& operator += (User& user);
  bool operator < (const User& user) const;

//.cpp
//    User(name=Alice, friends=[Bob, Charlie])
std::ostream& operator << (std::ostream& os, const User& user) {
  os << "User(name=" + user._name + ", friends=[";
  for (int i = 0; i < user._size; ++i) {
    if (i < user._size - 1) {
      os << user._friends[i] + ", ";
    } else {
      os << user._friends[i];
    }
  }
  os << (std::string)"])";
  return os;
}

User::~User() {
  delete[] _friends;
  _name.clear();
  _size = 0;
  _capacity = 0;
}

User::User(const User& user) {
  _name = user._name;
  _size = user._size;
  _capacity = user._capacity;
  _friends = new std::string[_capacity];
  for (int i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }
}

User& User::operator=(const User& user) {
  _name = user._name;
  _size = user._size;
  _capacity = user._capacity;
  delete[] _friends;    // !!!
  _friends = new std::string[_capacity];
  for (int i = 0; i < _size; ++i) {
    _friends[i] = user._friends[i];
  }
  return *this;
}

User& User::operator += (User& user) {    // NOT const User&
  add_friend(user.get_name());
  user.add_friend(_name);
  return *this;
}

bool User::operator < (const User& user) const {
  return this->_name < user.get_name();
}
```

