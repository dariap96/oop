#include <string>
using namespace std;

class PersonView {
public:
    int id;
    string name;
    string surname;
    string position;
    PersonView( string n, string s, string p){
        name=n;
        surname=s;
        position=p;
    };
};