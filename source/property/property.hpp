#pragma once

namespace fe
{
    typedef struct PropertyContainer PropertyContainer;
    struct PropertyContainer
    {
        PropertyContainer()
        {
        }

        virtual ~PropertyContainer()
        {
        }
    };
}

#define FE_PROPERTY_CLASSNAME

#define FE_PROPERTY_VAR(type, name) type name;
#define FE_PROPERTY_CLASS_BEGIN class FE_PROPERTY_CLASSNAME : fe::PropertyContainer {
#define FE_PROPERTY_CLASS_END };
#define FE_PROPERTY_INITIALIZE_BEGIN FE_PROPERTY_CLASSNAME() : fe::PropertyContainer()
#define FE_PROPERTY_INITIALIZE_VAR(name, val) ,name(val)
#define FE_PROPERTY_INITIALIZE_END {}
#define FE_PROPERTY_DESTROY_DEGIN virtual ~FE_PROPERTY_CLASSNAME() {
#define FE_PROPERTRY_DESTROY_VAR(var, action) action(var);
#define FE_PROPERTY_DESTROY_END }

