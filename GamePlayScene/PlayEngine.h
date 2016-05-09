#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <QObject>
#include <string>
#include <QMediaPlayer>
#include <QTimer>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include "SheetMusic.h"
#include "SheetMusicPlayer.h"

using namespace std;

class PlayEngine : public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

    public:
        PlayEngine(string oveName);

        void keyPressEvent(QKeyEvent * event);

        void readSheetMusic();
        void playSheetMusic();
        void playMusic();

        SheetMusic sheetMusic;
        SheetMusicPlayer * sheetMusicPlayer;



    private:
        QTimer * moveTimer;
        string inputOve;
        QMediaPlayer * BGMusic;

    public slots:
        void spawnDongKa(int type);
        void spawnGrade(int grade);

    signals:
        void hitKey(int);
};

#endif // PLAYENGINE_H
