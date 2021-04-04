#include <string>

#include <map>

using namespace std;
class Task;
#include <map>
using namespace std;

class Report {
public:
    map<Task, string> report;
};

class IState: public Report   {
protected:
    Task *task{};
public:
    void set_context(Task *t) {
        task=t;
    }
    virtual void Handle()= 0;

};

class Open: public IState{
public:
    void Handle() override {
        pair p=make_pair(&task,"open");
        report.emplace(p);
    }

};
class Active: public IState {
public:
    void Handle() override {
        pair p=make_pair(&task,"changed");
        report.emplace(p);
    }

};
class Resolved: public IState {
public:
    void Handle() override {
        pair p=make_pair(&task,"finished");
        report.emplace(p);
    }
};

class Task {
private: IState *state;
public:
    map <Task,string> changes;
    string name;
    string description;
    int id;
    string comment;
    int employee_id;
    int last_time_changed;
    int time_created;
    Task(string n, string d){
        this->name = n;
        description = d;
    }

    Task() {}

    void TransitionTo(IState *state1) {
        if (this->state!=nullptr)
            delete this->state;
        this->state = state1;
        this->state->set_context(this);
    }
    void Request1() {
        this->state->Handle();
    }

};




