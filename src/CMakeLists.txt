set(SOURCE_FILES
	"blendMeshDeformer.h"
	"blendMeshDeformer.cpp"
	"pluginMain.cpp"
)

find_package(Maya REQUIRED)

include_directories(${MAYA_INCLUDE_DIR})
link_directories(${MAYA_LIBRARY_DIR})

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${MAYA_LIBRARIES})
target_include_directories(${PROJECT_NAME} PRIVATE ${MAYA_LIBRARIES})
MAYA_PLUGIN(${PROJECT_NAME})
