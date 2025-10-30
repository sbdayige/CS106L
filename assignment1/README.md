# Assignment 1: SimpleEnroll

Due Friday, October 17th, at 11:59PM

## Overview

It’s that time of the quarter again; time to use SimpleEnroll 🤗 Wootwoot.
One thing everyone realizes in their Stanford career at one point is that they
have to eventually graduate — and so enrolling in classes becomes a strategic
endeavor to maximize the XP towards graduation, while also being able to sleep
more than 4 hours a night!

In this hopefully short assignment, we’re going to use data from the
ExploreCourses API to figure out which CS classes on ExploreCourses are
offered this year, and which are not! We’ll be taking advantage of streams, while also exercising initialization and references in C++. Lets jump in ʕ•́ᴥ•̀ʔ っ

There are only two files you should need to care about:

- `main.cpp`: All your code goes here 😀!
- `utils.cpp`: Contains some utility functions. You'll use functions defined in this file, but you don't otherwise need to modify it.

## Running your code

To run your code, first you'll need to compile it. Open up a terminal (if you are using VSCode, hit <kbd>Ctrl+\`</kbd> or go to **Terminal > New Terminal** at the top). Then make sure that you are in the `assignment1/` directory and run:

```sh
g++ -std=c++20 main.cpp -o main
```

Assuming that your code compiles without any compiler errors, you can now do:

```sh
./main
```

which will actually run the `main` function in `main.cpp`. This will execute your code and then run an autograder that will check that your code is correct.

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

## Part 0: Read the code and fill in the `Course` struct

1. In this assignment, we'll be using the `Course` struct to represent records pulled from ExploreCourses in C++. Take a look at the (incomplete) definition of the `Course` struct in `main.cpp` and fill in the field definitions. Ultimately, we'll be using streams to generate `Course`s --- remember what types streams deal with?

2. Take a look at the `main` function in `main.cpp`, and take special notice of how `courses` is passed into `parse_csv`, `write_courses_offered`,
   and `write_courses_not_offered`. Think about what these functions are doing. Do you need to change anything in the function definition? Spoiler, you do.

## Part 1: `parse_csv`

Check out `courses.csv`, it is a CSV file, with three columns: Title, Number of
Units, and Quarter. Implement `parse_csv` so that, for each line in the csv file, it creates a struct `Course` containing the Title, Number of Units, and Quarter for that line.

A couple of things you need to think about:

1. How are you going to read in `courses.csv`? Muahahaha, perhaps a
   stream 😏?
2. How will you get each line in the file?

### Hints

1. Take a look at the `split` function we provide in `utils.cpp`. It may come in handy! \* Feel free to check out the implementation of `split` and ask us any questions about it – you
   should be able to reason about it since it’s using a `stringstream`.
2. Each **line** is a record! _This is important, so we're saying it again :>)_
3. In CSV files (and specifically in `courses.csv`), the first line is usually a row that defines the column names (a column header row). This line doesn't actually correspond to a `Course`, so you'll need to skip it somehow!

## Part 2: `write_courses_offered`

Ok. Now you have a populated `courses` vector which has all of the records
of the `courses.csv` file neatly stored in a `Course` struct! You find yourself
interested in only the courses that are offered, right? **A course is considered offered if its Quarter field is not the string `“null”`.** In this function, write out to `“student_output/courses_offered.csv”` all the courses that don’t have
`“null”` in the quarter field.

> [!IMPORTANT]  
> When writing out to the CSV file, please follow this format:
>
> ```
> <Title>,<Number of Units>,<Quarter>
> ```
>
> Note that there are **no spaces** between the commas! The autograder will not be happy if this format is not followed!
>
> Also, **make sure to write out the column header row** as the first line in the output. This is the same line you had to skip in `courses.csv` for the previous step!

Once `write_courses_offered` has been called, we expect that all of the offered courses (and consequently all the courses you wrote to the output file) will be removed from the `all_courses` vector. **This means that after this
function runs, `all_courses` should ONLY contain courses that are
not offered!**

One way to do this is to keep track of the courses that are offered perhaps with another vector and delete them from `all_courses`. Just like in Python and many other languages, it is a bad idea to remove elements from a data structure while you are iterating over it, so you'll probably want to do this _after_ you have written all offered courses to file.

## Part 3: `write_courses_not_offered`

So you’re curious about courses that aren’t offered... In the
`write_courses_not_offered` function, write out to
`“student_output/courses_not_offered.csv”` the courses in
`unlisted_courses`. Remember since you deleted the courses that are
offered in the previous step, `unlisted_courses` trivially contains ONLY courses that are not offered – lucky you. So this step should look really similar to Part 2 except shorter and a _tiny_ bit simpler.

## 🚀 Submission Instructions

After compiling and running, if your autograder looks like this:

![An image showing a terminal window where the autograder has run with all tests passing](docs/autograder.png)

then you have finished the assignment! Woot woot.

To submit the assignment:

