<p align="center">
  <img src="docs/header.png" alt="Header image with the text, in a code font, [~]$ ispell, on a black background" />
</p>

# 作业 4：Ispell

截止时间：11 月 8 日（周六）晚上 11:59

## 概述

现在我们已经讨论了 STL 的核心组件 —— 容器、迭代器、函子和算法 —— 以及驱动它们的关键成分 —— 模板，接下来把这些内容整合起来！在本次作业中，你将为 Ispell（一个旧的 Unix 风格的简单拼写检查器）编写核心逻辑。为此，你需要编写一些使用 `<algorithm>` 头和新的 C++ ranges 库的代码。

所有代码都应写在 `spellcheck.cpp` 中。完成后，你会得到一个像文档中示例那样的拼写检查程序：

<p align="center">
  <img src="docs/spellcheck.png" alt="An example terminal run of the spellcheck program" />
</p>

> [!IMPORTANT]
> 本作业说明看起来可能很长，但实际上需要你编写的代码并不多！我们提供了许多额外细节以便更容易完成作业。如果有任何疑问，请在 Ed/lecture/OH 上提问！

要下载起始代码，请参阅课程作业仓库中的“**Getting Started**”部分。

## 运行你的代码

要运行代码，首先需要编译。打开终端（在 VSCode 中按 <kbd>Ctrl+`</kbd> 或选择 **Terminal > New Terminal**）。确保当前目录为 `assignment4/`，然后运行：

```sh
g++ -std=c++20 main.cpp spellcheck.cpp -o main
```

如果代码编译通过（无编译错误），可以运行：

```sh
./main
```

这会执行 `main.cpp` 中的 `main` 函数。

在实现过程中，我们建议间歇性地使用 autograder 编译/测试，以确保进度正确。

> [!NOTE]
>
> ### Windows 注意事项
>
> 在 Windows 上，你可能需要使用以下命令来编译以便能看到输出：
>
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp spellcheck.cpp -o main
> ```
>
> 可执行文件可能名为 `main.exe`，这时运行：
>
> ```sh
> ./main.exe
> ```

## Ispell 的工作原理

经典的 Unix 程序 Ispell 的工作流程如下。首先将字典加载到内存中（包含常见的英文单词）。如果某个词在字典中找不到，则认为该词拼写错误。对每个拼写错误的词，使用 Damerau–Levenshtein 距离算法来生成建议单词。该算法表示将一个词变换为另一个词需要做多少次编辑（插入、删除、替换单个字符，或交换相邻两个字符）。如果拼写错误的词与字典中某个词的 Damerau–Levenshtein 距离恰好为 1，则把该字典词加入建议列表。思路是：人们通常只会犯一个小的拼写错误（例如 "mispelled" vs. "misspelled"）。

在本作业中，我们为你提供了构建拼写检查器所需的全部基础设施，包括 Damerau–Levenshtein 函数的实现。你的任务是实现拼写检查的核心算法。具体来说，你需要实现一个将输入字符串划分为若干 token 的算法（`tokenize`），以及另一个根据（已 token 化的）输入和字典识别拼写错误并给出建议的算法（`spellcheck`）。为增加挑战性（并与上周的课程相关），有一个限制：代码中不能使用任何 for/while 循环。必须完全使用 STL：`tokenize` 使用传统的 STL 算法实现，`spellcheck` 使用新的 ranges 库。通过此过程，你将学习如何使用算法和 lambda 操作现代 C++ 数据结构。

下面的手册会逐步引导你完成实现细节。

### `tokenize`

```cpp
struct Token { std::string content; size_t src_offset; };
using Corpus = std::set<Token>;
Corpus tokenize(std::string& input);
```

`tokenize` 接收一个输入字符串并将其拆分为若干 `Token` 对象。查看 `spellcheck.h` 中的 `Token` 定义：`Token` 表示文件中一段内容——从概念上来说就是文本中的一个单词；在代码中则是出现在文件中某个索引 `src_offset` 的 `std::string`。我们的目标是将输入文件划分为一组 `Token`，称为 `Corpus`（类型别名为 `std::set<Token>`）。

关键约束：token 被空白字符或文件边界包围。例如字符串 `"history will absolve me"` 将产生四个 token：

- `{ content: "history", src_offset: 0 }`
- `{ content: "will", src_offset: 8 }`
- `{ content: "absolve", src_offset: 13 }`
- `{ content: "me", src_offset: 21 }`

实现 `tokenize` 时请使用传统 STL 方法（如 `std::transform`），不要使用 for/while。总体策略：

1. 找出所有指向空白字符的迭代器
2. 在连续的空白迭代器之间生成 token
3. 删除空 token

下面是逐步指导：

1. 步骤一：识别所有指向空白字符的迭代器

如果能获取字符串中所有指向空白字符的迭代器，那么 token 就是任意两个空白字符之间的字符区间。我们本来需要多次调用 `find_if` 来收集这些迭代器，幸运的是仓库中提供了 `find_all`：

```cpp
// utils.cpp
template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);
```

该函数返回从 `begin` 到 `end` 范围内所有满足 `pred` 的元素的迭代器向量。重要的是，返回向量也包含边界迭代器 `begin` 和 `end`（即返回的迭代器要么满足 `pred(*it)`，要么等于 `begin`，要么等于 `end`），并按顺序返回。

你可以把 `std::isspace` 作为谓词传入（注意传入 `std::isspace` 以避免重载解析问题）。

2. 步骤二：在连续空白迭代器之间生成 token

有了这些空白字符迭代器后，token 就是任意两个连续迭代器之间的字符区间。`Token` 提供了一个接收源码字符串和迭代器对的构造函数，会自动处理边缘的空白及标点修剪：

