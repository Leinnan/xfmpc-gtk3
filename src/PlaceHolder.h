#ifndef PLACEHOLDER_H
#define PLACEHOLDER_H
#include <gtkmm.h>

class PlaceHolder : public Gtk::Box
{
public:
    PlaceHolder(bool p_reverse_order = true, Glib::ustring header_text = "Test page");
    ~PlaceHolder();
private:
    Gtk::Label label_header;
    Gtk::Label label_1;
    Gtk::Label label_2;
    Gtk::Button button_1;
    Gtk::Button button_2;

};

#endif // PLACEHOLDER_H
