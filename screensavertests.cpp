#include "ScreenSaver.h"
#include <cassert>

void test_correct_text() {
    ScreenSaver ss;
    assert(ss.isValidGameName(QString("пятнашки")));
}

void test_upper_text() {
    ScreenSaver ss;
    assert(!ss.isValidGameName(QString("ПЯТНАШКИ")));
}

void test_spaces_text() {
    ScreenSaver ss;
    assert(!ss.isValidGameName(QString("п  ятн ашк      и ")));
}

void test_hell_text() {
    ScreenSaver ss;
    assert(!ss.isValidGameName(QString("П  ятн АШк      И ")));
}
