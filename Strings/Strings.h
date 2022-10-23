#pragma once
#include"../Orchestra/Orchestra.h"
class Strings: public Orchestra{
private:
    std::string manufacturer_name;
    std::string short_description;

public:
    Strings();
    Strings(Strings& str);
    ~Strings() override;

    void set_manufacture(std::string _manufacture);
    void set_description(std::string _description);
    std::string get_manufacture();
    std::string get_description();

    void set_cost(double _cost) override;
    void set_name(std::string _name) override;
    void set_owner(std::string _owner) override;
    void set_total_num(int _total_num) override;

    double get_cost() override;
    std::string get_name() override;
    std::string get_owner() override;
    int get_total_num() override;

    void show() override;
    void saving() override;
    void rewrite() override;

    friend std::ostream& operator<<(std::ostream& os, const Strings& obj) {
        os << "Type = Brass\n" << "name = " <<obj.name<<"\n"<< "cost = " <<obj.cost<<"\n"
           << "owner = " <<obj.owner_name<<"\n"<< "total = " <<obj.total_number<<"\n"<< "description = "
           <<obj.short_description <<std::endl;
        return os;
    }
};