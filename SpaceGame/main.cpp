//////////////////////////////////////////////////////////////////////////////
// SpaceGame - A game that takes place in space                             //
// Copyright © 2013 Peter Atashian                                          //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

int main(int, char **) {
    std::set_terminate([]() {
        std::cerr << "Fatal termination!" << std::endl;
        std::abort();
    });
    std::filebuf buf;
    buf.open("SpaceGame.log", std::ios::app | std::ios::out);
    std::cout.rdbuf(&buf);
    std::cerr.rdbuf(&buf);
    try {
        std::cout << "Starting up SpaceGame" << std::endl;
        
        std::cout << "Shutting down SpaceGame" << std::endl;
        return EXIT_SUCCESS;
    } catch (std::exception const & e) {
        std::cerr << "Fatal uncaught exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    } catch (...) {
        std::cerr << "Fatal unknown exception!" << std::endl;
        return EXIT_FAILURE;
    }
}