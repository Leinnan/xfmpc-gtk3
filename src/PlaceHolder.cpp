#include "PlaceHolder.h"

PlaceHolder::PlaceHolder(bool p_reverse_order, Glib::ustring header_text)
{
    set_orientation(Gtk::ORIENTATION_VERTICAL);
    label_header.set_markup("<span size=\"xx-large\">" + header_text + "</span>");
    label_1.set_markup("<span size=\"x-large\"><b>Some test</b> Tex</span>t");
    label_2.set_markup("<span size=\"medium\">Another test</span>");
    
    pack_start(label_header, false, false, 0);
    if(p_reverse_order){
        pack_start(label_1, false, false, 0);
        pack_end(label_2, false, false, 0);
        pack_start(button_1, false, false, 0);
        pack_start(button_2, false, false, 0);
    }
    else{
        pack_start(button_2, false, false, 0);
        pack_start(label_1, false, false, 0);
        pack_end(button_1, false, false, 0);
        pack_start(label_2, false, false, 0);
    }
}

PlaceHolder::~PlaceHolder()
{
}

