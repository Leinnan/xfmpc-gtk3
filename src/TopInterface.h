#ifndef TOPINTERFACE_H
#define TOPINTERFACE_H
#include <gtkmm.h>
#include "SettingsButtonMenu.h"

class TopInterface : public Gtk::Box
{
public:
    TopInterface();
    ~TopInterface();
private:
    Gtk::Box controls_box;
    Gtk::Box more_controls_box;
    Gtk::Box info_box;
    Gtk::Button button_prev;
    Gtk::Button button_pp;
    Gtk::Button button_stop;
    Gtk::Button button_next;
    Gtk::MenuButton settings_button;
    Gtk::EventBox   progress_box;
    Gtk::ProgressBar progress_bar;
    Gtk::VolumeButton volume_button;
    Gtk::Label title;
    Gtk::Label subtitle;
    SettingsButtonMenu settings_button_menu;
};

#endif // TOPINTERFACE_H
