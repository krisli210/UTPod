#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "UtPod.h"

using namespace std;

UtPod::UtPod() {
    memSize = 0 ;
    songs = NULL ;
}

UtPod::UtPod(int size) {
    this->memSize = size ;
    this->songs = NULL ;
}


int UtPod::addSong(Song const &s) {

    if (s.getSize() < getRemainingMemory()) { // if there's room
        SongNode *temp = new SongNode;
        temp->s.setArtist(s.getArtist()) ;
        temp->s.setTitle(s.getTitle())  ;
        temp->s.setSize(s.getSize()) ;

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
        total += p->s.getSize() ;
        p = p->next ;
    }
    return getTotalMemory()-total ; //return difference */

}

int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::removeSong(Song const &s) {

    if (songs == NULL) // if empty returns not found
        return NOT_FOUND ;

    int index = findSong(s) ;
    //cout << index << endl ;
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
        cout << p->s.getArtist() << ", " << p->s.getTitle() << ", " << p->s.getSize() << "Mb" << endl ;
        p = p->next ;
    }
}

int UtPod::numSongs() { // returns number of songs in the linked list
    SongNode *p = songs ;
    int count = 0 ;
    while (p != NULL) {
        p = p->next ;
        count++ ;
    }
    return count ;
}

void UtPod::shuffle() {
    unsigned int currentTime = (unsigned)time(0) ;
    srand(currentTime) ;
    SongNode *p1, *p2 ;
    Song temp ;
    for (int i = 0 ; i < 10 ; i++) {
        p1 = p2 = songs;
        int index1 = (rand() % numSongs()) ; //serve as indices that we need to switch
        int index2 = (rand() % numSongs()) ;
        for (int j = 0; j < index1; j++) // set pointers to position
            p1 = p1->next;
        for (int j = 0; j < index2; j++)
            p2 = p2->next;
        temp = p1->s; // temp = first song, first song = second song, second song = temp
        p1->s = p2->s;
        p2->s = temp;
    }
}

void UtPod::sortSongList() {

}

UtPod::~UtPod() {

}