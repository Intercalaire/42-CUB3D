/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgobet <rgobet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 04:18:10 by vgodart           #+#    #+#             */
/*   Updated: 2024/08/28 09:40:26 by rgobet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*        CE QUIL CA FALLOIR FAIRE ET POURQUOI           

doc daide: https://lodev.org/cgtutor/raycasting.html + son fichier cpp avec le code et qql explications
aide2 (github): https://github.com/iciamyplant/Cub3d-Linux/blob/master/README.md
github https://github.com/Asalek/cub3D/blob/main/mandatory/rayCasting/ray_calculation.c#L15 voir son .h pour les fonctions qql explications, (jsp si c'est la meme personne mais le github est inspire du doc d'aide)
ytb https://www.youtube.com/watch?v=gYRrGTC7GtA un peu chiant car pas mlx
un v-word kesako ??? https://youtu.be/gID_FKfncZI?si=81TdqYQk7TQ5dQFh


le raycaster est appeler dans une fonction qui gere l'affichage de la map, ( voir mini-explication phrase du dessous )
.tout ce qui se trouve apres se sitout dans une boucle (appel de plusieurs fonctions): globalement la boucle parcourt la map, et pour chaque colonne de pixel on calcule la distance du rayon et on dessine le mur correspondant

double planeX = 0, planeY = 0.66; // le plan de la camera est perpendiculaire a la direction du joueur

ici deltaDistX et deltaDistY sont les distances que le rayon doit parcourir pour passer d'une case a l'autre en x et en y.
	double rayDirX = dirX + planeX * cameraX;
	double rayDirY = dirY + planeY * cameraX;

  #les valeur de pour la cameraX peuvent etre calculees de cette facon :
  cameraX = 2 * x / w - 1; // x est la position du pixel actuel sur l'ecran et w est la largeur de l'ecran soit 
  ou  cameraX = 2 * x / (double)X_AXIS - 1;   X_AXIS est la longueur de l'ecran si x represente les abscisses (attention peut etre l'inverse mais)

  TOUT CE QUI EST X_AXIS ET Y_AXIS, ROTATE_SPEED PEUT ETRE A DEFINIR DANS LE FICHIER CUB3D.H


	si les rayons ne sont pas 0 alors on calcule les deltaDistX et deltaDistY (attention au division par 0 if OBLIGATOIRe)
	deltaDistX = fabs(1 / rayDirX);
	deltaDistY = fabs(1 / rayDirY);
	definition fabs : elle retourne la valeur absolue d'un nombre à virgule flottante. du style fabs(-10.25) retourne +10.25 /et/ fabs(+10.25) retourne +10.25
	sinon (si rayons == 0) alors
		deltaDistX = 1e30; ou 7728; (sur le doc c'est 1e30 mais sur le github c'est 7728 avec une mention a 1e30)
		deltaDistY = 1e30; ou 7728; (sur le doc c'est 1e30 mais sur le github c'est 7728 avec une mention a 1e30)
		note : 1e30 est un nombre assez grand pour eviter les divisions par 0, c'est un nombre arbitraire et tres grand qui est utilise pour representer l'infini en informatique

->  Faire une fonction de deplacement pour le raycaster pour calculer les coordonnees du rayon

if(rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - posX) * deltaDistX;
      }
      if(rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - posY) * deltaDistY;
      }
	while ("ne touche pas le mur alors on passe a la case suivante") "== on avance le rayon"
	
	    if(sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        "regarder si le rayon touche un mur"
        if(worldMap[mapX][mapY] > 0) 
			hit = 1; "hit represente si le rayon a touche un mur (la condition de la boucle while)"
		"si le rayon touche un mur alors on calcule la distance du mur"
		if(side == 0)
		  perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX; ou de facon plus simple perpWallDist = (sideDistX - deltaDistX)
		else
		  perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY; ou de facon plus simple perpWallDist = (sideDistY - deltaDistY)
		"pour comprendre les version simplifiees il faut comprendre la formule de la distance du mur, je te conseille d'aller voir le doc d'aide mais en gros c'est une formule de math tah les fou
		si tu as extremement besoin je peux essayer de te l'expliquer et de la demontrer mais va falloir que je my mette bien (ca me derange pas mais laisse moi le temps de demander a des gens et tout avant)"
		ensuite :

		je continurais demain pour comprendre en profondeut le reste du code surtout que sur le doc le code est surper court mais long sur le github (ils ont quand meme la meme facon de proceder)

		"calcul de la hauteur du mur"
		lineHeight = (int)(h / perpWallDist); ou h est la hauteur de l'ecran
		"calcul des limites du mur"
		ensuite on dessine le mur
		drawStart = -lineHeight / 2 + h / 2;


    ROTA_CAM 
    "rotation de la camera"
    si touche gauche
      alors la dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed); 
      et dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      et planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed); 
      et planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    si touche droite
      alors la dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed); 
      et dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      et planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed); 
      et planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);

    .ici oldDirX et oldPlaneX sont les valeurs de dirX et planeX avant la rotation, logique
    .dirX et dirY sont les coordonnees de la direction du joueur (Vecteur de direction)
    .planeX et planeY sont les coordonnees du plan de la camera (Vecteur du plan)



	xPixel =((i+0.5) / WIDTH − 0.5)× largeur du plan

	largeur du plan=2×tan( FOV/2 )×distance au plan(SCREEN)
	distance au plan est la distance entre la caméra et le plan de l'image.
	qui est SCREEN

	DirX = PosX + xPixel
	DirY = PosY + WALL_HEIGHT
​
	# Calculer la longueur du vecteur
	length = np.sqrt(D_x**2 + D_y**2 + D_z**2) < z useless
	length = np.sqrt(D_x**2 + D_y**2) // fonctionnelle

	# Normaliser le vecteur
	D_x_normalized = D_x / length
	D_y_normalized = D_y / length
	D_z_normalized = D_z / length <- useless
​
 
*/