#include <iostream>
#include <fstream>
#include <cstdlib>
#ifndef UTPOD_H
#define UTPOD_H
#include "song.h"

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
    UtPod() ;
    UtPod(int size) ;

    int addSong(Song const &s); // Adds song passed to this function to the beginning of linked list, returns 0 for success and -1 for failure, prints an error message if song is too big
    int removeSong(Song const &s); // Calls findSong() and removes song passed to this function, returns 0 for success and -1 for failure, prints an error message if song isn't found
    int findSong(Song const &s) ; //Returns integer value of the index of the song passed to this function, returns -1 if not found
    void shuffle(); //Swaps two random songs twenty times
    void showSongList(); //Sorts songs alphabetically by title, then artist, then size. Prints "Empty List" if there are no songs
    void sortSongList(); //Traverses linked list and prints each song's title, artist, and size
    int getTotalMemory(); //Returns total memory of the UtPod
    int getRemainingMemory(); //Returns remaining memory of the UtPod
    int numSongs() ; //Returns the number of songs in the UtPod
    void clearMemory() ; //Clears all songs from the UtPod
    ~UtPod();

};



#endif
