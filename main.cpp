#include <iostream>
#include <iterator>
#include <list>
#include <exception>
#include <map>
#include <string>

using namespace std;

class Product {
private:
public:
    int code;
    string name;
    Product() {
        code=0; name=" ";
    }
    Product(int pcode,string pname) {
        code=pcode; name=pname;
    }
};

class Shop {
private:
    int code;
public:
    string name;
    string adress;
    typedef pair <int, int> number_price;
    map <Product, number_price> products;
    map <Product, number_price>:: iterator it ;
Shop(){code=0;name=" ";adress=" ";}
Shop(int scode, string sname, string sadress){
    code=scode;
    name=sname;
    adress=sadress;
}
bool is_product(int code) {
    for (auto it=products.begin(); it!=products.end(); it++) {
        if ( it->first.code == code) return 1;
        else return 0;
    }
}
int how_many_of(int code) {
  if (is_product(code)!=0) {
      for (auto it=products.begin(); it!=products.end(); it++) {
          if ( it->first.code == code) {
               return it->second.first;
          }
      }
  }
}
int get_price_of_p_here(Product p) {
 if (is_product(p.code)!=0) {
     for (auto it=products.begin(); it!=products.end(); it++) {
         if ( it->first.code == p.code) {
            return it->second.second;
            break;
         }
     }
 }
}
    int get_price_of_x_p_here(Product p,int x) {
        if (is_product(p.code)!=0) {
            for (auto it=products.begin(); it!=products.end(); it++) {
                if ( it->first.code == p.code) {
                    return x*( it->second.second);

                    break;
                }
            }
        }
    }


void add_products(Product p,int number_of,int price) {
    pair <int,int> n_p;
    n_p=make_pair(number_of,price);

        for (auto it=products.begin(); it!=products.end(); it++) {
            if ( it->first.code == p.code) {
                it->second.first=number_of;
                it->second.second=price;
            }
        }
}
list<pair< string, int>> what_to_buy(int money) {
    list <pair<string,int>> names;
    for (auto it=products.begin(); it!=products.end(); it++) {
        if  (money - (it->second.second) >= 0 ) {
            pair <string,int> k(it->first.name,money/ it->second.second);
            names.insert(names.begin(),k);
        }
    }
    names.unique();
    return names;
}
int y;
int do_consignment(Product p, int number_of) {
    if (is_product(code)!=0) {
        if (number_of <= how_many_of(p.code)) {
            for (auto it=products.begin(); it!=products.end(); it++) {
                if ( it->first.code == p.code) {
                    y=it->second.second;
                }
            }
          return number_of*y ;
        }
        else throw std::runtime_error("Consignment was done unsucsessfully. There are not enough products at this shop\n ");
    }
}

};

list <Shop> :: iterator it;
Shop find_cheapest1(Product p,list <Shop> s) {
   it=s.begin();
    Shop cheapest;
    int mp = it->get_price_of_p_here(p);

    for (it=s.begin();it!=s.end();it++)
    {   if (it->is_product(p.code)!=0&& it->get_price_of_p_here(p)<mp) {
        mp= it->get_price_of_p_here(p);
         cheapest=*it;
    }
        throw std::runtime_error("In none of these shops the product is available");
    }
            return cheapest;
    }
Shop find_cheapest2(Product p, int number_of, list <Shop> s ){
    it=s.begin();
    int mp = it->get_price_of_p_here(p);
     Shop cheapest;
    for (it=s.begin();it!=s.end();it++) {
    if (it->is_product(p.code)!=0&& it->get_price_of_x_p_here(p,number_of)<mp){
        mp= it->get_price_of_p_here(p);
        cheapest=*it;
    }
        throw std::runtime_error( "There isn't a shop with the required number of products available");
    }

    return cheapest;
}

int main() {
//1
 Shop Shop1(1, "A", "Serova 47");
 Shop Shop2(2, "B", "Fedora Abramova 4");
 Shop Shop3(3, "C", " Nansena 3");
 list <Shop> shops;
 shops.push_back(Shop1);
 shops.push_back(Shop2);
 shops.push_back(Shop3);
//2
 Product P1(1,"chair" );
 Product P2(2,"table" );
 Product P3(3, "water" );
 Product P4(4, "apple" );
 Product P5(5, "milk" );
 Product P6(6,"bread" );
 Product P7(7, "banana" );
 Product P8(8,"cup" );
 Product P9(9, "plate" );
 Product P10(10, "charger" );
//3
Shop1.add_products(P1, 5, 500);
Shop2.add_products(P1,2,200 );
Shop3.add_products(P1, 1, 100);
Shop3.get_price_of_x_p_here(P1,5);
//4
find_cheapest1(P1, shops);
//5
Shop1.what_to_buy(1000);
//6
Shop1.do_consignment(P1,2);
//7
find_cheapest2(P1,5, shops);
return 0;
};