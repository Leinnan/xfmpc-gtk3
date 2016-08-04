#include "MpdConnection.h"

MpdConnection::MpdConnection()
{
    this->conn = mpd_connection_new( "localhost", 6600 ,30000);
}

MpdConnection::~MpdConnection()
{
}
void MpdConnection::UpdateConnection(){
    if(mpd_recv_idle(conn, false) == 0){
        this->conn = mpd_connection_new( "localhost", 6600 ,30000);
    }
}
void MpdConnection::NextSong()
{
    this->UpdateConnection();
    mpd_send_next(conn);
    mpd_response_finish(conn);
}

void MpdConnection::PrevSong()
{
    this->UpdateConnection();
    mpd_send_previous(conn);
    mpd_response_finish(conn);
}

void MpdConnection::PauseSong()
{
    this->UpdateConnection();
    mpd_send_pause(conn, true);
    mpd_response_finish(conn);
}

void MpdConnection::PlaySong()
{
    this->UpdateConnection();
    mpd_send_play(conn);
    mpd_response_finish(conn);
}

void MpdConnection::StopSong()
{
    this->UpdateConnection();
    mpd_send_stop(conn);
    mpd_response_finish(conn);
}



mpd_state MpdConnection::GetMpdState(){
    mpd_status * my_mpd_status = NULL;
    mpd_send_status(conn);
    my_mpd_status = mpd_recv_status(conn);
    return mpd_status_get_state(my_mpd_status);
}