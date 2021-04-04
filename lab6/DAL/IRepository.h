#include <list>
using namespace std;

template <typename T>
class IRepository {
public:
    virtual list <T> get_all() {};
    virtual T get(int id) {};
    virtual void Createid(T) {};
    virtual void Delete(T) {};
};
