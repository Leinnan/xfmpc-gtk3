#ifndef SETTINGSBUTTONMENU_H
#define SETTINGSBUTTONMENU_H
#include <gtkmm.h>
#include "Functions.h"

class SettingsButtonMenu : public Gtk::Menu
{
public:
    SettingsButtonMenu();
    ~SettingsButtonMenu();
private:
    Gtk::CheckMenuItem menu_check_repeat;
    Gtk::CheckMenuItem menu_check_random;
    Gtk::CheckMenuItem menu_check_single_mode;
    Gtk::CheckMenuItem menu_check_consume_mode;
    Gtk::ImageMenuItem menu_preferences;
    Gtk::MenuItem      menu_shortcuts;
    Gtk::MenuItem      menu_about;
    Gtk::MenuItem      menu_exit;
    Gtk::SeparatorMenuItem      separator;
    
};

#endif // SETTINGSBUTTONMENU_H
