#include <iostream>
#include "Engineer.h"
#include "Employee.h"
#include "Personal.h"
#include "Interfaces.h"
#include "Project.h"
#include "Factory.h"

int main() {
  // >>>>>>>>>>>>>>>TESTS<<<<<<<<<<<<<<<<<<
  Project project1(1, 10000, 0);
  Project project2(2, 20000, 0);
  Project project3(3, 30000, 0);
  Programmer programmer(2, "Programmer", 34534, 543, Positions::programmer, 0, &project1);
  Tester tester(3, "Tester", 5, 5, Positions::tester, 0, &project2);
  TeamLeader teamLeader(4, "TeamLeader", 0, 0, Positions::team_leader, 0, &project3);

  Cleaner cleaner(5, "Cleaner", 40, 1000, Positions::cleaner, 0);

  cleaner.calc_salary(9009);
  std::cout << std::endl;
  cleaner.print_info();
  std::cout << cleaner.get_payment();
  std::cout << "---------------------" << std::endl;

  Driver driver(6, "Driver", 40, 1000, Positions::driver, 0);

  driver.calc_salary(100);
  std::cout << std::endl;
  driver.print_info();
  std::cout << driver.get_payment();
  std::cout << "---------------------" << std::endl;

  programmer.calc_salary(0);
  std::cout << std::endl;
  programmer.print_info();
  std::cout << programmer.get_payment();
  std::cout << "---------------------" << std::endl;

  tester.calc_salary(0);
  std::cout << std::endl;
  tester.print_info();
  std::cout << tester.get_payment();
  std::cout << "---------------------" << std::endl;

  teamLeader.calc_salary(0);
  std::cout << std::endl;
  teamLeader.print_info();
  std::cout << teamLeader.get_payment();
  std::cout << "---------------------" << std::endl;
  std::vector<Project *> projects = {&project1, &project2, &project3};

  ProjectManager projectManager(7, "ProjectManager", 40, Positions::project_manager, projects);

  projectManager.calc_salary(100);
  std::cout << std::endl;
  projectManager.print_info();
  std::cout << projectManager.get_payment();
  std::cout << "---------------------" << std::endl;

  SeniorManager seniorManager(8, "SeniorManager", 40, Positions::senior_manager, projects);

  seniorManager.calc_salary(100);
  std::cout << std::endl;
  seniorManager.print_info();
  std::cout << seniorManager.get_payment();
  std::cout << "---------------------" << std::endl;

  // Создаем объект Factory и загружаем данные из файла
  Factory factory("C:\\Users\\Tima\\CLionProjects\\StaffDemo\\employees.txt");

  // Получаем векторы работников и проектов
  std::vector<Employee *> employees = factory.getEmployees();
  std::vector<Project *> factoryProjects = factory.getProjects(); // Переименованная переменная

  // Присваиваем случайное количество часов работы каждому работнику
  factory.assignRandomWorkTime();
  // Рассчитываем зарплату каждого работника
  factory.calculatePayments();

  // Выводим информацию о каждом проекте
  for (auto &project : factoryProjects) {
    std::cout << "Project ID: " << project->get_id() << std::endl;
    std::cout << "Project Budget: " << project->get_budget() << std::endl;
    std::cout << "-------------------------" << std::endl;
  }
  // Выводим информацию о каждом работнике
  for (auto &employee : employees) {
    employee->print_info();
    std::cout << "Payment: " << employee->get_payment() << std::endl;
    std::cout << "-------------------------" << std::endl;
  }

  return 0; // Не забываем закр
}