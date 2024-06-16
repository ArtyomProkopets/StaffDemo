#include <iostream>
#include "Project.h"

Project::Project(int id, int budget, int number_of_employee)
    : id(id), budget(budget), number_of_employee(number_of_employee) {}

int Project::get_budget() const {
  return budget;
}

int Project::get_id() const {
  return id;
}

void Project::set_budget(int budget) {
  this->budget = budget;
}
int Project::get_number_of_employee() const {
  return number_of_employee;
}
void Project::set_number_of_employee(int number_of_employee) {
  this->number_of_employee = number_of_employee;
}

ProjectManager::ProjectManager(int id,
                               std::string name,
                               int workTime,
                               Positions position,
                               std::vector<Project *> &projects)
    : Employee(id, std::move(name), workTime, position, 0), projects(projects) {
  this->position = project_manager;
}

int ProjectManager::calc_budget_part() {
  return int(0.3 * projects[0]->get_budget()); // у менеджера проекта всегда только один проект
}

int ProjectManager::calc_pro_additions(int bonus) {
  return bonus * 100;
}

int ProjectManager::calc_Heads() {
  return 1000 * projects[0]->get_number_of_employee();
}

void ProjectManager::calc_salary(int bonus) {
  payment = (calc_Heads() + calc_budget_part()) * 5;
}

void ProjectManager::print_info() {
  std::cout << "Project Manager Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Managed Project: " << std::endl;
  std::cout << "  Project ID: " << projects[0]->get_id() << ", Budget: " << projects[0]->get_budget() << std::endl;
}

SeniorManager::SeniorManager(int id,
                             std::string name,
                             int workTime,
                             Positions position,
                             std::vector<Project *> &projects)
    : ProjectManager(id, std::move(name), workTime, position, projects) {
  this->position = senior_manager;
  this->projects = projects;
}

int SeniorManager::calc_budget_part() {
  int total_budget = 0;
  for (const auto &project : projects) {
    total_budget += project->get_budget();
  }
  return int(0.2 * total_budget);
}

int SeniorManager::calc_pro_additions(int bonus) {
  return bonus * 20000;
}

void SeniorManager::calc_salary(int bonus) {
  for (const auto &project : projects) {
    payment += project->get_number_of_employee() * 1000;
  }
  payment += calc_budget_part();
  payment *= 5;
}

void SeniorManager::print_info() {
  std::cout << "Senior Manager Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Managed Projects: " << std::endl;
  for (const auto &project : projects) {
    std::cout << "  Project ID: " << project->get_id() << ", Budget: " << project->get_budget() << std::endl;
  }
}