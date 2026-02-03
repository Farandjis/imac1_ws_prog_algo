#include <iostream>
#include <sil/sil.hpp>
#include "random.hpp"
#include <math.h>

using namespace std;
using namespace sil;

void exo1(sil::Image &image) {
    // NE GARDER QUE LE VERT
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = 0.f; // on met le rouge à 0
            image.pixel(x, y).b = 0.f; // de même pour le bleu
            // ---> il ne reste plus que la couleur vertes
        }
    }
}

void exo2(sil::Image &image) {
    // ÉCHANGER LES CANAUX
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            float r_temporaire = image.pixel(x, y).r;
            image.pixel(x, y).r = image.pixel(x, y).b; // on remplace le rouge par le bleu
            image.pixel(x, y).b = r_temporaire;  // le bleu par le rouge
        }
    }
}

void exo3(sil::Image &image) {
    // NOIR & BLANC

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            float r_temporaire = image.pixel(x, y).r;
            float g_temporaire = image.pixel(x, y).g;
            float b_temporaire = image.pixel(x, y).b;
            // on calcul la luminance
            float luminance = 0.3 * r_temporaire + 0.59 * g_temporaire + 0.11 * b_temporaire;

            // on définit la même valeur à chaque canal de couleur --> cela donne du gris
            image.pixel(x, y).r = luminance;
            image.pixel(x, y).g = luminance;
            image.pixel(x, y).b = luminance;
        }
    }
}


void exo4(sil::Image &image) {
    // NÉGATIF
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = 1 - image.pixel(x, y).r; // on prend l'inverse du rouge
            image.pixel(x, y).g = 1 - image.pixel(x, y).g;
            image.pixel(x, y).b = 1 - image.pixel(x, y).b;
        }
    }
}

void exo5(sil::Image &image) {
    // en soit l'image que l'on prend en paramètre ne sert pas à grand chose puisqu'on va la remplacer.
    // DEGRADÉ
    sil::Image image2{300/*width*/, 200/*height*/};
    image = image2; // juste pour prendre la forme de l'image de l'énnoncé

    float valeurPourIncrementer = 1 / (float) image.width(); // on calcul une valeur que l'on va multiplier
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = valeurPourIncrementer * x; // plus x est grand, plus le produit sera grand et donc plus ce sera clair
            image.pixel(x, y).g = valeurPourIncrementer * x;
            image.pixel(x, y).b = valeurPourIncrementer * x;
            // on obtient un dégradé
        }
    }

}

void exo6(sil::Image &image) {
    // MIROIR

    Image image_copie = image;

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = image_copie.pixel(image.width() - x - 1, y).r; // on prend l'inverse du rouge
            image.pixel(x, y).g = image_copie.pixel(image.width() - x - 1, y).g;
            image.pixel(x, y).b = image_copie.pixel(image.width() - x - 1, y).b;
        }
    }
}

void exo7(sil::Image &image) {
    // IMAGE BRUITÉE
    set_random_seed(0); // on définit un seed afin d'obtenir la même suite de nombres aléatoire à chaque lancement

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            if (0 == random_int(0,5)) {
                // on a une chance sur cinq que le pixel soit bruité
                image.pixel(x, y).r = random_float(0, 1); // on prend une nuance de rouge aléatoire
                image.pixel(x, y).g = random_float(0, 1); // de même
                image.pixel(x, y).b = random_float(0, 1); // de même
            }
        }
    }
}


void exo8(sil::Image &image) {
    // ROTATION A 90°

    // on créer une image noir avec la longueur et largeur de image inversé.
    // cela signifie donc que x pour image équivaut à y pour nouvelleImage
    sil::Image nouvelleImage{image.height(), image.width()};

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            // attention à la confusion !! le point x de image correspond au point y de nouvelleImage
            // de même y de image --> y2 de nouvelleImage
            float y2 = nouvelleImage.width() - y - 1;
            nouvelleImage.pixel(y2, x).r = image.pixel(x, y).r; // on prend l'inverse du rouge
            nouvelleImage.pixel(y2, x).g = image.pixel(x, y).g;
            nouvelleImage.pixel(y2, x).b = image.pixel(x, y).b;
        }
    }
    image = nouvelleImage;
}

void exo9(sil::Image &image) {
    // RGB split

    // imaginons que le rouge, bleu et le vert soient trois calques.
    // on va déplacer deux des calques

    sil::Image nouvelleImage{image.width(), image.height()};

    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            if (x+30 < image.width()) // on avance 30 px le ""calque"" rouge
                nouvelleImage.pixel(x+30, y).r = image.pixel(x,y).r;

            nouvelleImage.pixel(x, y).g = image.pixel(x, y).g;

            if (x-30 > 0) // on recule de 30px le ""calque"" bleu
            nouvelleImage.pixel(x-30, y).b = image.pixel(x, y).b;
        }
    }

    image = nouvelleImage;
}

