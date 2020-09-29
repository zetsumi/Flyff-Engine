#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <utility>

#include <framework_fengine.h>
#include <io/file/reader.hpp>

#pragma warning( disable: 4251 )

namespace fe
{
    class API_DECLSPEC ReaderText
    {
        std::unordered_map<std::string, std::string>    texts = {};

        bool    loadJson(const std::string& fileName, bool skillEmpty = false);

    public:
        ReaderText(const ReaderText* o) : ReaderText(*o)
        {
        }
        ReaderText() = default;
        ReaderText(const ReaderText&) = default;
        ReaderText(ReaderText&&) noexcept = default;
        ReaderText& operator=(const ReaderText&) = default;
        ReaderText& operator=(ReaderText&&) = default;
        virtual ~ReaderText() = default;

        /**
         * @brief Recupérer le chaîne de caractères
         * 
         * @param key Nom de la clef stockant la valeur
         * @return const std::string 
         */
        const std::string    get(const std::string& key) const noexcept
        {
            auto it = texts.find(key);
            if (it != texts.end())
                return it->second;
            return std::forward<std::string>("");
        }
        /**
         * @brief Verifier que la clef a déjà etait stocker
         * 
         * @param key clef
         * @return true 
         * @return false 
         */
        bool    has(const std::string& key) const noexcept
        {
            return texts.find(key) != texts.end() ? true : false;
        }

        /**
         * @brief Charge les fichier TEXT
         * 
         * @param fileName Nom du fichier
         * @param mode Mode de lecture
         * @param skillEmpty Option permettant d'ignorer les nom de sort vide ou invalid present dans le fichier chargé. Si true on ignore.
         * @return true 
         * @return false 
         */
        bool    load(const std::string& fileName, LOADER_MODE mode, bool skillEmpty = false) noexcept;
    };
}



#pragma warning( default: 4251 )