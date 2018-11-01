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

    bool operator ==(Song const &rhs) ; //Operator override, returns true if two songs' titles, artists, and sizes are the same
    bool operator >(Song const &rhs) ; //Operator override, returns true if LHS is alphabetically greater than RHS ; checks title, then artist, then size
    bool operator <(Song const &rhs) ;//Operator override,  returns true if LHS is alphabetically less than RHS ; checks title, then artist, then size 
    string getTitle() const ; //Returns title
    void setTitle(string title) ; //Sets title of the song to input
    string getArtist() const ; //Returns artist
    void setArtist(string artist) ; //Sets artist of the song to input
    int getSize() const ; //Returns size
    void setSize(int size) ; //Sets size of the song to input
    ~Song();
};

#endif
