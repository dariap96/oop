#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <exception>
//дописать throw exc
using namespace std;

class Client{
public:
    string name;
    string surname;
    string adress;
    string pasport_num;
    list <string> ids;
    bool full_data() const {
        if (this->adress==" " && this->pasport_num==" ")
            return false;
        else
            return true;
    };

    Client(){
        adress=" ";
        pasport_num=" ";
    }

    Client(string n,string s,string a, string p){
        name=n;
        surname=s;
        adress=a;
        pasport_num=p;
    }
};

class Client_builder: public Client{
protected:
    string name;
    string surname;
    string adress;
    string pasport_num;

public:
   Client_builder * set_name(string N){
     // if (N=="-") { throw std::runtime_error ;}
       this->name=N;
       return this;
   };
   Client_builder * set_surname(string S){
       //if " " throw exc
       this->surname=S;
       return this;
   };
    Client_builder * set_adress(string A){
        this->adress=A;
        return this;
    }
    Client_builder * set_pasport_num(string P){
        this->pasport_num=P;
        return this;
    }
    Client build() {
        return *new Client(name, surname, adress, pasport_num);
    }
};

 class Bank_Account : public Client  {
 public :
    int time_opened; //в часах
    string s_name;
    int id;
    int sum_now;

    Bank_Account( ) {
        time_opened=0;
        sum_now=0;
        id=0;
        s_name="";
    }
    Bank_Account(Client c, string s_namee, int g) {
        id=g;
        s_name=s_namee;
        sum_now=0;
        time_opened=0;
    }

     int minus{};
 };
 class Bank;
class Transaction { //че-то сделать с макс переводом банка с сомнительного счета
public:
    int id=0;
     Bank B(int i, double k, double j);
    int backup1=0;
    int backup2=0;
    virtual Transaction * Execute(Client c, Bank_Account s, int sum, int idd) {
        return this;
    };
    virtual Transaction * Undo(Client c, Bank_Account s, int idd){
        return this;
    };
}
;
class Add: public Transaction{
public:
    Add * Execute(Client c, Bank_Account s, int sum, int idd) override{
        s.sum_now += sum;
        this->id=idd;
        return this;
    }

    Add * Undo(Client c, Bank_Account s, int idd) override{
    return this;
    }
};
class Minus: public Transaction{
public:
    Minus * Execute(Client c, Bank_Account s, int sum, int idd) override {
        backup1=s.sum_now;
        if (c.full_data()) {
            if (sum <= s.sum_now) {
                s.sum_now -=sum;
                cout << "ok";
            }
        } else {

            if (sum < this.B(int i,double k, double j)->somn_limit && sum <= s.sum_now) {
                s.sum_now -=sum;
                cout << "ok";
            } else { cout << "minus snyatiya are not proveded + check if your data isn't full "; }
        }
     this->id=idd;
        return this;
    }
    Minus * Undo(Client c, Bank_Account s, int idd ) override{
        s.sum_now=backup1;
        this->id=idd;
        return this;
    }


};
class Trans: public Transaction{
public:
    Trans * Execute1(Client c, Bank_Account s1, Bank_Account s2, int sum, int idd)  {
        int limit;
        if (c.full_data() || sum <= limit) {
            backup1 = s1.sum_now;
            s1.sum_now -= sum;
            backup2 = s2.sum_now;
            s2.sum_now += sum;
        }
        else { cout << "not enough money+ chefck your data ";
        }
        this->id=idd;
        return this;
    }

    Trans * Undo1(Client c, Bank_Account s1, Bank_Account s2, int sum, int idd) {
        s1.sum_now=backup1;
        s2.sum_now=backup2;
        this->id=idd;
        return this;
    }


};

class Debet:  public Bank_Account {
public:
    Debet(Client c, string s_namee, int g) {
        id=g;
        s_name=s_namee;
        sum_now=0;
    }
};

class Deposit :  public Bank_Account{

    Deposit(Client c, string s_namee, int g) {
        id=g;
        s_name=s_namee;
        sum_now=0;
    }
    int end_time;
    int set_end_time(int d ){end_time=d;};

    int isitend_date() {
        if (end_time==time_opened) {
            return 1;
        } else return 0;
    }
    void trans(Client c,Bank_Account s1, Bank_Account s2,int sum, int g) {
        if (isitend_date()) {
            Trans t= *new Trans;
            t.Execute1(c,s1,s2,sum, g);
        } else { cout << "this transaction isn't avauilable yet"; }
    }

    void get_money(Client c, Bank_Account s, int sum, int g) {
        if (isitend_date()) {
            Minus m=*new Minus;
            m.Execute(c,s,sum,g);
        }
        else { cout << "this transaction isn't avauilable yet";}

    }
};
class Credit:   public Bank_Account{
    Credit(Client c, string s_namee, int g) {
        id=g;
        s_name=s_namee;
        sum_now=0;
        minus=0;
    }
    int minus=0;
    void get_money(Client c, Bank_Account s, int sum, int g ) {
        Minus m=*new Minus;
        m.Execute(c,s,sum,g);
    }
    void trans_money(Client c, Bank_Account s1, Bank_Account s2, int sum, int g ) {
        Trans t= *new Trans;
        t.Execute1(c,s1,s2,sum,g);
    }
    explicit Credit()= default;

};
class Bank {
public:
    Bank(int somn, int percent, int kredit_percent) {
        somn_limit=somn;
        procent=percent;
        kredit_procent=kredit_percent;
    }
   list <Bank_Account> all_Bank_Accounts_here;
    int somn_limit;
    int procent;

    int kredit_procent;

    vector <int> plus_money;

    void day_end(){ for ( auto i: all_Bank_Accounts_here) {
            if (i.s_name != "kredit") {
                int j= i.id;
                    plus_money[j] += i.sum_now * (procent / 365 / 100);
            }
            else { int j= i.id;
              plus_money[j]=i.minus + i.minus*(kredit_procent/100);
            }
            i.time_opened+=24;
        }

    }
    void month_end_add_percent_komm(){
    for (auto i: all_Bank_Accounts_here) {
        if (i.s_name != "kredit") {
        int j= i.id;
      i.sum_now+= plus_money[j];}
        else { int j= i.id; i.minus=plus_money[j];
        }
    }
    }
    int after_time(int days, int idd){
       for (int i=0;i<=days;i++) {
         day_end();
       }
       for (auto i: all_Bank_Accounts_here) {
           if (i.id == idd) {  if (i.s_name != "kredit") {
                   return i.sum_now;}
                   else {return i.minus;}
           }
       }
    }

};
void cancel(int transid, Client c, Bank_Account s,vector <Transaction> v){
     for (auto i:v) {
         if (i.id==transid){
             i.Undo(c,s,transid);
         }
     }
}


int main() {
   int idgenerator=0;
   int transidgen=0;
    vector < Transaction> history;
    auto i=new Client_builder;
    auto new_client=i->set_name("Daria")->set_surname("Pomazan")->build();
    Client c=new_client;
    Bank Bank1(50000,3.65,0.01);
    Debet b(c,"debet",idgenerator);
    idgenerator++;
    Bank1.all_Bank_Accounts_here.emplace_back(b);
    Minus m=*new Minus;
    m.Execute(c,b,500,transidgen);
    transidgen++;
    cancel(m.id,c,b,history);
    return 0;
}
