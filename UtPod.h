#include <iostream>
#include <fstream>
#include <cstdlib>
#ifndef UTPOD_H
#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    UtPod() {
        memSize = 0 ;
        songs = NULL ;
    }
    UtPod(int size) {
        this->memSize = size ;
        this->songs = NULL ;
    }

    int addSong(Song const &s);
    int removeSong(Song const &s);
    int findSong(Song const &s) ;
    void shuffle();
    void showSongList();
    void sortSongList();

    int getTotalMemory();

    int getRemainingMemory();
    ~UtPod();

};



#endif