#include "edge.h"

//void Dictionary::Add(MonoObject* _this, const char* name, MonoObject* value)
//{
//    static MonoMethod* add;
//
//    if(!add) {
//        add = mono_class_get_method_from_name(mono_object_get_class(_this),
//            "System.Collections.Generic.IDictionary<string,object>.Add", -1);
//    }
//
//    void* params[2];
//    params[0] = mono_string_new(mono_domain_get(), name);
//    params[1] = value;
//
//    mono_runtime_invoke(add, _this, params, NULL);
//}

void Dictionary::Add(MonoObject* _this, const char* name, MonoObject* value)
{
    static MonoMethod* add;

    if(!add) {
        add = mono_class_get_method_from_name(MonoEmbedding::GetClass(), "AddPropertyToObject", -1);
    }

    void* params[3];
    params[0] = _this;	//dict
    params[1] = mono_string_new(mono_domain_get(), name);	// key
    params[2] = value;	// value

    mono_runtime_invoke(add, _this, params, NULL);
}