```cpp
// spellcheck.cpp
template <typename It>
Token(std::string& source, It begin, It end);
```

你需要对每对连续迭代器调用该构造函数。可以使用 `std::transform`（两个输入范围 + 二元操作）的重载，为二元操作传入一个 lambda，参数为两个 `std::string::iterator`，返回 `Token{ source, it1, it2 }`。注意：lambda 必须按引用捕获 `source`（例如 `[&source](auto it1, auto it2) { return Token{source, it1, it2}; }`），否则代码无法运行。

输出容器使用 `std::set<Token> tokens`，并用 `std::inserter(tokens, tokens.end())` 作为 `std::transform` 的输出迭代器。

对于两个输入范围的选择，要确保二元操作的每次调用都对应连续的空白迭代器对（提示：两个输入范围可以相互重叠）。

3. 步骤三：删除空 token

可能会生成一些空的 token（例如连续多个空白字符），可以使用 `std::erase_if` 从 `std::set` 中删除满足条件（例如 `token.content.empty()`）的元素。

最终返回 `tokens`。

完成此步骤后，程序会开始输出 token 数量。编译并运行示例：

```sh
./main "hello wrld"
```

输出应类似：

```
Loading dictionary... loaded 464811 words.
Tokenizing input... got 2 tokens.
```

说明 `tokenize` 已成功将大约 46 万条字典单词和输入字符串 `"hello wrld"` 切分为 token。接下来需要实现 `spellcheck`，因为目前 `"wrld"` 可能仍被误判为正确。

### `spellcheck`

```cpp
struct Misspelling { Token token; std::set<std::string> suggestions; };
using Dictionary = std::unordered_set<std::string>;
std::set<Misspelling> spellcheck(const Corpus& source, const Dictionary& dictionary);
```

`spellcheck` 接收一个已 token 化的 `Corpus`（`tokenize` 的输出）和一个 `Dictionary`（`std::unordered_set<std::string>`，表示所有有效的英文单词），并返回若干 `Misspelling` 结构体。每个 `Misspelling` 表示一个拼写错误的 `token` 以及该 token 的建议单词集合。

识别拼写错误的算法步骤（使用 `std::ranges::views`）：

1. 跳过已经拼写正确的词。
2. 否则，在字典中查找与之 edit-distance（Damerau–Levenshtein）为 1 的词作为建议。
3. 丢弃没有任何建议的拼写错误项。

实现提示：

1. 步骤一：跳过已拼写正确的词

如果词出现在 `dictionary` 中，则认为拼写正确（例如 `dictionary.contains("world")` 为 true，而 `dictionary.contains("wrld")` 为 false）。用 `std::ranges::views::filter` 来筛选拼写错误的 token。在构造 lambda 时需要访问 `dictionary`（通常按引用捕获以避免复制）。

2. 步骤二：在字典中查找 edit-distance 为 1 的词作为建议

对于每个错误 token，使用 `std::ranges::views::transform` 将其转换为 `Misspelling` 对象。生成建议的方法是遍历 `dictionary` 并筛选出与 `token.content` 的 `levenshtein` 距离为 1 的单词。可使用提供的 `levenshtein` 函数：

```cpp
size_t levenshtein(const std::string& a, const std::string& b);
```

该实现会在距离大于 1 时提前退出，从而提高效率。

在构建建议集合时，需要在 lambda 内嵌套另一个 `rv::filter`，然后把该视图 materialize（使用 `std::set<std::string>(view.begin(), view.end())`）来获取 `std::set<std::string>` suggestions。最后返回 `Misspelling{ token, suggestions }`。

3. 步骤三：丢弃没有建议的 Misspelling

有些拼写错误（例如无意义的字符串）在字典中找不到任何 edit-distance 为 1 的单词，此时 `suggestions` 为空，需要把这些条目过滤掉。再用一次 `rv::filter` 过滤空建议，然后使用 `std::set<Misspelling>` 的迭代器构造函数将视图 materialize 为 `std::set<Misspelling>` 并返回。

注意：`std::ranges::to` 是 C++23 的特性，可能在某些编译器上不可用。为保证兼容性，请在本作业中仅使用到 C++20，并用 `std::set` 的迭代器构造函数来 materialize 视图。

如果一切实现正确，拼写检查器将能正常工作。示例：

```sh
./main "This string is mispelled"
```

你应看到类似示例中的输出。

你也可以检查示例文件：

```sh
./main --stdin < "examples/(marquez).txt"
```

> PowerShell 用户：在 PowerShell 下等效命令为：
>
> ```sh
> Get-Content "examples/(marquez).txt" | ./main --stdin
> ```

程序支持的选项如下：

```
./main [--dict dict_path] [--stdin] [--unstyled] [--profile] text

--dict dict_path  设置字典位置，默认为 words.txt
--stdin           从 stdin 读取（可用于文件重定向或管道）
--unstyled        不对输出添加颜色
--profile         打印 tokenizing / spellcheck 所用时间（用于性能分析）
text              要检查的文本（如果不使用 stdin）
```

如果你想挑战性能，可以尝试 `--profile`。尽管实现为暴力遍历整个约 50 万单词的字典，但程序仍能相当快地运行。在保证结果正确的前提下，欢迎尝试优化性能（可选）。

## 提交说明

为完整测试拼写检查器，可重新编译并运行 autograder：

```sh
./main
```

如果通过所有测试，即可提交作业。提交步骤：

1. 填写反馈表单（文档中给出链接）。
2. 在 Paperless 上提交作业。

你的交付物应为：

- `spellcheck.cpp`

在截止时间前你可以多次提交。
