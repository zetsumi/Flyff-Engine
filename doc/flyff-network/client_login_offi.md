# Login
Description de different interaction entre le `Client` et le `LoginServer`.<br>

## Processus

### SEND
Liste des paquets que le `Client` envoie au `LoginServer`.<br>

#### Tick Count
Apres c'etre connect au connecter le `Client` envoie un paquet ***PACKETTYPE_QUERYTICKCOUNT***.<br>
| NAME              |      TYPE         |  DESCRIPTION      |
|:----------        |:-------------:    |:------            |
| TIMER CURRENT     |  unsigned __int32 | le temps actuel   |

	ar << (DWORD)timeGetTime();
#### Get List Player
Apres c'etre synchroniser avec lec serveur (connection + Tick Count) le `Client` demande la liste des joueurs du compte.<br>
Le paquet ***PACKETTYPE_GETPLAYERLIST***.<br>
| NAME              |      TYPE         |  DESCRIPTION                  |
|:----------        |:-------------:    |:------                        |
| PROTOCOL VERSION  |  string           | ...                           |
| AUTH KEY          |  unsigned __int32 | Clef d'authentification       |
| ACCOUNT           |  string           | Login du compte               |
| PASSWORD          |  string           | Le mot de passe               |
| ID                |  unsigned __int32 | Le mot de passe               |

***AUTH KEY*** est recuperer via `Certifier` dans le paquet ***PACKETTYPE_SRVR_LIST***.<br>


### RECEIVE
Liste des paquets que le `LoginServer` envoie au `Client`.<br>

### PACKETTYPE_PLAYER_LIST
Liste des joueurs
