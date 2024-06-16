#ifndef STAFFDEMO_INCLUDE_MANAGER_H_
#define STAFFDEMO_INCLUDE_MANAGER_H_

#include "Employee.h"
#include "Interfaces.h"
#include <vector>

class Manager : public Employee, public ProjectBudget, public Heading {
 protected:
  vector<Project*> projects;

 public:
  Manager(int id, string name, string position) : Employee(id, name, position) {}

  void addProject(Project* project) {
    projects.push_back(project);
  }

  virtual int calcBudgetPart(float part, int budget) override {
    return static_cast<int>(budget * part);
  }

  virtual int calcProAdditions() override {
    return 0;
  }

  virtual int calcHeads() override {
    return 0;
  }

  void calc() override {
    payment = 0;
    for (auto project : projects
        ) {
      payment += calcBudgetPart(0.1, project->budget) + calcProAdditions();
    }
    payment += calcHeads();
  }
};

class ProjectManager : public Manager {
 public:
  ProjectManager(int id, string name, string position) : Manager(id, name, position) {}
  int calcHeads() override {
    // Calculation based on team members
    return 1000; // example value
  }
};

class SeniorManager : public Manager {
 public:
  SeniorManager(int id, string name, string position) : Manager(id, name, position) {}
  int calcHeads() override {
    // Calculation based on multiple teams
    return 2000; // example value
  }




#endif //STAFFDEMO_INCLUDE_MANAGER_H_
