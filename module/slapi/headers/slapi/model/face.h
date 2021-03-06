// Copyright 2013 Trimble Navigation Ltd. All Rights Reserved.
#ifndef SLAPI_MODEL_FACE_H_
#define SLAPI_MODEL_FACE_H_

#include <slapi/slapi.h>
#include <slapi/geometry.h>
#include <slapi/model/geometry_input.h>
#include <slapi/model/defs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
@struct SUFaceRef
@brief  References a face.
*/

/**
@brief Converts from an \ref SUFaceRef to an \ref SUEntityRef.
       This is essentially an upcast operation.
@param[in] face The given face reference.
@return
- The converted SUEntityRef if face is a valid face.
- If not, the returned reference will be invalid.
*/
SU_EXPORT SUEntityRef SUFaceToEntity(SUFaceRef face);

/**
@brief Converts from an \ref SUEntityRef to an \ref SUFaceRef.
       This is essentially a downcast operation so the given entity must be
       convertible to an \ref SUFaceRef.
@param[in] entity The given entity reference.
@return
- The converted SUFaceRef if the downcast operation succeeds
- If not, the returned reference will be invalid
*/
SU_EXPORT SUFaceRef SUFaceFromEntity(SUEntityRef entity);

/**
@brief Converts from an \ref SUFaceRef to an \ref SUDrawingElementRef.
       This is essentially an upcast operation.
@param[in] face The given face reference.
@return
- The converted \ref SUEntityRef if face is a valid face.
- If not, the returned reference will be invalid.
*/
SU_EXPORT SUDrawingElementRef SUFaceToDrawingElement(SUFaceRef face);

/**
@brief Converts from an \ref SUDrawingElementRef to an \ref SUFaceRef.
       This is essentially a downcast operation so the given element must be
       convertible to an SUFaceRef.
@param[in] drawing_elem The given element reference.
@return
- The converted \ref SUFaceRef if the downcast operation succeeds
- If not, the returned reference will be invalid
*/
SU_EXPORT SUFaceRef SUFaceFromDrawingElement(SUDrawingElementRef
                                             drawing_elem);

/**
@brief Creates a face without holes.
@param[out] face       The face object created.
@param[in]  vertices3d The array of vertices that make the face.
@param[in]  outer_loop The loop input that describes the outer loop of the face.
                       If the function is successful, the new face will take
                       ownership of the loop and this reference will be
                       invalidated.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_NULL_POINTER_INPUT if vertices3d or outer_loop is NULL
- \ref SU_ERROR_INVALID_INPUT if outer_loop contains invalid input data
- \ref SU_ERROR_GENERIC if the the points specified by outer_loop do not lie on
  a plane within 1.0e-3 tolerance
- \ref SU_ERROR_NULL_POINTER_OUTPUT if face is NULL
- \ref SU_ERROR_OVERWRITE_VALID if face already refers to a valid object
*/
SU_RESULT SUFaceCreate(SUFaceRef* face,
                       const struct SUPoint3D vertices3d[],
                       SULoopInputRef* outer_loop);

/**
@brief Creates a simple face without holes from an array of vertices.
@param[out] face       The face object created.
@param[in]  vertices3d The array of vertices of the face.
@param[in]  len        The length of the array of vertices.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_NULL_POINTER_INPUT if vertices3d is NULL
- \ref SU_ERROR_NULL_POINTER_OUTPUT if face is NULL
- \ref SU_ERROR_GENERIC if the specified vertices do not lie on a plane within
  1.0e-3 tolerance
- \ref SU_ERROR_OVERWRITE_VALID if face already refers to a valid face object
*/
SU_RESULT SUFaceCreateSimple(SUFaceRef* face,
                             const struct SUPoint3D vertices3d[],
                             size_t len);

/**
@brief Retrieves the normal vector of a face object.
@param[in]  face   The face object.
@param[out] normal The 3d normal vector retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if normal is NULL
*/
SU_RESULT SUFaceGetNormal(SUFaceRef face, struct SUVector3D* normal);

/**
@brief Releases a face object and its associated resources.
@param[in] face The face object.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_NULL_POINTER_INPUT if face points to an NULL
- \ref SU_ERROR_INVALID_INPUT if the face object is not a valid object.
*/
SU_RESULT SUFaceRelease(SUFaceRef* face);

/**
@brief Retrieves the number of edges in a face.
@param[in]  face  The face object.
@param[out] count The number of edges.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if the face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if count is NULL
*/
SU_RESULT SUFaceGetNumEdges(SUFaceRef face, size_t* count);

/**
@brief Retrieves the edges in the face.
@param[in]  face  The face object.
@param[in]  len   The number of edges to retrieve.
@param[out] edges The edges retrieved.
@param[out] count The number of edges retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if edges or count is NULL
*/
SU_RESULT SUFaceGetEdges(SUFaceRef face, size_t len, SUEdgeRef edges[],
                         size_t* count);

/**
@brief Retrieves the plane of the face.
@param[in]  face  The face object.
@param[out] plane The 3d plane retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if plane is NULL
*/
SU_RESULT SUFaceGetPlane(SUFaceRef face, struct SUPlane3D* plane);

/**
@brief Retrieves the number of vertices that the face is associated with.
@param[in]  face  The face object.
@param[out] count The number of vertices.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if count is NULL
*/
SU_RESULT SUFaceGetNumVertices(SUFaceRef face, size_t* count);

/**
@brief Retrieves the vertex objects associated with a face object.
@param[in]  face     The face object.
@param[in]  len      The number of vertices to retrieve.
@param[out] vertices The vertices retrieved.
@param[out] count    The number of vertices retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if vertices or count is NULL
*/
SU_RESULT SUFaceGetVertices(SUFaceRef face, size_t len,
                            SUVertexRef vertices[], size_t* count);

