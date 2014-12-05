#ifndef WIDGETKANA_H
#define WIDGETKANA_H
#include <QVector>
#include "Kana.h"
#include "ListeKana.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFont>
#include <QWidget>
#include <QtGui>
#include <QHBoxLayout>
#include <QPushButton>
#include <QKeyEvent>
#include <QUrl>
#include <QMultimedia>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QAudioFormat>
#include <QSound>

/* classe permettant d'afficher la liste des kanas */
class WidgetKana : public QWidget
{
    Q_OBJECT
public:
    WidgetKana();
    void afficheKanaActuel();
    void createIcons();

public slots:
    void afficheSpoil();
    void moveToLeft();
    void moveToRight();
    void pronounce();
    void setKana(QString);
signals:

private:
    bool spoil_actif;
    bool hiragana;
    ListeKana* liste_kana;
    QLabel* caractere_jap;
    QLabel* caractere_romaji;
    Kana* getCurrentKana();
    //bouton afficher_romaji qui change quand on appuie dessus
    QPushButton* hide_romaji;
};

#endif // WIDGETKANA_H
