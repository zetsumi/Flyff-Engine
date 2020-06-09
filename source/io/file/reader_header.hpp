#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>

#include <framework_fengine.h>
#include <io/file/reader.hpp>

#pragma warning( disable: 4251 )
namespace fe
{
    /**
     * @brief Objet permet de charge et manipuler les HEADER
     * Les HEADER dans flyff sont à l'origine des fichier .h permet de faire le lien entre les macro utilise dans le code et les fichier de configuration.
     * Les HEADER sont une sucession de define C++.
     * #define PROP 1
     * 
     */
    class API_DECLSPEC ReaderHeader
    {
        std::unordered_map<std::string, fe::type::_uint>    defines = {};

        /**
         * @brief Verifie la chaîne de caractère est bien un format HEADER.
         * Si la ligne contient un define une clef et une valeur (#define PROP 1)
         * 
         * @param line Chaîne de caractère devant un define et une valeur
         * @return true 
         * @return false 
         */
        bool    isValidLineHeader(const std::string& line) const noexcept;
        /**
         * @brief Supprime les charactère inutile dans la chaîne de caractère.
         * Permet de purifier la chaîne de caractère pour un traitement plus simple et rapide.
         * 
         * @param line Chaîne de cractère à traiter
         */
        void    removeEmpty(std::string& line) const noexcept;
        /**
         * @brief Charge un fichier au format HPP (référence au C++)
         * 
         * @param fileName Nom du fichier d'entrée
         * @return true 
         * @return false 
         */
        bool    loadFromHeaderHPP(const std::string& fileName) noexcept;
        /**
         * @brief Charge un fichier au format JSON
         * 
         * @param fileName Nom du fichier d'entrée
         * @return true 
         * @return false 
         */
        bool    loadFromJSON(const std::string& fileName) noexcept;
        /**
         * @brief Charge un fichier au format XML
         * 
         * @param fileName Nom du fichier d'entrée
         * @return true 
         * @return false 
         */
        bool    loadFromXML(const std::string& fileName) noexcept;
    public:
        ReaderHeader(const ReaderHeader* o) : ReaderHeader(*o)
        {
        }
        ReaderHeader() = default;
        ReaderHeader(const ReaderHeader&) = default;
        ReaderHeader(ReaderHeader&&) noexcept = default;
        ReaderHeader& operator=(const ReaderHeader&) = default;
        ReaderHeader& operator=(ReaderHeader&&) = default;
        virtual ~ReaderHeader() = default;

        /**
         * @brief Charge les fichier et stocke les valeurs.
         * Le format de lecture est donnée en paramètre
         * 
         * @param fileName Nom du fichier d'entrée
         * @param mode Mode de lecture du fichier
         * @return true 
         * @return false 
         */
        bool                load(const std::string& fileName, LOADER_MODE mode) noexcept;
        /**
         * @brief Permet d'écritre le fichier précédement charger au format JSON
         * 
         */
        void                write() const noexcept;
        /**
         * @brief Retourne la valeur correspond au id du define donné
         * 
         * @param id L'id unique du header recherché. Si la valeur n'est pas trouvé retourne 0
         * @return fe::type::_uint 
         */
        fe::type::_uint     get(const std::string& id) const noexcept;
        /**
         * @brief Permet de vérifier si la clef/id du define est stocké
         * 
         * @param id Clef/id unique du define recherché
         * @return true 
         * @return false 
         */
        bool                has(const std::string& id) const;
    };
}

#pragma warning( default: 4251 )