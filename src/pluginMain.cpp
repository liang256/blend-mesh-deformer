#include "blendMeshDeformer.h"
#include <maya/MFnPlugin.h>

MStatus initializePlugin(MObject obj)
{
    MStatus status;

    MFnPlugin fnPlugin(obj, "Liang", "1.0", "Any");

    status = fnPlugin.registerNode("blendMesh", 
        BlendMeshDeformer::id,
        BlendMeshDeformer::creator,
        BlendMeshDeformer::initialize,
        MPxNode::kDeformerNode
    );
    CHECK_MSTATUS_AND_RETURN_IT(status)

    return status;
}

MStatus uninitializePlugin(MObject obj)
{
    MStatus status;

    MFnPlugin fnPlugin(obj);

    status = fnPlugin.deregisterNode(BlendMeshDeformer::id);
    CHECK_MSTATUS_AND_RETURN_IT(status)

    return status;
}