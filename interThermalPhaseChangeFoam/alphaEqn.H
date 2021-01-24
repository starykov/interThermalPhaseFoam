{


    word alphaScheme("div(phi,alpha)");
    word alpharScheme("div(phirb,alpha)");

    surfaceScalarField phir("phir", phic*interface.nHatf());

tmp<surfaceScalarField> talphaPhi;

   volScalarField alpha10("alpha10", alpha1);

    for (int aCorr=0; aCorr<nAlphaCorr; aCorr++)
    {
        tmp<surfaceScalarField> talphaPhiCorr
        (
            fvc::flux
            (
                phi,
                alpha1,
                alphaScheme
            )
          + fvc::flux
            (
                -fvc::flux(-phir, alpha2, alpharScheme),
                alpha1,
                alpharScheme
            )
        );

        //Linear source term
        volScalarField Sp
        (
            IOobject
            (
                "Sp",
                runTime.timeName(),
                mesh
            ),
            divU
        );

        //alpha1 source term due to condensation and divergence of velocity
        volScalarField Su
        (
            IOobject
            (
                "Su",
                runTime.timeName(),
                mesh
            ),
            phaseChangeModel->alpha1Gen()
        );

        if (MULESCorr)
        {
            talphaPhiCorr.ref() -= talphaPhi();

            volScalarField alpha100("alpha100", alpha10);
            alpha10 = alpha1;

            MULES::correct
            (
                geometricOneField(),
                alpha1,
                talphaPhi(),
                talphaPhiCorr.ref(),
                Sp,
                Su,
                oneField(),
                zeroField()
            );

            // Under-relax the correction for all but the 1st corrector
            if (aCorr == 0)
            {
                talphaPhi.ref() += talphaPhiCorr();
            }
            else
            {
                alpha1 = 0.5*alpha1 + 0.5*alpha10;
                talphaPhi.ref() += 0.5*talphaPhiCorr();
            }
        }
        else
        {
            MULES::explicitSolve
            (
                geometricOneField(),
                alpha1,
                phi,
                talphaPhiCorr.ref(),
                Sp,
                Su,
                oneField(),
                zeroField()
            );

            talphaPhi = talphaPhiCorr;
        }

        alpha2 = 1.0 - alpha1;
    }

    rhoPhi = talphaPhi()*(rho1 - rho2) + phi*rho2;

    // Cache alphaPhi
    alphaPhi10 = talphaPhi();

    Info<< "Liquid phase volume fraction = "
        << alpha1.weightedAverage(mesh.V()).value()
        << "  Min(" << alpha1.name() << ") = " << min(alpha1).value()
        << "  Max(" << alpha1.name() << ") = " << max(alpha1).value()
        << endl;




    /*
    word alphaScheme("div(phi,alpha)");
    word alpharScheme("div(phirb,alpha)");


    surfaceScalarField phir(phic*interface.nHatf());

    for (int aCorr=0; aCorr<nAlphaCorr; aCorr++)
    {
        surfaceScalarField phiAlpha
        (
            fvc::flux
            (
                phi,
                alpha1,
                alphaScheme
            )
          + fvc::flux
            (
                -fvc::flux(-phir, scalar(1) - alpha1, alpharScheme),
                alpha1,
                alpharScheme
            )
        );

        //Linear source term
        volScalarField Sp
        (
            IOobject
            (
                "Sp",
                runTime.timeName(),
                mesh
            ),
            divU
        );

        //alpha1 source term due to condensation and divergence of velocity
        volScalarField Su
        (
            IOobject
            (
                "Su",
                runTime.timeName(),
                mesh
            ),
            phaseChangeModel->alpha1Gen()
        );


        MULES::explicitSolve
        (
            geometricOneField(),
            alpha1,
            phi,
            phiAlpha.ref(),
            Sp,
            Su,
            1,
            0
        );

        rhoPhi +=
            (runTime.deltaT()/totalDeltaT)
           *(phiAlpha*(rho1 - rho2) + phi*rho2); 
    }

    Info<< "Liquid phase volume fraction = "
        << alpha1.weightedAverage(mesh.V()).value()
        << "  Min(alpha1) = " << min(alpha1).value()
        << "  Max(alpha1) = " << max(alpha1).value()
        << endl;
*/
}
