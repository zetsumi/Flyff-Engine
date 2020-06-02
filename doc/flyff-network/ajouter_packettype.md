# Introduction

Guide permettant d'ajouter la lecture et l'ectire d'un paquet.<br>
La bibliotheque ___Flyff-Network___ permet de recevoir des paquets TCP et d'en envoyer.<br>
Les paquets sont classee en deux categorie ***PACKETTYPE*** et ***SNAPSHOTTYPE***(voir document snapshot.md et packet.md).<br>

# PACKETTYPE

## Reception
La reception d'un ***PACKETTYPE*** se fait a travers une classe heritant d'`HandlerMessage`.<br>
Dans notre exemple nous creons une classe `HandlerCustom`.<br>

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

        [[noreturn]] void	initialize(void) override
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

Dans notre exemple la classe `HandlerCustom` s'initialize via `initialize(void)`.<br>
La fonction `initialize` doit toujours etre creer et appeller apres avoir creer l'instance de l'object.<br>
Par defaut la classe `HandlerCustom`.<br> va reagir au PACKETTYPE par defaut de la classe `HandlerMessage`, ce traitement est gerer directement par `Flyff-Network`.<br>
<br>

Nous allons creer un ***PACKETTYPE*** ___PACKETTYPE_TEST_CUSTOM___ pour notre exemple.<br>
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

Ajouter une callback sur la PACKETTYPE. Il faut :
* Creer une structure acceuillent les donnees.
* Creer une fonction factory permettant de creer un pointeur sur la structure.
* Creation de la callback

___Creation de la structure___:
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
		inline PacketCustom& operator<<(fe::PacketBuilder& pb) override
		{
            var << pb;
            var2 << pb;
			FE_CONSOLELOG("var[%u] var2[%d]", var, var2);
			return *this;
		}
	};
}
```

___Creation de la factory :___
Si vous ajouter une factory pour ***login*** ==> `source\handler\login\packets\packet_logins.hpp`
Si vous ajouter une factory pour ***certifier*** ==> `source\handler\certifier\packets\packet_certifiers.hpp`
Si vous ajouter une factory pour ***cache*** ==> `source\handler\cache\packets_snap\packets_type.hpp.hpp`

```cpp
[[nodiscard]] inline fe::PacketMessage* packetCustom(void) { return new fe::PacketCustom(); }
```

___Creation de la callback dans `HandlerCustom` :___
Vous devez modifier la fonction `initailize` de votre classe `HandlerCustom`.<br>
```cpp
        [[noreturn]] void	initialize(void) override
        {
            fe::HandlerMessage::initialize();
	        packetOperator[fe::packet::PACKETTYPE::PACKETTYPE_TEST_CUSTOM] = std::bind(fe::packettype::packetCustom);
        }
```
Quand le client recevra le packettype `PACKETTYPE_TEST_CUSTOM` la fonction `fe::packettype::packetCustom` sera appeller puis la surcharge d'operator `<<`.<br>
Ce mechanisme de callback est gerer directement par `Flyff-Network`.<br>
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
Le message sera ajouter a la pile des messages. Votre classe contient une variable `std::queue` en privee.<br>
Afin d'acceder aux messages que vous avez recue vous devez utiliser la fonction `getPacket` dans votre client.<br>

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