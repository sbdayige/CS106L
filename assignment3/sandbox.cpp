/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include<iostream>
#include "class.h"

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  // 学生任务：构造你的类的一个实例！
  
  // 示例：构造 CoffeeCup 的实例（带默认构造和带参构造）
  // 这里演示如何使用我们实现的类。你可以替换为自己的类实现或扩展功能。
  
  // 包含头文件放在函数体外的源文件顶部（main.cpp 已包含 sandbox.cpp），
  // 但为了保证可读性，在这里显式包含声明文件。

  CoffeeCup defaultCup; // 默认构造
  CoffeeCup myCup("Alice", 250.0, true); // 带参构造：250ml 热饮

  // 演示 getter/setter
  std::cout << "Default cup owner: " << defaultCup.getOwner() << "\n";
  std::cout << "My cup owner: " << myCup.getOwner() << ", volume=" << myCup.getVolume() << "ml\n";

  myCup.pour(50.0);
  std::cout << "After pouring 50ml, volume=" << myCup.getVolume() << "ml\n";
}