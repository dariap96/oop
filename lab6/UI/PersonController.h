#include "PersonView.h"
#include "/Users/dariapomazan/CLionProjects/oop6_BLL/Service.cpp"
using namespace std;
 class PersonController{
 public:
     Service service;

     PersonController(Service s){
         service=s;
     }
     void add_employee1(PersonView p){
         if (p.position == "basic") {
             Basic_e e(p.name,p.surname,service.TCSRepo);
             this->service.EmployeeRepo.all_employees.push_back(e);}
          else { Leader_e e(p.name,p.surname,service.TCSRepo);
             this->service.EmployeeRepo.all_employees.push_back(e);}
         }


     };
