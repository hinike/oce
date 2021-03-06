## OCE MSVC Build Instructions

1 INTRODUCTION

2. PREREQUISITES

  2.1. Cmake

  2.2. External Libraries

    2.2.1. Compile the libs by yourself

    2.2.2. Using OCE - BUNDLE

3. Extracting the sources

4. Configuring

  4.1. Designate a build directory

  4.2. Run cmake-gui

  4.3. Select the generator

  4.4. Configuration Options

  4.5. Configuring library paths

    4.5.1. TCL

    4.5.2. OCE bundle

    4.5.3. Using your own compiled libs

  4.6. Generating

5. Compiling

6. Installing

  6.1. External libs

  6.2. Command line

7. Building for Win64

8. Building for both Win32 and Win64

9. Final Notes

  9.1. Debug libraries

  9.2. Debug symbols 

## 1. Introduction

This guide will help you throught recompiling OCE from scratch. Consider downloading precompiled
binaries if you just want to use it in a supported compiler.

## 2. Prerequisites

### 2.1. Cmake

OCE build system requires CMake 2.8 to function. Download and install it at www.cmake.org

### 2.2. External Libraries
Some modules of OCE require external libraries. These include

- freetype , required by Visualization
- TCL , required by DRAW
- gl2ps and FreeImage , optionally required by Visualization
- TBB , optionally required to to multithreading

If you use DRAW , we strongly suggest that you install ActiveState TCL for Win32 or Win64. It comes with
a simple to use installation package and cmake automatically finds it.

You have two choices to build or use dependency binaries:

- Compile all the libs by yourself
- Use OCE-WIN-BUNDLE (see below), to be found at http://www.github.com/QbProg/oce-win-bundle

#### 2.2.1. Compile the libs by yourself
        
These libs must be downloaded and compiled separately.
If you find precompiled binaries, make sure that the compiler version used to compile matches
exactly the one installed in your system (even the service pack level).
If you choose build the libraries, make sure you compile them in debug and release.

#### 2.2.2. Using OCE - BUNDLE
      
The bundle will let you compile all the libraries required by oce in one simple step.

If you choose to use the bundle, make sure you have extracted it in the "oce-win-bundle" subfolder
of your oce source tree.
To do this, you could just download the sources manually from the oce-win-bundle github repository or 
invoke the FetchBundle.bat file using one of these two options:
> FetchBundle.bat 
  downloads the development version of the bundle from github and clones it in the oce-win-bundle subdir.
> FetchBundle.bat <version>
  downloads a specific tag of the bundle from github and clones it in the oce-win-bundle subdir.
  Use this version if you want to compile a specific OCE version. For instance
>  FetchBundle.bat 0.17.0 
  downloads the correct bundle version to be used with OCE.        

NOTE : the bundle will compile with the same options as OCE. So if you compile OCE statically, the bundle
libraries will be compiled statically, if you compile OCE dynamically the bundle libraries will be compiled dynamically.
    
## 3. Extracting the sources
    
- Download oce-x.x.zip and extract it in a folder. Say C:\oce-src

## 4. Configuring

We strongly suggest the use of out-of-source CMake builds. This means that the temporary
compilation projects and objects will not pollute the source folder.

### 4.1. Designate a build directory 

You can use a subdirectory of the source one, or a completely different one. 
In this case we will use c:\oce-src\Build32\

### 4.2. Run cmake-gui 

This is the GUI front-end to CMake. It will help you to select
the compilation options and configurations.  

- In the "Where is the source code" field put the oce source directory : C:\oce-src
- In the "Where to build the binaries" field put your build folder : C:\oce-src\Build32\
- Press "Configure"

### 4.3. Select the generator 
      
The first time you press "Configure", you will have to select the compiler you plan to use. 
Select one of the "Visual Studio xx" generators, and select the "Win64" ones if you want to do a
64bit compilation
      
### 4.4. Configuration Options

After the first configuration step, you will have to select the options.
You will find a lot of options: concentrate first on these that begin with OCE_
Here the most important ones:

- OCE_INSTALL_PREFIX : the destination folder of the INSTALL phase. 
At the end of the process, you will find there all the includes, binaries, libraries,etc...
NOTE : This directory is filled only when you compile the INSTALL project.
In this example we'll set it pointing to C:/oce-bin/

- OCE_USE_MSVC_EXPRESS : enable this if you are using the express edition. 
- OCE_BUILD_SHARED_LIB : disable this if you want static libraries
- OCE_WITH_xxx : enable or disable the usage of the xxx external library
- OCE_xxxxxx : enables or disables a specific component to be built. (i.e. OCE_VISUALIZATION, OCE_DRAW , etc...) 
- OCE_INSTALL_PDB_FILES : enable this if you want to copy resulting PDB files (debug symbols) in the INSTALL directory

