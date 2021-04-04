#include "TaskView.h"
#include "/Users/dariapomazan/CLionProjects/oop6_BLL/Service.cpp"
using namespace std;

class TaskController {
public:
    list<TaskView> alltasks;
    Service service;
    TaskController(Service s) {
        service = s;
    }


 void Add_Task (TaskView t) {
        Task task(t.name,t.description);
        service.TCSS.create_task(task);
        service.TCSS.change_employee(task,t.emp_id);
    }


};