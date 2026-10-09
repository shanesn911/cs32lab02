#include "student.h"
#include <string>
#include <cstring>

Student::Student(const char * const name, int perm) {
  this->name = nullptr;          // setName deletes the old name, so start clean
  this->setName(name);
  this->setPerm(perm);
}

int Student::getPerm() const {
  return perm;
}

const char * const Student::getName() const {
  return name;
}

void Student::setPerm(const int permNumber) {
  perm = permNumber;
}

void Student::setName(const char * const newName) {
  // allocate and copy first, so s.setName(s.getName()) is safe
  char *copy = new char[strlen(newName) + 1];
  strcpy(copy, newName);
  delete [] this->name;          // deleting nullptr is fine
  this->name = copy;
}

Student::Student(const Student &orig) {
  this->name = nullptr;
  this->setName(orig.name);
  this->setPerm(orig.perm);
}

Student::~Student() {
  delete [] name;
}

Student & Student::operator=(const Student &right) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  this->setName(right.name);     // frees old name, deep-copies new one
  this->setPerm(right.perm);

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 

}

std::string Student::toString() const {
  return "[" + std::string(name) + "," + std::to_string(perm) + "]";
}