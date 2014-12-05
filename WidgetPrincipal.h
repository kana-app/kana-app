#ifndef WIDGETPRINCIPAL_H
#define WIDGETPRINCIPAL_H
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QListWidgetItem>
#include <QLabel>
class WidgetPrincipal : public QWidget
{
public:
    WidgetPrincipal();
    QPushButton* getButtonLearn();
    QPushButton* getButtonQuizz();
    void createIcons();

signals:

private:
    QPushButton* button_quizz;
    QPushButton* button_learn;
};

#endif // WIDGETPRINCIPAL_H
