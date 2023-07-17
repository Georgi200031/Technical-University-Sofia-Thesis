#pragma once
#include <string>

/* GRAPHICS CONSTANTS */
static const char* SETTINGS = "settings";
static const char* BGCOLOR = "background_color";
static const char* IMGSETTINGS = "image_settings";
static const char* WIDTH = "width";
static const char* HEIGHT = "height";
static const char* CAMERA = "camera";
static const char* POS = "position";
static const char* MATRIX = "matrix";
static const char* OBJECTS = "objects";
static const char* VERTICES = "vertices";
static const char* TRIANGLES = "triangles";
static const char* LIGHTS = "lights";
static const char* LIGHTINTENSITY = "intensity";
static const char* MAT_INDEX = "material_index";
static const char* MATERIALS = "materials";
static const char* MAT_TYPE = "type";
static const char* MAT_TYPE_DIFFUSE = "diffuse";
static const char* MAT_TYPE_REFLECTIVE = "reflective";
static const char* MAT_ALBEDO = "albedo";
static const char* MAT_IOR = "ior";
static const char* MAT_SMOOTH = "smooth_shading";
static const char* BUCKETSIZE = "bucket_size";
static const char* BACK_FACE_CULLING = "back_face_culling";
static const char* GI_ON = "gi_on";
static const char* REFLECTIONS_ON = "reflections_on";
static const char* REFRACTIONS_ON = "refractions_on";


//Lighting
static const float SHADOW_BIAS = 0.001f;
static const float REFLECTION_RAY_BIAS = 0.001f;
static const float REFRACTION_RAY_BIAS = 0.04f;
static const float HIT_RAY_BIAS = 0.001f;

//define invalid Triangle
static const int invalidIndexTriangle = -1;

//define maxColorComponent
static const int maxColorComponent = 255;

//define newTab and newLine
static const std::string newTab = "\t";
static const std::string newLine = "\n";

//define math
static const float EPSILON = 0.00000001f;

//define PI
static const float PI = static_cast<float>(3.14159265358979323846);

//define max depth of ray intersect scene
static const int maxRayDepth = 5;

//define min,max infinity value
static float minFloatValue = -FLT_MAX;
static float maxFloatValue = FLT_MAX;

//define max box triangle count to stop AccTree  as depth
static int maxBoxTrianglesCount = 13;

//define all 3d axis index
static int axisCount = 3;

//Acc Tree Depth i.e according this depth have leaf node
static const int AccTreeDepth = 30;

//invalidParrent for leaf depth
static const int invalidParent = -1;

static const int diffuseReflectionRaysCount = 1;


 static int raysInPixels = 1;

static const int maxDepthDiffuseReflectRay = 3;


/*
SETTINGS FOR FRAMES
*/

static const int totalFrames = 100;
