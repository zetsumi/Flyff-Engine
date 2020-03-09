# Flyff-Engine

> Designed by Zetsumi </br>
> Projet permettant de chargé les fichier crééer par [Flyff-Script](https://github.com/zetsumi/Flyff-Scripts)

# Organisation Repertoire Exemples :
* resource : Fichier de test valide
    * json
    * xml
    * header
    * text
* samples : Suite d'exemple d'utilisation de Flyff-Engine
    * Properties : Exemple de chargement et d'utilisation des propriété


# Organisation Repertoire Source :
* source
    * io
        * file : permet l'abstraction de chargement et lecture des fichiers
    * project : Regroupement de la logique de stockage et d'utilsation des propriété chargé
        * loader : Logique et structure de chargement d'une fichier
    * property : Structure des différentes propriétés à chargé
    * third_party : Ensemble de code source permettant la réalisation du projet
        * json : Manipulation des fichiers JSON
        * xml : Manipulation des fichiers XML


# Avancemenet:
- [x] Abstraction du chargement des fichiers JSON
- [x] Abstraction du chargement des fichiers XML
- [x] Mise en place de la logique de chargement des fichier produits par Flyff-Script
- [x] Stocker et recupérer des valeurs stocker

# TODO :
- [ ] Test unitaire
- [ ] Utilisation d'au moins deux bibliotheque différent pour le JSON
- [ ] Utilisation d'au moins deux bibliotheque différent pour le XML
- [ ] Utilisation d'au moins deux bibliotheque différent pour le CSV
- [ ] Mise en place d'un benchmark


 