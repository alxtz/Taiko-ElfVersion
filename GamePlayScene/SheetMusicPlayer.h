#ifndef SHEETMUSICPLAYER_H
#define SHEETMUSICPLAYER_H


#include <QTimer>
#include <QObject>
#include "SheetMusic.h"

class SheetMusicPlayer : public QObject
{
    Q_OBJECT

    public:
        SheetMusicPlayer(SheetMusic * inputSheet);
        int currentNote;
        SheetMusic & sheetMusic;
        void count();
        void start();

        QTimer * singleTimer;

    public slots:
        void spawn();
        void pause();
        void resume();
        void emitOveEnd();

    signals:
        void shootDongKa(int);
        void setSpawn();
        void oveEnd();

        void disableEsc();


    private:
        bool justPaused;
        int remainingTime;
};

#endif // SHEETMUSICPLAYER_H
