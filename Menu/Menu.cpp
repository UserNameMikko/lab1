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
                find_per();
                break;
            case 7:
                exit_from_program();
                break;
        }
    }
}
int Menu::show_options() {
    int c;
    std::cout << "1 - show all instruments\n2 - add new instrument\n3 - save all into the text file\n"
                 "4 - load data from file\n5 - delete chosen instrument\n6 - \n7 - exit\n-> ";

    std::cin >> c;
    return c;
}

void Menu::show_all_instruments() {
    try{
        if (list.get_size() == 0)
            throw "list is empty";
        for (int i = 0; i < list.get_size(); i++)
            list[i]->show();
    }
    catch (const char* er){
        std::cout << er << std::endl;
    }

}

/*void Menu::change_data(){
    int c2;
    try{
        std::cout << "Êàêóþ ôèãóðó õîòèòå èçìåíèòü?" << std::endl;
        std::cout << "Ââåäèòå íîìåð ôèãóðû îò 1 äî " << list.get_size() << std::endl;
        std::cin >> c2;
        if (c2<1 || c2>list.get_size()) {
            throw "index out of bounds";
        }
        list[c2 - 1]->show();
        std::cout << "Êàêîé ïàðàìåòð íåîáõîäèìî ðåäàêòèðîâàòü?" << std::endl;
        int par;
        std::cout << "1 - Òèï" << std::endl;
        std::cout << "2 - Ðàçìåðû" << std::endl;
        std::cin >> par;
        switch (par) {
            case 1:
                std::cout << "Ïðè ñìåíå òèïà ôèãóðû íåîáõîäèìî èçìåíèòü åå ðàçìåðû" << std::endl;
                list[c2 - 1]->rewrite();
                break;
            case 2:
                double a1, a2, a3;
                std::cout << "Ââåäèòå òðè íîâûõ ðàçìåðà." << std::endl;
                std::cout << "Åñëè ó ôèãóðû (íàïðèìåð êðóã) åñòü òîëüêî 1 ðàçìåð (ðàäèóñ), ââåäèòå ðàäèóñ, à îñòàëüíûå ïàðàìåòðû çàäàéòå íóëåì" << std::endl;
                std::cin >> a1 >> a2 >> a3;
                list[c2 - 1]->redact(a1, a2, a3);
                break;
        }
        std::cout << "Äàííûå èçìåíåíû!" << std::endl;

    }
    catch (const char* err)
    {
        std::cout << err << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

}*/
void Menu::add_new(){
    int c;
    std::cout<<"which instrument i need to add?\n1 - Brass\n2 - Percussion\n3 - String\n-> ";
    std::cin >> c;
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
    catch (...){
        std::cout << "Âûçâàíî èñêëþ÷åíèå!" << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

}
void Menu::load_from_file(){
    list.load();
    std::cout << "successfully restored from data.txt!" << std::endl;
}
void Menu::delete_instrument() {
    int c;
    try {
        if (list.get_size() == 0)
            throw "list is empty!";

    }
    catch (...) {
        std::cout << "Âûçâàíî èñêëþ÷åíèå!" << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

    std::cout << "Êàêóþ ôèãóðó âû õîòèòå óäàëèòü?" << std::endl;
    std::cout << "Ââåäèòå ÷èñëî îò 1 äî " << list.get_size() << std::endl;
    /*for (int i = 0; i < list.get_size(); i++) {
        list[i]->show();
    }*/
    try{
        std::cin >> c;
        if (c<1 || c>list.get_size())
            throw"Ââåäåíî íåêîððåêòíîå ÷èñëî!";

        list.remove(list.get_size()-c);
        std::cout << "Âûáðàííàÿ ôèãóðà óäàëåíà" << std::endl;

    }
    catch (...){
        std::cout << "Âûçâàíî èñêëþ÷åíèå!" << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

}
void Menu::find_per(){
    int p;
    try
    {
        for (int i = 0; i < list.get_size(); i++)
            list[i]->show();
        std::cout <<" " << std::endl;
        std::cin >> p;
        if (p<1 || p>list.get_size()) {
            throw "Ââåäåíî íåêîððåêòíîå ÷èñëî!";
        }
       // std::cout << "Ïåðèìåòð: " << list[p1 - 1]->Per() << std::endl;

    }
    catch (...)
    {
        std::cout << "Âûçâàíî èñêëþ÷åíèå!" << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

}

void Menu::exit_from_program(){
    exit = 0;
}