void exo10_eclaircissement(sil::Image &image) {
    // LUMINOSITÉ : ÉCLAIRCISSEMENT
    float luminosite = 0.1; // plus la valeur sera grande, plus l'image sera clair, plus on la diminue, plus elle sera sombre
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = image.pixel(x, y).r + luminosite;
            image.pixel(x, y).g = image.pixel(x, y).g + luminosite;
            image.pixel(x, y).b = image.pixel(x, y).b + luminosite;

        }
    }
}

void exo10_assombrissement(sil::Image &image) {
    // LUMINOSITÉ : ASSOMBRISSEMENT
    float luminosite = -0.1; // plus la valeur sera grande, plus l'image sera clair, plus on la diminue, plus elle sera sombre
    for (int x{0}; x < image.width(); ++x)
    {
        for (int y{0}; y < image.height(); ++y)
        {
            image.pixel(x, y).r = image.pixel(x, y).r + luminosite;
            image.pixel(x, y).g = image.pixel(x, y).g + luminosite;
            image.pixel(x, y).b = image.pixel(x, y).b + luminosite;

        }
    }
}


void disque(sil::Image &image, glm::vec3 couleur, int taille)
{
    // DISQUE
    float x_centre = image.width() / 2;
    float y_centre = image.height() / 2;

    float y = sin(0) * 0; // juste pour se rappeler que y c'est sin en réalité
    float x = cos(0) * 0;


    // on se déplace sur le cercle trigo
    // ici de tout à droite à tout en haut
    // arc haut droit
    for (float i = 0; i <= 4; i += 0.0001)
    {
        // à chaque point sur l'arc de cercle
        y = (sqrt(i) / 2) * taille;
        x = (sqrt(4 - i) / 2) * taille;
        // on part de ce point, on va jusq'au centre vertical de l'image (x_centre)
        for (int i = x; i >= 0; i -= 1)
        {
            image.pixel(x_centre + i, y_centre + y) = couleur;
        }
    }

    // arc haut gauche
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = (sqrt(i) / 2) * taille;
        x = - (sqrt(4 - i) / 2) * taille;

        // même idée mais cette fois ci on se trouve à gauche et on va au centre
        for (int i = x; i <= 0; i += 1)
        {
            image.pixel(x_centre + i, y_centre + y) = couleur;
        }
    }

    // arc bas droit
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = -(sqrt(i) / 2) * taille;
        x = (sqrt(4 - i) / 2) * taille;

        for (int i = x; i >= 0; i -= 1)
        {
            image.pixel(x_centre + i, y_centre + y) = couleur;
        }
    }

    // arc bas gauche
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = -(sqrt(i) / 2) * taille;
        x = -(sqrt(4 - i) / 2) * taille;

        for (int i = x; i <= 0; i += 1)
        {
            image.pixel(x_centre + i, y_centre + y) = couleur;
        }
    }
}

void cercle(sil::Image &image)
{
    // DISQUE
    float x_centre = image.width() / 2;
    float y_centre = image.height() / 2;

    float y = sin(0) * 0; // juste pour se rappeler que y c'est sin en réalité
    float x = cos(0) * 0;


    // on se déplace sur le cercle trigo
    // ici de tout à droite à tout en haut
    // arc haut droit
    for (float i = 0; i <= 4; i += 0.0001)
    {
        // à chaque point sur l'arc de cercle
        y = (sqrt(i) / 2) * 100;
        x = (sqrt(4 - i) / 2) * 100;
        image.pixel(x_centre + x, y_centre + y).g = 1; // on le colorie en vert
    }

    // arc haut gauche
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = (sqrt(i) / 2) * 100;
        x = - (sqrt(4 - i) / 2) * 100;
        image.pixel(x_centre + x, y_centre + y).g = 1;
    }

    // arc bas droit
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = -(sqrt(i) / 2) * 100;
        x = (sqrt(4 - i) / 2) * 100;
        image.pixel(x_centre + x, y_centre + y).g = 1;
    }

    // arc bas gauche
    for (float i = 0; i <= 4; i += 0.0001)
    {
        y = -(sqrt(i) / 2) * 100;
        x = -(sqrt(4 - i) / 2) * 100;
        image.pixel(x_centre, y_centre).g = 1;
    }
}


void exo11(sil::Image &image)
{
    // DISQUE
    glm::vec3 blanc = {1, 1, 1};
    disque(image, blanc, 100);
}

void exo12(sil::Image &image)
{
    // CERCLE
    glm::vec3 blanc = {1, 1, 1};
    glm::vec3 noir = {1, 1, 1};
    disque(image, blanc, 100);
    disque(image, noir, 90);
}




int main()
{
    // sil::Image image{"images/photo.jpg"};
    // sil::Image image{"images/logo.png"};
    sil::Image image{500/*width*/, 500/*height*/};
    // TODO: modifier l'image

    exo11(image);


    image.save("output/pouet.png");


}


