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

\*---------------------------------------------------------------------------*/

#include "functionObjectTemplate.H"
#include "fvCFD.H"
#include "unitConversion.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(VolumeLiquidFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    VolumeLiquidFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 5f85d2fd7834732970420e7ec86a1f522b2910f9
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void VolumeLiquid_5f85d2fd7834732970420e7ec86a1f522b2910f9(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

const fvMesh& VolumeLiquidFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

VolumeLiquidFunctionObject::VolumeLiquidFunctionObject
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    functionObjects::regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

VolumeLiquidFunctionObject::~VolumeLiquidFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool VolumeLiquidFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        printMessage("read VolumeLiquid");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool VolumeLiquidFunctionObject::execute()
{
    if (false)
    {
        printMessage("execute VolumeLiquid");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool VolumeLiquidFunctionObject::write()
{
    if (false)
    {
        printMessage("write VolumeLiquid");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool VolumeLiquidFunctionObject::end()
{
    if (false)
    {
        printMessage("end VolumeLiquid");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// ************************************************************************* //

