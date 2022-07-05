# blend-mesh-deformer
implement a blendshape node of Maya in C++

### Compile
```sh
mkdir build && cd build
cmake -G "Unix Makefiles" -DMAYA_VERSION=2019 ../
cmake --build . --config Release
```
The result binary file would be created at `<progject_path>/build/src/blendMeshDeformer.<extension>`.

### Usage
1. Open example file `maya/demo.mb`
2. Load the pulg-in, `<progject_path>/build/src/blendMeshDeformer.<extension>`
3. Select target mesh
4. Run command: `deformer -type blendMesh;`
5. Connect the source shape's `outMesh` to the blendMesh's `blendMesh`.<br>
  ![image](https://user-images.githubusercontent.com/23650308/175256755-8d2606af-3e5c-4843-a083-286f71ea522e.png)

### Demo
![blend](https://user-images.githubusercontent.com/23650308/175259327-e1362626-d2cd-447a-a005-29e39a113136.gif)
![paint](https://user-images.githubusercontent.com/23650308/175259343-0bccb884-bad5-44d3-b1b9-7712bdb2d812.gif)
