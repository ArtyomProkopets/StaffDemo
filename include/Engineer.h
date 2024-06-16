#pragma once
#ifndef STAFFDEMO_INCLUDE_ENGINEER_H_
#define STAFFDEMO_INCLUDE_ENGINEER_H_

#include <iostream>
#include "Personal.h"
#include "Interfaces.h"

class Project;

class Engineer : public Personal, public Project_Budget {
 public:
  Engineer(int id, std::string name, int work_time, int salary, Positions position, int payment, Project *project);
  int calc_budget_part() override;
  void calc_salary(int bonus) override;
  void print_info() override;
  virtual ~Engineer() = default;
 protected:
  Project *project;
};

class Programmer : public Engineer {
 public:
  Programmer(int id, std::string name, int work_time, int salary, Positions position, int payment, Project *project);
  void calc_salary(int bonus) override;
  int calc_pro_additions(int bonus) override;
  void print_info() override;
  ~Programmer() override = default;
};

class Tester : public Engineer {
 public:
  Tester(int id, std::string name, int work_time, int salary, Positions position, int payment, Project *project);
  void calc_salary(int bonus) override;
  int calc_pro_additions(int bugs) override;
  void print_info() override;
  ~Tester() override = default;
};

class TeamLeader : public Programmer, public Heading {
 public:
  TeamLeader(int id, std::string name, int work_time, int salary, Positions position, int payment, Project *project);
  void calc_salary(int bonus) override;
  int calc_Heads() override;
  void print_info() override;
  ~TeamLeader() override = default;
};

#endif //STAFFDEMO_INCLUDE_ENGINEER_H_