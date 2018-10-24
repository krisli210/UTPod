#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Song.h"
#include "UtPod.h"

using namespace std;


int UtPod::addSong(Song const &s) {

    if (s.size < getRemainingMemory()) { // if there's room
        SongNode *temp = new SongNode;
        temp->s.artist = s.artist ;
        temp->s.title  = s.title ;
        temp->s.size = s.size ;

        if (songs == NULL) { // if empty list
            temp->next = NULL;
            songs = temp;
        }
        else {
            temp->next = songs;
            songs = temp;
        }

        return SUCCESS ;
    }

    else { // if full
        cout << "Full" << endl;
        return NO_MEMORY ;
    }
}

int UtPod::getRemainingMemory() {
    int total = 0 ;
    SongNode *p = songs ;
    while (p != NULL) { // add each node's size
        total += p->s.size ;
        p = p->next ;
    }
    return getTotalMemory()-total ; //return difference
}

int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::removeSong(Song const &s) {

    if (songs == NULL) // if empty returns not found
        return NOT_FOUND ;

    int index = findSong(s) ;
    cout << index << endl ;
    if (index == -1) // if findSong returns a -1 it means it traversed list without finding
        return NOT_FOUND ;

    SongNode *trail = songs ;
    SongNode *p = songs ;

    if (index == 0) {
        songs = songs->next ;
        delete(p) ;
    }
    else { //sets pointer to index of the match and trail to one behind it
        for (int i = 0 ; i < index ; i++) {
            p = p->next ;
        }
        for (int i = 0 ; i < index-- ; i++) {
            trail = trail->next ;
        }
        trail->next = p->next ;
        delete(p) ;
    }
    return SUCCESS ;
    return 0 ;
}

int UtPod::findSong(Song const &s) { //finds the index of the song in the linked list, returns -1 if not found
    int index = 0 ;
    SongNode *p = songs ;
    while (p != NULL) {
        if (p->s == s) // overloaded operator: if node song is identical to input song
            return index ;
        else {
            index++;
            p = p->next;
        }
    }
    return -1 ; // if not found by now, return -1 as not found

}

void UtPod::showSongList() {
    SongNode *p = songs ;
    while (p != NULL) {
        cout << p->s.artist << ", " << p->s.title << ", " << p->s.size << "Mb" << endl ;
        p = p->next ;
    }
}

void UtPod::shuffle() {

}

void UtPod::sortSongList() {

}

UtPod::~UtPod() {

}