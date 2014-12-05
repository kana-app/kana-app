#ifndef KANALABEL_H
#define KANALABEL_H

#include <QLabel>

class KanaLabel : public QLabel
{
public:
    KanaLabel(QString romaji,QString jap);
    KanaLabel(Qstring romaji,QString jap, QString img);
private:
    QString m_romaji;
    QString m_jap;
    QString m_img;
};

#endif // KANALABEL_H