After you set the required options , press CONFIGURE. You will likely get errors.  To fix those errors, you
have to tell CMake where to find headers and libraries for dependencies, this is discussed just below.
      
### 4.5. Configuring library paths

Now, depending on the enabled options, it's time to set the external library directories.

#### 4.5.1. TCL

If you use ActiveState TCL, CMake will find it automatically. Else, you should set the variables 
starting with TCL_ and TK (eventually available in the "Advanced" section of cmake-gui)

#### 4.5.2. OCE bundle
     
- Enable the OCE_USE_BUNDLE option
- Press Configure
- Enable the OCE_USE_BUNDLE option. This option is automatically enabled if the oce-win-bundle subdir is present in the 
   directory structure.
- Press Configure

The libraries will be built in the OCE solution and will be available in the binaries directory.
         
#### 4.5.4. Using your own compiled libs

For each lib, set the appropriate fields pointing to the include directories or libraries.
For example, you will have to set FREETYPE_INCLUDE_DIR to C:/freetype-???/include/ and so on...
Reconfigure until all the errors go away

### 4.6. Generating      
    
Once you configured everything , press the Generate button. It will create a MSVC solution in C:\oce-src\Build32\OCE.sln
If you want to change settings, you can return to cmake-gui , reconfigure and regenerate again.

## 5. Compiling

You can just open c:/oce-src/Build32/OCE.sln and compile as usual from the IDE.
You must compile the Debug configuration and one of the Release ones. 
RelWithDebInfo is good because it generates debug symbols while being optimized.
 
If you use MSVC2010 , you can build from the commandline using a Visual Studio 2010 prompt.
 
    cd \oce-src\Build32
    msbuild OCE.sln /p:Configuration=Debug
    msbuild OCE.sln /p:Configuration=RelWithDebInfo
 
The process could take hours, depending on the system. If you have a multicore machine and MSVC 2010, BEFORE running these commands you can run
 
    SET cl=/MP
 
the compiler will then use all your cores to compile.
 
If you get compilation errors, it is likely that you did something wrong in the configure phase. Go back there and make sure that all the libraries are found.
 
## 6. Installing
  
In CMake+MSVC, INSTALLing means copying just the required files to a designed folder, set by OCE_INSTALL_PREFIX.
This include header files, libs, binaries and data files.
Object files will be left in the BUILD directory. This means that you can distribute your INSTALL folder and other will be able to use
it to compile programs dependent by OCE.
  
Once compiled, from the IDE explicitly compile the "INSTALL" project. 
You do this by right-clicking on the project and selecting "Compile".

IMPORTANT : do this once for each Configuration you compiled : Debug and RelWithDebInfo

After the INSTALL phase, we'll find the result in c:\oce-bin\Win32
 
## 6.1. External libs

We miss just one piece : unless you have these in your path, copy all the external DLLs in the \bin folder of the installation directory.
(remember tcl85.dll too)

If you used oce-win-bundle, copy the dlls from c:\oce-win-bundle-win32\bin and c:\oce-win-bundle-win32\bind to your c:\oce-bin\Win32\bin forlder.
 
## 6.2. Command line

Again, in MSVC2010 command prompt you can run
    
    msbuild INSTALL.vcxproj /p:Configuration=Debug 
    msbuild INSTALL.vcxproj /p:Configuration=RelWithDebInfo 
   
and you will get the same effect.

## 7. Building for Win64

You should do exactly the same step as before, except that 
 - Use a "Win64" generator in the Configure phase
 - Use the "win64" oce-win-bundle packages
 - Install TCL for 64 bit and all your libs compiled for 64bits
 - Use a Build64 folder in the CMake configuration phase
 - Installation files will go in OCE_INSTALL_PREFIX/Win64
   
## 8. Building for both Win32 and Win64

First of all, let's make this clear: CMake doesn't support mixing 32bit and 64bit compilation. 
You will have to do all the steps two times, one for win32, one for win64. 
Just use a Build32 and Build64 folder, and configure *exactly* in the same way the two projects.

You CAN use the same OCE_INSTALL_PREFIX, if you configure the two build in the same way. 
Otherwise it is better to use different installation folders.
You will find the binaries in the OCE_INSTALL_PREFIX/Win32 and OCE_INSTALL_PREFIX/Win64 directories.

## 9. Final Notes

### 9.1. Debug libraries

You can avoid to build the debug libraries , but then you won't be able to build projects using oce in debug mode. It is *UNSUPPORTED* and really not working to link release libraries in debug configurations.
  
### 9.2. Debug symbols 

If you include them in the INSTALL directory, you will be able to see OCE call stacks and local variables. The INSTALL dir will grow in size
of about 200MB.
