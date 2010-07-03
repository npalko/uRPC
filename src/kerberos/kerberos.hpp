// src/kerberos/kerberos.hpp
//
//

// Kerberos Overview:
//
// Mac OS X, UNIX: GSS-API (shared files)
// Windows: SSPI (Security Support Provider Interface) (call the OS)
//
// Client Authentication:
//  1. Client login produces a Ticket-Granting-Ticket
//  2. Obtain a Session-Ticket by sending the Ticket-Granting-Ticket and 
//     application information to the KDC
//  3. Client caches the Session-Ticket, and will not need another 
//      Session-Ticket until it expires


#ifndef URPC_KERBEROS_HPP
#define URPC_KERBEROS_HPP

namespace urpc {
namespace kerberos {

// Use the Ticket-Granting-Ticket (obtained from the Authentication Server when 
// the user logged in to the client system) to request a Session Ticket from 
// the Ticket-Granting-Sever in order to authenticate to the uRPC server. 

void requestSessionTicket ();
void submitSessionTicketToServer ();

}
}


#endif // URPC_KERBEROS_HPP