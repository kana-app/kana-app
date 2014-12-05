#ifndef TIMECOMPTEUR_H
#define TIMECOMPTEUR_H

#include <QTimer>
#include "FaderWidget.h"
#include <QStackedWidget>
#include <QLabel>
#include <QHBoxLayout>
class TimeCompteur : public QWidget
{
    Q_OBJECT
public:
    TimeCompteur();
    TimeCompteur(int debut,int time);
    void stoppeCompteur();
    void lanceCompteur(int time=1000);
    void initialiseCompteur();
    void setBegin(int);
    int getDerniereValeur();
signals:
    void finCompteur();
public slots:
    void decrementeCompteur();


private:
    int m_debut;
    QTimer *timer;
    int debut_compteur;
    //utilisation d'un QStackedWidget pour l'animation
    QStackedWidget *stacked_widget;
    int derniere_valeur;

};

#endif // TIMECOMPTEUR_H
