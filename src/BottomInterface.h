#ifndef BOTTOMINTERFACE_H
#define BOTTOMINTERFACE_H
#include <gtkmm.h>
#include "PlaceHolder.h"

class BottomInterface : public Gtk::Box
{
public:
    BottomInterface();
    ~BottomInterface();
private:
    Gtk::Notebook notebook;
    
    PlaceHolder placeholder_1;
    PlaceHolder placeholder_2;

};

#endif // BOTTOMINTERFACE_H
