#include "BottomInterface.h"

BottomInterface::BottomInterface() :
placeholder_1(true, "Current Playlist"),
placeholder_2(false, "Browse database")
{
    set_orientation(Gtk::ORIENTATION_VERTICAL);
    set_border_width(0);
    
    pack_start(notebook, true, true, 0);
    notebook.set_show_tabs (true);
    notebook.append_page(placeholder_1, "Current Playlist");
    notebook.append_page(placeholder_2, "Browse database");
    
    show_all();
}

BottomInterface::~BottomInterface()
{
}

