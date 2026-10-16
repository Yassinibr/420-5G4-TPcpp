# TP C++ - Gestion de bibliothèque

**Nom :** Yassin Ibrahim

## Fonctionnalités ajoutées

* **ID automatique :** quand on ajoute un utilisateur, le programme lui donne automatiquement un ID.
* **Tri des livres :** les livres sont affichés en ordre alphabétique selon leur titre.
* **Journal d'activités :** les actions importantes sont enregistrées dans `activity.log`. Les nouvelles actions s'ajoutent à la suite des anciennes.
* **Correction de sauvegarde :** si aucun dossier de données n'est donné au lancement, le programme affiche un message et n'essaie pas de sauvegarder dans un chemin vide.

## Question 1 - C++

J'ai utilisé `std::sort` pour trier les livres par titre. Cette fonction fait partie de la bibliothèque standard du C++ et se trouve dans `<algorithm>`. Dans mon projet, je l'utilise dans `library.cpp` pour mettre les livres en ordre alphabétique. Pour faire le tri, je compare le titre de deux livres avec `getTitle()`. Si le premier titre vient avant le deuxième, il sera placé avant lui. Ça permet d'avoir une liste plus facile à consulter sans devoir trier les livres manuellement.

## Question 2 - Une autre solution pour la bibliothèque

Si la bibliothèque avait des millions de livres, je choisirais PostgreSQL pour stocker les données au lieu de tout garder dans des fichiers texte. Une base de données serait plus pratique pour chercher des livres, gérer les utilisateurs et suivre les emprunts. Je pourrais garder le programme en C++ et utiliser une bibliothèque comme `libpq` pour communiquer avec PostgreSQL. Le programme enverrait des requêtes SQL pour ajouter ou rechercher des livres, et la base de données retournerait les résultats. On pourrait aussi ajouter des index pour rendre les recherches plus rapides. Je trouve que cette solution serait plus adaptée si la bibliothèque devenait très grande.