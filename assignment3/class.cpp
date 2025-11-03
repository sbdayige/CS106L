/*
 * CS106L Assignment 3: Make a Class
 * Implementation for CoffeeCup
 */

#include "class.h"
#include <algorithm>
#include <cctype>

// Default constructor: empty owner, 0 ml, not hot
CoffeeCup::CoffeeCup() : owner_(""), volume_ml_(0.0), is_hot_(false) {}

// Custom constructor
CoffeeCup::CoffeeCup(const std::string& owner, double volume_ml, bool is_hot)
    : owner_(owner), volume_ml_(volume_ml), is_hot_(is_hot) {
  normalizeOwner();
  clampVolume();
}

// Destructor: nothing special to clean up for this simple class,
// implemented explicitly for the assignment requirement.
CoffeeCup::~CoffeeCup() {}

// Getters
std::string CoffeeCup::getOwner() const { return owner_; }
double CoffeeCup::getVolume() const { return volume_ml_; }
bool CoffeeCup::isHot() const { return is_hot_; }

// Setters
void CoffeeCup::setOwner(const std::string& owner) {
  owner_ = owner;
  normalizeOwner();
}

void CoffeeCup::setVolume(double volume_ml) {
  volume_ml_ = volume_ml;
  clampVolume();
}

void CoffeeCup::setHot(bool hot) { is_hot_ = hot; }

// Pour: subtract amount (if available), clamp non-negative
void CoffeeCup::pour(double amount_ml) {
  if (amount_ml < 0) return; // ignore negative pours
  volume_ml_ -= amount_ml;
  clampVolume();
}

// Private helper: ensure owner is non-empty; trim simple whitespace and
// set to "Unknown" if empty.
void CoffeeCup::normalizeOwner() {
  // trim leading/trailing spaces (simple)
  auto l = owner_.find_first_not_of(' ');
  auto r = owner_.find_last_not_of(' ');
  if (l == std::string::npos) {
    owner_.clear();
  } else {
    owner_ = owner_.substr(l, r - l + 1);
  }

  if (owner_.empty()) owner_ = "Unknown";
}

// Private helper: ensure volume is within reasonable bounds [0, 10000]
void CoffeeCup::clampVolume() {
  if (volume_ml_ < 0.0) volume_ml_ = 0.0;
  if (volume_ml_ > 10000.0) volume_ml_ = 10000.0; // arbitrary upper cap
}
