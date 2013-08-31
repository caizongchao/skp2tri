// Copyright 2013 Trimble Navigation Ltd.  All Rights Reserved
#ifndef SLAPI_MODEL_ATTRIBUTE_DICTIONARY_H_
#define SLAPI_MODEL_ATTRIBUTE_DICTIONARY_H_

#include <slapi/slapi.h>
#include <slapi/unicodestring.h>
#include <slapi/model/defs.h>
#include <slapi/model/typed_value.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
@struct SUAttributeDictionaryRef
@brief  A dictionary type with SUStringRef objects as keys and SUTypedValueRef
        objects as values.
*/

/**
@brief Retrieves the name of an attribute dictionary object.
@param[in]  dictionary The attribute dictionary object.
@param[out] name       The name retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if dictionary is an invalid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if name if NULL
- \ref SU_ERROR_INVALID_OUTPUT if name references an invalid object
*/
SU_RESULT SUAttributeDictionaryGetName(SUAttributeDictionaryRef dictionary,
                                       SUStringRef* name);

/**
@brief Inserts a key-value pair into an attribute dictionary object.
@param[in] dictionary The attribute dictionary object.
@param[in] key        The key of the key-value pair. Assumed to be UTF-8
                      encoded.
@param[in] value_in   The value of the key-value pair.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if dictionary or value_in is an invalid object.
- \ref SU_ERROR_NULL_POINTER_INPUT if key is NULL
*/
SU_RESULT SUAttributeDictionarySetValue(SUAttributeDictionaryRef dictionary,
                                        const char* key,
                                        SUTypedValueRef value_in);

/**
@brief Retrieves the value associated with a given key from an attribute
       dictionary.
@param[in] dictionary The attribute dictionary object.
@param[in] key        The key of the key-value pair. Assumed to be UTF-8
                      encoded.
@param[out] value_out The value retrieved. Must be a valid object, i.e.
                      must have been allocated via \ref SUTypedValueCreate.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if dictionary is an invalid object
- \ref SU_ERROR_NULL_POINTER_INPUT if key is NULL
- \ref SU_ERROR_NULL_POINTER_OUTPUT if value_out is NULL
- \ref SU_ERROR_INVALID_OUTPUT if value_out is an invalid object
- \ref SU_ERROR_NO_DATA if there is no value associated with the given key in
  the dictionary
*/
SU_RESULT SUAttributeDictionaryGetValue(SUAttributeDictionaryRef dictionary,
                                        const char* key,
                                        SUTypedValueRef* value_out);

/**
@brief Retrieves the number of keys in an attribute dictionary object.
@param[in]  dictionary The attribute dictionary object.
@param[out] count      The number of keys.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if dictionary is an invalid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if count is NULL
*/
SU_RESULT SUAttributeDictionaryGetNumKeys(SUAttributeDictionaryRef dictionary,
                                          size_t* count);

/**
@brief Retrieves the array of keys of an attribute dictionary object.
@param[in]  dictionary The attribute dictionary object.
@param[in]  len        The number of keys to retrieve.
@param[out] keys       The keys retrieved.
@param[out] count      The number of keys retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if dictionary is an invalid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if keys or count is NULL
*/
SU_RESULT SUAttributeDictionaryGetKeys(SUAttributeDictionaryRef dictionary,
                                       size_t len,
                                       SUStringRef keys[],
                                       size_t* count);

#ifdef __cplusplus
}  //  extern "C" {
#endif

#endif  // SLAPI_MODEL_ATTRIBUTE_DICTIONARY_H_