1. Please complete the feedback form [at this link](https://forms.gle/UeD6zjmUpFbhGgw98).
2. Submit your assignment on [Paperless](https://paperless.stanford.edu)!

Your deliverable should be:

# 作业 1：SimpleEnroll

截止：10 月 17 日，星期五，晚上 11:59

## 概述

学期又到了；是时候使用 SimpleEnroll 🤗 了。在斯坦福的学习生涯中，大家都会遇到必须毕业的时刻——选课变成了一件既要为毕业积累学分（XP），又要尽量保证睡眠的策略性工作。

在这个相对简短的作业中，我们将使用 ExploreCourses API 的数据来判断哪些计算机科学（CS）课程在今年有开设，哪些没有！我们会利用流（streams），并练习 C++ 中的初始化与引用。让我们开始 ʕ•́ᴥ•̀ʔ っ

只有两个你需要关注的文件：

- `main.cpp`：你需要在这里编写所有代码 😀！
- `utils.cpp`：包含一些实用工具函数。你会使用这里的函数，但通常不需要修改它。

## 运行你的代码

要运行代码，首先需要编译。打开终端（如果你使用 VSCode，按 <kbd>Ctrl+`</kbd> 或在顶部菜单选择 **Terminal > New Terminal**）。然后确保当前目录是 `assignment1/`，运行：

```sh
g++ -std=c++20 main.cpp -o main
```

如果代码能成功编译（没有编译错误），你可以运行：

```sh
./main
```

这会执行 `main.cpp` 中的 `main` 函数。程序执行结束后会运行一个自动评分器（autograder）来检查你的输出是否正确。

在实现过程中，我们建议你间歇性地编译并运行 autograder 来确认实现方向是否正确。

> 注意（NOTE）
>
> ### Windows 使用说明
>
> 在 Windows 上，你可能需要使用下面的命令来编译以便能看到输出：
>
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp -o main
> ```
>
> 可执行文件可能为 `main.exe`，这时请用：
>
> ```sh
> ./main.exe
> ```

## 第 0 部分：阅读代码并填写 `Course` 结构体

1. 在本作业中，我们使用 `Course` 结构体来表示从 ExploreCourses 获取到的课程记录。查看 `main.cpp` 中不完整的 `Course` 结构体定义并填写字段类型。最终我们会使用流（streams）来生成 `Course` —— 记住流可以处理哪些类型吗？

2. 查看 `main.cpp` 中的 `main` 函数，注意 `courses` 是如何被传入 `parse_csv`、`write_courses_offered` 和 `write_courses_not_offered` 的。想想这些函数的行为。你需要修改函数的签名吗？提示：需要。

## 第 1 部分：`parse_csv`

查看 `courses.csv`，它是一个包含三列的 CSV 文件：Title（课程名）、Number of Units（学分数）和 Quarter（学期）。实现 `parse_csv`，对 csv 文件中的每一行创建一个 `Course` 结构体，包含该行的 Title、Number of Units 和 Quarter。

需要考虑的点：

1. 你将如何读取 `courses.csv`？也许使用流（stream）？
2. 如何按行读取文件？

### 提示

1. 查看我们在 `utils.cpp` 中提供的 `split` 函数，它可能会很有用！
   - 你可以查看 `split` 的实现并提问 —— 它使用 `stringstream`，应该好理解。
2. 每一行代表一条记录！_这一点很重要，我们再次强调 :>_
3. 在 CSV 文件（尤其是 `courses.csv`）中，第一行通常是列名（表头），这一行不对应任何 `Course`，因此需要跳过它。

## 第 2 部分：`write_courses_offered`

现在你已经有了一个填充好的 `courses` 向量，里面包含了 `courses.csv` 的所有记录！你现在只对那些已开课的课程感兴趣。**当课程的 Quarter 字段不是字符串 `"null"` 时，说明该课程已开课。** 在此函数中，把所有 Quarter 不是 `"null"` 的课程写入 `student_output/courses_offered.csv`。

> 重要（IMPORTANT）
> 写 CSV 时请遵循下面的格式：
>
> ```
> <Title>,<Number of Units>,<Quarter>
> ```
>
> 注意逗号两边**不要有空格**！autograder 对格式非常严格。
>
> 另外，**请确保在输出文件的第一行写入列头（表头）**，这与在 `parse_csv` 中跳过的表头相同。

在 `write_courses_offered` 执行之后，我们期望所有已开课的课程都从 `all_courses` 向量中删除。也就是说，执行完该函数后 `all_courses` 应只包含未开课的课程！

一种做法是先记录所有已开课的课程（例如放入另一个向量），写完文件后再从 `all_courses` 中删除它们。像很多语言一样，在遍历时直接从容器中删除元素是不安全的，因此你应当在写完后再删除。

## 第 3 部分：`write_courses_not_offered`

接下来你需要处理未开课的课程…… 在 `write_courses_not_offered` 中，把 `unlisted_courses` 写入 `student_output/courses_not_offered.csv`。

因为在上一步你已经从 `all_courses` 中删除了已开课课程，传入该函数的 `unlisted_courses` 理论上只包含未开课课程——很幸运。因此这一步与第 2 部分非常相似，但更短一些和更简单一些。

## 🚀 提交说明

编译并运行后，如果 autograder 显示所有测试通过（如下图），则说明你完成了作业！

（此处为 autograder 通过的终端截图说明）

提交步骤：

1. 请填写反馈表单（链接）：https://forms.gle/UeD6zjmUpFbhGgw98
2. 在 Paperless 上提交你的作业（链接）：https://paperless.stanford.edu

你的交付物应包括：

- `main.cpp`
