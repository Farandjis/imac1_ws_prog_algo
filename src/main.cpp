#include <algorithm>
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


void disque(sil::Image &image, glm::vec3 couleur, int taille, float x_centre, float y_centre)
{
    // on se déplace sur la moitié du cercle trigo
    // on va tracer un demi cercle en haut, tout en dessinant un demi cercle en bas
    for (float i = 0; i <= 4; i += 0.0001)
    {
        // à chaque point sur l'arc de cercle
        float y = (sqrt(i) / 2) * taille; // correspond à sin
        float x = (sqrt(4 - i) / 2) * taille; // correspond à cos
        // on part de ce point, on va jusq'au centre vertical de l'image (x_centre)
        for (int i = x; i >= -x; i -= 1)
        {
            if (x_centre + i < image.width() && y_centre + y < image.height() && x_centre + i >= 0 && y_centre + y >= 0)
            {
                image.pixel(x_centre + i, y_centre + y) = couleur;
                image.pixel(x_centre + i, y_centre - y) = couleur;
            }
        }
    }
}



void cercle(sil::Image &image, glm::vec3 couleur, int taille, float x_centre, float y_centre, int epaisseur)
{
    // CERCLE
    for (float i = 0; i <= 2*M_PI; i += 0.0001)
    {
        // à chaque point sur l'arc de cercle
        for (int pourEpaisseur = taille; pourEpaisseur <= taille+epaisseur; pourEpaisseur++)
        {
            float y = sin(i) * pourEpaisseur;
            float x = cos(i) * pourEpaisseur;
            if (x_centre + x < image.width() && y_centre + y < image.height() && x_centre + x >= 0 && y_centre + y >= 0)
            {
                image.pixel(x_centre + x, y_centre + y) = couleur;
            }
        }

    }

}



void exo11(sil::Image &image)
{
    // DISQUE
    glm::vec3 blanc = {1, 1, 1};
    disque(image, blanc, 100, image.width() / 2, image.height() / 2);
    }

void exo12(sil::Image &image)
{
    // CERCLE
    glm::vec3 blanc = {1, 1, 1};
    cercle(image, blanc, 100, image.width() / 2, image.height() / 2, 10);

}

void exo13(sil::Image &image)
{
    // ANIMATION
    Image imageParDefaut = image;
    glm::vec3 blanc = {1, 1, 1};

    for (int i = 0; i < image.width(); i += image.width() / 25) // 10 est le nombre d'images générés
    {
        disque(image, blanc, 100, i, image.height() / 2);
        image.save("output/exo13_" + to_string(i) + ".png"); // on génère l'image png
        image = imageParDefaut; // on rafraîchit l'arrière plan
    }
}

void exo14(sil::Image &image)
{
    // ROSACE
    glm::vec3 blanc = {1, 1, 1};
    float x_centre = image.width() / 2;
    float y_centre = image.height() / 2;
    cercle(image, blanc, 100, x_centre, y_centre, 3); // dessine le cercle du milieu

    // on parcourt le cercle du milieu
    for (float i = 0; i <= M_PI*2; i += M_PI / 3)
    {
        float y = sin(i)*100;
        float x = cos(i)*100;

        // on dessine un cercle avec comme centre, le point du cercle du milieu
        cercle(image, blanc, 100, x_centre + x, y_centre + y, 3);

    }

}

void insertionImage(Image &fond, Image &aInserer, int x, int y)
{
    for (int i = 0; i < aInserer.width(); i++)
    {
        for (int j = 0; j < aInserer.height(); j++)
        {
            fond.pixel(x+i,y+j) = aInserer.pixel(i,j);
        }
    }
}


void exo15(sil::Image &image) {
    // MOSAÏQUE

    sil::Image fond{image.width()*5, image.height()*5};

    for (int i = 0; i < fond.width(); i += fond.width() / 5)
    {
        for (int j = 0; j < fond.width(); j += fond.height() / 5)
        {
            insertionImage(fond, image, i, j);
        }
    }
    image = fond; // pour renvoyer le fond comme image
}

void exo16(sil::Image &image) {
    // MOSAÏQUE MIROIR

    sil::Image fond{image.width()*5, image.height()*5};

    for (int i = 0; i < fond.width(); i += fond.width() / 5)
    {
        for (int j = 0; j < fond.width(); j += fond.height() / 5)
        {
            Image imageATraiter = image;
            if (i / (fond.width() / 5) % 2 == 1)
            {
                  exo6(imageATraiter);
            }
            insertionImage(fond, imageATraiter, i, j);
        }
    }
    image = fond;  // pour renvoyer le fond comme image
}


void exo17(sil::Image &image) {
    // GLITCH

    /* Idée :
     *      1. On choisit une position aléatoire sur l'image.
     *      2. On choisit une autre position aléatoire sur l'image.
     *      3. On choisit les dimensions d'un rectangle de manière aléatoire
     *      4. On parcourt une boucle imbriquée longueur largeur à l'aide du rectangle
     *      5. On échange chaque pixel entre les deux positions
    */

    set_random_seed(0);
    // On génère un glitch par itération
    for (int i = 0; i < 255; i++)
    {
        // 1. position 1
        int x1 = random_int(0, image.width());
        int y1 = random_int(0, image.height());

        // 2. position 2
        int x2 = random_int(0, image.width());
        int y2 = random_int(0, image.height());

        // 3. rectangle
        int lMax = random_int(0, 20); // largeur
        int hMax = random_int(0, 10); // hauteur
        for (int l = 0; l < lMax; l++)
        {
            for (int h = 0; h < hMax; h++)
            {;
                int x1bis = (x1+l < image.width()) ? x1+l : l;
                int y1bis = (y1+h < image.height()) ? y1+h : h;
                int x2bis = (x2+l < image.width()) ? x2+l : l;
                int y2bis = (y2+h < image.height()) ? y2+h : h;
                glm::vec3 temporaire = image.pixel(x1bis, y1bis);
                image.pixel(x1bis, y1bis) = image.pixel(x2bis, y1bis);
                image.pixel(x2bis, y2bis) = temporaire;
            }
        }
    }
}

float brightness(glm::vec3 const pixel)
{
    return (pixel.r + pixel.g + pixel.b) / 3;
}


void exo18(sil::Image &image) {
    set_random_seed(0);
    for (int i = 0; i < image.pixels().size() - image.width(); i += image.width())
    {
        int longueur = random_int(0, 100); // nombre de pixels concernés par le trie

        // on trie 2x par ligne
        for (int j = 0; j < 2; j++)
        {
            // on prend une position aléatoire sur la ligne, à partir de cette position on mélage
            int positionAleatoireSurLaLigne = random_int(i, i + image.width());

            // on trie
            std::sort(image.pixels().begin() + positionAleatoireSurLaLigne, image.pixels().begin() +positionAleatoireSurLaLigne + longueur,
            [](const glm::vec3& pixel1, const glm::vec3& pixel2)
                    {
                        return brightness(pixel1) < brightness(pixel2);
                    });
        }

    }

}

int main()
{
    // sil::Image image{"images/photo.jpg"};
    sil::Image image{"images/logo.png"};
    // sil::Image image{500/*width*/, 500/*height*/};
    // TODO: modifier l'image

    exo18(image);


    image.save("output/pouet.png");


}


