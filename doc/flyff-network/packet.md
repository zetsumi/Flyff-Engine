# Packet Structure

## Structure d'un packet.

### Recue
| ID            |      OCTECT       |  DESCRIPTION          |
|:----------    |:-------------:    |:------                |
| HEADER MARK   |  1                | 0x5e, fixe            |
| LENGTH        |  4                | taille                |
| PACKETTYPE    |  4                | type du paquet        |
| DATA          |  LENGTH - 4       | donnee du paquet      |

### Envoie
| ID            |      OCTECT       |  DESCRIPTION          |
|:----------    |:-------------:    |:------                |
| HEADER MARK   |  1                | 0x5e, fixe            |
| SESSION ID1   |  4                | temps chiffrer        |
| LENGTH        |  4                | taille                |
| SESSION ID2   |  4                | temps chiffer         |
| PACKETTYPE    |  4                | type du paquet        |
| DPID          |  4                | identifiant client    |
| DATA          |  LENGTH - 4       | donnee du paquet      |


## ID
Description des différentes partie du paquet.

### HEADER MARK
Chaque paquet commence par une marque/séparateur.<br>
Cette valeur est fixe ! Elle vaut ***0x5e***, en ascii ***^***.<br>

### SESSION ID
Pas très claire pour le moment.<br>
Il semblerait que le serveur envoyant un timer se qui permettrait de restait synchro avec le serveur.<br>
Le ***SESSION ID1*** et ***SESSION ID2*** sont envoyé chiffré ! La methode est ***Crc32***.<br>

### LENGHT
La ***LENGTH*** représente la taille du paquette qu'il reste à lire avec l'octect contenant le ***LENGHT***.<br>
Cela permet d'ajuster la méthode [recv](https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv) afin de recevoir et rassembler l'information complète.<br>

### PACKETTYPE
Le ***PACKETTYPE*** est le nom de l'évènement que le client ou serveur veut communiquer.<br>
L'action à effectuer sur le programme est determiné via ce ***PACKETTYPE***.<br>

### DPID
Ou `Direct Player ID` représente un `ID` unique définie par la bilbiothèque [DirectPlay](https://docs.microsoft.com/en-us/previous-versions/windows/desktop/bb153243(v%3Dvs.85)) de DirectX 9.0.<br>
Il n'est pas présent dans les paquets envoyé entre le `Client` et le `Certifier`.<br>
`LoginServer` le recoit mais l'ignore.<br>
`CacheServer` l'utilise pour redistrubé les paquets vers le bon client.<br>

### DATA
La partie ***DATA*** représente les informations que le client ou serveur souhaite communiquer.<br>
Cette partie peut contenir des [type primitif](https://en.wikipedia.org/wiki/C_data_types) ou des type personnalite.<br>
Les données sont stockées en [little endian](https://en.wikipedia.org/wiki/Endianness).<br>
