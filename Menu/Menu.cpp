#include "Menu.h"
void Menu::main_menu(){
    while (exit == 1) {
        switch (show_options()){
            case 1:
                show_all_instruments();
                break;
            case 2:
                add_new();
                break;
            case 3:
                save_to_file();
                break;
            case 4:
                load_from_file();
                break;
            case 5:
                delete_instrument();
                break;
            case 6:
                find_cost_of_instrument();
                break;
            case 7:
                exit_from_program();
                break;
            default:
                break;
        }
    }
}
int Menu::show_options() {
    int c;
    std::cout << "1 - show all instruments\n2 - add a new instrument\n3 - save all instruments into the text file\n"
                 "4 - load data from file\n5 - delete instrument\n6 - find cost of instrument stack(only one type)\n"
                 "7 - exit\n-> ";
    std::cin >> c;
    if (c < 1 || c > 7)
        throw "bad number";
    return c;
}

void Menu::show_all_instruments() {
    if (list.get_size() == 0)
        throw "list is empty";
    for (int i = 0; i < list.get_size(); i++)
            list[i]->show();
}
void Menu::add_new(){
    int c;
    std::cout<<"which instrument i need to add?\n1 - Brass\n2 - Percussion\n3 - String\n-> ";
    std::cin >> c;
    if (c < 1 || c > 3)
        throw "bad number";
    switch (c) {
        case 1: // Brass
            Brass * brass;
            brass = new Brass;
            figures = brass;
            brass->rewrite();
            list.insert(figures);
            break;
        case 2: // Percussion
            Percussion * percussion;
            percussion = new Percussion;
            figures = percussion;
            percussion->rewrite();
            list.insert(figures);
            break;
        case 3: // Strings
            Strings* strings;
            strings = new Strings;
            figures = strings;
            strings->rewrite();
            list.insert(figures);
            break;
        default:
            break;
    }
    std::cout << "success" << std::endl;
}
void Menu::save_to_file(){
    try{
        if (list.get_size() == 0)
            throw "list is empty";
        list.save();
        std::cout << "successfully saved into data.txt" << std::endl;
    }
    catch (std::exception exception){
        std::cout << "something went wrong!" << std::endl << exception.what() << std::endl;
    }

}
void Menu::load_from_file(){
    list.load();
    std::cout << "successfully restored from data.txt!" << std::endl;
}
void Menu::delete_instrument() {
    int c;

    if (list.get_size() == 0)
        throw "list is empty!";

    std::cout << "Now you have " << list.get_size() <<" instruments"<<std::endl<<
    "input an index of instrument which will be deleted";
    std::cin >> c;
    if (c < 1 || c > list.get_size()-1)
        throw"index out of bounds";
    list.remove(c-1);
    std::cout << "instrument deleted successfully" << std::endl;

}
void Menu::find_cost_of_instrument(){
    int p;
    try{
        for (int i = 0; i < list.get_size(); i++)
            list[i]->show();
        std::cout <<"input the instrument which cost of all instances you want to calculate: " << std::endl;
        std::cin >> p;
        if (p<1 || p>list.get_size())
            throw "index out of bounds";
        std::cout<<"cost of all instances of current instrument: " <<
        list[p - 1]->get_total_num() * list[p - 1]->get_cost()<<std::endl;
    }
    catch (std::exception exception){
        std::cout << "something went wrong!" << std::endl << exception.what() << std::endl;
    }
}
void Menu::exit_from_program(){
    exit = 0;
}