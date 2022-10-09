#ifndef LAB1_MENU_H
#define LAB1_MENU_H
#pragma once
#include "../Keeper/Keeper.h"
#include "../Orchestra/Orchestra.h"
class Menu {
protected:
    Keeper list;
    Orchestra* figures;
    int exit = 1;
public:
    void main_menu();
    int show_options();
    void show_all_instruments();
    void change_data();
    void add_new();
    void save_to_file();
    void load_from_file();
    void delete_instrument();
    void find_per();
    void exit_from_program();
};
#endif //LAB1_MENU_H
