#include "blendMeshDeformer.h"

MTypeId BlendMeshDeformer::id(0x00000214);
MObject BlendMeshDeformer::aBlendMesh;
MObject BlendMeshDeformer::aBlendWeight;

BlendMeshDeformer::BlendMeshDeformer()
{
}

BlendMeshDeformer::~BlendMeshDeformer()
{
}

void* BlendMeshDeformer::creator()
{
    return new BlendMeshDeformer;
}

MStatus BlendMeshDeformer::deform(
    MDataBlock& data,
    MItGeometry& itGeo, // Iterator
    const MMatrix& localToWorldMatrix,
    unsigned int geomIndex
){
    MStatus status;

    // Get the input mesh
    MDataHandle hBlendMesh = data.inputValue(aBlendMesh, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MObject oBlendMesh = hBlendMesh.asMesh();
    if (oBlendMesh.isNull())
    {
        return MS::kSuccess;
    }

    MFnMesh fnMesh(oBlendMesh, &status);
    CHECK_MSTATUS_AND_RETURN_IT(status);
    MPointArray blendPoints;
    fnMesh.getPoints(blendPoints);

    float blendWeight = data.inputValue(aBlendWeight).asFloat();
    float env = data.inputValue(envelope).asFloat();

    MPoint point;
    for (; !itGeo.isDone(); itGeo.next())
    {
        point = itGeo.position();
        point += (blendPoints[itGeo.index()] - point) * blendWeight * env;
        itGeo.setPosition(point);
    }

    return MS::kSuccess;
}

MStatus BlendMeshDeformer::initialize()
{
    MStatus status;
    MFnNumericAttribute nAttr;
    MFnTypedAttribute tAttr;

    aBlendMesh = tAttr.create("blendMesh", "blendMesh", MFnData::kMesh);
    addAttribute(aBlendMesh);
    attributeAffects(aBlendMesh, outputGeom);

    aBlendWeight = nAttr.create("blendWeight", "blendWeight", MFnNumericData::kFloat);
    addAttribute(aBlendWeight);
    nAttr.setMin(0.0f);
    nAttr.setMax(1.0f);
    nAttr.setKeyable(true);
    attributeAffects(aBlendWeight, outputGeom);

    return MS::kSuccess;
}