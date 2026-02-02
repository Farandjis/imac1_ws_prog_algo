#include <iostream>
#include <sil/sil.hpp>
#include "random.hpp"
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
            // attention à la confusion !! le point x de image correspond au point y2 de nouvelleImage
            // de même y de image --> x2 de nouvelleImage
            float x2 = nouvelleImage.height() - x - 1;
            float y2 = nouvelleImage.width() - y - 1;
            nouvelleImage.pixel(y2, x2).r = image.pixel(x, y).r; // on prend l'inverse du rouge
            nouvelleImage.pixel(y2, x2).g = image.pixel(x, y).g;
            nouvelleImage.pixel(y2, x2).b = image.pixel(x, y).b;
        }
    }
    image = nouvelleImage;
}


int main()
{
    sil::Image image{"images/logo.png"};
    // TODO: modifier l'image

    exo8(image);


    image.save("output/pouet.png");


}


