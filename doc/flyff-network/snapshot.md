# Snapshop

Les snapshot sont des paquets envoyee depuis le `WorldServer` decrivant une action passee.<br>
Le snapshot sont encapsuler dans le type de paquet ***PACKETTYPE_SNAPSHOT***.<br>
<br>

Un snapshot contient toujours l'identifiant de l'objet !<br>
Pour les snapshot nous pouvons suivre la logique suivante :<br>
<br>
4 octects --> Identifiant Joueur<br>
2 octects --> Le nombre de snapshot recue<br>
whille {nombre de snapshot}<br>
    4 octects --> L'identifiant de l'objet<br>
    2 octects --> le type du snapshot<br>
    X octects --> La donnee envoyer<br>
<br>
Nous ne pouvons pas savoir la taille des donnee liee a 1 snapshot.<br>
Il faut connaitre les donnees envoyee.<br>

