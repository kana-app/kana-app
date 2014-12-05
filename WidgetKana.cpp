#include "WidgetKana.h"
//widget pour afficher la liste des kanas
WidgetKana::WidgetKana()
{
    setMinimumWidth(300);
    hiragana=true;
    spoil_actif=true;
    liste_kana = new ListeKana();
    caractere_romaji = new QLabel();
    caractere_jap = new QLabel();
    QVBoxLayout* layout_base = new QVBoxLayout(this);
    QFont police_jap = QFont("Ubuntu",180);
    caractere_jap->setFont(police_jap);
    QFont police_romaji = QFont("Ubuntu",130);
    caractere_romaji->setFont(police_romaji);

    layout_base->addWidget(caractere_jap);
    layout_base->addWidget(caractere_romaji);

    QHBoxLayout* layout_fleches = new QHBoxLayout;

    QPushButton* fleche_gauche = new QPushButton("Précédent");
    QPushButton* fleche_droite = new QPushButton("Suivant");
    hide_romaji = new QPushButton("Cacher Romaji");

    QPushButton* prononciation = new QPushButton("Prononcer");


    fleche_droite->setStyleSheet(" QPushButton {"
                                       "     background-color: #C1E21B;"
                                       "     border-style: outset;"
                                       "     border-width: 2px;"
                                       "     border-radius: 10px;"
                                       "     border-color: beige;"
                                       "     font: bold 14px;"
                                       "     padding: 6px;"
                                       " }"
                                       " QPushButton:pressed {"
                                       "     background-color: #AAC417;"
                                       "     border-style: inset;"
                                       " }");
    fleche_gauche->setStyleSheet(" QPushButton {"
                                       "     background-color: #C1E21B;"
                                       "     border-style: outset;"
                                       "     border-width: 2px;"
                                       "     border-radius: 10px;"
                                       "     border-color: beige;"
                                       "     font: bold 14px;"
                                       "     padding: 6px;"
                                       " }"
                                       " QPushButton:pressed {"
                                       "     background-color: #AAC417;"
                                       "     border-style: inset;"
                                       " }");

    hide_romaji->setStyleSheet(" QPushButton {"
                                       "     background-color: #22BBD6;"
                                       "     border-style: outset;"
                                       "     border-width: 2px;"
                                       "     border-radius: 10px;"
                                       "     border-color: beige;"
                                       "     font: bold 14px;"
                                       "     min-width: 10em;"
                                       "     padding: 6px;"
                                       " }"
                                       " QPushButton:pressed {"
                                       "     background-color: #2e5d7b;"
                                       "     border-style: inset;"
                                       " }");
    prononciation->setStyleSheet(" QPushButton {"
                                       "     background-color: #22BBD6;"
                                       "     border-style: outset;"
                                       "     border-width: 2px;"
                                       "     border-radius: 10px;"
                                       "     border-color: beige;"
                                       "     font: bold 14px;"
                                       "     min-width: 10em;"
                                       "     padding: 6px;"
                                       " }"
                                       " QPushButton:pressed {"
                                       "     background-color: #2e5d7b;"
                                       "     border-style: inset;"
                                       " }");


    layout_base->addWidget(prononciation);


    layout_base->addWidget(hide_romaji);
    layout_fleches->addWidget(fleche_gauche);
    layout_fleches->addWidget(fleche_droite);

    layout_base->addLayout(layout_fleches);
    // connexion bouton hide
    QObject::connect(hide_romaji,SIGNAL(clicked()),this,SLOT(afficheSpoil()));
    // connexion boutons fleches
    QObject::connect(fleche_gauche,SIGNAL(clicked()),this,SLOT(moveToLeft()));
    QObject::connect(fleche_droite,SIGNAL(clicked()),this,SLOT(moveToRight()));


    //connexion prononciation
    QObject::connect(prononciation,SIGNAL(clicked()),this,SLOT(pronounce()));

    afficheKanaActuel();
}




void WidgetKana::afficheKanaActuel()
{
    /* récuppération du kana actuel pour l'afficher */
    Kana* kanasel= getCurrentKana();
    /* mise à jour du label jap */
    caractere_jap->setText("<center>"+kanasel->getJap()+"</center>");
    /* mise à jour du label romaji */
    if(spoil_actif)
        caractere_romaji->setText("<center>"+kanasel->getRomaji()+"</center>");
    else
        caractere_romaji->setText("");

}

// active/desactive le spoil à chaque appel
void WidgetKana::afficheSpoil()
{
    // en fonction du statut actif du spoil on change le texte du bouton
    if (spoil_actif)
        hide_romaji->setText("Afficher Romaji");
    else
        hide_romaji->setText("Cacher Romaji");

    spoil_actif=!spoil_actif;
    afficheKanaActuel();
}

// charge le kana de gauche
void WidgetKana::moveToLeft()
{
    liste_kana->deplaceSelection(true);
    //update
    afficheKanaActuel();
}

// charge le kana de droite
void WidgetKana::moveToRight()
{
    liste_kana->deplaceSelection(false);
    //update
    afficheKanaActuel();
}

/** renvoie le kana hiragana courant si hiragana == true
 * sinon renvoie le katakana courant **/
Kana* WidgetKana::getCurrentKana()
{

    return liste_kana->getSelection(hiragana);
}


// à terme permettra de selectionner un kanji en rajoutant un choix
void::WidgetKana::setKana(QString choix)
{
    hiragana=(choix=="Hiragana");
    afficheKanaActuel();
}

// prononce le kana actuel
void WidgetKana::pronounce()
{
    QSound::play(":/sons/ressources/sons/"+getCurrentKana()->getRomaji()+".wav");
}
