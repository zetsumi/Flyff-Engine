#pragma once

#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>

#include <framework_fengine.h>
#include <io/file/reader.hpp>
#include <io/file/reader_header.hpp>
#if defined(FLYFFENGINE_JSON_PICOJSON)
#include <third_party/json/picojson.h>
#else
#endif


namespace fe
{
    /**
     * @brief Redifinition des types JSON cela les bliotheque utiliser
     * Le principe etant d'abstraire et ne pas etre liée a une bibliotheque tout le long du projet
     * 
     */
    namespace type
    {
        namespace json
        {

#if defined(FLYFFENGINE_JSON_PICOJSON)
            typedef picojson::object    object;
            typedef picojson::array     array;
            typedef picojson::value     value;
#else
#endif
        }
    }
    /**
     * @brief Object permettant le chargement des fichiers JSON
     * L'object et concue pour abstraire différent type de bibliotheque JSON utilisable
     * 
     */
    class API_DECLSPEC ReaderJson
    {
    public:
        fe::type::json::value  root;
        ReaderHeader header;

        ReaderJson();
        ~ReaderJson();

        /**
         * @brief Charge le contenue du fichier
         * 
         * @param szFileJson Nome du fichier
         * @return true 
         * @return false 
         */
        bool    load(const std::string& szFileJson) noexcept;
        /**
         * @brief Permet d'écrire les donnée stocker en mémoire dans un fichier au format JSON
         * 
         * @param szFileName Nom du fichier de sortie
         * @return true 
         * @return false 
         */
        bool    write(const std::string& szFileName) noexcept;
        /**
         * @brief Permet d'écrire les donnée passé en paramètre dans un fichier au format JSON
         * 
         * @param v 
         * @param szFileName Nom du fichier de sortie
         * @return true 
         * @return false 
         */
        bool    write(fe::type::json::value& v, const std::string& szFileName) noexcept;

        /**
         * @brief Recuperer le valeur contenue la valeur passé en paramètre
         * 
         * @tparam T Type de la valeur souhaité
         * @tparam U Type de la valeur passé en paramètre
         * @param container Conteneur de type U contenant une valeur de type T
         * @return constexpr T& 
         */
        template<typename T, typename U>
        constexpr T& get(U& container)
        {
#if defined(FLYFFENGINE_JSON_PICOJSON)
            return container.get<T>();
#else
            return 0;
#endif
        }

        /**
         * @brief Retourne le boolean contenant dans la variable passé en paramètre
         * 
         * @tparam T Type de container
         * @param container Conteneur de type T contenant un boolean
         * @return true 
         * @return false 
         */
        template<typename T>
        constexpr bool getBoolean(T& container)
        {
#if defined(FLYFFENGINE_JSON_PICOJSON)
            return container.evaluate_as_boolean();
#else
#endif
        }

        /**
         * @brief Retourne un nombre de type T contenue dans container
         * 
         * @tparam T Type du nombre souhaité
         * @tparam U Type du conteneur
         * @param container Conteneur de type T contenant un nombre de type U
         * @return constexpr T 
         */
        template<typename T, typename U>
        constexpr T getNumber(U& container)
        {
            if (container.is<double>() == true)
                return static_cast<T>(container.get<double>());
#if defined(FLYFFENGINE_JSON_PICOJSON)
            if (container.is<std::string>() == true)
            {
                std::string& str = container.get<std::string>();
                if (str.find("0x") != std::string::npos)
                    return static_cast<T>(std::stoll(str.c_str(), nullptr, 16));
                if (header.has(str) == true)
                    return static_cast<T>(header.get(str));
                if (std::is_same<std::int64_t, T>::value)
                    return static_cast<T>(std::atoll(str.c_str()));
                if (std::is_same<std::uint64_t, T>::value)
                    return static_cast<T>(std::stoll(str.c_str(), nullptr, 10));
            }
            return static_cast<T>(container.get<double>());
#else
#endif
        }
    };
}

#pragma warning( default: 4251 )