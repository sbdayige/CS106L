#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <cctype>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string& source) {
  // Find all iterators pointing to whitespace (including begin/end)
  auto its = find_all(source.begin(), source.end(),
                      [](char c) { return std::isspace(static_cast<unsigned char>(c)); });

  Corpus tokens;

  // Transform adjacent iterator pairs into Token objects and insert into the set
  if (its.size() >= 2) {
    std::transform(its.begin(), its.end() - 1, its.begin() + 1, std::inserter(tokens, tokens.end()),
                   [&source](auto it1, auto it2) { return Token{source, it1, it2}; });
  }

  // Erase any empty tokens (e.g., produced by consecutive whitespace)
  std::erase_if(tokens, [](const Token& t) { return t.content.empty(); });

  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary) {
    namespace rv = std::ranges::views;

    // Build a ranges pipeline:
    // 1) keep tokens that are NOT in the dictionary
    // 2) for each token, produce a Misspelling where suggestions are dictionary words
    //    at Damerau-Levenshtein distance == 1
    // 3) drop Misspelling objects that have empty suggestion sets
    auto view = source
        | rv::filter([&dictionary](const Token& t) { return !dictionary.contains(t.content); })
        | rv::transform([&dictionary](const Token& t) {
            auto candidates = dictionary | rv::filter([&t](const std::string& w) {
                                return levenshtein(t.content, w) == 1;
                              });
            std::set<std::string> suggestions(candidates.begin(), candidates.end());
            return Misspelling{t, suggestions};
          })
        | rv::filter([](const Misspelling& m) { return !m.suggestions.empty(); });

    return std::set<Misspelling>(view.begin(), view.end());
};

/* Helper methods */

#include "utils.cpp"