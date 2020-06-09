# Snapshop

Les snapshot sont des paquets envoyés depuis le `WorldServer` décrivant une action passée.<br>
Le snapshot sont encapsulé dans ***PACKETTYPE_SNAPSHOT***.<br>

<br>
Un snapshot contient toujours l'identifiant de l'objet ___objid___ !<br>
Pour les snapshot nous pouvons suivre la logique suivante :<br>

<br>
4 octects --> Identifiant Joueur<br>
2 octects --> Le nombre de snapshot reçue<br>
while {nombre de snapshot}<br>
    4 octects --> L'identifiant de l'objet<br>
    2 octects --> le type du snapshot<br>
    X octects --> La donnee envoyer<br>

<br>
Nous ne pouvons pas savoir la taille des donnée liée à 1 snapshot.<br>
Il faut connaître les données envoyé.<br>
