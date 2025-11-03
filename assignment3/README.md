<p align="center">
  <img src="docs/bjarne.jpg" alt="Bjarne Stroustrup writing the declaration of a class on a whiteboard" />
</p>

# Assignment 3: Make a Class

Due Saturday November 1st at 11:59PM

## Overview

<pre>
(\_/)
(•x•) <b>Howdy</b>
(<☕)
</pre>

Now that we've learned about classes, it’s time for you to make your own! Have fun with this, let the creative juices flow. Your class can represent anything, and feel free to make more than one if you'd like. There are some requirements though. As long as you meet these requirements, you’ll get credit for this assignment! 🙂

There are four files you'll work with for this assignment:

- `class.h` - This is the header file for your class, where the class **declaration** will go.
- `class.cpp` - This is the `.cpp` file for your class, where the class **definition** will go.
- `sandbox.cpp` - You'll construct an instance of your class here.
- `short_answer.txt` - You'll answer a few short answer questions here.

To download the starter code for this assignment, please see the instructions for [**Getting Started**](../README.md#getting-started) on the course assignments repository.

## Running your code

To run your code, first you'll need to compile it. Open up a terminal (if you are using VSCode, hit <kbd>Ctrl+\`</kbd> or go to **Terminal > New Terminal** at the top). Then make sure that you are in the `assignment3/` directory and run:

```sh
g++ -std=c++20 main.cpp class.cpp -o main
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
> g++ -static-libstdc++ -std=c++20 main.cpp class.cpp -o main
> ```
>
> in order to see output. Also, the output executable may be called `main.exe`, in which case you'll run your code with:
>
> ```sh
> ./main.exe
> ```

## Part 1: Making your class

Let your creative juices flow! Fill in `class.h` and `class.cpp` to create your own custom class. Please refer to the relevant slides from Tuesday's lecture on classes for more information. Your class can represent pretty much anything you want, as long as it meets the following requirements.

> [!IMPORTANT]
>
> ### Class Requirements
>
> Your class must:
>
> 1. Have a custom constructor taking **one or more** parameters.
> 2. Have a default (parameterless) constructor (i.e. constructor overloading).
> 3. Have one or more private member fields (i.e. variables).
> 4. Have one or more private member functions.
>    - Remember, private functions are like what happens underneath the hood of your car! They are a necessary part of the implementation of a class, but shouldn't be exposed in the public interface. Try to think of a private member function that logically makes sense in the context of your class.
> 5. Have **at least one** public getter function for one of the private fields.
>    - E.g. if `int data` is the field, you must have a function called `get_data` or `getData` with the signature <pre lang="cpp">int getData();</pre>
>    - The getter function should also be marked `const`. Refer to Thursday's lecture on `const` correctness if you are unfamiliar!
> 6. Have at least one public setter function for one of the private fields.
>    - E.g. if `int data` is the field, you must have a function called `set_data` or `setData` with the signature <pre lang="cpp">void setData(int value);</pre>

Note that this is the bare minimum to get credit for the assignment. Please feel free to go above and beyond these requirements or create more than one class if you want extra practice!

> [!NOTE]
> For brownie points, you can choose to create a class template instead of a regular class using the `template <typename T>` notation discussed on Thursday's lecture. This is totally optional!
>
> Note that if you do decide to create a class template, you **must remove class.cpp
> from the compilation command.** For example, on Mac/Linux, the compilation
> command will be:
>
> ```sh
> g++ -std=c++20 main.cpp -o main
> ```
>
> Remember to also swap the includes so that the `.h` file includes the `.cpp`
> file at the end of the file, as discussed in Thursday's lecture.

Now that you've created your class, let's actually use it. **Inside of the `sandbox` function in `sandbox.cpp`, construct an instance of your class!** You can do so however you like (call default constructor, use uniform initialization, etc.).

To see if you did everything correctly, compile and run your code! The autograder will give you feedback on your class and check if it meets the specifications above.

## Part 2: Short answer questions

Please answer the following questions inside `short_answer.txt`. We expect about 2-3 sentences per question.

> [!IMPORTANT] > `short_answer.txt`
>
> - **Q1:** What’s const-correctness and why is it important?
> - **Q2:** Is your class const-correct? How do you know?

## 🚀 Submission Instructions

To submit the assignment:

1. Please complete the feedback form [at this link](https://forms.gle/GmhzW9NycQ44hyF86).
2. Submit your assignment on [Paperless](https://paperless.stanford.edu)!

Your deliverable should be:

- `class.h`
- `class.cpp`
- `sandbox.cpp`
- `short_answer.txt`

You may resubmit as many times as you'd like before the deadline.

## 中文翻译

<p align="center">
  <img src="docs/bjarne.jpg" alt="Bjarne Stroustrup writing the declaration of a class on a whiteboard" />
</p>

# 作业 3：创建一个类

截止时间：11 月 1 日（周六）23:59

## 概述

<pre>
(\_/)
(•x•) <b>Howdy</b>
(<☕)
</pre>

现在我们已经学习了类（classes），是时候自己动手写一个类啦！发挥你的想象力吧。你的类可以代表任何事物，也可以创建不止一个类。如果你满足下面的要求，就能得到作业分 🙂

有四个文件需要你完成：

- `class.h` - 这是类的头文件，放类的声明（declaration）。
- `class.cpp` - 这是类的实现文件，放类的定义（definition）。
- `sandbox.cpp` - 在这里构造（instantiate）你的类的一个实例。
- `short_answer.txt` - 在这里回答几个简短问题。

要获取起始代码，请参考课程作业仓库的 “Getting Started” 说明：[../README.md#getting-started](../README.md#getting-started)。

## 运行你的代码

要运行代码，先编译。打开终端（VSCode 中按 Ctrl+`或者顶部选择 Terminal > New Terminal）。确保当前目录为`assignment3/`，运行：

```sh
g++ -std=c++20 main.cpp class.cpp -o main
```

如果编译通过，可运行：

```sh
./main
```

这会执行 `main.cpp` 中的 `main` 函数。

建议在制作过程中间歇性地使用 autograder 编译测试，以确保实现满足要求。

> 注意（Windows）
>
> 在 Windows 上，可能需要使用：
>
> ```sh
> g++ -static-libstdc++ -std=c++20 main.cpp class.cpp -o main
> ```
>
> 来看到输出。可执行文件可能为 `main.exe`，此时运行：
>
> ```sh
> ./main.exe
> ```

## 第 1 部分：创建你的类

发挥创意！在 `class.h` 和 `class.cpp` 中实现自定义类。请参考课堂讲义关于类的内容。你的类可以代表任何事物，但必须满足以下要求。

> 重要：类的要求
>
> 你的类必须：
>
> 1. 有一个自定义构造函数，接受一个或多个参数。
> 2. 有一个默认（无参）构造函数（即构造函数重载）。
> 3. 包含一个或多个私有成员字段（私有变量）。
> 4. 包含一个或多个私有成员函数。
>    - 私有函数类似于汽车内部机制：是实现细节，不应暴露在公有接口上。想一想在你的类语境下哪些私有函数是合理的。
> 5. 至少有一个公有 getter，用于访问某个私有字段，并且应标记为 `const`。
> 6. 至少有一个公有 setter，用于修改某个私有字段。

这些是获得作业分数的最低要求；欢迎超额完成或创建多个类以获得更多练习。

> 额外加分（可选）
>
> 你可以选择使用类模板（`template <typename T>`）。如果使用类模板：
>
> - 编译时应移除 `class.cpp`（例如在 macOS/Linux 上编译时：
>
> ```sh
> g++ -std=c++20 main.cpp -o main
> ```
>
> - 并在 `.h` 文件末尾包含 `.cpp` 文件（如课堂上讨论的那样）。

完成类后，请在 `sandbox.cpp` 的 `sandbox` 函数中构造类的一个实例（可以使用默认或带参构造）。

编译并运行，autograder 会检查你的实现是否满足要求并返回反馈。

## 第 2 部分：简短问答

请在 `short_answer.txt` 中回答以下问题，每题约 2-3 句。

> 问题（`short_answer.txt`）：
>
> - Q1: 什么是 const-correctness，为什么它重要？
> - Q2: 你的类是否满足 const-correctness？你如何确认？

## 提交说明

提交流程：

1. 填写反馈表（链接）。
2. 在 Paperless 提交作业（链接）。

应提交的文件：

- `class.h`
- `class.cpp`
- `sandbox.cpp`
- `short_answer.txt`

截止前可多次重新提交。
