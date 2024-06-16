#pragma once
#ifndef STAFFDEMO_INCLUDE_PROJECT_H_
#define STAFFDEMO_INCLUDE_PROJECT_H_

#include "Employee.h"
#include "Interfaces.h"
#include <vector>

class Project {
 public:
  Project() = default;
  Project(int id, int budget, int number_of_employee);
  int get_budget() const;
  int get_id() const;
  void set_budget(int budget);
  int get_number_of_employee() const;
  void set_number_of_employee(int number_of_employee);
 private:
  int id;
  int budget;
  int number_of_employee;
};

class ProjectManager : public Employee, public Project_Budget, public Project, public Heading {
 public:
  ProjectManager(int id, std::string name, int workTime, Positions position, std::vector<Project *> &projects);
  int calc_budget_part() override;
  int calc_pro_additions(int bonus) override;
  void calc_salary(int bonus) override;
  void print_info() override;
  int calc_Heads() override;
  ~ProjectManager() override = default;
 private:
  std::vector<Project *> projects;
};

class SeniorManager : public ProjectManager {
 public:
  SeniorManager(int id, std::string name, int workTime, Positions position, std::vector<Project *> &projects);
  int calc_budget_part() override;
  int calc_pro_additions(int bonus) override;
  void calc_salary(int bonus) override;
  void print_info() override;
  ~SeniorManager() override = default;
 private:
  std::vector<Project *> projects;
};

#endif //STAFFDEMO_INCLUDE_PROJECT_H_