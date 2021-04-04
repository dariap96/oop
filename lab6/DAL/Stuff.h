#include <string>
#include <list>
#include <map>
#include "Task.h"
#include "Task_Control_System_Repository.cpp"
using namespace std;

class IEmployee {
protected:
    IEmployee* leader;
public:
    Task_Control_System S;
    int id;
    string name;
    string surname;
    list <Task> my_tasks;
    list <Task> changed;
    list <Report> my_reports;
//    Report one_day;
//    list <Report> sprint_report;


    void set_leader(IEmployee *l){
        this->leader=l;
    }
    IEmployee * get_leader() {
        return this->leader;
    }
    virtual void add_employe(IEmployee *s) {
    }
    virtual void remove_employe(IEmployee *s) {
    }
//    Task add_task(Task_Control_System_Repository S, string n, string d, int m, int s){
//         Task t=S.create_task(n,d);
//        t.employee_id = this->id;
//        t.last_time_changed = m*60+s;
//        t.time_created = m*60 + s;
//        my_tasks.push_back(t);
//        t.TransitionTo(new Open);
//        t.Request1();
//        return t;
//
//    }
//    Task change_task(Task_Control_System_Repository S, Task t, string d, int m, int s) {
//        Task t1 = S.change_task(t,d);
//        t.last_time_changed = m*60+s;
//        changed.push_back(t);
//        t.Request1();
//        return t;
//    }
//     Task comment_task(Task_Control_System_Repository S,Task t, string c, int m,int s) {
//     Task t1 = S.comment(t,c);
//        t.last_time_changed = m*60+s;
//        return t;
//    }
//    void finish_task(Task t) {
//        t.TransitionTo(new Resolved);
//        t.Request1();
//    }
//    void new_day() {
//       this->one_day.report.clear();
//    }
//
//
//    void day_end(){
//        my_reports.push_back(one_day);
//        sprint_report.push_back(one_day);
//    }
//    void new_sprint(){
//        my_reports.clear();
//    }
//    void sprint_end() {
//        sprint_report.merge(my_reports);
//    }
};

class Basic_e: public IEmployee{

};

class Leader_e: public IEmployee {
public: list <IEmployee*> Employees;
    list <Report> e_reports;
    list<Report> team_report;
    void add_employe(IEmployee *s) override {
     this->Employees.push_back(s);
     s->set_leader(this);
    }
    void remove_employe(IEmployee *s) override {
        this->Employees.remove(s);
        s->set_leader(nullptr);
    }
//     list<Report> sprint_report() {
//        for (auto i: this->Employees) {
//            team_report.merge(i->sprint_report);
//        }
//        return team_report;
//    }

};


