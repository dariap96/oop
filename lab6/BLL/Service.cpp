using namespace std;
#include <list>
#include "IService.h"
#include "Stuff.h"
#include "Task.h"
#include "Task_Control_System.h"
#include "/Users/dariapomazan/CLionProjects/oop6_DAL/TaskRepository.cpp"
#include "/Users/dariapomazan/CLionProjects/oop6_DAL/StuffRepository.cpp"
#include "/Users/dariapomazan/CLionProjects/oop6_DAL/Task_Control_System_Repository.cpp"
class Service {
public:

    ITaskRepository TaskRepo;
    IEmployeeRepository EmployeeRepo;
    Task_Control_System_Repository TCSRepo;
    Service(ITaskRepository repo1, IEmployeeRepository repo2, Task_Control_System_Repository repo3) {
       TaskRepo=repo1;
       EmployeeRepo=repo2;
       TCSRepo=repo3;
    };
        Service(){

        };
         class Employee_Service: public IService<IEmployee> {
        list <IEmployee> all_employees;
        Task_Control_System_Repository TCSR;

        list<IEmployee> get_all() override {
            return all_employees;
        };

        IEmployee get(int id1) override {
            for (auto i: all_employees) {
                if (i.id == id1)
                    return i;
            }
        };

        void Createid(IEmployee e) override {
            e.id = all_employees.size();
            all_employees.push_back(e);
        };

        void Delete(IEmployee e) override {
            all_employees.remove(e);
        };
    };
    class TaskService: public  IService<Task>, public Task_Control_System_Repository{
    public:
        TaskService(){};
        ITaskRepository TaskRepo;
        list<Task> get_all() override {
            return all_tasks;
        };

        Task get(int id1) override {
            for (auto i: all_tasks) {
                if (i.id == id1)
                    return i;
            }
        };

        void Createid(Task t) override {

            t.id = all_tasks.size();
            all_tasks.push_back(t);
        };

        void Delete(Task t) override {
            all_tasks.remove(t);
        };
    };
    Employee_Service ES;
    TaskService TS;
    class Task_Control_System_Service: public Task_Control_System_Repository,public IEmployee {
    public:
        Task_Control_System_Repository TCSRepo;
        Task get(int id1) {
            for (auto i: all_tasks) {
                if (i.id == id1)
                    return i;
            }
        };
        Task get_by_time_created(int s, int m) {
            for (auto i: all_tasks) {
                if (i.time_created == s*60+m)
                    return i;
            }
        };
        Task get_by_time_changed(int s, int m) {
            for (auto i: all_tasks) {
                if (i.last_time_changed == s*60+m)
                    return i;
            }
        }

        Task employee_tasks(int id1) {
            for (auto i: all_tasks) {
                if (i.id == id1)
                    return i;
            }
        }
        Task create_task(Task t) {

            all_tasks.push_back(t);
            t.TransitionTo(new Open);
            return t;
        }
        Task change_task(Task t,string d) {
            t.description = d;
            t.TransitionTo(new Active);
        }
        Task comment(Task t, string c) {
            t.comment += " " + c;
        }
        Task change_employee(Task t, int id) {
            t.employee_id = id;
        }
        Task show_tasks(IEmployee e) {
            for (auto i: e.my_tasks) {
                return i;
            }
        }
        list<Task> changed_by_this_employee(IEmployee e) {
            return e.changed;
        }

    };
    Task_Control_System_Service TCSS;



};
