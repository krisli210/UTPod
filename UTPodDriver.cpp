/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t(512);


    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;


    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "result = " << result << endl;

    Song ABBA("ABBA", "Dancing Queen" , 10) ;
    Song ABBA2("ABBA", "ZZZZZ", 10) ;
    Song zzTop("zzTop", "La Grange", 10) ;
    Song zzTop2("zzTop", "ZZZZZ", 10) ;
    Song Test("Test", "Hey Jude1", 5) ;
    Song Test2("Test", "Hey Jude1", 6) ;
    Song Test3("Test", "Hey Jude1", 512) ;

    result = t.addSong(Test) ;
    cout << "result = " << result << endl;
    result = t.addSong(Test2) ;
    cout << "result = " << result << endl;
    result = t.addSong(Test3) ;
    cout << "result = " << result << endl;
    result = t.addSong(ABBA) ;
    cout << "result = " << result << endl;
    result = t.addSong(zzTop) ;
    cout << "result = " << result << endl;
    result = t.addSong(ABBA2) ;
    cout << "result = " << result << endl;
    result = t.addSong(zzTop2) ;
    cout << "result = " << result << endl;

    cout << "\n" ;
    t.showSongList();

    t.shuffle() ;
    cout << "Shuffled:\n" ;
    t.showSongList() ;

    t.sortSongList() ;
    cout << "Sorted:\n" ;
    t.showSongList() ;

    cout << "Remove zzTop and ABBA songs" << endl;
    result = t.removeSong(ABBA) ;
    cout << "result = " << result << endl;
    result = t.removeSong(ABBA2) ;
    cout << "result = " << result << endl;
    result = t.removeSong(zzTop) ;
    cout << "result = " << result << endl;
    result = t.removeSong(zzTop2) ;
    cout << "result = " << result << endl;

    cout << "\n" ;
    t.showSongList() ;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    cout << "Remove Beatles Songs" << endl ;
    result = t.removeSong(s1) ;
    cout << "result = " << result << endl;
    result = t.removeSong(s2) ;
    cout << "result = " << result << endl;
    result = t.removeSong(s3) ;
    cout << "result = " << result << endl;
    result = t.removeSong(s4) ;
    cout << "result = " << result << endl;
    result = t.removeSong(s5) ;
    cout << "result = " << result << endl;

    cout << "\n" ;
    t.showSongList() ;
    cout << "remaining memory = " << t.getRemainingMemory() << endl;

    return 0 ;
}
//
// Created by krisl on 10/23/2018.
//

