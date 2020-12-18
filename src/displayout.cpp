/*_____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
 |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|
  _     ____                   ____             _        _                ___   _        _
 | |   / ___|_ __ ___  ___ ___/ ___|  ___   ___| | _____| |_ ___  __   __/ _ \ / |      | |
 | |  | |   | '__/ _ \/ __/ __\___ \ / _ \ / __| |/ / _ \ __/ __| \ \ / / | | || |      | |
 | |  | |___| | | (_) \__ \__ \___) | (_) | (__|   <  __/ |_\__ \  \ V /| |_| || |      | |
 | |   \____|_|  \___/|___/___/____/ \___/ \___|_|\_\___|\__|___/   \_/  \___(_)_|      | |
 |_|                                                                                    |_|
  _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____ _____
 |_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|_____|


=========================================================
    -Copyright (C) 2019 Neoa Software

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
=========================================================

*/

//#pragma once

// ---------------- CODE ---------------- \\

#include "displayout.h"


displayout::displayout() {
    // Init the display thread

    ThreadDisplay = std::thread(&displayout::Threaded_Display, this);


}

displayout::~displayout() {
    // Join the main thread from here
    SetToQuit = true;

    

    // if it takes too long for the thread to join then we can hang here
    /// TODO fix this hang
    
 
}


void displayout::out(int enumTypeColor, std::string ToDisplay) {
    //std::cout << D_COLOR::blueM << "Got new display content!" << D_COLOR::defM << "\n";
    //std::cout << D_COLOR::blueM << "Content Memory --> " << enumTypeColor << " : " << ToDisplay << D_COLOR::defM << "\n";

    D_COLOR::ColorM::Modifier ModColor[] = { D_COLOR::defM, D_COLOR::blueM, D_COLOR::greenM, D_COLOR::redM, D_COLOR::redM, D_COLOR::magentaM, D_COLOR::yellowM };

    D_COLOR::__OBJSTRING ColorBack = { ToDisplay, D_COLOR::debugstring[enumTypeColor], ModColor[enumTypeColor]};

    PreDisplayControl.push_back(ColorBack);

}

void displayout::Threaded_Display() {
    

    std::cout << D_COLOR::greenM << "Starting Displayout!" << D_COLOR::defM << "\n";
    // Start the init for the display thread that will be displaying all content from a thread(s)
    while (!SetToQuit || ( PreDisplayControl.size() > 0 && PreDisplayControl.size() < 100 )) {
        int SLE = 1000000;
        while(SLE > 0) {SLE --;}
        

        if (PreDisplayControl.size() > 0) {
            
            auto i = &PreDisplayControl[0];

            std::cout << "Memory --> " << i << " = \'" << i->Message << "\'" << std::endl;
            
            //std::cout << i->DebugType << "[" << i->Prompt << "]: " << i->Message << D_COLOR::defM << "\n";
          
            if (PreDisplayControl[0].Message == "") {
                i++;
                std::cout << "NULL LOC! Next = " << i  <<  " = \'" << i->Message << "\'" << std::endl;
                PreDisplayControl.erase(PreDisplayControl.begin());
            }
            else {
                PreDisplayControl.erase(PreDisplayControl.begin());
                std::cout << "After:   " << PreDisplayControl[0].Message << "\n";
            }

            

            
            
        }
        
    }

    std::cout << D_COLOR::yellowM << "Stopping Displayout!" << D_COLOR::defM << "\n";

    Thread_done = true;

}