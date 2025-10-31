/*
 * CS106L 作业2：婚姻匹配 (Marriage Pact)
 * 由 Haven Whitney 创建，Fabio Ibanez & Jacob Roberts-Baca 修改。
 *
 * 欢迎来到 CS106L 的第2次作业！请完成此文件中的每个 STUDENT TODO。
 * 你不需要修改其他文件。
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <random>
#include <unordered_set>

std::string kYourName = "Shenshen Guo"; // 别忘了把这里改成你的名字！

/**
 * 接受一个文件名，返回一个包含所有申请者姓名的集合。
 *
 * @param filename  要读取的文件名。
 *                  文件的每一行都是一个申请者的姓名。
 * @returns         从文件中读取的所有申请者姓名的集合。
 *
 * @remark 你可以将此函数（以及下面的函数）的返回类型改为 `std::unordered_set`。
 *         如果这样做，请同时修改 `utils.h` 中对应的函数。
 */
std::set<std::string> get_applicants(std::string filename) {
  std::ifstream infile(filename);
  std::set<std::string> st;
  if (!infile.is_open()) {
    std::cerr << "Error: could not open file '" << filename << "' for reading." << std::endl;
    return st;
  }
  std::string line;
  while (std::getline(infile, line)) {  
    st.insert(line);
  }
  return st;
}

/**
 * 从给定的学生姓名集合中，找到与指定姓名匹配（首字母相同）的名字，并返回一个指针队列。
 *
 * @param name      返回的名字队列应该与此姓名具有相同的首字母。
 * @param students  学生姓名的集合（按引用传入）。
 * @return          包含指向每个匹配姓名的指针的 `std::queue`。
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // 遍历集合时不要按值复制元素（那样 &it 会指向局部临时对象，返回后变为悬空指针）。
  std::queue<const std::string*> q;
  if (name.empty()) return q;
  char initial = name[0];
  for (const std::string& s : students) {
    if (!s.empty() && s[0] == initial) {
      // 取集合中元素的地址是安全的（只要集合仍然存在且元素未被 erase）。
      q.push(&s);
    }
  }
  return q;
}

/**
 * 接受一个指向可能匹配项的指针队列，并确定唯一的最佳匹配！
 *
 * 你可以以任何方式实现此函数，但尽量不要只是简单地调用 `pop()`，尝试实现稍复杂一点的选择逻辑。
 *
 * @param matches 可能匹配的队列。
 * @return        你“神奇的唯一真爱”的姓名。
 *                如果 `matches` 为空，将返回 "NO MATCHES FOUND."。
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // 如果没有候选则返回提示
  if (matches.empty()) return "NO MATCHES FOUND.";

  // 将队列中的指针收集到向量中（同时清空队列）。
  std::vector<const std::string*> candidates;
  while (!matches.empty()) {
    const std::string* p = matches.front();
    matches.pop();
    if (p != nullptr) candidates.push_back(p);
  }

  if (candidates.empty()) return "NO MATCHES FOUND.";

  // 随机选择一个候选（使用随机设备 + mt19937）。
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<std::size_t> dist(0, candidates.size() - 1);
  std::size_t idx = dist(gen);

  // 返回被选中名字的拷贝（返回类型是 std::string）。
  return *candidates[idx];
}

#if 1
/* #### Please don't remove this line! #### */
/* #### 请不要删除此行！（为兼容自动评分，保留原始英文标记） #### */
#endif
#include "autograder/utils.hpp"
