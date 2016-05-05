#ifndef SHEETMUSIC_H
#define SHEETMUSIC_H


#include "Note.h"

class SheetMusic
{
    public:
        SheetMusic();
        Note notes[1000];

        int BPM;
};

#endif // SHEETMUSIC_H
