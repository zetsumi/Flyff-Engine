# Certifier
Description de different interaction entre le `Client` et le `Certifier`.<br>

## Processus
Le `Client` garde une connection avec le `Certifier` durant la phase de connection.<br>
Une fois que le `Client` a recue la liste de joueurs via le `LoginSever` ***PACKETTYPE_PLAYER_LIST*** la connection se ferme.<br>

### Test de connection
Le `Client` effectue un test de connection TCP uniquement via `connect` puis `close` la socket.<br>
Cela verifie uniquement que le serveur est ***en ligne***.<br>
```cpp
TestNetLib(g_Neuz.m_lpCertifierAddr, PN_CERTIFIER);
```

### PING PONG
Cela permet de verifier que le `Client` est toujours a l'ecoute.<br>
Un message paquette ***PACKETTYPE_PING*** doit etre envoyer toutes les minutes.<br>


### KEEP ALIVE
Le serveur envoie regulierement un paquet ***PACKETTYPE_KEEP_ALIVE***.<br>
Il s'attend que le client lui retourne aussi un paquet ***PACKETTYPE_KEEP_ALIVE***.<br>
Le paquet envoyer et envoyer ne contient aucune ***DATA***.<br>

### Login
Une fois que le joueur rentre un compte le `Client` se connect au `Certifier` et envoie le packet ***PACKETTYPE_CERTIFY***.<br>

| NAME          |      TYPE         |  DESCRIPTION                  |
|:----------    |:-------------:    |:------                        |
| BUILD VERSION |  string           | Le numero de build du serveur |
| LOGIN         |  string           | Le nom de compte              |
| PASSWORD      |  string           | Le mot de passe               |

Attention le ***PASSWORD*** est un assemblage de `kikugalanet` + le mot de passe du joueur, le tout haser ***MD5*** puis chiffrer via ***CRC32***.<br>

### SERVEUR LISTE
Une fois connecter le serveur envoie un paquet ***PACKETTYPE_SRVR_LIST*** contenant la liste des serveur et channels.<br>
| NAME          |      TYPE         |  DESCRIPTION                              |
|:----------    |:-------------:    |:------                                    |
| AUTH KEY      |  unsigned __int32 | La clef d'authentification                |
| ACCOUNT FLAG  |  unsigned char    | flag du compte                            |
| ACCOUNT       |  string           | Le compte du joueur                       |
| NUMBER SERVER |  unsigned __int32 | Le total de serveur + channels            |
| INFORMATION   |  structure        | Information sur les serveur et channels   |

Enfin de recuperer les ***INFORMATIO*** il faut boucler sur ***NUMBER SERVER***.<br>
***INFORMATION*** struture :

| NAME          |      TYPE         |  DESCRIPTION                  |
|:----------    |:-------------:    |:------                        |
| PARENT        |  unsigned __int32 | identifiant du parent         |
| ID            |  unsigned __int32 | identifiant                   |
| NAME          |  string           | nom                           |
| ADDR          |  string           | adresse ip                    |
| ...           |  unsigned __int32 | ...                           |
| COUNT         |  unsigned __int32 | Nombre de client connecter    |
| ENABLE        |  unsigned __int32 | En ligne ou Hors ligne        |
| MAX           |  unsigned __int32 | Nombre maximun de client      |
