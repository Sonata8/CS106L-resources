这个 assignment 的实质是训练我们**阅读文档来调用接口的能力**，在这个过程中熟悉一些 STL 的用法、lambda 的应用等等。到目前为止这个 assignment 的 README 文件是最长的。需要耐心阅读。具体代码的实现逻辑是不难的。但是有一些细节值得注意。笔者在实现的时候犯了不少混，也在这里记录一下，应该说这些都是十分宝贵的经验。

## tokenize

这里我们主要有三个步骤：用指针标记词之间的空格；把这些词实际分出来；删除多余的空格。最后一步是因为，教师希望我们使用`find_all`找出所有空格的指针，然后认为两个指针之间就是一个单词；但是，**如果两个实际的单词之间有多个空格**，分词的时候无法自动跳过去。

需要注意的两个地方：

- lambda 捕获 `source`的时候，**必须**以**引用(&)**的方式捕获。这是为什么呢？按照教师的指引，我们的 lambda 需要做一个“封装”的二元运算，把两个指针之间的单词（也有可能是空格，如上所述）封装成`Token`。我们很有必要看一眼`Token`在`spellcheck.h`里头的定义，因为这关系到我们如何使用这个“接口”。于是我们发现：![image-20251111102811676](C:\Users\Nices\AppData\Roaming\Typora\typora-user-images\image-20251111102811676.png)

  `Token`的 constructor 中，source 是以**引用**的方式传入的。如果我们在 lambda 中仅仅按值捕获，那么在 lambda 结束之后这个值就会被**析构**掉，这就很可能会（**实际上的确会，应该和之后的函数中使用多次 view 有关，但是具体咋回事我暂且蒙在鼓里...**）导致悬垂引用，从而在之后的`spellcheck`函数中使用时崩溃。

- `std::transform`中的末尾位置应当设置成`space.end()-1`。因为这个末尾是第一个指针的末尾，而第二个指针我们设置成第一个指针之后的那个位置来“夹出”所有的单词。如果末尾错误的设置成`space.end()`，就会在最后试图访问`space.end()+1`，导致崩溃。

```cpp
Corpus tokenize(const std::string& source) {
  auto space = find_all(source.begin(), source.end(), ::isspace);
  
  auto op = [&source](auto it1, auto it2) {     // & is necessary!!!!!!!!!!!!!
    Token token = {source, it1, it2};
    return token;
  };
  Corpus tokens;
  std::transform(space.begin(), space.end() - 1, space.begin() + 1,
                 std::inserter(tokens, tokens.end()), op);
  // ! IMPORTANT: space.end() - 1, NOT space.end() !!!!

  std::erase_if(tokens, [](Token token) { return token.content.empty(); });

  return tokens;
}
```

## spellcheck

这一部分没有什么坑点，主要是训练自己严格按照接口定义的方式去使用的能力。笔者一开始没有认真看定义的类型，在使用 range 的时候吃了不少亏。

```cpp
std::set<Mispelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
  namespace rv = std::ranges::views;
  auto pred = [&dictionary](auto token){ return !(dictionary.contains(token.content)); };
  auto func = [&dictionary](auto token) {
    auto sub_pred = [&token](auto dicWord) {
      return levenshtein(token.content, dicWord) == 1;
    };
    auto sub_view = dictionary | rv::filter(sub_pred);
    std::set<std::string> suggestions(sub_view.begin(), sub_view.end());
    return Mispelling(token ,suggestions);
  };
  auto notDrop = [](auto word) {
    return !(word.suggestions.empty());
  };
  auto view = source
        | rv::filter(pred)
        | rv::transform(func)
        | rv::filter(notDrop);
  
  return std::set<Mispelling>(view.begin(), view.end());
};
```

## 反思

笔者中学打算法竞赛的时候写过不少代码，自诩码力还算可以。但是，应该说算法竞赛所需要的对语言本身的掌控能力要求是比较低的。他们不涉及很复杂的接口调用，也不涉及内存的管理。因此，在做这个 assignment 的时候，笔者想当然的把接口随地大小用，看似一气呵成，实则只能对着各种类型报错发呆焦虑。笔者的收获是，在实际的项目应用中，要摒弃以前只关注逻辑而忽略细节的习惯，要知道代码应该怎么写，也要训练能实际上优雅的写出来的能力。