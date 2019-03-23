# OcctDebugNativs

This project do nothing but for test display of variables content (OpenCASCADE classes), in debugger windows.

Suggest use Visual Studio 2015 or later, as:
1. In Visual Studio 2012 and later, visualizers can be put in a separate file in subdirectory Visualizers.

2. In Visual Studio 2015, visualizers can support CustomListItems for customized display of hashtable. In OCCT, there are many hashtables, NCollection_Map, NCollection_IndexedMap, etc. I don't know whether support or not CustomListItems in vs2013, but certainly not support in vs2012.

## Warning for bug
1. NCollection_Array2. ArrayItems support customized multi-dimensional arrays, but it looks like need an array for given the size of every row, I do not know how to do this if not modify the structure of NCollection_Array2. So it will display wrong content for NCollection_Array2 when not equal of the results for (myUpperCol - myLowerCol) and (myUpperRow - myLowerRow);

2. the types base on NCollection_BaseMap. I only traversed the first layer of hashtable. Fortunately, this is usually case of hashtable, as the need to avoid collision. However, this is not strict.


## Usage
Clone this project, and test it, you will see the effect of customized.

But if you want the effect also in other projects, you should do the next step:

Download the occt.natvis and put it in the the user-specific natvis directory (%USERPROFILE%\My Documents\Visual Studio 2015\Visualizers), or the system-wide Natvis directory (%VSINSTALLDIR%\Common7\Packages\Debugger\Visualizers). This is where .natvis files that are installed with Visual Studio are copied. You can add other files to this directory as well if you have administrator permissions.

## Reference
1. [Create Custom Views of Native Objects](https://msdn.microsoft.com/en-us/library/jj620914.aspx)

2. Debugging tools and hints, using Visual Studio debugger, customized display of variables content, from the OpenCASCADE doc.
