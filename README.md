# My_World
Editeur de monde en CSFML en 3D

COMPILATION

    make

USAGE

    ./my_world [map]


DESCRIPTION

    [map] fichier contenant une carte à charger. Encodage de la carte décrit dans le fichier .legend

CONTROLES

    [ZQSD] Rotation de la caméra
    [Souris] Interactions avec la carte. Cliquez sur les boutons pourr changer d'outils !
    
    Outils disponibles:
        - Cliquez sur un point afin de mofifier sa hauteur
        - Cliquez sur un point et maintenez, puis déplacez vous pour applatir la hauteur des points adjacents
        - Changer la texture de la tuile

Projet EPITECH réalisé par Edouard CHHANG et Maxime SENARD

Répartition des tâches :

Edouard CHHANG : Affichage 3D, Outils de terraformation, Caméra

Maxime SENARD : Ecran d'acceuil, Boutons, HUD, parser de boutons
