/*#include "Menu.h"
void Menu::main_menu()
{
    while (exit == 1) {
        switch (show_options())
        {
            case 1:
                show_all_figures();
                break;
            case 2:
                change_data();
                break;
            case 3:
                add_new();
                break;
            case 4:
                save_to_file();
                break;
            case 5:
                load_from_file();
                break;
            case 6:
                delete_figure();
                break;
            case 7:
                find_per();
                break;
            case 8:
                exit_from_programm();
                break;
        }
    }
}
int Menu::show_options()
{
    int c1;
    std::cout << "" << std::endl;
    std::cin >> c1;
    return c1;
}

void Menu::show_all_figures()
{
    try
    {
        if (list.get_size() == 0) {
            throw "Ñïèñîê ïóñò! Âûâîäèòü íå÷åãî!";
        }
        for (int i = 0; i < list.get_size(); i++) {
            list[i]->show();
        }
    }
    catch (const char* er)
    {
        std::cout << er << std::endl;
        std::cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << std::endl;
    }

}

void Menu::change_data()
{
    int c2;
    try
    {
        cout << "Êàêóþ ôèãóðó õîòèòå èçìåíèòü?" << endl;
        cout << "Ââåäèòå íîìåð ôèãóðû îò 1 äî " << list.get_size() << endl;
        cin >> c2;
        if (c2<1 || c2>list.get_size()) {
            throw "Íåêîððåêòíûé íîìåð!";
        }
        list[c2 - 1]->show();
        cout << "Êàêîé ïàðàìåòð íåîáõîäèìî ðåäàêòèðîâàòü?" << endl;
        int par;
        cout << "1 - Òèï" << endl;
        cout << "2 - Ðàçìåðû" << endl;
        cin >> par;
        switch (par) {
            case 1:
                cout << "Ïðè ñìåíå òèïà ôèãóðû íåîáõîäèìî èçìåíèòü åå ðàçìåðû" << endl;
                list[c2 - 1]->rewrite();
                break;
            case 2:
                double a1, a2, a3;
                cout << "Ââåäèòå òðè íîâûõ ðàçìåðà." << endl;
                cout << "Åñëè ó ôèãóðû (íàïðèìåð êðóã) åñòü òîëüêî 1 ðàçìåð (ðàäèóñ), ââåäèòå ðàäèóñ, à îñòàëüíûå ïàðàìåòðû çàäàéòå íóëåì" << endl;
                cin >> a1 >> a2 >> a3;
                list[c2 - 1]->redact(a1, a2, a3);
                break;
        }
        cout << "Äàííûå èçìåíåíû!" << endl;

    }
    catch (const char* err)
    {
        cout << err << endl;
        cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << endl;
    }

}
void Menu::add_new()
{
    int c3;
    cout << "Êàêóþ ôèãóðó íåîáõîäèìî äîáàâèòü?" << endl;
    cout << "1 - Ïëîñêàÿ" << endl;
    cout << "2 - Îáúåìíàÿ" << endl;
    cin >> c3;
    switch (c3) {
        case 1:
            Flat * flat;
            flat = new Flat;
            figures = flat;
            flat->rewrite();
            list.insert(figures);
            break;
        case 2:
            Solid * solid;
            solid = new Solid;
            figures = solid;
            solid->rewrite();
            list.insert(figures);
            break;
        default:
            break;
    }
    cout << "Íîâàÿ ôèãóðà áûëà äîáàâëåíà!" << endl;
}
void Menu::save_to_file()
{
    try
    {
        if (list.get_size() == 0) {
            throw "Ñïèñîê ïóñò! Ñîõðàíÿòü íå÷åãî!";
        }
        list.save();
        cout << "Äàííûå ñîõðàíåíû â ôàéë data.txt" << endl;
    }
    catch (...)
    {
        cout << "Âûçâàíî èñêëþ÷åíèå!" << endl;
        cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << endl;
    }

}
void Menu::load_from_file()
{
    list.load();
    cout << "Äàííûå èçâëå÷åíû èç ôàéëà!" << endl;
}
void Menu::delete_figure()
{
    int c4;
    try
    {
        if (list.get_size() == 0) {
            throw "Ñïèñîê ïóñò!";
        }
    }
    catch (...)
    {
        cout << "Âûçâàíî èñêëþ÷åíèå!" << endl;
        cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << endl;
    }

    cout << "Êàêóþ ôèãóðó âû õîòèòå óäàëèòü?" << endl;
    cout << "Ââåäèòå ÷èñëî îò 1 äî " << list.get_size() << endl;
    /*for (int i = 0; i < list.get_size(); i++) {
        list[i]->show();
    }//
    try
    {
        cin >> c4;
        if (c4<1 || c4>list.get_size())
        {
            throw"Ââåäåíî íåêîððåêòíîå ÷èñëî!";
        }
        list.remove(list.get_size()-c4);
        cout << "Âûáðàííàÿ ôèãóðà óäàëåíà" << endl;

    }
    catch (...)
    {
        cout << "Âûçâàíî èñêëþ÷åíèå!" << endl;
        cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << endl;
    }

}
void Menu::find_per()
{
    int p1;
    try
    {
        for (int i = 0; i < list.get_size(); i++) {
            list[i]->show();
        }
        cout << "Ââåäèòå íîìåð ôèãóðû, ïåðèìåòð èëè ïåðèìåòð îñíîâàíèÿ/ñå÷åíèÿ êîòîðîé íåîáõîäèìî íàéòè" << endl;
        cin >> p1;
        if (p1<1 || p1>list.get_size()) {
            throw "Ââåäåíî íåêîððåêòíîå ÷èñëî!";
        }
        cout << "Ïåðèìåòð: " << list[p1 - 1]->Per() << endl;

    }
    catch (...)
    {
        cout << "Âûçâàíî èñêëþ÷åíèå!" << endl;
        cout << "Èñêëþ÷åíèå îáðàáîòàíî!" << endl;
    }

}

void Menu::exit_from_programm()
{
    exit = 0;
}*/