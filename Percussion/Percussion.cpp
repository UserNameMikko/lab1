#include"Percussion.h"

Percussion::Percussion(){
    this->type ="";
    this->name = "";
    this->cost = 0;
    this->owner_name = "";
    this->total_number = 0;
}
Percussion::Percussion(const Percussion &perc) {
    this->type = perc.type;
    this->total_number = perc.total_number;
    this->name = perc.name;
    this->cost = perc.cost;
    this->owner_name = perc.owner_name;
}

double Percussion::get_cost() {
    return this->cost;
}
std::string Percussion::get_name() {
    return this->name;
}
std::string Percussion::get_owner(){
    std::cout<< "get_owner_perc"<< std::endl;
    return this->owner_name;
}
int Percussion::get_total_num() {
    return this->total_number;
}
std::string Percussion::get_type(){
    return this->type;
}



void Percussion::set_cost(double _cost) {
    this->cost = _cost;
}
void Percussion::set_name(std::string _name) {
    this->name = _name;
}
void Percussion::set_owner(std::string _owner) {
    this->owner_name = _owner;
}
void Percussion::set_total_num(int _total_num) {
    this->total_number = _total_num;
}
void Percussion::set_type(std::string _type){
    this->type = _type;
}


void Percussion::show() {

}
void Percussion::saving() {

}
void Percussion::rewrite() {

}
Percussion::~Percussion() = default;