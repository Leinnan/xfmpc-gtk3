#ifndef MPDCONNECTION_H
#define MPDCONNECTION_H
#include <mpd/client.h>
#include <stdlib.h> // executing system commands

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
    mpd_state GetMpdState();
private:
	mpd_connection *conn;

};

#endif // MPDCONNECTION_H
