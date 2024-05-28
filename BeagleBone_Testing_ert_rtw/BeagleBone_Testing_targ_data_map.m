    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 2;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (BeagleBone_Testing_P)
        ;%
            section.nData     = 16;
            section.data(16)  = dumData; %prealloc

                    ;% BeagleBone_Testing_P.K_discrete
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_P.Lykyhatkk1_Y0
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 24;

                    ;% BeagleBone_Testing_P.deltax_Y0
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 25;

                    ;% BeagleBone_Testing_P.MPU9250_SampleTime
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 26;

                    ;% BeagleBone_Testing_P.A_Value
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 27;

                    ;% BeagleBone_Testing_P.KalmanGainM_Value
                    section.data(6).logicalSrcIdx = 5;
                    section.data(6).dtTransOffset = 63;

                    ;% BeagleBone_Testing_P.C_Value
                    section.data(7).logicalSrcIdx = 6;
                    section.data(7).dtTransOffset = 93;

                    ;% BeagleBone_Testing_P.KalmanGainL_Value
                    section.data(8).logicalSrcIdx = 7;
                    section.data(8).dtTransOffset = 123;

                    ;% BeagleBone_Testing_P.B_Value
                    section.data(9).logicalSrcIdx = 8;
                    section.data(9).dtTransOffset = 153;

                    ;% BeagleBone_Testing_P.D_Value
                    section.data(10).logicalSrcIdx = 9;
                    section.data(10).dtTransOffset = 177;

                    ;% BeagleBone_Testing_P.Constant1_Value
                    section.data(11).logicalSrcIdx = 10;
                    section.data(11).dtTransOffset = 197;

                    ;% BeagleBone_Testing_P.Gain1_Gain
                    section.data(12).logicalSrcIdx = 11;
                    section.data(12).dtTransOffset = 198;

                    ;% BeagleBone_Testing_P.Constant_Value
                    section.data(13).logicalSrcIdx = 12;
                    section.data(13).dtTransOffset = 199;

                    ;% BeagleBone_Testing_P.X0_Value
                    section.data(14).logicalSrcIdx = 13;
                    section.data(14).dtTransOffset = 205;

                    ;% BeagleBone_Testing_P.Constant_Value_e
                    section.data(15).logicalSrcIdx = 14;
                    section.data(15).dtTransOffset = 211;

                    ;% BeagleBone_Testing_P.CovarianceZ_Value
                    section.data(16).logicalSrcIdx = 15;
                    section.data(16).dtTransOffset = 212;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% BeagleBone_Testing_P.Enable_Value
                    section.data(1).logicalSrcIdx = 16;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_P.isSqrtUsed_Value
                    section.data(2).logicalSrcIdx = 17;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 3;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (BeagleBone_Testing_B)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% BeagleBone_Testing_B.Reshapexhat
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% BeagleBone_Testing_B.PWM
                    section.data(1).logicalSrcIdx = 3;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_B.Product2
                    section.data(2).logicalSrcIdx = 4;
                    section.data(2).dtTransOffset = 4;

                    ;% BeagleBone_Testing_B.Product3
                    section.data(3).logicalSrcIdx = 5;
                    section.data(3).dtTransOffset = 10;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% BeagleBone_Testing_B.ang
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 6;
        sectIdxOffset = 3;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (BeagleBone_Testing_DW)
        ;%
            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.obj
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.obj_h
                    section.data(1).logicalSrcIdx = 1;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_DW.obj_j
                    section.data(2).logicalSrcIdx = 2;
                    section.data(2).dtTransOffset = 1;

                    ;% BeagleBone_Testing_DW.obj_d
                    section.data(3).logicalSrcIdx = 3;
                    section.data(3).dtTransOffset = 2;

                    ;% BeagleBone_Testing_DW.obj_b
                    section.data(4).logicalSrcIdx = 4;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.MemoryX_DSTATE
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.Scope3_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_DW.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.EnabledSubsystem_SubsysRanBC
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_DW.MeasurementUpdate_SubsysRanBC
                    section.data(2).logicalSrcIdx = 13;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% BeagleBone_Testing_DW.icLoad
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% BeagleBone_Testing_DW.EnabledSubsystem_MODE
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% BeagleBone_Testing_DW.MeasurementUpdate_MODE
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1295071894;
    targMap.checksum1 = 939863594;
    targMap.checksum2 = 1642654792;
    targMap.checksum3 = 2669884193;

