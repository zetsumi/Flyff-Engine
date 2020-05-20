# Flyff-Engine

## ![](https://img.icons8.com/color/24/000000/creative-commons--v1.png) License
Le code source et l'application elle-même sont destinés à être utilisés en fonction de la pièce jointe [license](./LICENSE.md).<br>
![](https://mirrors.creativecommons.org/presskit/buttons/88x31/svg/by-nc-sa.svg)><br>

/!\ Ce projet n'est pas affilié avec ***Gala Lab*** /!\\.

> Designed by Zetsumi.</br>

### Cibles
`Windows 10`.<br>
`Visual Studio 2019`.<br>
`C++` >= `17`.<br>

***Flyff Ressource***
Projet permettant de chargé les fichier crééer par [Flyff-Script](https://github.com/zetsumi/Flyff-Scripts).<br>

***Flyff Network***
/!\ Ce projet n'est pas affilié avec ***Eastrall*** /!\\.<br>
Projet permettant de communiquer avec les serveurs flyffs v15 ou [Rhisis](https://github.com/Eastrall/Rhisis).<br>


## <img src="https://raw.githubusercontent.com/isocpp/logos/master/cpp_logo.png" width="40" height="40"> <img src="https://upload.wikimedia.org/wikipedia/commons/c/c7/Windows_logo_-_2012.png" width="40" height="40"> <img src="https://fr.wikipedia.org/wiki/Fichier:Flyff_logo.svg" width="40" height="40">
[![forthebadge](http://forthebadge.com/images/badges/built-with-love.svg)](http://forthebadge.com)</br>
[![discord](https://discordapp.com/api/guilds/294405146300121088/widget.png)](https://discord.gg/fZP7TWq)</br>


### Organisation Répertoire Source :
* ___source___
    * ___io___
        * ___file___ : Permet l'abstraction de chargement et lecture des fichiers.
        * ___network___ : Gestion de la socket reseau.
            * ___emit___ : Gestion des envoies et reception des paquets.
    * ___project___ : Regroupement de la logique de stockage et d'utilsation des propriété chargé.
        * ___loader___ : Logique et structure de chargement d'un fichier.
    * ___property___ : Structure des différentes propriétés.
    * ___handler___ : Gestionnaire d'évenement
    * ___util___ : Ensemble de fonction utile dans toutes circontances.
    * ___crypto___ : Outil de chiffrement et hash.
    * ___third_party___ : Ensemble de code source externe.
        * ___json___ : Manipulation des fichiers JSON.
        * ___xml___ : Manipulation des fichiers XML.

### Organisation Répertoire Exemples :
* ___resource___ : Fichier de test valide
    * ___json___
    * ___xml___
    * ___header___
    * ___text___
* ___samples___ : Suite d'exemple d'utilisation de Flyff-Engine
    * ___Properties___ : Exemple de chargement et d'utilisation des propriété
    * ___ClientTest___ : Exemple de communication avec les serveurs.
