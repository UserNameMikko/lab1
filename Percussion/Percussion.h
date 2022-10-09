#pragma once
#include "../Orchestra/Orchestra.h"
#include <vector>
class Percussion: public Orchestra{
private:
    std::string type;
public:
    Percussion();
    Percussion(const Percussion& perc);
    ~Percussion() override;

    void set_type(std::string _type);
    void set_cost(double _cost) override;
    void set_name(std::string _name) override;
    void set_owner(std::string _owner) override;
    void set_total_num(int _total_num) override;

    std::string get_type();
    double get_cost() override;
    std::string get_name() override;
    std::string get_owner() override;
    int get_total_num() override;

    void show() override;
    void saving() override;
    void rewrite() override;

    friend std::ostream& operator<<(std::ostream& os, const Percussion& obj) {
        std::vector<std::string> v;
        v.push_back(obj.name);
        v.push_back(obj.owner_name);
        v.push_back(obj.type);
        v.push_back(std::to_string(obj.total_number));
        v.push_back(std::to_string(obj.cost));
        for (int i = 0; i < v.size(); i++)
            os << v[i] + " ";
        return os;
    }
};