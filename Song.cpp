//
// Created by krisl on 10/23/2018.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Song.h"

using namespace std;

Song::Song()
{
    title = "" ;
    artist = "" ;
    size = 0 ;
}

Song::Song(string artist, string title, int size)
{
    this->artist = artist;
    this->title = title;
    this->size = size;
}

string Song::getTitle() const {
    return title ;
}

void Song::setTitle(string title) {
    this->title = title ;
}

string Song::getArtist() const
{
    return artist ;
}

void Song::setArtist(string artist)
{
    this->artist = artist ;
}

int Song::getSize() const
{
    return size ;
}

void Song::setSize(int size)
{
    this->size = size ;
}

bool Song::operator ==(Song const &rhs)
{
    return (title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size) ;
}

Song::~Song() {

}