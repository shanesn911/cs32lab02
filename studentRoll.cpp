#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node *n = new Node;
  n->s = new Student(s);         // deep copy via Student's copy constructor
  n->next = NULL;
  if (tail == NULL) {
    head = tail = n;
  } else {
    tail->next = n;
    tail = n;
  }
}

std::string StudentRoll::toString() const {
  std::string result = "[";
  for (Node *p = head; p != NULL; p = p->next) {
    result += p->s->toString();
    if (p->next != NULL)
      result += ",";
  }
  result += "]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {
  head = tail = NULL;
  for (Node *p = orig.head; p != NULL; p = p->next)
    insertAtTail(*(p->s));
}

StudentRoll::~StudentRoll() {
  while (head != NULL) {
    Node *next = head->next;
    delete head->s;
    delete head;
    head = next;
  }
  tail = NULL;
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);

  // free the current list
  while (head != NULL) {
    Node *next = head->next;
    delete head->s;
    delete head;
    head = next;
  }
  tail = NULL;

  // deep copy the other list
  for (Node *p = right.head; p != NULL; p = p->next)
    insertAtTail(*(p->s));

  // KEEP THE CODE BELOW THIS LINE
  // Overloaded = should end with this line, despite what the textbook says.
  return (*this); 
  
}