#pragma once
#ifndef INCLUDE_EMPLOYEE_H_
#define INCLUDE_EMPLOYEE_H_

#include <string>
#include <vector>

enum Positions {
  programmer,
  team_leader,
  project_manager,
  senior_manager,
  cleaner,
  driver,
  tester,
};

class Employee {
 public:
  Employee(int id, std::string name,
           int work_time, Positions position, int payment);
  virtual void calc_salary(int bonus) = 0;
  virtual void print_info() = 0;
  void SetWorkTime(int hours);
  int get_id() const;
  int get_payment() const;
  virtual ~Employee() = default;
 private:
  int id;
 protected:
  Positions position;
  int payment;
  int work_time;
  std::string name;
  std::vector<std::string> enum_print = {"programmer",
                                         "team_leader",
                                         "project_manager",
                                         "senior_manager",
                                         "cleaner",
                                         "driver",
                                         "tester"};
};

#endif  // INCLUDE_EMPLOYEE_H_