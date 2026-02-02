Matthieu FARANDJIS\
E3 IMAC
<div align="center">
<img height="95" src="images/README/esiee.jpg" title="logo esiee paris"/>

# README - Workshop Prog & Algo

---

<br>

Pour le rapport, faites une section par exercice que vous avez fait. Montrez une image avant
et après application de l'effet (comme c'est fait dans l'énoncé des exercices). Le rapport n'a
pas besoin d'être long. Pour les exercices où vous jugez cela utile, mettez un petit texte
expliquant des spécificités de l'algo que vous avez implémenté, et les pièges potentiels dans
lesquels il ne faut pas tomber
<br><br><br>

</div>


<br><br>

---

<a id="summary"></a>

## Plan

- **[1. Ne garder que le vert](#p1)**
- **[2. Échanger les canaux](#p2)**
- **[3. Noir & Blanc](#p3)**
- **[4. Négatif](#p4)**
- **[5. Dégradé](#p5)**
- **[6. Miroir](#p6)**
- **[7. Image bruitée](#p7)**
- **[8. Rotation à 90°](#p8)**
- **[9. RGB split](#p9)**
- **[10. Luminosité](#p10)**
  - **[10.1 Éclaircissement](#p10-1)**
  - **[10.2 Assombrissement](#p10-2)**
- **[11. Disque](#p11)**
- **[12. Cercle](#p12)**

---

### <a id="p1"></a> 1. Ne garder que le vert

<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo1.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

On met le rouge et le bleu à 0, il ne reste plus que le vert.

<br><br><br>

### <a id="p2"></a> 2. Échanger les canaux
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo2.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

On remplace le rouge par le bleu et le bleu par le rouge.

<br><br><br>

### <a id="p3"></a> 3. Noir & Blanc
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo3.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

On calcule la luminance à l'aide de la formule suivante : `luminance = 0.3 * rouge + 0.59 * vert + 0.11 * bleu;`\
On donne comme valeur à chaque couleur, la valeur de la luminance.
<br><br><br>

### <a id="p4"></a> 4. Négatif
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo4.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

On inverse les couleurs : `couleur = 1 - [la teinte de la couleur]`

<br><br><br>

### <a id="p5"></a> 5. Dégradé
<div align="center">
<img height="200" src="images/README/exo5.png" title=""/>
<br>
<i>Version générée</i>
</div>

Ici l'image a été entièrement générée.\
Le pixel tout à gauche est noir, celui tout à droite est blanc.\
On divise la teinte blanche (1) par la longueur de l'image (300 ici), on obtient une valeur.\
Cela donne un calcul du type : `nuance_gris = valeur * x`, où quand x = 0, c'est noir, et quand x = longueur (donc 300), c'est blanc.\
On donne la même nuance de gris à toute la colonne, et on change automatiquement à chaque déplacement sur l'axe x puisque nous suivons la boucle imbriquée.
<br><br><br>

### <a id="p6"></a> 6. Miroir
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo6.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

# Lorem ipsum

<br><br><br>

### <a id="p7"></a> 7. Image bruitée
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo7.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

Lorsque nous parcourons l'image, nous avons 25% de chance que le pixel soit modifié (bruité).\
Lorsqu'il est décidé que ce pixel est bruité, on récupère une valeur aléatoire que nous donnons aux teintes rouges, vertes et bleues.\
\
Nous utilisons un seed afin qu'à chaque lancement du programme, nous obtenons la même suite aléatoire et donc le même résultat que sur l'image juste au dessus (version modifiée).

<br><br><br>

### <a id="p8"></a> 8. Rotation à 90°
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo8.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

# Lorem ipsum

<br><br><br>

### <a id="p9"></a> 9. RGB split
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo9.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

Pour illustrer : nous sommes sur un logiciel graphique comme Paint.NET.\
Chaque couleur est un calque. On décide de décaler le calque bleu à 30 pixels sur la gauche, le calque rouge à 30 pixels sur la droite.\
En faisant cela, nous obtenons la version modifiée affiché dans ce rapport.\
\
Il suffit juste de créé une nouvelle image (noir) et de placer de manière décalé, comme il est décrit, le pixel que nous avons récupéré sur l'image d'origine.

<br><br><br>

### <a id="p10"></a> 10. Luminosité
<div align="center">
<img height="200" src="images/logo.png" title=""/>
<img height="200" src="images/README/exo10.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

# Lorem ipsum à voir avec le professeur si c'est légal

<br><br>

#### <a id="p10-1"></a> 10.1 Éclaircissement
<div align="center">
<img height="200" src="images/photo.jpg" title=""/>
<img height="200" src="images/README/exo10_e.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

Lorem ipsum

<br><br>

#### <a id="p10-2"></a> 10.2 Assombrissement
<div align="center">
<img height="200" src="images/photo.jpg" title=""/>
<img height="200" src="images/README/exo10_a.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

Lorem ipsum

<br><br><br>

### <a id="p11"></a> 11. Disque
<div align="center">
<img height="200" src="images/README/noir.png" title=""/>
<img height="200" src="images/README/exo11.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

# Lorem ipsum à voir avec le professeur si c'est légal

<br><br><br>

### <a id="p12"></a> 12. Cercle
<div align="center">
<img height="200" src="images/README/noir.png" title=""/>
<img height="200" src="images/README/exo12.png" title=""/>
<br>
<i>Image originale et version modifiée</i>
</div>

# Lorem ipsum à voir avec le professeur si c'est légal

<br><br><br>
