#ifndef KANA_H
#define KANA_H

#include <QString>
class Kana
{
public:
    Kana();
    Kana(QString romaji,QString jap);
    Kana(QString romaji,QString jap, QString img);
    QString getImg();
    QString getRomaji();
    QString getJap();
private:
    QString m_romaji;
    QString m_jap;
    QString m_img;
};

#endif // KANA_H
