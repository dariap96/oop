#include <string>
#include "/Users/dariapomazan/CLionProjects/oop6_BLL/Task.h"
 using namespace std;
class TaskView {
public:
    int emp_id;
    string name;
    string description;
     TaskView(string n, string d,int employee_id){
         this->name = n;
         this->description = d;
         emp_id=employee_id;
     }
};
