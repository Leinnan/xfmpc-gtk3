#include "TopInterface.h"

TopInterface::TopInterface()
: controls_box(Gtk::ORIENTATION_HORIZONTAL, 0),
  info_box(Gtk::ORIENTATION_VERTICAL, 0),
  more_controls_box(Gtk::ORIENTATION_HORIZONTAL, 0),
  button_prev(),
  button_pp(),
  button_stop(),
  button_next(),
  progress_bar()
{
    set_orientation(Gtk::ORIENTATION_VERTICAL);
    set_spacing(10);
    set_border_width(0);
    
    
    Glib::RefPtr<Gtk::StyleContext> context = get_style_context();
    context->add_class("primary-toolbar");
    
    info_box.set_border_width(5);
    
    pack_start(controls_box, true, true, 0);
    pack_start(more_controls_box, true, true, 0);
    
    
    button_prev.set_relief (Gtk::RELIEF_NONE);
    button_pp.set_relief (Gtk::RELIEF_NONE);
    button_stop.set_relief (Gtk::RELIEF_NONE);
    button_next.set_relief (Gtk::RELIEF_NONE);
    
    button_prev.set_image_from_icon_name("media-skip-backward",Gtk::ICON_SIZE_BUTTON);
    button_pp.set_image_from_icon_name("media-playback-start",Gtk::ICON_SIZE_BUTTON);
    button_stop.set_image_from_icon_name("media-playback-stop",Gtk::ICON_SIZE_BUTTON);
    button_next.set_image_from_icon_name("media-skip-forward",Gtk::ICON_SIZE_BUTTON);
    


    progress_bar.set_text ("0:00 / 0:00");
    progress_bar.set_show_text (true);
    progress_bar.set_fraction (0.3f);
    progress_box.add(progress_bar);
    
    
    controls_box.pack_start(button_prev, false, false, 0);
    controls_box.pack_start(button_pp, false, false, 0);
    controls_box.pack_start(button_stop, false, false, 0);
    controls_box.pack_start(button_next, false, false, 0);
    controls_box.pack_start(progress_box, true, true, 4);
    controls_box.pack_end(volume_button, false, false, 0);
    
    
    more_controls_box.pack_start(info_box, true, true, 0);
    more_controls_box.pack_end(settings_button, false, false, 0);
    
    
    settings_button.set_image_from_icon_name("gtk-properties",Gtk::ICON_SIZE_BUTTON);
    settings_button.set_popup(settings_button_menu);
    
    title.set_markup("<span size=\"x-large\"><b>Dobry Wieczór</b></span>");
    subtitle.set_markup("<span size=\"medium\">Xfmpc GTK3 mockup</span>");
    
    title.set_justify(Gtk::JUSTIFY_LEFT);
    title.set_alignment(0.0f, 0.5f);
    subtitle.set_alignment(0.0f, 0.5f);
    subtitle.set_justify(Gtk::JUSTIFY_LEFT);
    
    info_box.pack_start(title, false, false, 0);
    info_box.pack_start(subtitle, false, false, 0);
    
    show_all();
}

TopInterface::~TopInterface()
{
}

