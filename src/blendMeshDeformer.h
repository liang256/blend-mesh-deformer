#ifndef BLENDMESHDEFORMER_H
#define BLENDMESHDEFORMER_H

#include <maya/MPxDeformerNode.h>
#include <maya/MFnNumericAttribute.h>
#include <maya/MObject.h>
#include <maya/MGlobal.h>
#include <maya/MFnMesh.h>
#include <maya/MPointArray.h>
#include <maya/MItGeometry.h>
#include <maya/MFnTypedAttribute.h>

class BlendMeshDeformer: public MPxDeformerNode
{
public:
    BlendMeshDeformer();
    virtual ~BlendMeshDeformer();
    static void* creator();

    virtual MStatus deform(
        MDataBlock& data,
        MItGeometry& itGeo,
        const MMatrix& localToWorldMatrix,
        unsigned int geomIndex
    );
    static MStatus initialize();

    static MTypeId id;
    static MObject aBlendMesh;
    static MObject aBlendWeight;
};

#endif