/**
@brief Retrieves the outer loop of a face object.
@param[in]  face The face object.
@param[out] loop The loop object retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT is loop is NULL
*/
SU_RESULT SUFaceGetOuterLoop(SUFaceRef face, SULoopRef* loop);

/**
@brief Retrieves the number of loops in a face.
@param[in]  face  The face object.
@param[out] count The number of inner loops.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if the face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if count is NULL
*/
SU_RESULT SUFaceGetNumInnerLoops(SUFaceRef face, size_t* count);

/**
@brief Retrieves the loops in the face.
@param[in]  face  The face object.
@param[in]  len   The number of loops to retrieve.
@param[out] loops The inner loops retrieved.
@param[out] count The number of inner loops retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face object is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if loops or count is NULL
*/
SU_RESULT SUFaceGetInnerLoops(SUFaceRef face, size_t len, SULoopRef loops[],
                              size_t* count);

/**
@brief Adds a hole to the face. The face object must be associated with a parent
       component.
@param[in] face       The face object.
@param[in] vertices3d The array of vertices references by the added loop.
@param[in] loop       The loop input that describes the inner loop.
                      If the function is successful, the new face will take
                      ownership of the loop and this reference will be
                      invalidated.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_NULL_POINTER_INPUT if vertices3d or loop is NULL
- \ref SU_ERROR_INVALID_INPUT if loop contains invalid input data
- \ref SU_ERROR_GENERIC if the face object is not associated with a parent
  component.
*/
SU_RESULT SUFaceAddInnerLoop(SUFaceRef face,
                             const struct SUPoint3D vertices3d[],
                             SULoopInputRef* loop);

/**
@brief Retrieves the front material associated with a face object.
@param[in]  face     The face object.
@param[out] material The material object retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if material is NULL
*/
SU_RESULT SUFaceGetFrontMaterial(SUFaceRef face, SUMaterialRef* material);

/**
@brief Sets the front material of a face object.
@param[in] face     The face object.
@param[in] material The material object to set.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face or material is not a valid object
*/
SU_RESULT SUFaceSetFrontMaterial(SUFaceRef face, SUMaterialRef material);

/**
@brief Retrieves the back material associate with a face object.
@param[in]  face     The face object.
@param[out] material The material object retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if material is NULL
*/
SU_RESULT SUFaceGetBackMaterial(SUFaceRef face,
                                SUMaterialRef* material);

/**
@brief Sets the back material of a face object.
@param[in] face     The face object.
@param[in] material The material object to set.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face or material is not a valid object
*/
SU_RESULT SUFaceSetBackMaterial(SUFaceRef face, SUMaterialRef material);

/**
@brief Retrieves the flag indicating whether a face object has an affine
       texture applied to its front.
@param[in]  face      The face object.
@param[out] is_affine The flag retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if is_affine is NULL
- \ref SU_ERROR_NO_DATA if face does not have a textured material applied to its
  front
*/
SU_RESULT SUFaceIsFrontMaterialAffine(SUFaceRef face, bool* is_affine);

/**
@brief Retrieves the flag indicating whether a face object has an affine
       texture applied to its back.
@param[in]  face      The face object.
@param[out] is_affine The flag retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if is_affine is NULL
- \ref SU_ERROR_NO_DATA if face does not have a textured material applied to its
  back
*/
SU_RESULT SUFaceIsBackMaterialAffine(SUFaceRef face, bool* is_affine);

/**
@brief Computes the area of the face, taking into account all the inner loops
       and cuts from openings.
@param[in]  face The face object.
@param[out] area The area retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if area is NULL
*/
SU_RESULT SUFaceGetArea(SUFaceRef face, double* area);

/**
@brief Retrieves a flag indicating whether the face is complex, i.e. contains
       either inner loops or openings cut by attached component instances or
       attached groups.
@param[in]  face       The face object.
@param[out] is_complex The flag retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid face object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if is_complex is NULL
*/
SU_RESULT SUFaceIsComplex(SUFaceRef face, bool* is_complex);

/**
@brief Creates a UV helper for the face.
@param[in]  face  The face object.
@param[in]  front Flag indicating whether to compute the UV coordinates for
                  the front of the face.
@param[in]  back  Flag indicating whether to compute the UV coordinates for
                  the back of the face.
@param[in]  texture_writer An optional texture writer to aid in texture
                           coordinate calculations for non-affine textures.
@param[out] uv_helper      The UV helper object created. Must be deallocated
                           via \ref SUUVHelperRelease.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if uv_helper is NULL
*/
SU_RESULT SUFaceGetUVHelper(SUFaceRef face, bool front, bool back,
                            SUTextureWriterRef texture_writer,
                            SUUVHelperRef* uv_helper);

/**
@brief Creates a UV helper for the face given a specific texture handle.
@param[in] face  The face object.
@param[in] front Flag indicating whether to compute the UV coordinates for
                 the front of the face.
@param[in] back  Flag indicating whether to compute the UV coordinates for
                 the back of the face.
@param[in] texture_writer An optional texture writer to aid in texture
                          coordinate calculations for non-affine textures.
@param[in] textureHandle  The handle of the image that should be mapped to the
                          face.
@param[out] uv_helper     The UV helper object created.  Must be deallocated
                          via \ref SUUVHelperRelease.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if face is not a valid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if uv_helper is NULL.
*/
SU_RESULT SUFaceGetUVHelperWithTextureHandle(SUFaceRef face,
    bool front,
    bool back,
    SUTextureWriterRef texture_writer,
    long textureHandle,
    SUUVHelperRef* uv_helper);

#ifdef __cplusplus
}  //  extern "C" {
#endif

#endif  // SLAPI_MODEL_FACE_H_
