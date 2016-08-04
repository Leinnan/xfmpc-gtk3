#ifndef MPDCONNECTION_H
#define MPDCONNECTION_H
#include <mpd/client.h>
#include <stdlib.h> // executing system commands
#include <glibmm/ustring.h>
#include <iostream>
#include <sstream>
#include <string>

struct song{
    Glib::ustring title = "NONE";
    Glib::ustring artist = "NONE";
    Glib::ustring album = "NONE";
    Glib::ustring filename = "/dev/null";
    int date = 1996;
    int elapsed= 0;
    int total= 1;
};

class MpdConnection
{
public:
    MpdConnection();
    ~MpdConnection();
    void UpdateConnection();
    void NextSong();
    void PrevSong();
    void PauseSong();
    void PlaySong();
    void StopSong();
    void PlayThisSong(int p_song_id);
    mpd_state GetMpdState();
    void UpdateCurrentSong();
    song GetCurrentSong();
private:
	mpd_connection *conn;
    song current_song;
};

#endif // MPDCONNECTION_H
