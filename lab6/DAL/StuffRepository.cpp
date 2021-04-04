#include "Stuff.h"
#include "IRepository.h"
#include <list>
using namespace std;

class IEmployeeRepository: public  IRepository<IEmployee>{
public:
    list <IEmployee> all_employees;

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
