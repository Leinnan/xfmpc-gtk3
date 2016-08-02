#include "MainWindow.h"

MainWindow::MainWindow()
: vbox(Gtk::ORIENTATION_VERTICAL, 0),
  top_interface(&my_mpd_connection)
{
    set_title("Xfmpc");
    set_default_icon_name("sonata");
    set_icon_name ("sonata");
    set_default_size(300,400);
    add(vbox);
    vbox.pack_start(top_interface, false, false, 0);
    vbox.pack_start(bottom_interface, true, true, 0);
    show_all();
    
}

MainWindow::~MainWindow()
{
}

