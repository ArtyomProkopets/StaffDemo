#pragma once
#ifndef INCLUDE_PERSONAL_H_
#define INCLUDE_PERSONAL_H_
#include <iostream>
#include <string>
#include <utility>
#include "Employee.h"
#include "Interfaces.h"

class Personal : public Employee, public Work_Base_Time {
 public:
  Personal(int id, std::string name,
           int workTime, int salary, Positions position, int payment);
  int calc_bonus_salary(int bonus) override;
  void print_info() override;
  int calc_base_salary(int salary, int work_time_salary) override;
  ~Personal() override = default;
 protected:
  int salary;
};

class Driver : public Personal {
 public:
  Driver(int id, std::string name,
         int work_time, int salary, Positions position, int payment);
  void calc_salary(int bonus) override;
  int calc_bonus_salary(int bonus) override;
  void print_info() override;
};

class Cleaner : public Personal {
 public:
  Cleaner(int id, std::string name,
          int work_time, int salary, Positions position, int payment);
  void calc_salary(int bonus) override;
  void print_info() override;
};
#endif  // INCLUDE_PERSONAL_H_