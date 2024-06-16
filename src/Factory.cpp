#include "Factory.h"
#include <fstream>
#include <sstream>
#include "Engineer.h"
#include "Project.h"
#include <cstdlib>
#include <ctime>
Factory::Factory(const std::string &filename) {
  loadFromFile(filename);
}

std::vector<Employee *> Factory::getEmployees() {
  return employees;
}

std::vector<Project *> Factory::getProjects() {
  return projects;
}

void Factory::loadFromFile(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::string type;
    std::getline(ss, type, ':');

    if (type == "project") {
      int id;
      int budget;

      ss >> id;
      ss.ignore(1, ':');
      ss >> budget;

      projects.push_back(new Project(id, budget, 0));
    } else if (type == "employee") {
      std::string position, name;
      int id, salary;

      std::getline(ss, position, ':');
      ss >> id;
      ss.ignore(1, ':');
      std::getline(ss, name, ':');
      ss >> salary;

      if (position == "driver") {
        employees.push_back(new Driver(id, name, 0, salary, driver, 0));
      } else if (position == "cleaner") {
        employees.push_back(new Cleaner(id, name, 0, salary, cleaner, 0));
      } else {
        int projectId;
        ss.ignore(1, ':');
        ss >> projectId;
        for (auto &proj : projects) {
          if (proj->get_id() == projectId) {
            if (position == "tester") {
              employees.push_back(new Tester(id, name, 0, salary, tester, 0, proj));
            } else if (position == "programmer") {
              employees.push_back(new Programmer(id, name, 0, salary, programmer, 0, proj));
            } else if (position == "team_leader") {
              employees.push_back(new TeamLeader(id, name, 0, salary, team_leader, 0, proj));
            } else if (position == "project_manager") {
              std::vector<Project *> managerProjects = {proj};
              employees.push_back(new ProjectManager(id, name, 0, project_manager, managerProjects));
            } else if (position == "senior_manager") {
              std::vector<Project *> seniorProjects{proj};
              ss.ignore(1, ':');
              std::string projectIdStr;
              while (std::getline(ss, projectIdStr, ':')) {  // Разделяем строку на отдельные id проектов
                int seniorProjectId = std::stoi(projectIdStr);
                for (auto &proj : projects) {
                  if (proj->get_id() == seniorProjectId) {
                    seniorProjects.push_back(proj);
                  }
                }
              }
              employees.push_back(new SeniorManager(id, name, 0, senior_manager, seniorProjects));
            }
            break;
          }
        }
      }
    }
  }
}

void Factory::assignRandomWorkTime() {
  srand(time(0));
  for (auto &employee : employees) {
    int randomWorkTime = 35 + rand() % 16;  // Часы работы от 35 до 50
    employee->SetWorkTime(randomWorkTime);
  }
}

void Factory::calculatePayments() {
  for (auto &employee : employees) {
    employee->calc_salary(rand() % 20);  // случайный бонус для каждого от 0 до 19
  }
}