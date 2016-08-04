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

void MpdConnection::PlayThisSong(int p_song_id)
{
    this->UpdateConnection();
    mpd_send_play_id(conn, p_song_id);
    mpd_response_finish(conn);
}

mpd_state MpdConnection::GetMpdState(){
    mpd_status * my_mpd_status = NULL;
    mpd_send_status(conn);
    my_mpd_status = mpd_recv_status(conn);
    return mpd_status_get_state(my_mpd_status);
}

void MpdConnection::UpdateCurrentSong(){
    this->UpdateConnection();
    std::cout << "1\n";
    mpd_song * song_pointer = NULL;
    std::cout << "1\n";
    
    
    mpd_command_list_begin(conn, true);
    mpd_send_status(conn);
    //mpd_send_current_song(conn);
    mpd_command_list_end(conn);
    
    mpd_status * my_mpd_status = NULL;
    my_mpd_status = mpd_recv_status(conn);
    std::cout << "1\n";
    //song_pointer = mpd_recv_song(conn);
    std::cout << "1\n";
    if((my_mpd_status) && (mpd_status_get_state(my_mpd_status) == MPD_STATE_PLAY)){
        current_song.elapsed = mpd_status_get_elapsed_time(my_mpd_status);
        current_song.total = mpd_status_get_total_time(my_mpd_status);
       // const char * current_song_title = mpd_song_get_tag(song_pointer, MPD_TAG_TITLE, 0);
        //std::cout << "TEST: " << i << "\n";
    //    const char * current_song_artist = mpd_song_get_tag(song_pointer, MPD_TAG_ARTIST, 0);
    //    std::cout << "1\n" << current_song_artist;
        //mpd_song_free(song_pointer);
        mpd_status_free(my_mpd_status);
    }
    mpd_response_finish(conn);
    mpd_connection_free(conn);
}

song MpdConnection::GetCurrentSong(){
    this->UpdateCurrentSong();
    return current_song;
}