# Packet Structure

Structure d'un packet.

| ID            |      OCTECT       |  DESCRIPTION      |
|:----------    |:-------------:    |:------            |
| HEADER MARK   |  1                | 0x5e, fix         |
| SESSION ID    |  4                | temps chiffrer    |
| LENGTH        |  4                | taille            |
| SESSION ID    |  4                | temps chiffer     |
| PACKETTYPE    |  4                | type du paquet    |
| DATA          |  LENGTH - 4       | donnee du paquet  |
