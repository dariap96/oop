#include <iostream>
#include "TaskController.h"
#include "PersonController.h"
#include "ReportController.h"
#include "/Users/dariapomazan/CLionProjects/oop6_BLL/Service.cpp"
using namespace std;

Task_Control_System_Repository TCSR;
IEmployeeRepository ER;
ITaskRepository TR;
Service service(TR,ER,TCSR);
TaskController TC(service);
PersonController PC(service);

enum cmds{
add_task,
add_employee,
make_report,
finish_task,
};

void do_command(cmds cmd) {
    switch (cmd) {
        case add_task: {
            cout << "name and desription needed";
            string n, d;
            int id;
            cin >> n >> d;
            cout << "your id";
            cin >> id;
            TaskView t(n, d, id);
            TC.Add_Task(t);
        }
            break;

        case add_employee: {
            string n, s, position;
            cout << "name,surname,position";
            cin >> n >> s >> position;
            PersonView p(n, s, position);
            PC.add_employee1(p);
        }
            break;

    }
}
int main() {
   do_command(add_employee);
   do_command(add_task);


    return 0;
}
