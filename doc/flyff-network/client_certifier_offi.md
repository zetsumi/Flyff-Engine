# Certifier
Description de different interaction entre le `Client` et le `Certifier`.<br>

## Processus

### Test de connection
Le `Client` effectue un test de connection TCP uniquement via `connect` puis `close` la socket.<br>
Cela verifie uniquement que le serveur est ***en ligne***.<br>
```cpp
TestNetLib(g_Neuz.m_lpCertifierAddr, PN_CERTIFIER);
```

### PING PONG
Le client doit garder une connection ouverte avec le `Certifier` via un service de `PING PONG`.<br>
Cela permet de verifier que le `Client` est toujours a l'ecoute.<br>


### Login
Une fois que le joueur rentre un compte le `Client` se connect au `Certifier` et envoie le packet ***PACKETTYPE_CERTIFY***.<br>

| NAME          |      TYPE         |  DESCRIPTION                  |
|:----------    |:-------------:    |:------                        |
| BUILD VERSION |  string           | Le numero de build du serveur |
| LOGIN         |  string           | Le nom de compte              |
| PASSWORD      |  string           | Le mot de passe               |

Attention le ***PASSWORD*** est un assemblage de `kikugalanet` + le mot de passe du joueur, le tout haser ***MD5*** puis chiffrer via ***CRC32***.<br>

