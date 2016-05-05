#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <QObject>
#include <string>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "SheetMusic.h"
#include "SheetMusicPlayer.h"

using namespace std;

class PlayEngine : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        PlayEngine(string oveName);

        void readSheetMusic();
        void playSheetMusic();

        SheetMusic sheetMusic;
        SheetMusicPlayer * sheetMusicPlayer;

    private:
        QTimer * moveTimer;
        string inputOve;
        QMediaPlayer * BGMusic;
        void playMusic();

    public slots:
        void spawnDongKa(int type);
};

#endif // PLAYENGINE_H
