#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

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

/* Helper methods */

#include "utils.cpp"