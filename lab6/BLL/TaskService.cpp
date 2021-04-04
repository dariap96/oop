#include "IService.h"
#include "Task_Control_System.h"
#include <list>
using namespace std;

class ITaskRepository: public  IService<Task>, public Task_Control_System{
public:

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
