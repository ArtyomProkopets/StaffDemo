#include "Employee.h"

Employee::Employee(int id, std::string name, int work_time, Positions position, int payment)
    : id(id), name(std::move(name)), work_time(work_time), position(position), payment(payment) {}

void Employee::SetWorkTime(int hours) {
  work_time = hours;
}

int Employee::get_id() const {
  return id;
}
int Employee::get_payment() const {
  return payment;
}