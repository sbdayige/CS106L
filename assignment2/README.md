<p align="center">
  <img src="docs/marriage_pact.png" alt="Marriage Pact Logo" />
</p>

# Assignment 2: Marriage Pact

Due Saturday, October 25th at 11:59PM

## Overview

Happy assignment 2! This is meant to be a very short and sweet bit of practice to get you started working with the STL's containers and pointers.

These are the files you need to care about:

- `main.cpp`: All your code goes here 😀!
- `short_answer.txt`: Short answer responses go here 📝!

To download the starter code for this assignment, please see the instructions for [**Getting Started**](../README.md#getting-started) on the course assignments repository.

## Running your code

To run your code, first you'll need to compile it. Open up a terminal (if you are using VSCode, hit <kbd>Ctrl+\`</kbd> or go to **Terminal > New Terminal** at the top). Then make sure that you are in the `assignment2/` directory and run:

```sh
g++ -std=c++20 main.cpp -o main
```

Assuming that your code compiles without any compiler errors, you can now do:

```sh
./main
```

which will actually run the `main` function in `main.cpp`.

As you are following the instructions below, we recommend intermittently compiling/testing with the autograder as a way to make sure you're on the right track!

> [!NOTE]
>
> ### Note for Windows
>
> On Windows, you may need to compile your code using
>
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp -o main
> ```
>
> in order to see output. Also, the output executable may be called `main.exe`, in which case you'll run your code with:
>
> ```sh
> ./main.exe
> ```

## Part 0: Setup

Welcome to the Marriage Pact! Before you begin, we'll need to know your name. Please change the constant `kYourName` at the top of `main.cpp` from `"STUDENT TODO"` to your full name (with a space between first and last).

## Part 1: Get all applicants

You’ve been waiting for days to get your Marriage Pact initials this year, and they’ve finally arrived in your inbox! This year, they’re implementing a new rule: your match MUST share your own initials to be eligible. However, even after talking about it for hours with your friends, you have no idea who your match could be! There are thousands of students on campus, and you can’t just go through the whole roster by hand to draft up a list of your potential soulmates. Fortunately enough for you, you’re in CS106L, and you remember that C++ has a pretty quick method of going through collected, similar information – containers!

We’ve included a `.txt` file of all of the (fictional) students who signed up for The Marriage Pact this year (`students.txt`). Each line includes the first and last name of the student. You will first write the function `get_applicants`:

> [!IMPORTANT]
>
> ### `get_applicants`
>
> From the `.txt` file, parse all of the names into a set. Each line contained in the file named `filename` is a single applicant's name. In your implementation, you are free to choose between an ordered (`std::set`) and unordered set (`std::unordered_set`) as you wish! If you do choose to use an unordered set, please change the relevant function definitions!

Additionally, please answer the following short answer question in `short_answer.txt`:

> [!IMPORTANT]
>
> ### `short_answer.txt`
>
> **Q1:** It is your choice to use either an ordered or unordered set. In a few sentences, what are some of the tradeoffs between the two? Additionally, please give an example (that has not been shown in lecture) of a valid hash function that could be used to hash student names for an unordered set.

> [!NOTE]
> All names appearing in this assignment are fictitious. Any resemblance to real persons, living or dead, is purely coincidental.

## Part 2: Find matches

Great detective work! Now that you’ve narrowed down your list of potential soulmates, it’s time to put it to the test. After a long day of acapella and consulting club meetings, you return to your dorm to learn from your roommate that there is a mixer for Marriage Pact matches at Main Quad that night! Your best chance of finding true love is imminent — if only you can get out of your Ultimate Frisbee practice. Quickly, you decide to interview everyone who shares your initials at the mixer, and you get to work coding up a function that will compile the order for you automatically.

For this section, you will write the functions `find_matches` and `get_match`:

> [!IMPORTANT]
>
> ### `find_matches`
>
> From the set `students` (generated in the previous part), take all names that share initials with the parameter `name` and place pointers to them in a new `std::queue`.
>
> - If you’re having trouble figuring out how to iterate through a set, it could be helpful to look back over [Thursday’s lecture on iterators and pointers](https://office365stanford-my.sharepoint.com/:p:/g/personal/jtrb_stanford_edu/EbOKUV784rBHrO3JIhUSAUgBvuIGn5rSU8h3xbq-Q1JFfQ?e=BlZwa7).
> - You will need to be familiar with the operations of a `std::queue` for this part. Take a look at cppreference's documentation [here](https://en.cppreference.com/w/cpp/container/queue).
> - Hint: It might help to define a helper function that computes the initials of some student's name. Then you can use that helper function to compare the initials of `name` with the initials of each name in `students`.

From here please implement the function `get_match` to find your “one true match.”:

> [!IMPORTANT]
>
> ### `get_match`
>
> Gets your “one true match” from the queue of all possible matches. This can be determined as you see fit; choose some method of acquiring one student from the queue, ideally something with a bit more thought than a single `pop()`, but it doesn’t have to be particularly complicated! Consider random values or other methods of selection.
>
> If your initials have no matches in the dataset, print `“NO MATCHES FOUND.”` Better luck next year 😢

Afterwards, answer the following question in `short_answer.txt`:

> [!IMPORTANT]
>
> ### `short_answer.txt`
>
> **Q2:** Note that we are saving pointers to names in the queue, not names themselves. Why might this be desired in this problem? What happens if the original set where the names are stored goes out of scope and the pointers are referenced?

## 🚀 Submission Instructions

To submit the assignment:

1. Please complete the feedback form [at this link](https://forms.gle/Zv27LwmtCPz88Kg46).
2. Submit your assignment on [Paperless](https://paperless.stanford.edu)!

````markdown
<p align="center">
  <img src="docs/marriage_pact.png" alt="Marriage Pact Logo" />
</p>

# 作业 2：婚姻匹配（Marriage Pact）

截止时间：10 月 25 日 星期六 23:59

## 概述

欢迎来到第 2 次作业！这是一个简短的练习，旨在帮助你熟悉 STL 容器和指针的基本用法。

你需要关注的文件有：

- `main.cpp`：所有代码写在这里 😀
- `short_answer.txt`：在这里填写简答题答案 📝

要下载本次作业的起始代码，请参阅课程作业仓库中的 [**入门指南（Getting Started）**](../README.md#getting-started)。

## 运行你的代码

要运行代码，首先需要编译。打开终端（如果使用 VSCode，可按 <kbd>Ctrl+`</kbd> 或在上方选择 **Terminal > New Terminal**）。确保当前工作目录为 `assignment2/`，然后运行：

```sh
g++ -std=c++20 main.cpp -o main
```

如果代码能通过编译（没有编译器错误），接着运行：

```sh
./main
```

上述命令会执行 `main.cpp` 中的 `main` 函数。

我们建议在实现过程中间隔性地使用自动评分器进行编译/测试，以确保你的进度正确。

> 注意（Windows）
>
> 在 Windows 上，你可能需要使用下面的方式编译以看到输出：
>
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp -o main
> ```
>
> 生成的可执行文件可能名为 `main.exe`，这时请用：
>
> ```sh
> ./main.exe
> ```

## 第 0 部分：设置

欢迎来到 Marriage Pact！在开始前，我们需要知道你的姓名。请在 `main.cpp` 顶部将常量 `kYourName` 从 `"STUDENT TODO"` 改为你的全名（名字与姓氏之间加空格）。

## 第 1 部分：获取所有申请者

你终于收到了今年的 Marriage Pact 首字母匹配名单！今年引入了一条新规则：你的匹配者必须与您拥有相同的首字母才有资格匹配。然而，即使和朋友讨论了很久，你仍然不知道谁可能是你的匹配者！校内有成千上万名学生，无法手动逐个查看名单来列出潜在对象。幸运的是，你在 CS106L 课程中，记得 C++ 提供了高效的容器来处理此类集合数据。

我们提供了一个包含所有（虚构）报名参加本年度 Marriage Pact 的学生名单的 `.txt` 文件（`students.txt`）。每一行包含一位学生的名字和姓氏。你首先需要实现函数 `get_applicants`：

> 重要
>
> ### `get_applicants`
>
> 从 `.txt` 文件中解析所有名字并放入集合。文件 `filename` 中的每一行都是一个申请者的姓名。在实现时，你可以自由选择使用有序集合（`std::set`）或无序集合（`std::unordered_set`）。如果选择使用无序集合，请同时修改相关函数的签名。

此外，请在 `short_answer.txt` 中回答下面的简答题：

> 重要
>
> ### `short_answer.txt`
>
> **Q1:** 你可以选择使用有序集合或无序集合。请简要说明两者各自的权衡（tradeoffs）。另外，给出一个（课堂未给出的）可用于对学生姓名进行哈希的有效哈希函数示例。

> 注：本作业中出现的所有姓名均为虚构，如有雷同纯属巧合。

## 第 2 部分：查找匹配

干得好！现在你已经把潜在匹配列表缩小，是时候检验它们了。经历了一天的活动后，你回到宿舍，得知当晚在 Main Quad 有一个 Marriage Pact 的联谊会！你的最佳机会即将到来——如果你能从终极飞盘训练中抽身的话。你决定在联谊会上快速询问所有与自己首字母相同的人，并编写代码自动生成采访顺序。

在此部分，你需要实现 `find_matches` 和 `get_match` 两个函数：

> 重要
>
> ### `find_matches`
>
> 从上一步生成的集合 `students` 中，找到所有与参数 `name` 首字母相同的姓名，并将指向这些姓名的指针放入新的 `std::queue` 中。
>
> - 如果不知道如何遍历 `set`，可以回顾课程中关于迭代器与指针的讲解。
> - 你需要熟悉 `std::queue` 的操作，参考 cppreference 的文档。
> - 提示：可以定义一个辅助函数来计算姓名的首字母，然后用它来比较 `name` 与 `students` 中每个名字的首字母。

接着实现 `get_match`，用于从候选队列中选出“唯一真爱”：

> 重要
>
> ### `get_match`
>
> 从所有候选者的队列中获取你的“唯一真爱”。选择策略由你决定；最好实现比简单的 `pop()` 更有思考的选择方式（例如使用随机选择或其他方法），但不必太复杂。
>
> 如果没有任何匹配者，请输出 `"NO MATCHES FOUND."`。

完成后，请在 `short_answer.txt` 回答下面的问题：

> 重要
>
> ### `short_answer.txt`
>
> **Q2:** 注意我们在队列中保存的是指向名字的指针，而不是名字本身。这在本题中有什么好处？如果原始保存姓名的集合超出作用域后仍然去引用这些指针，会发生什么情况？

## 提交说明 🚀

提交作业的步骤：

1. 请填写反馈表（表单链接）。
2. 在 Paperless 上提交你的作业。

你需要提交的文件：

- `main.cpp`
- `short_answer.txt`

你可以在截止前多次重新提交。
````
