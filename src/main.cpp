#include <gtkmm.h>
#include <gtkmm/application.h>
#include <stdlib.h>
#include "MainWindow.h"

int main (int argc, char *argv[])
{
    Glib::RefPtr<Gtk::Application> xfmpc_app = Gtk::Application::create(argc, argv, "org.gtkmm.example");


    MainWindow main_window;
    //Shows the window and returns when it is closed.
    return xfmpc_app->run(main_window);
}