# Certifier
Description de différent interaction entre le `Client` et le `Certifier`.<br>

## Processus
Le `Client` garde une connection avec le `Certifier` durant la phase de connection.<br>
Une fois que le `Client` a reçue la liste de joueurs via le `LoginSever` ***PACKETTYPE_PLAYER_LIST*** la connection se ferme.<br>

### Test de connection FLYFORFUN
Le `Client` effectue un test de connection via `connect` puis `close` la socket.<br>
Cela verifie uniquement que le serveur est ***en ligne***.<br>
```cpp
TestNetLib(g_Neuz.m_lpCertifierAddr, PN_CERTIFIER);
```

### PING PONG
Cela permet de vérifier que le `Client` est toujours à l'écoute.<br>
Un message ***PACKETTYPE_PING*** doit tre envoyer toutes les minutes.<br>

### KEEP ALIVE
Le serveur envoie régulièrement un paquet ***PACKETTYPE_KEEP_ALIVE***.<br>
Il s'attend que le client lui retourne aussi un paquet ***PACKETTYPE_KEEP_ALIVE***.<br>
Le paquet envoyer et reçue ne contient aucune ***DATA***.<br>

### Login
Une fois que le joueur rentre un compte le `Client` se connect au `Certifier` et envoie le packet ***PACKETTYPE_CERTIFY***.<br>

| NAME          |      TYPE         |  DESCRIPTION                  |
|:----------    |:-------------:    |:------                        |
| BUILD VERSION |  string           | Le numero de build du serveur |
| LOGIN         |  string           | Le nom de compte              |
| PASSWORD      |  string           | Le mot de passe               |
<br>
> Attention le ***PASSWORD*** est un assemblage de `kikugalanet` + le mot de passe du joueur, le tout hash en ***MD5*** puis chiffré via ***CRC32***.<br>

### SERVEUR LISTE
Une fois connecté le serveur envoie un paquet ***PACKETTYPE_SRVR_LIST*** contenant la liste des serveurs et channels.<br>
| NAME          |      TYPE         |  DESCRIPTION                              |
|:----------    |:-------------:    |:------                                    |
| AUTH KEY      |  unsigned __int32 | La clef d'authentification                |
| ACCOUNT FLAG  |  unsigned char    | flag du compte                            |
| ACCOUNT       |  string           | Le compte du joueur                       |
| NUMBER SERVER |  unsigned __int32 | Le total de serveur + channels            |
| INFORMATION   |  structure        | Information sur les serveur et channels   |
<br>
> Enfin de recuperer les ***INFORMATION*** il faut boucler sur ***NUMBER SERVER***.<br>
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
