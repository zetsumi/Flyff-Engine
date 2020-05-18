# Certifier

## Test Connection
Le client effectue un test de connection via `Certifier`.<br>
```cpp
TestNetLib(g_Neuz.m_lpCertifierAddr, PN_CERTIFIER);
```
Le test consiste a se `connecter` puis de se `deconnecter`.<br>
Cela verifie uniquement que le serveur est ***Online***.<br>

## Login
Une fois que le joueur rentre un compte le client se connect au `Certifier` et envoie le packet ***PACKETTYPE_CERTIFY***.
