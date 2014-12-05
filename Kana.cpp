#include "Kana.h"

Kana::Kana()
{
}

Kana::Kana(QString romaji, QString jap) : m_romaji(romaji), m_jap(jap)
{
}

Kana::Kana(QString romaji, QString jap, QString img) : m_romaji(romaji), m_jap(jap), m_img(img)
{
}

QString Kana::getImg()
{
    return m_img;
}

QString Kana::getRomaji()
{
    return m_romaji;
}

QString Kana::getJap()
{
    return m_jap;
}
