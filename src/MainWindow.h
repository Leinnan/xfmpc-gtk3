#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <gtkmm/button.h>
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include "TopInterface.h"
#include "BottomInterface.h"
#include "MpdConnection.h"

class MainWindow : public Gtk::Window
{
public:
    MainWindow();
    ~MainWindow();
    MpdConnection GetMpdConnection();
private:
    MpdConnection my_mpd_connection;
    Gtk::Box vbox;
    TopInterface top_interface;
    BottomInterface bottom_interface;

};

#endif // MAINWINDOW_H
