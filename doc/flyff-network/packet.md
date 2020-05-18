# Packet Structure

## Structure d'un packet.
| ID            |      OCTECT       |  DESCRIPTION      |
|:----------    |:-------------:    |:------            |
| HEADER MARK   |  1                | 0x5e, fixe        |
| SESSION ID1   |  4                | temps chiffrer    |
| LENGTH        |  4                | taille            |
| SESSION ID2   |  4                | temps chiffer     |
| PACKETTYPE    |  4                | type du paquet    |
| DATA          |  LENGTH - 4       | donnee du paquet  |

## ID
Description des differentes partie du paquet.

### HEADER MARK
Chaque paquet commence par une marque/separateur.<br>
Cette valeur est fixe ! Elle vaut ***0x5e***, en ascii ***^***.<br>

### SESSION ID
Pas tres claire pour le moment.<br>
Il semblerait que le serveur envoyant un timer se qui permettrait de restait synchro avec le serveur.<br>
Le ***SESSION ID1*** et ***SESSION ID2*** sont envoyer chiffree ! La methode est ***Crc32***.<br>

### LENGHT
La ***LENGTH*** represente la taille du paquette qu'il reste a lire avec l'octect contenant le ***LENGHT***.<br>
Cela permet d'ajuster la methode [recv](https://docs.microsoft.com/en-us/windows/win32/api/winsock/nf-winsock-recv) afin de recevoir et ressembler l'information complete.<br>

### PACKETTYPE
Le ***PACKETTYPE*** est le nom de l'evenement que le client ou serveur veut communiquer.<br>
L'action a effectuer sur le programme est determiner via ce ***PACKETTYPE***.<br>

### DATA
La partie ***DATA*** represente la partie les informations que le client ou serveur souhaite communiquer.<br>
Cette partie peut contenur des [type primitif](https://en.wikipedia.org/wiki/C_data_types) ou des type personnalite.<br>
Les donnee sont stocker en [little endian](https://en.wikipedia.org/wiki/Endianness).<br>
