/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Description
    Template for use with dynamic code generation of a functionObject.

SourceFiles
    functionObjectTemplate.C

\*---------------------------------------------------------------------------*/

#ifndef functionObjectTemplate_H
#define functionObjectTemplate_H

#include "regionFunctionObject.H"

//{{{ begin codeInclude
#line 104 "/home/ded/OpenFOAM/ded-v2012/solvers/CFD-PC/interThermalPhaseFoam/tutorials/Stefan/system/controlDict.functions.VolumeLiquid"
#include <fstream>
//}}} end codeInclude

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward Declarations
class fvMesh;

/*---------------------------------------------------------------------------*\
                         A templated functionObject
\*---------------------------------------------------------------------------*/

class VolumeLiquidFunctionObject
:
    public functionObjects::regionFunctionObject
{
    // Private Data

//{{{ begin codeData
        
//}}} end codeData


    // Private Member Functions

        //- Report a message with the SHA1sum
        inline static void printMessage(const char* message)
        {
            Info<< message << " sha1: " << SHA1sum << '\n';
        }

        //- Cast reference of objectRegistry to fvMesh
        const fvMesh& mesh() const;

        //- No copy construct
        VolumeLiquidFunctionObject(const VolumeLiquidFunctionObject&) = delete;

        //- No copy assignment
        void operator=(const VolumeLiquidFunctionObject&) = delete;

public:

    //- SHA1 representation of the code content
    static constexpr const char* const SHA1sum = "5f85d2fd7834732970420e7ec86a1f522b2910f9";

    //- Runtime type information
    TypeName("VolumeLiquid");


    // Constructors

        //- Construct from Time and dictionary
        VolumeLiquidFunctionObject
        (
            const word& name,
            const Time& runTime,
            const dictionary&
        );


    //- Destructor
    virtual ~VolumeLiquidFunctionObject();


    // Member Functions

        //- Read the dictionary
        virtual bool read(const dictionary& dict);

        //- Execute (at time-step)
        virtual bool execute();

        //- Write (at write interval)
        virtual bool write();

        //- Executed at the final time-loop
        virtual bool end();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //

