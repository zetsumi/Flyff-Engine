# Login
Description des différentes interaction entre le `Client` et le `LoginServer`.<br>

## Processus
Le `Client` garde une connection avec le `LoginServer` durant la phase de connection.<br>

### SEND
Liste des paquets que le `Client` envoie au `LoginServer`.<br>

#### Tick Count
Apres c'être connecté au `LoginServer` le `Client` envoie un paquet ***PACKETTYPE_QUERYTICKCOUNT***.<br>
| NAME              |      TYPE         |  DESCRIPTION      |
|:----------        |:-------------:    |:------            |
| TIMER CURRENT     |  unsigned __int32 | le temps actuel   |

	ar << (DWORD)timeGetTime();
#### Get List Player
Après c'être synchroniser avec lec serveur (connection + Tick Count) le `Client` demande la liste des joueurs du compte via ***PACKETTYPE_GETPLAYERLIST***.<br>

| NAME              |      TYPE         |  DESCRIPTION                  |
|:----------        |:-------------:    |:------                        |
| PROTOCOL VERSION  |  string           | ...                           |
| AUTH KEY          |  unsigned __int32 | Clef d'authentification       |
| ACCOUNT           |  string           | Login du compte               |
| PASSWORD          |  string           | Le mot de passe               |
| ID                |  unsigned __int32 | Le mot de passe               |

***AUTH KEY*** est recupéré via `Certifier` dans le paquet ***PACKETTYPE_SRVR_LIST***. Une étape de vérification est donc déclencher.<br>

### RECEIVE
Liste des paquets que le `LoginServer` envoie au `Client`.<br>

### PACKETTYPE_PLAYER_LIST
Liste des joueurs
