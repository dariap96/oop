#include "Task_Control_System.h"
#include"/Users/dariapomazan/CLionProjects/oop6_DAL/Task_Control_System_Repository.cpp"
#include "Task.h"
#include "Stuff.h"
#include <list>

class Task_Control_System_Service: public Task_Control_System_Repository,public IEmployee {
public:
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

    list <Task> employee_tasks(int id1) {
        for (auto i: all_tasks) {
            if (i.id == id1)
                return i;
        }
    }
    Task create_task(string n,string d) {
        Task t=Task(n,d);
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
    Task change_employee(Task t, IEmployee e) {
        t.employee_id = e.id;
    }
    Task show_tasks(IEmployee e) {
        for (auto i: e.my_tasks) {
            return i;
        }
    }
    list<Task> changed_by_this_employee(IEmployee e) {
        return e.changed;
    }
//    list<Task> employees_tasks(Leader_e e) {
//       // Report j;
//        for (auto i: e.Employees)  {
//            for (auto  j: i->my_tasks ) {
//
//            e.e_reports.push_back(j); }
//        }
//    }

};
