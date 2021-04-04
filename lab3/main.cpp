#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

class Transport {
public:
    string name;
    int speed;
    string type;
    virtual double all_time(int d){
        return d/speed;
    };
};
class Earth: public Transport{
public:
    virtual double time_resting(int d) {
 return d;
    }
    double all_time(int d) override{
        return (d/speed)+time_resting(d);}

};
class Air : public Transport{
public: int new_dist;
       virtual double k(int d) {
return d;
    }
    double all_time(int d) override {
        k(d);
        return new_dist/speed;
    }
};
template <class T>
class AERace  {
public:
    int distance;
    string race_type;
    AERace<T>(string r_t,int d) {
        distance = d;
        race_type=r_t;
    }
     list <Transport> participants;
     void Register(Transport k) {
         if (race_type==k.type)
            participants.push_back(k);
        }


    Transport start_race() {
        Transport winner ;
        auto it=participants.begin();
        int min = it->all_time(distance);

        for (it; it!=participants.end();it++) {
            if (it->all_time(distance) < min) {
                min = it->all_time(distance);
                winner = *it;
            }
        }
        return winner;
    }

};

 class Two_v: public Earth {
 public:
     int time_moving;
     double time_resting(int d) override {
         int i=(d/(speed*time_moving));
         if (i <1) { return 0;}
         if (i>=1&&i<=2) {return 5;}
         else return 5+(i-1)*8;
     }

     Two_v()  {
         type = "earth";
         name = "Two_v";
         speed = 10;
         time_moving = 30;
     };
 };

  class B_v: public Earth {
  public:
        int time_moving;
        double time_resting(int d) override {
            int i=d/(speed*time_moving);
            if (i <1) { return 0;}
            if (i>=1&&i<=2) {return 10;}
            else return 10+(i-1)*5;
        }
        B_v() {
          type = "earth";
          name = "B_s";
          speed = 6;
          time_moving = 60;
      };
    };

    class Kent: public Earth  {
    public:
        int time_moving;
        double time_resting(int d) override{
            int i= d/(speed*time_moving);
            if (i <1) { return 0;}
            if (i>=1&&i<=2) {return 2;}
            else return i*2;
        };
        Kent() {
            type = "earth";
            name = "Kent";
            speed = 15;
            time_moving = 8;
        };
    };

    class V_b:public Earth {
    public:
        int time_moving;
         double time_resting(int d) override {
            int i=(d)/(speed*time_moving);
            if (i <1) { return 0;}
            if (i>=1&&i<=2) {return 5;}
            if (2>i&&i<=3) {return 6.5;}
            else return 5+6.5+(i-2)*8;
        }
        V_b() {
            type = "earth";
            name = "V_b";
            speed = 40;
            time_moving = 10;

        };
    };

    class K_s: public Air  {
    public:
        double k(int d) override {

          if (d <1000) new_dist=d ;
          if (1000 <=d&& d <5000) new_dist=d *(1-0.03);
          if (5000<=d&& d <10000) new_dist=d *(1-0.1);
          if (d >=10000) new_dist=d*(1-0.05);
          return new_dist;
        }

        K_s() {
            type = "air";
            name = "K_s";
            speed = 10;
        }
    };
    class Metla: public Air{
    public:
        double k (int d) override{
            if (d <1000) new_dist= d;
            else {
                if (1000<=d&&d<100000)
                {
                    new_dist =  d * (1 -  d / 100000);
                }
            }
            return new_dist;
        }

        Metla() {
            type = "air";
            name = "Metla";
            speed = 20;
        }
    };
    class Stupa: public Air {
        public:
        double kk;

        double all_time(int d) override{
            new_dist=d*(1-kk);
           return new_dist/speed;
        };

        Stupa() {
            type = "air";
            name = "Stupa";
            speed = 8;
            kk = 0.06;
        }
    };


int main() {
    AERace<Air> race1("air",1000);
    Stupa stupa1;
    Metla metla1;
    K_s k_s1;
    race1.Register(stupa1);
    race1.Register(metla1);
    race1.Register(k_s1);
    cout << race1.start_race().name << "\n";
    return 0;
}
