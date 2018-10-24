//
// Created by krisl on 10/23/2018.
//
using namespace std;
#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H



class Song
{
public:
    string title ;
    string artist;
    int size ;

    Song() {
        title = "" ;
        artist = "" ;
        size = 0 ;
    }
    Song(string artist, string title, int size) {
        this->artist = artist ;
        this->title = title ;
        this->size = size ;
    }

    bool operator ==(Song const &rhs) {
        return (title == rhs.title &&
                artist == rhs.artist &&
                size == rhs.size) ;
    }
};

#endif //UTPOD_SONG_H