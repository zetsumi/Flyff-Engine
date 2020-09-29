# Introduction

Guide permettant d'ajouter la lecture et l'écriture d'un paquet.<br>
La bibliothèque ___Flyff-Network___ permet de recevoir des paquets TCP et d'en envoyer.<br>
Les paquets sont classée en deux catégories ***PACKETTYPE*** et ***SNAPSHOTTYPE*** (voir document snapshot.md et packet.md).<br>

# PACKETTYPE

## Réception
La réception d'un ***PACKETTYPE*** se fait à travers une classe heritant d'`HandlerMessage`.<br>
Dans notre exemple nous créons une classe `HandlerCustom`.<br>
```cpp
#pragma once

#include <framework_fengine.h> // framework flyff engine
#include <io/network/message/handler_message.hpp> // objet HandlerMessage
#include <io/network/message/packet_message.hpp> // Liste des PACKETTYPE

namespace fe
{
	class HandlerCustom : public HandlerMessage
	{
		HandlerLogin() = default;
		~HandlerLogin() = default;

        void	initialize(void) override
        {
            fe::HandlerMessage::initialize();
        }
    }
}

int main()
{
    // Initialisation des socket
    HandlerCustom hc;
    hc.initialize();
    // Initialisation des callback reseau
    return 0;
}
```
La classe `HandlerCustom` s'initialize via `initialize(void)`.<br>
La fonction `initialize` doit toujours être créer et appellé apres avoir créer l'instance de l'object.<br>
Par défaut la classe `HandlerCustom` va reagir au ***PACKETTYPE*** déjà listé dans `HandlerMessage`, ce traitement est gérer directement par `Flyff-Network`.<br>

<br>
Nous allons ajouter la lecture d'un ***PACKETTYPE*** ___PACKETTYPE_TEST_CUSTOM___ pour notre exemple.<br>
```cpp
namespace fe
{
	namespace packet
	{
		enum class PACKETTYPE : fe::type::_32uint
		{
			PACKETTYPE_TEST_CUSTOM = 0x123456
		}
    	}
}
```
<br>

Pour ajouter une callback sur le ***PACKETTYPE***.<br>
Il faut :
* Créer une structure acceuillent les données.
* Créer une fonction factory permettant de créer un pointeur sur la structure.
* Création de la callback

___Création de la structure___:
```cpp
#pragma once

namespace fe
{
	struct PacketCustom : public PacketMessage
	{
		fe::type::_32int var = 0;
		fe::type::_32int var2 = 0;

		PacketCustom() = default;
		~PacketCustom() = default;
		PacketCustom& operator<<(fe::PacketBuilder& pb) override
		{
			var << pb;
			var2 << pb;
			FE_CONSOLELOG("var[%u] var2[%d]", var, var2);
			return *this;
		}
	};
}
```

___Création de la factory :___
Si vous ajouter une factory pour ***login*** ==> `source\handler\login\packets\packet_logins.hpp`
Si vous ajouter une factory pour ***certifier*** ==> `source\handler\certifier\packets\packet_certifiers.hpp`
Si vous ajouter une factory pour ***cache*** ==> `source\handler\cache\packets_snap\packets_type.hpp.hpp`

```cpp
[[nodiscard]] fe::PacketMessage* packetCustom(void) { return new fe::PacketCustom(); }
```

___Création de la callback dans `HandlerCustom` :___
Vous devez modifier la fonction `initailize` de votre classe `HandlerCustom`.<br>
```cpp
void	initialize(void) override
{
    fe::HandlerMessage::initialize();
    packetOperator[fe::packet::PACKETTYPE::PACKETTYPE_TEST_CUSTOM] = std::bind(fe::packettype::packetCustom);
}
```
Quand le client recevra le packettype `PACKETTYPE_TEST_CUSTOM` la fonction `fe::packettype::packetCustom` sera appeller.<br>
Votre strucutre se remplie via la surcharge opérator `<<`.<br>
Ce mechanisme de callback est gérer directement par `Flyff-Network`[msghander](https://github.com/zetsumi/Flyff-Engine/blob/master/source/io/network/message/handler_message_recv.cpp).<br>
___Exemple :___
```cpp
fe::PacketBuilder pb;
// set pb...
if (packeType == PACKETTYPE_TEST_CUSTOM)
{
    auto it = packetOperator.find(packeType);
    fe::PacketMessage* msg = nullptr;
    msg = it->second();
    *msg << pb;
}
```
Le message sera ajouté à la pile des messages.<br>
Votre classe contient une variable `std::queue` en `private`.<br>
Afin d'acceder aux messages que vous avez reçue vous devez utiliser la fonction `getPacket` dans votre client.<br>
___Exemple :___
```cpp
int main()
{
    // Initialisation des socket
    HandlerCustom hc;
    hc.initialize();
    // Initialisation des callback reseau

    std::thread([hc]()
        {
            while (true)
            {
                auto msg = hc.getPacket();
            }
        }
    );

    return 0;
}
```
Vous pouvez aussi voir directement le fichier `main.cpp` du sample `ClientTest`.<br>
