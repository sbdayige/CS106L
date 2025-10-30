/*
 * CS106L 作业 1：SimpleEnroll
 * 作者：Fabio Ibanez，Jacob Roberts-Baca 修改
 *
 * 欢迎来到 CS106L 的第 1 个作业！请在本文件中完成所有标记为 STUDENT TODO 的部分。
 * 你通常不需要修改其他文件。
 *
 * 学生需要实现的函数：parse_csv、write_courses_offered、
 * write_courses_not_offered
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

const std::string COURSES_OFFERED_PATH = "student_output/courses_offered.csv";
const std::string COURSES_NOT_OFFERED_PATH = "student_output/courses_not_offered.csv";
/**
 * 表示学生可以在 ExploreCourses 上选的课程。
 * 请在此 struct 中填写字段的类型。
 * 提示：记住 C++ 流（streams）能处理的类型吗？
 */
struct Course {
  /* 课程标题 */ std::string title;
  /* 学分（作为字符串，便于与 utils.cpp 中的静态断言兼容） */ std::string number_of_units;
  /* 学期（如果没有开课则为字符串 "null"） */ std::string quarter;
};

/**
 * 注意：
 * 我们需要在声明 `Course` 结构体之后再 `#include "utils.cpp"`，
 * 这样 utils.cpp 中的代码才能知道 `Course` 的定义。
 * 记住，`#include` 会直接把文件内容插入到当前位置。
 */
#include "utils.cpp"

/**
 * 该函数应当用 `Course` 结构体填充 `courses` 向量。
 * 我们希望根据 `courses.csv` 中的每一行记录创建对应的 `Course` 实例。
 *
 * 提示：
 * 1) 查看我们在 utils.cpp 中提供的 split 函数。
 * 2) 每一行（LINE）对应一条记录！这一点非常重要。
 * 3) CSV 的第一行通常是列名（表头），需要跳过。
 *
 * @param filename 要解析的文件名。
 * @param courses  用于填充的课程向量。
 */
void parse_csv(std::string filename, std::vector<Course>& courses) {
  std::ifstream infile(filename);
  if (!infile.is_open()) {
    std::cerr << "Error: could not open file '" << filename << "' for reading." << std::endl;
    return;
  }

  auto trim = [](std::string s) {
    // 去掉两端空白、引号和回车
    while (!s.empty() && (s.back() == '\r' || s.back() == '\n' || s.back() == ' ' || s.back() == '\t' || s.back() == '"'))
      s.pop_back();
    size_t i = 0;
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t' || s[i] == '"'))
      ++i;
    return s.substr(i);
  };

  std::string line;
  // 读取并丢弃表头行
  if (!std::getline(infile, line)) {
    return;
  }

  while (std::getline(infile, line)) {
    if (line.empty()) continue;
    std::vector<std::string> parts = split(line, ',');

    // 更稳健的解析：quarter 是最后一列，units 是倒数第二列，title 为剩余部分（可能包含逗号）
    if (parts.size() < 2) continue; // 格式不对，跳过

    std::string quarter = trim(parts.back());
    parts.pop_back();
    std::string units = trim(parts.back());
    parts.pop_back();

    // 剩下的部分拼接为 title（注意原 CSV 中标题如果包含逗号已经被拆分）
    std::string title;
    for (size_t i = 0; i < parts.size(); ++i) {
      if (i) title += ",";
      title += parts[i];
    }
    title = trim(title);

    courses.push_back({title, units, quarter});
  }
}

/**
 * 该函数有两个要求：
 *
 * 1) 将已开课的课程写入文件：
 *    "student_output/courses_offered.csv"
 *
 * 2) 从 `all_courses` 向量中删除已开课的课程。
 *    注意：请在写入文件之后再进行删除操作！
 *
 * 提示：
 * 1) 记录需要删除的课程。
 * 2) 使用我们提供的 delete_elem_from_vector 函数来删除元素。
 * 3) 记得在输出文件开头写入 CSV 的表头（参见 courses.csv）。
 *
 * @param all_courses 由 parse_csv 填充的所有课程向量；该向量将在函数中被修改，删除所有已开课的课程。
 */
void write_courses_offered(std::vector<Course>& all_courses) {
  std::ofstream outfile(COURSES_OFFERED_PATH);
  if (!outfile.is_open()) {
    std::cerr << "Error: could not open file '" << COURSES_OFFERED_PATH << "' for writing." << std::endl;
    return;
  }

  // 写入表头
  outfile << "Title,Number of Units,Quarter\n";

  // 收集已开课课程，先写出文件，再从 all_courses 中删除
  std::vector<Course> offered;
  for (const Course& c : all_courses) {
    if (c.quarter != "null") {
      outfile << c.title << "," << c.number_of_units << "," << c.quarter << "\n";
      
      offered.push_back(c);
    }
  }

  // 从 all_courses 中删除已开课课程（在写入之后进行）
  for (const Course& c : offered) {
    delete_elem_from_vector(all_courses, c);
  }
}

/**
 * 将未开课的课程写入文件：
 * "student_output/courses_not_offered.csv"
 *
 * 该函数总是在 `write_courses_offered` 之后调用。
 * 由于上一步已经从 all_courses 中删除了已开课课程，传入的 `unlisted_courses`
 * 理应只包含未开课的课程。
 *
 * 提示：此函数与 `write_courses_offered` 非常相似。
 *
 * @param unlisted_courses 未开课课程的向量。
 */
void write_courses_not_offered(std::vector<Course>& unlisted_courses) {
  std::ofstream outfile(COURSES_NOT_OFFERED_PATH);
  if (!outfile.is_open()) {
    std::cerr << "Error: could not open file '" << COURSES_NOT_OFFERED_PATH << "' for writing." << std::endl;
    return;
  }

  // 写入表头
  outfile << "Title,Number of Units,Quarter\n";

  // 此时 unlisted_courses 应只包含未开课的课程
  for (const Course& c : unlisted_courses) {
    if (c.quarter == "null") {
      outfile << c.title << "," << c.number_of_units << "," << c.quarter << "\n";
    }
  }
}

int main() {
  /* 确保你已经正确定义了 Course 结构体！ */
  static_assert(is_valid_course<Course>, "Course struct is not correctly defined!");

  std::vector<Course> courses;
  parse_csv("courses.csv", courses);

  /* 调试时可取消注释： */
  // print_courses(courses);

  write_courses_offered(courses);
  write_courses_not_offered(courses);

  return run_autograder();
}