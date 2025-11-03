/*
 * CS106L Assignment 3: Make a Class
 * Example class: CoffeeCup
 */

#ifndef ASSIGNMENT3_CLASS_H
#define ASSIGNMENT3_CLASS_H

#include <string>

class CoffeeCup {
public:
  // Default constructor
  CoffeeCup();

  // Custom constructor (takes parameters)
  CoffeeCup(const std::string& owner, double volume_ml, bool is_hot);

  // Getters (const-correct)
  std::string getOwner() const;
  double getVolume() const;
  bool isHot() const;

  // Setters
  void setOwner(const std::string& owner);
  void setVolume(double volume_ml);
  void setHot(bool hot);

  // A small public action
  void pour(double amount_ml); // remove amount from cup

private:
  // Private member fields
  std::string owner_;
  double volume_ml_; // milliliters
  bool is_hot_;

  // Private helper functions (implementation details)
  void normalizeOwner();
  void clampVolume();
};

#endif // ASSIGNMENT3_CLASS_H
