#include "Engineer.h"
#include "Project.h"

Engineer::Engineer(int id,
                   std::string name,
                   int work_time,
                   int salary,
                   Positions position,
                   int payment,
                   Project *project)
    : Personal(id, std::move(name), work_time, salary, position, payment), project(project) {}

int Engineer::calc_budget_part() {
  return project->get_budget() * 0.1;
}

void Engineer::calc_salary(int bonus) {
  payment = calc_base_salary(salary, work_time) + calc_bonus_salary(bonus);
}

void Engineer::print_info() {
  std::cout << "Engineer Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Project ID: " << project->get_id() << ", Budget: " << project->get_budget() << std::endl;
}

Programmer::Programmer(int id,
                       std::string name,
                       int work_time,
                       int salary,
                       Positions position,
                       int payment,
                       Project *project)
    : Engineer(id, std::move(name), work_time, salary, position, payment, project) {
  this->position = programmer;
  project->set_number_of_employee(project->get_number_of_employee() + 1);
}

int Programmer::calc_pro_additions(int bonus) {
  return bonus * 1000;
}

void Programmer::calc_salary(int bonus) {
  payment = calc_base_salary(salary, work_time) + calc_pro_additions(bonus) + calc_budget_part();
}

void Programmer::print_info() {
  std::cout << "Programmer Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Project ID: " << project->get_id() << ", Budget: " << project->get_budget() << std::endl;
}

Tester::Tester(int id, std::string name, int work_time, int salary, Positions position, int payment, Project *project)
    : Engineer(id, std::move(name), work_time, salary, position, payment, project) {
  this->position = tester;
  project->set_number_of_employee(project->get_number_of_employee() + 1);
}

int Tester::calc_pro_additions(int bugs) {
  return bugs * 10;
}

void Tester::calc_salary(int bugs) {
  payment = calc_base_salary(salary, work_time) + calc_pro_additions(bugs) + calc_budget_part();
}

void Tester::print_info() {
  std::cout << "Tester Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Project ID: " << project->get_id() << ", Budget: " << project->get_budget() << std::endl;
}

TeamLeader::TeamLeader(int id,
                       std::string name,
                       int work_time,
                       int salary,
                       Positions position,
                       int payment,
                       Project *project)
    : Programmer(id, std::move(name), work_time, salary, position, payment, project) {
  this->position = team_leader;
  project->set_number_of_employee(project->get_number_of_employee() + 1);
}

int TeamLeader::calc_Heads() {
  return salary * 100;
}

void TeamLeader::calc_salary(int bonus) {
  payment = calc_base_salary(salary, work_time) + calc_budget_part() + calc_Heads();
}

void TeamLeader::print_info() {
  std::cout << "Team Leader Info:" << std::endl;
  std::cout << "ID: " << Employee::get_id() << std::endl;
  std::cout << "Name: " << name << std::endl;
  std::cout << "Work Time: " << work_time << std::endl;
  std::cout << "Position: " << enum_print[position] << std::endl;
  std::cout << "Project ID: " << project->get_id() << ", Budget: " << project->get_budget() << std::endl;
}