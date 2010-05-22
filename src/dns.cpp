// 
//

#include <boost/asio.hpp>
#include <boost/bind.hpp>



dns::resolver::query

query(qname, rdtype=dns.rdatatype.A, 
rdclass=dns.rdataclass.IN, 
tcp=False, source=None)


    boost::asio::ip::udp::resolver resolver(io_service);
    boost::asio::ip::udp::resolver::query query(argv[1], "dns");
	
	