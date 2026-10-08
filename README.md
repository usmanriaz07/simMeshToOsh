A tool to convert simmetrix meshes to Omegah meshes. The tool in Omegah repo requires Simmetrix model. This tool is independent of the underlying Simmetrix model and only needs Simmetrix mesh.
Didn't work with underlying Native models (Parasolid). Will try to figure it our in future when I have some extra time.

**Usage:** 
* ``./simMesh2Osh SimmetrixMesh.sms outputOmegahMesh.osh(optional) ``
* Required: ``simMesh2Osh`` executable,  simmetrix mesh with extension ``.sms``
* Optional: Ouput file name. if not given, output file will be ``output.osh``
