//
// Created by krisl on 10/23/2018.
//
using namespace std;

#ifndef UTPOD_SONG_H
#define UTPOD_SONG_H
#include <string>


class Song
{
private:
    string title ;
    string artist ;
    int size ;

public:
    Song();
    Song(string artist, string title, int size);

    bool operator ==(Song const &rhs) ;
    bool operator >(Song const &rhs) ;
    bool operator <(Song const &rhs) ;
    string getTitle() const ;
    void setTitle(string title) ;
    string getArtist() const ;
    void setArtist(string artist) ;
    int getSize() const ;
    void setSize(int size) ;
    ~Song();
};

#endif