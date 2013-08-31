// Copyright 2013 Trimble Navigation Ltd.  All rights reserved.

#ifndef SLAPI_RENDERING_OPTIONS_H_
#define SLAPI_RENDERING_OPTIONS_H_

#include <slapi/color.h>
#include <slapi/slapi.h>
#include <slapi/model/defs.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
@struct SURenderingOptionsRef
@brief  Used to get and set values in a rendering options object.
*/

/**
@brief  Sets values in a rendering options object.
@param[in] rendering_options The rendering options object.
@param[in] key               The key. Assumed to be UTF-8 encoded.
@param[in] value_in          The value used to set the option.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if rendering_options or value_in is an invalid
  object
- \ref SU_ERROR_NULL_POINTER_INPUT if key is NULL
*/
SU_RESULT SURenderingOptionsSetValue(SURenderingOptionsRef rendering_options,
                                     const char* key,
                                     SUTypedValueRef value_in);

/**
@brief  Retrieves the name of a scene object.
@param[in]  rendering_options The rendering options object.
@param[in]  key               The key. Assumed to be UTF-8 encoded.
@param[out] value_out         The value retrieved.
@return
- \ref SU_ERROR_NONE on success
- \ref SU_ERROR_INVALID_INPUT if rendering_options is an invalid object
- \ref SU_ERROR_NULL_POINTER_INPUT if key is NULL
- \ref SU_ERROR_INVALID_OUTPUT if value_out is an invalid object
- \ref SU_ERROR_NULL_POINTER_OUTPUT if value_out is NULL

The breakdown of rendering options and value types is shown in the table below.

Rendering Option         | Value Type
------------------------ | ----------------------
BackgroundColor          | SUTypedValueType_Color
BandColor                | SUTypedValueType_Color
ConstructionColor        | SUTypedValueType_Color
DepthQueWidth            | SUTypedValueType_Int32
DisplayColorByLayer      | SUTypedValueType_Bool
DisplayDims              | SUTypedValueType_Bool
DisplayFog               | SUTypedValueType_Bool
DisplayInstanceAxes      | SUTypedValueType_Bool
DisplaySketchAxes        | SUTypedValueType_Bool
DisplayText              | SUTypedValueType_Bool
DisplayWatermarks        | SUTypedValueType_Bool
DrawDepthQue             | SUTypedValueType_Bool
DrawGround               | SUTypedValueType_Bool
DrawHidden               | SUTypedValueType_Bool
DrawHorizon              | SUTypedValueType_Bool
DrawLineEnds             | SUTypedValueType_Bool
DrawProfilesOnly         | SUTypedValueType_Bool
DrawSilhouettes          | SUTypedValueType_Bool
DrawUnderground          | SUTypedValueType_Bool
EdgeColorMode            | SUTypedValueType_Int32
EdgeDisplayMode          | SUTypedValueType_Int32
EdgeType                 | SUTypedValueType_Int32
ExtendLines              | SUTypedValueType_Bool
FaceBackColor            | SUTypedValueType_Color
FaceColorMode            | SUTypedValueType_Int32
FaceFrontColor           | SUTypedValueType_Color
FogColor                 | SUTypedValueType_Color
FogEndDist               | SUTypedValueType_Double
FogStartDist             | SUTypedValueType_Double
FogUseBkColor            | SUTypedValueType_Bool
ForegroundColor          | SUTypedValueType_Color
GroundColor              | SUTypedValueType_Color
GroundTransparency       | SUTypedValueType_Int32
HideConstructionGeometry | SUTypedValueType_Bool
HighlightColor           | SUTypedValueType_Color
HorizonColor             | SUTypedValueType_Color
InactiveFade             | SUTypedValueType_Double
InactiveHidden           | SUTypedValueType_Bool
InstanceFade             | SUTypedValueType_Double
InstanceHidden           | SUTypedValueType_Bool
JitterEdges              | SUTypedValueType_Bool
LineEndWidth             | SUTypedValueType_Int32
LineExtension            | SUTypedValueType_Int32
LockedColor              | SUTypedValueType_Color
MaterialTransparency     | SUTypedValueType_Bool
ModelTransparency        | SUTypedValueType_Bool
RenderMode               | SUTypedValueType_Int32
SectionActiveColor       | SUTypedValueType_Color
SectionCutWidth          | SUTypedValueType_Int32
SectionDefaultCutColor   | SUTypedValueType_Color
SectionInactiveColor     | SUTypedValueType_Color
ShowViewName             | SUTypedValueType_Bool
SilhouetteWidth          | SUTypedValueType_Int32
SkyColor                 | SUTypedValueType_Color
Texture                  | SUTypedValueType_Bool
TransparencySort         | SUTypedValueType_Int32

Some of the options map to enumerated values, as shown in the table below.

Option          | Value | Meaning
--------------- | ----- | -------
EdgeColorMode   | 0:    | ObjectColor
&nbsp;          | 1:    | ForegroundColor
&nbsp;          | 2:    | DirectionColor
EdgeDisplayMode | 0:    | EdgeDisplayNone
&nbsp;          | 1:    | EdgeDisplayAll
&nbsp;          | 2:    | EdgeDisplayStandalone
RenderMode      | 0:    | RenderWireframe
&nbsp;          | 1:    | RenderHidden
&nbsp;          | 2:    | RenderFlat
&nbsp;          | 3:    | RenderSmooth
&nbsp;          | 4:    | RenderTextureObsolete
&nbsp;          | 5:    | RenderNoMaterials
FaceColorMode   | 0:    | TwoSided
&nbsp;          | 1:    | OneSided
EdgeType        | 0:    | EdgeStandard
&nbsp;          | 1:    | EdgeNPR
*/
SU_RESULT SURenderingOptionsGetValue(SURenderingOptionsRef rendering_options,
                                     const char* key,
                                     SUTypedValueRef* value_out);

#ifdef __cplusplus
}
#endif

#endif  // SLAPI_RENDERING_OPTIONS_H_
