#include"Strings.h"
Strings::Strings(){
    this->name = "";
    this->cost = 0;
    this->owner_name = "";
    this->total_number = 0;
    this->manufacturer_name = "";
    this->short_description = "";
}
Strings::Strings(Strings &str) {
    this->name = str.name;
    this->cost = str.cost;
    this->owner_name = str.owner_name;
    this->total_number = str.total_number;
    this->manufacturer_name = str.manufacturer_name;
    this->short_description = str.short_description;
}
void Strings::set_manufacture(std::string _manufacture){
    this->manufacturer_name = _manufacture;
}
void Strings::set_description(std::string _description){
    this->short_description = _description;
}
void Strings::set_total_num(int _total_num) {
    this->total_number = _total_num;
}
void Strings::set_cost(double _cost) {
    this->cost = _cost;
}
void Strings::set_name(std::string _name) {
    this->name = _name;
}
void Strings::set_owner(std::string _owner) {
    this->owner_name = _owner;
}

std::string Strings::get_manufacture(){
    return this->manufacturer_name;
}
std::string Strings::get_description(){
    return this->short_description;
}
int Strings::get_total_num() {
    return this->total_number ;
}
double Strings::get_cost() {
    return this->cost;
}
std::string Strings::get_name() {
    return this->name;
}
std::string Strings::get_owner() {
    return this->owner_name;
}

void Strings::show() {

}
void Strings::saving() {

}
void Strings::rewrite() {

}
Strings::~Strings() = default;