# Flyff Network
/!\ Ce projet n'est pas affilié avec ***Eastrall*** /!\<br>
Projet permettant de communiquer avec les serveurs fly for fun v15 ou [Rhisis](https://github.com/Eastrall/Rhisis).<br>

Flyff-Network est une bibliothèque dynamique écrie en C++ 17.<br>
Elle permet d'effectuer la communication réseau entre un programme et les serveur flyf for fun v15.<br>

# Structure
La bibliothèque est séparé en 2 partie. `network` et `handler`.<br> `Network` permet d'effectuer des communication basique en regle particulière entre deux programme en TCP.<br>
`Handler` extrait les données recue provenant d'un serveur fly for fun. Il connait la structure des paquets reçue et peut en envoyé.<br>
<br>

Network est composé des objets :
* fe::Network
* fe::Socket
* fe::Transaction
* fe::PacketBuilder
* fe::PacketStrucutre
<br>

Ces objets permettent de recréer une communication entre deux programme en TCP.<br>
`fe::Network` stock uniquement les `adresse ip` et le `port`.<br>
`fe::Socket` est une abstraction pour `SOCKET`.<br>
`fe::Transaction` permet d'abstraire le méchanisme d'envoie et de reception des paquets.<br>
Handler est un composant permettant de recevoir et d'envoyer des paquets au serveurs.

# Processus
Effectuer le processus de `fe::Transaction` créer un thread permettant de recupérer les paquet en [asynchrone](https://eduscol.education.fr/numerique/dossier/archives/eformation/notion-de-temps/synchrone-asynchrone).<br>
Chaque paquet reçue est traité en [synchrone](https://eduscol.education.fr/numerique/dossier/archives/eformation/notion-de-temps/synchrone-asynchrone), la reception appel la `handlerCallBack` passé en paramètre à `e::Transaction::run`.<br>
<br>

Un `Handler` construction la liste de ces callbaks via `initialize`.<br>
Le programme peut `attendre` ou non la fin thread au via `fe:Transaction::wait(true)`.<br>
<br>

Lorsqu'un `handler` recoit le paquet ***PACKETTYPE_WELCOM*** un thread est automiquement créer, il permet de gérer le process ***PIGN***.<br>

Exemple :
`connect_server_custom.cpp`
<br>

```cpp
bool connection_server(void)
{
	fe::Network network{};
    fe::Socket _socket{};
    fe::Transaction trans{};
    fe::HandlerCustom custom{}; // Herite de fe::HandlerMessage

    // Set l'IP et le port utiliser.
	_socket.setIP("127.0.0.1");
	_socket.setPort(28000);
	if (network.isValid() == false)
		return false;

    // Connection vers le serveur.
	if (_socket.connect(network) == false)
		return false;

    // Initialisation de trans.
	if (trans.setSocket(&_socket) == false)
		return false;
	trans.setMode(fe::MODE_TRANSACTION::MODE_CLIENT);

    // Initialisation du handler custom.
	custom.initialize();
	custom.setTransaction(&trans);

    // Lancement du processus de transaction du client.
    // Set la callback dans le cas de reception de paquets.
	auto onMsg = std::bind(&fe::HandlerMessage::onMsg, &custom, std::placeholders::_1, std::placeholders::_2);
	if (trans.run(onMsg) == false)
		return false;

    // On attend que le thread se detruit.
	trans.wait();
}
```