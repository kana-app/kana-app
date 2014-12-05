#ifndef WIDGETFINQUIZZ_H
#define WIDGETFINQUIZZ_H
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
class WidgetFinQuizz : public QWidget
{
public:
    WidgetFinQuizz();
    WidgetFinQuizz(int);
    void setScore(int);
private:
    //score à afficher
    int score;
    //label score
    QLabel *score_label;
};

#endif // WIDGETFINQUIZZ_H
