//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

package helloworld_1.simulations;

import helloworld_1.Txc;

//
// Two instances (tic and toc) of Txc connected.
//
network Tictoc
{
    @display("bgb=343,421");
    submodules:
        tic[2]: Txc {
            @display("is=vl;p=64,118;i=,cyan"); //change color to cyan
        }
        toc[2]: Txc {
            @display("is=vl;p=269,235;i=,gold"); //change color to gold
        }
    //     tac[6]: Txc {
    //         @display("is=vl;p=153,302;i=,blue"); //change color to cyan
    //    }
    connections:
        tic[0].out++ --> {  delay = 100ms; } --> toc[1].in++;
        tic[0].in++ <-- {  delay = 100ms; } <-- toc[1].out++;

       // tic.in <-- {  delay = 100ms; } <-- tac.out;
       // tac.in <-- {  delay = 100ms; } <-- toc.out;
}
