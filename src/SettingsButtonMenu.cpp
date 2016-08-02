#include "SettingsButtonMenu.h"

SettingsButtonMenu::SettingsButtonMenu()
{
    
    menu_check_repeat.set_label("Repeat");
    menu_check_random.set_label("Random");
    menu_check_single_mode.set_label("Single mode");
    menu_check_consume_mode.set_label("Consume mode");
    menu_preferences.set_label("Preferences");
    menu_shortcuts.set_label("Shortcuts");
    menu_about.set_label("About");
    menu_exit.set_label("Quit");
    menu_exit.signal_activate().connect(sigc::ptr_fun(&application_quit));
    
    
    
    this->append(menu_check_repeat);
    this->append(menu_check_random);
    this->append(menu_check_single_mode);
    this->append(menu_check_consume_mode);
    this->append(separator);
    this->append(menu_preferences);
    this->append(menu_shortcuts);
    this->append(menu_about);
    this->append(menu_exit);
    
    this->show_all();
}

SettingsButtonMenu::~SettingsButtonMenu()
{
}

