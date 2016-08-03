#include "TopInterface.h"

TopInterface::TopInterface(MpdConnection * p_mpd_connection_pointer)
: controls_box(Gtk::ORIENTATION_HORIZONTAL, 0),
  more_controls_box(Gtk::ORIENTATION_HORIZONTAL, 0),
  info_box(Gtk::ORIENTATION_VERTICAL, 0),
  button_prev(),
  button_play(),
  button_pause(),
  button_stop(),
  button_next(),
  progress_bar()
{
    set_orientation(Gtk::ORIENTATION_VERTICAL);
    set_spacing(10);
    set_border_width(0);
    
    mpd_connection_pointer = p_mpd_connection_pointer;
    
    Glib::RefPtr<Gtk::StyleContext> context = get_style_context();
    context->add_class("primary-toolbar");
    
    info_box.set_border_width(5);
    
    pack_start(controls_box, true, true, 0);
    pack_start(more_controls_box, true, true, 0);
    
    
    button_prev.set_relief (Gtk::RELIEF_NONE);
    button_play.set_relief (Gtk::RELIEF_NONE);
    button_pause.set_relief (Gtk::RELIEF_NONE);
    button_stop.set_relief (Gtk::RELIEF_NONE);
    button_next.set_relief (Gtk::RELIEF_NONE);
    
    button_prev.set_image_from_icon_name("media-skip-backward",Gtk::ICON_SIZE_BUTTON);
    button_play.set_image_from_icon_name("media-playback-start",Gtk::ICON_SIZE_BUTTON);
    button_pause.set_image_from_icon_name("media-playback-pause",Gtk::ICON_SIZE_BUTTON);
    button_stop.set_image_from_icon_name("media-playback-stop",Gtk::ICON_SIZE_BUTTON);
    button_next.set_image_from_icon_name("media-skip-forward",Gtk::ICON_SIZE_BUTTON);
    
    button_prev.signal_clicked().connect(sigc::mem_fun((*mpd_connection_pointer), &MpdConnection::PrevSong));
    button_play.signal_clicked().connect(sigc::mem_fun((*mpd_connection_pointer), &MpdConnection::PlaySong));
    button_pause.signal_clicked().connect(sigc::mem_fun((*mpd_connection_pointer), &MpdConnection::PauseSong));
    button_stop.signal_clicked().connect(sigc::mem_fun((*mpd_connection_pointer), &MpdConnection::StopSong));
    button_next.signal_clicked().connect(sigc::mem_fun((*mpd_connection_pointer), &MpdConnection::NextSong));

    //button_prev.signal_clicked().connect(sigc::mem_fun(this, &TopInterface::UpdateButtonsVisibility));

    progress_bar.set_text ("0:00 / 0:00");
    progress_bar.set_show_text (true);
    progress_bar.set_fraction (0.3f);
    progress_box.add(progress_bar);
    
    
    volume_button.set_label("MADLEN UMYJ STOPY!");
    
    controls_box.pack_start(button_prev, false, false, 0);
    controls_box.pack_start(button_play, false, false, 0);
    controls_box.pack_start(button_pause, false, false, 0);
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
    //this->UpdateButtonsVisibility();
    this->UpdateTitle();
}

TopInterface::~TopInterface()
{
}

void TopInterface::UpdateButtonsVisibility()
{
    mpd_state my_mpd_state = mpd_connection_pointer->GetMpdState();
    
    if(my_mpd_state == MPD_STATE_PAUSE){
        button_pause.set_sensitive(false);
        button_play.set_sensitive(true);
    }
    if(my_mpd_state == MPD_STATE_PLAY){
        button_pause.set_sensitive(true);
        button_play.set_sensitive(false);
    }
    else{
        button_play.set_sensitive(true);
        button_pause.set_sensitive(false);
    }
}

void TopInterface::UpdateTitle(){
    // prefix s_ stands for song
    Glib::ustring s_artist;
    Glib::ustring s_album;
    Glib::ustring s_title;
    Glib::ustring s_year;
    Glib::ustring new_title;
    Glib::ustring new_subtitle;

    /*s_artist = mpd_song_get_tag(song, MPD_TAG_ARTIST, 0);
    s_album = mpd_song_get_tag(song, MPD_TAG_ALBUM, 0);
    s_title = mpd_song_get_tag(song, MPD_TAG_TITLE, 0);*/
    s_artist = "Bonson";
    s_album = "ZNANY I LUBIANY";
    s_title = "Wow!";
    s_year = "2016";
    
    new_title = "<span size=\"x-large\"><b>" + s_title + "</b></span>";
    new_subtitle = "<span size=\"medium\">" + s_artist + "- " + s_album + "[" + s_year +  "]</span>";
    title.set_markup(new_title);
    subtitle.set_markup(new_subtitle);
}