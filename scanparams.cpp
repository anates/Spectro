#include "scanparams.h"

ScanParams::ScanParams()
{
    for(int i = 0; i < 3; i++)
        ScanParams::polSettings.push_back(false);
    ScanParams::finPos = 0;
    ScanParams::scanSpeed = 0;
    ScanParams::startPos = 0;
}

void ScanParams::clear(void)
{
    ScanParams::finPos = 0;
    ScanParams::scanSpeed = 0;
    ScanParams::startPos = 0;
    ScanParams::polSettings[0] = false;
    ScanParams::polSettings[1] = false;
    ScanParams::polSettings[2] = false;
}
