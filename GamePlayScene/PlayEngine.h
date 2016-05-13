#ifndef PLAYENGINE_H
#define PLAYENGINE_H


#include <string>

#include <QTimer>
#include <QObject>
#include <QKeyEvent>
#include <QMediaPlayer>
#include <QGraphicsPixmapItem>

#include "EscMenu.h"
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
        EscMenu * escMenu;

        bool isEsc;

    public slots:
        void spawnDongKa(int type);
        void spawnGrade(int grade);

        void moveTimerPause();
        void moveTimerResume();

    signals:
        void hitKey(int);
};

#endif // PLAYENGINE_H
