#pragma once
#ifndef STAFFDEMO_INCLUDE_FACTORY_H_
#define STAFFDEMO_INCLUDE_FACTORY_H_
#include <vector>
#include <string>
#include "Employee.h"
#include "Project.h"
#include "Personal.h"

class Factory {
 public:
  Factory(const std::string &filename);
  std::vector<Employee *> getEmployees();
  std::vector<Project *> getProjects();
  void assignRandomWorkTime();
  void calculatePayments();

 private:
  std::vector<Employee *> employees;
  std::vector<Project *> projects;
  void loadFromFile(const std::string &filename);
};
#endif //STAFFDEMO_INCLUDE_FACTORY_H_// Copyright 2024 HSE NN
// Author: Lev Pestov

#pragma once
#ifndef STAFFDEMO_INCLUDE_FACTORY_H_
#define STAFFDEMO_INCLUDE_FACTORY_H_
#include <vector>
#include <string>
#include "Employee.h"
#include "Project.h"
#include "Personal.h"

class Factory {
 public:
  Factory(const std::string &filename);
  std::vector<Employee *> getEmployees();
  std::vector<Project *> getProjects();
  void assignRandomWorkTime();
  void calculatePayments();

 private:
  std::vector<Employee *> employees;
  std::vector<Project *> projects;
  void loadFromFile(const std::string &filename);
};
#endif //STAFFDEMO_INCLUDE_FACTORY_H_