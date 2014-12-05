#include "GestionScore.h"

//prend en paramètre le chemin vers le fichier et le score
// enregistre seulement si supérieur au meilleur score
void sauverMeilleurScore(QString fichier_nom,int score)
{

    // Création d'un objet QFile
    QFile file(fichier_nom);
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() <<fichier_nom;


    }// Création d'un objet QTextStream à partir de notre objet QFile
    QTextStream flux(&file);

    //récupération du meilleur score dans le fichier
    int score_fichier;
    flux >> score_fichier;

    file.close();

    QFile file_w(fichier_nom);
    file_w.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&file_w);


    // écriture du score actuel seulement s'il est meilleur que le précédent score enregistré
    qWarning() << QString::number(score);

    if (score > score_fichier)
        out << score;

    // optional, as QFile destructor will already do it:
    file_w.close();
}


//retourne le score situé dans le fichier en paramètre
int chargerScore(QString fichier_nom)
{
    int score=0;
    QFile fichier(fichier_nom);
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "bg3";
    }
    QTextStream flux(&fichier);
    flux >> score;
    fichier.close();
    return score;

}

void sauverScore(QString fichier_nom,int score)
{
    QFile file_log(fichier_nom);

    // Ouverture / Création du fichier
    if(!file_log.exists()){
         file_log.open(QIODevice::WriteOnly | QIODevice::Text);
    } else {
         file_log.open(QIODevice::Append | QIODevice::Text);
    }

    QTextStream stream(&file_log);
    // On écrit dans le fichier
    stream << QString::number(score) << "\n";
    // Fermeture du fichier
    file_log.close();


}
